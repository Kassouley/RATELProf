local report_helper = require("utils.report_helper")

-- Overlap duration function
local function overlap(s1, e1, s2, e2)
    local s = math.max(s1, s2)
    local e = math.min(e1, e2)
    return math.max(0, e - s)
end

local function binary_search_kernels(kernel_table, target_time)
    local low, high = 1, #kernel_table
    while low <= high do
        local mid = math.floor((low + high) / 2)
        if kernel_table[mid].stop <= target_time then
            low = mid + 1
        else
            high = mid - 1
        end
    end
    return low -- first kernel with .stop > target_time
end

local function find_hidden_latency(copy_data, kernel_data, traces_data, TIME_THRESHOLD, HIDDEN_THRESHOLD_PCT)
    local not_hidden_copy_dur_per_sdma = {}

    local kernel_table = {}
    for _, v in pairs(kernel_data) do
        v.stop = v.start + v.dur
        v.gpu_node_id = ratelprof.utils.get_gpu_id(v, traces_data)
        table.insert(kernel_table, v)
    end
    table.sort(kernel_table, function(a, b) return a.start < b.start end)

    local items = {}
    local metrics = {}
    local trace_ids = {}
    
    local total_time_overlapped_per_gpu = {}
    local total_time_per_gpu = {}

    for id, copy in pairs(copy_data) do
        local start_copy = copy.start
        local stop_copy  = start_copy + copy.dur
        local dur_copy = copy.dur
        local sdma = copy.args.engine_id

        if not not_hidden_copy_dur_per_sdma[sdma] then
            not_hidden_copy_dur_per_sdma[sdma] = 0
        end

        if dur_copy > TIME_THRESHOLD then

            local time_overlapped = 0

            local copy_gpu_id = ratelprof.utils.get_gpu_id(copy, traces_data)

            local start_idx = binary_search_kernels(kernel_table, start_copy)

            for i = start_idx, #kernel_table do
                local kernel = kernel_table[i]

                if kernel.gpu_node_id == copy_gpu_id then
                    local start_kernel, stop_kernel = kernel.start, kernel.stop

                    if start_kernel >= stop_copy  then break end

                    time_overlapped = time_overlapped + overlap(start_copy, stop_copy, start_kernel, stop_kernel)
                end
            end

            local hidden_percentage = (time_overlapped / dur_copy) * 100

            if hidden_percentage < HIDDEN_THRESHOLD_PCT then
                not_hidden_copy_dur_per_sdma[sdma] = not_hidden_copy_dur_per_sdma[sdma] + dur_copy - time_overlapped

                if not total_time_overlapped_per_gpu[copy_gpu_id] then total_time_overlapped_per_gpu[copy_gpu_id] = 0 end
                if not total_time_per_gpu[copy_gpu_id] then total_time_per_gpu[copy_gpu_id] = 0 end

                total_time_overlapped_per_gpu[copy_gpu_id] = total_time_overlapped_per_gpu[copy_gpu_id] + time_overlapped
                total_time_per_gpu[copy_gpu_id] = total_time_per_gpu[copy_gpu_id] + dur_copy

                local entry_point = traces_data:find_entry_point(copy)
                table.insert(trace_ids, id)
                table.insert(metrics, time_overlapped)
                table.insert(items, {
                    tostring(copy_gpu_id),
                    tostring(id),
                    ratelprof.utils.get_copy_name(copy.args.src_type, copy.args.dst_type),
                    copy.args.size,
                    string.format("%.2f", hidden_percentage),
                    dur_copy,
                    time_overlapped,
                    traces_data:get_location_str(entry_point)
                })
            end
        end
    end

    local total_percentage_per_gpu = {}
    for gpu_id, total in pairs(total_time_per_gpu) do
        total_percentage_per_gpu[gpu_id] = string.format("%.2f", 100 - (total_time_overlapped_per_gpu[gpu_id] / total) * 100)
    end

    return items, total_percentage_per_gpu, not_hidden_copy_dur_per_sdma, trace_ids, metrics
end


local function compute_hidden_transfers_speedup(not_hidden_copy_dur_per_sdma, app_dur)
    local max_ideal_hidden_dur, _ = table.max(not_hidden_copy_dur_per_sdma)

    if max_ideal_hidden_dur == nil or max_ideal_hidden_dur == 0 then
        error("Invalid max ideal duration")
    end
    return app_dur / (app_dur - max_ideal_hidden_dur)
