local report_helper = require("utils/report_helper")

-- Sort function
local function sort_by_start(tbl)
    table.sort(tbl, function(a, b) return a.start < b.start end)
end

-- Overlap duration function
local function overlap(s1, e1, s2, e2)
    local s = math.max(s1, s2)
    local e = math.min(e1, e2)
    return math.max(0, e - s)
end

local function find_hidden_latency(copy_data, kernel_data, gpu_node_id_map)
    sort_by_start(kernel_data)

    local items = {}
    local percentage_per_gpu = {}

    for id, copy in pairs(copy_data) do
        local start_copy, stop_copy = copy.start, copy.stop
        local dur_copy = copy.dur
        local time_overlapped = 0

        local copy_gpu_id = ratelprof.utils.get_gpu_id(copy, gpu_node_id_map)

        for _, kernel in ipairs(kernel_data) do
            local kernel_gpu_id = ratelprof.utils.get_gpu_id(kernel, gpu_node_id_map)
            if kernel_gpu_id == copy_gpu_id then 
                local start_kernel, stop_kernel = kernel.start, kernel.stop
                if start_kernel >= stop_copy then break end
                if stop_kernel  >  start_copy then 
                    time_overlapped = time_overlapped + overlap(start_copy, stop_copy, start_kernel, stop_kernel)
                end
            end
        end

        local hidden_percentage = (time_overlapped / dur_copy) * 100

        if hidden_percentage < 50 then
            percentage_per_gpu[copy_gpu_id] = hidden_percentage

            items[#items+1] = {
                copy_gpu_id,
                id,
                ratelprof.utils.get_copy_name(copy.src_type, copy.dst_type),
                hidden_percentage,
                dur_copy,
                time_overlapped
            }
        end
    end

    return items, percentage_per_gpu
end

return function(traces_data, report_obj, opt)
    report_obj:set_name("Hidden transfers latency")
    report_obj:set_type("Analyze")

    
    local kernel_data = traces_data:get(ratelprof.consts._ENV.DOMAIN_KERNEL)

    if next(kernel_data) == nil then
        report_obj:skip("The report could not be analyzed because it does not contain the required kernel data.")
        return
    end

    local copy_data = traces_data:get(ratelprof.consts._ENV.DOMAIN_MEMORY)

    if next(copy_data) == nil then
        report_obj:skip("The report could not be analyzed because it does not contain the required memory data.")
        return
    end

    report_obj:set_headers({
        "GPU Node ID",
        "Copy ID",
        "Operation",
        "Hidden (%)",
        "Duration (ns)",
        "Hidden Duration (ns)"
    })

    local data, percentage_per_gpu = find_hidden_latency(copy_data, kernel_data, traces_data.node_id)

    local msg = [[
This rule identifies memory transfers whose latency is not fully hidden by concurrent kernel execution.
For each memory transfer, the rule calculates how much of its duration does not overlap with any kernel activity for each GPU.
Transfers that are not sufficiently overlapped may contribute to performance bottlenecks, as their latency is visible to the application.
]]

    local advice_msg = [[
The following memory transfers have less than 50% of their latency hidden by concurrent kernel execution.
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
        advice_msg = advice_msg .. "On GPU ID " .. gpu_id .. ", an average of " .. percent .. "% of memory transfer time is not overlapped by kernel execution.\n"
    end

    local no_advice_msg = "All memory transfers were sufficiently overlapped by kernel execution. No visible latency (>50%) due to memory transfers was detected.\n"

    if #data == 0 then 
        msg = msg .. no_advice_msg
    else
        msg = msg .. advice_msg
    end
    
    report_obj:set_custom_message(msg)
    report_obj:set_data(data)
end