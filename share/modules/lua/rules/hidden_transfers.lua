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

local function find_hidden_latency(traces_data, TIME_THRESHOLD, HIDDEN_THRESHOLD_PCT)

    local items = {}
    local metrics = {}
    local trace_ids = {}

    local total_percentage_per_gpu = {}
    local max_not_hidden_copy_per_gpu = {}


    traces_data:for_each_gpu(function (gpu_node_id, _)
        local not_hidden_copy_dur_per_sdma = {}

        local total_time_overlapped = 0
        local total_time = 0

        local kernel_data = traces_data:get(ratelprof.consts._ENV.DOMAIN_KERNEL)
        local copy_data = traces_data:get(ratelprof.consts._ENV.DOMAIN_COPY)

        for _, copy in ipairs(copy_data) do
            local start_copy = copy.start
            local stop_copy  = copy.stop
            local dur_copy   = copy.dur
            local sdma       = copy.args.engine_id

            if not not_hidden_copy_dur_per_sdma[sdma] then
                not_hidden_copy_dur_per_sdma[sdma] = 0
            end

            if dur_copy > TIME_THRESHOLD then
                local time_overlapped = 0
                local start_idx = binary_search_kernels(kernel_data, start_copy)

                 for i = start_idx, #kernel_data do
                    local kernel = kernel_data[i]
                    local start_kernel = kernel.start
                    local stop_kernel  = kernel.stop

                    if start_kernel >= stop_copy  then break end

                    time_overlapped = time_overlapped + overlap(start_copy, stop_copy, start_kernel, stop_kernel)
                end

                local hidden_percentage = (time_overlapped / dur_copy) * 100
                if hidden_percentage < HIDDEN_THRESHOLD_PCT then
                    not_hidden_copy_dur_per_sdma[sdma] = not_hidden_copy_dur_per_sdma[sdma] + dur_copy - time_overlapped


                    total_time_overlapped = total_time_overlapped + time_overlapped
                    total_time = total_time + dur_copy

                    local entry_point = traces_data:find_entry_point(copy)
                    table.insert(trace_ids, copy.id)
                    table.insert(metrics, time_overlapped)
                    table.insert(items, {
                        tostring(gpu_node_id),
                        tostring(copy.id),
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

        total_percentage_per_gpu[gpu_node_id] = string.format("%.2f", 100 - (total_time_overlapped / total_time) * 100)
        max_not_hidden_copy_per_gpu[gpu_node_id] = table.max(not_hidden_copy_dur_per_sdma)
    end)


    return items, total_percentage_per_gpu, max_not_hidden_copy_per_gpu, trace_ids, metrics
end


local function compute_hidden_transfers_speedup(max_not_hidden_copy_per_gpu, app_dur)
    local max_ideal_hidden_dur, _ = table.max(max_not_hidden_copy_per_gpu)

    if max_ideal_hidden_dur == nil or max_ideal_hidden_dur == 0 then
        error("Invalid max ideal duration")
    end
    return app_dur / (app_dur - max_ideal_hidden_dur)
end

return function(traces_data, _, opt)

    local HIDDEN_THRESHOLD_PCT = opt.th_hidden
    local TIME_THRESHOLD       = opt.th_dur

    local data, percentage_per_gpu, max_not_hidden_copy_per_gpu, trace_ids, metrics = find_hidden_latency(traces_data, TIME_THRESHOLD, HIDDEN_THRESHOLD_PCT)

    local app_dur = traces_data:get_app_dur()
    local speedup_factor = 1

    local total_percent = 0
    local npourcent = 0
    local score = 0

    local msg = ""

    if #data == 0 then 
        msg = "All memory transfers were sufficiently overlapped by kernel execution. No visible latency (>"..HIDDEN_THRESHOLD_PCT.."%) due to memory transfers was detected.\n\n"
    else
        speedup_factor = compute_hidden_transfers_speedup(max_not_hidden_copy_per_gpu, app_dur)
        msg = [[ 
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
            msg = msg .. "On GPU ID " .. gpu_id .. ", an average of " .. percent .. "% of memory transfer time is not hidden by kernel execution.\n\n"
        end
        if npourcent ~= 0 then
            score = total_percent/npourcent
        end

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