end

return function(traces_data, report_id, opt)

    local HIDDEN_THRESHOLD_PCT = report_helper.get_report_opt_value(report_id, "th_hidden", opt.report_opt)
    local TIME_THRESHOLD       = report_helper.get_report_opt_value(report_id, "th_dur",    opt.report_opt)

    local kernel_data = traces_data:get(ratelprof.consts._ENV.DOMAIN_KERNEL, opt)

    if next(kernel_data) == nil then
        return {skip = "The report could not be analyzed because it does not contain the required kernel data."}
    end

    local copy_data = traces_data:get(ratelprof.consts._ENV.DOMAIN_COPY, opt)

    if next(copy_data) == nil then
        return {skip = "The report could not be analyzed because it does not contain the required copy data."}
    end

    local data, percentage_per_gpu, copy_dur_per_sdma, trace_ids, metrics = find_hidden_latency(copy_data, kernel_data, traces_data, TIME_THRESHOLD, HIDDEN_THRESHOLD_PCT)

    local app_dur = traces_data:get_app_dur()
    local speedup_factor = 1
    local msg = ratelprof.consts._ALL_RULES_REPORT[report_id].desc

    local total_percent = 0
    local npourcent = 0
    local score = 0

    if #data == 0 then 
        local no_advice_msg = "\nAll memory transfers were sufficiently overlapped by kernel execution. No visible latency (>"..HIDDEN_THRESHOLD_PCT.."%) due to memory transfers was detected.\n\n"
        msg = msg .. no_advice_msg
    else
        speedup_factor = compute_hidden_transfers_speedup(copy_dur_per_sdma, app_dur)
        local advice_msg = [[ 
The following memory transfers have less than ]]..HIDDEN_THRESHOLD_PCT..[[% of their latency hidden by concurrent kernel execution.
Improving concurrency between memory transfers and kernels can help reduce total runtime and increase GPU utilization.
Note : 
  - Not every memory transfers can be hidden.
  - Memory transfers can also be hidden with other tasks, such as CPU computations, not just kernel concurrency.

W/O concurency :
  +-------------+----------------+-------------+
  | Memcpy(H2D) |     Kernel     | Memcpy(D2H) |
  +-------------+----------------+-------------+
-------------------------------------------------> Time

With 2-way concurency :                        |
  +-------------+----+----+                    |
  | Memcpy(H2D) | K1 |DH1 |                    |
  +-------------+----+----+----+               |
                     | K2 |DH2 |               |
                     +----+----+----+ Speed up |
                          | K3 |DH3 | <------> |
                          +----+----+
-------------------------------------------------> Time

With 3-way concurency :                        |
  +----+----+----+                             |
  |HD1 | K1 |DH1 |                             |
  +----+----+----+----+                        |
       |HD2 | K2 |DH2 |                        |
       +----+----+----+----+     Speed up      |
            |HD3 | K3 |DH3 | <---------------> | 
            +----+----+----+
-------------------------------------------------> Time
 
Perfectly hide all memory transfers might speed up your application by ]] .. string.format("x%.3f.\n\n", speedup_factor)


        for gpu_id, percent in pairs(percentage_per_gpu) do
            total_percent = total_percent + (100-percent)
            npourcent = npourcent + 1
            advice_msg = advice_msg .. "On GPU ID " .. gpu_id .. ", an average of " .. percent .. "% of memory transfer time is not hidden by kernel execution.\n\n"
        end
        if npourcent ~= 0 then
            score = total_percent/npourcent
        end

        msg = msg .. advice_msg



        table.sort(data, function(a, b)
            return a[7] < b[7]
        end)
    end

    local header = {
        "GPU ID",
        "Copy ID",
        "Operation",
        "Size (B)",
        "Hidden (%)",
        "Duration (ns)",
        "Hidden Duration (ns)",
        "Source",
    }

    local vis = #trace_ids > 0 and {header, trace_ids, metrics} or nil

    return {
        NAME = "Hidden transfers latency",
        TYPE = "Analyze",
        HEADER = header,
        DATA = data,
        MSG = msg,
        score = score,
        speedup = speedup_factor,

        -- Return data for visualize command
        vis = vis
    }
end