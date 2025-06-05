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

local function find_hidden_latency(copy_data, kernel_data, gpu_node_id_map, TIME_THRESHOLD, HIDDEN_THRESHOLD_PCT)

    local kernel_table = {}
    for _, v in pairs(kernel_data) do
        v.gpu_node_id = ratelprof.utils.get_gpu_id(v, gpu_node_id_map)
        table.insert(kernel_table, v)
    end
    table.sort(kernel_table, function(a, b) return a.start < b.start end)

    local items = {}
    local total_time_overlapped_per_gpu = {}
    local total_time_per_gpu = {}

    for id, copy in pairs(copy_data) do
        local start_copy, stop_copy = copy.start, copy.stop
        local dur_copy = copy.dur

        if dur_copy > TIME_THRESHOLD then
            local time_overlapped = 0

            local copy_gpu_id = ratelprof.utils.get_gpu_id(copy, gpu_node_id_map)

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
                if not total_time_overlapped_per_gpu[copy_gpu_id] then total_time_overlapped_per_gpu[copy_gpu_id] = 0 end
                if not total_time_per_gpu[copy_gpu_id] then total_time_per_gpu[copy_gpu_id] = 0 end

                total_time_overlapped_per_gpu[copy_gpu_id] = total_time_overlapped_per_gpu[copy_gpu_id] + time_overlapped
                total_time_per_gpu[copy_gpu_id] = total_time_per_gpu[copy_gpu_id] + dur_copy

                items[#items+1] = {
                    copy_gpu_id,
                    id,
                    ratelprof.utils.get_copy_name(copy.args.src_type, copy.args.dst_type),
                    copy.args.size,
                    string.format("%.2f", hidden_percentage),
                    dur_copy,
                    time_overlapped
                }
            end
        end
    end

    local total_percentage_per_gpu = {}
    for gpu_id, total in pairs(total_time_per_gpu) do
        total_percentage_per_gpu[gpu_id] = string.format("%.2f", 100 - (total_time_overlapped_per_gpu[gpu_id] / total) * 100)
    end

    return items, total_percentage_per_gpu
end

return function(traces_data, report_obj, opt)


    local HIDDEN_THRESHOLD_PCT = tonumber(opt.report_opt.th_hidden) or ratelprof.consts._ALL_RULES_REPORT.hidden_transfers.opt.th_hidden.default
    local TIME_THRESHOLD = tonumber(opt.report_opt.th_dur) or ratelprof.consts._ALL_RULES_REPORT.hidden_transfers.opt.th_dur.default


    report_obj:set_name("Hidden transfers latency")
    report_obj:set_type("Analyze")

    
    local kernel_data = traces_data:get(ratelprof.consts._ENV.DOMAIN_KERNEL)

    if next(kernel_data) == nil then
        report_obj:skip("The report could not be analyzed because it does not contain the required kernel data.")
        return
    end

    local copy_data = traces_data:get(ratelprof.consts._ENV.DOMAIN_COPY)

    if next(copy_data) == nil then
        report_obj:skip("The report could not be analyzed because it does not contain the required memory data.")
        return
    end

    report_obj:set_headers({
        "GPU Node ID",
        "Copy ID",
        "Operation",
        "Size (B)",
        "Hidden (%)",
        "Duration (ns)",
        "Hidden Duration (ns)"
    })

    local data, percentage_per_gpu = find_hidden_latency(copy_data, kernel_data, traces_data.node_id, TIME_THRESHOLD, HIDDEN_THRESHOLD_PCT)

    local msg = ratelprof.consts._ALL_RULES_REPORT.hidden_transfers.desc

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

With 2-way concurency :
  +-------------+----+----+
  | Memcpy(H2D) | K1 |DH1 |
  +-------------+----+----+----+
                     | K2 |DH2 |
                     +----+----+----+  Speed up
                          | K3 |DH3 | <--------> 
                          +----+----+
-------------------------------------------------> Time

With 3-way concurency :
  +----+----+----+
  |HD1 | K1 |DH1 |
  +----+----+----+----+
       |HD2 | K2 |DH2 |
       +----+----+----+----+      Speed up
            |HD3 | K3 |DH3 | <----------------> 
            +----+----+----+
-------------------------------------------------> Time

]]

    for gpu_id, percent in pairs(percentage_per_gpu) do
        advice_msg = advice_msg .. "On GPU ID " .. gpu_id .. ", an average of " .. percent .. "% of memory transfer time is not hidden by kernel execution.\n\n"
    end

    local no_advice_msg = "All memory transfers were sufficiently overlapped by kernel execution. No visible latency (>"..HIDDEN_THRESHOLD_PCT.."%) due to memory transfers was detected.\n\n"


    table.sort(data, function(a, b)
        return a[7] < b[7]
    end)

    if #data == 0 then 
        msg = msg .. no_advice_msg
    else
        msg = msg .. advice_msg
    end
    
    report_obj:set_custom_message(msg)
    report_obj:set_data(data)
end