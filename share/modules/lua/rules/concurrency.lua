local report_helper = require("utils.report_helper")

local function compute_kernel_overlap_percentage(kernel_data, traces_data, CONCURRENCY_THRESHOLD_PCT, opt)
    local all_kernels = {}

    for id, kernel in pairs(kernel_data) do
        kernel.id = id
        kernel.gpu_node_id = traces_data:get_gpu_id(kernel.args.gpu_id)
        kernel.stop = kernel.start + kernel.dur
        table.insert(all_kernels, kernel)
    end

    table.sort(all_kernels, function(a, b) return a.start < b.start end)

    local total_concurrent_time = 0
    local result_data = {}
    local trace_ids = {}
    local metrics = {}

    local n = #all_kernels

    for i = 1, n do
        local k = all_kernels[i]

        local intervals = {}

        -- Loop forward only while overlap is possible
        for j = i + 1, n do
            local other = all_kernels[j]
            if other.start >= k.stop then
                break -- No further overlaps possible
            end
            if other.start < k.stop and other.stop > k.start then
                -- Compute actual overlap interval
                local overlap_start = math.max(k.start, other.start)
                local overlap_stop  = math.min(k.stop, other.stop)
                table.insert(intervals, {start = overlap_start, stop = overlap_stop})
            end
        end

        -- Loop backward too
        for j = i - 1, 1, -1 do
            local other = all_kernels[j]
            if other.stop <= k.start then
                break -- No further overlaps possible
            end
            if other.start < k.stop and other.stop > k.start then
                -- Compute actual overlap interval
                local overlap_start = math.max(k.start, other.start)
                local overlap_stop  = math.min(k.stop, other.stop)
                table.insert(intervals, {start = overlap_start, stop = overlap_stop})
            end
        end

        -- Merge intervals
        table.sort(intervals, function(a, b) return a.start < b.start end)
        local merged = {}
        for _, iv in ipairs(intervals) do
            if #merged == 0 or iv.start > merged[#merged].stop then
                table.insert(merged, iv)
            else
                merged[#merged].stop = math.max(merged[#merged].stop, iv.stop)
            end
        end

        -- Compute total overlap duration
        local overlap_duration = 0
        for _, iv in ipairs(merged) do
            overlap_duration = overlap_duration + (iv.stop - iv.start)
        end

        total_concurrent_time = total_concurrent_time + overlap_duration

        local concurrency_pct = tonumber(string.format("%.2f", (overlap_duration / k.dur) * 100))
        if concurrency_pct >= CONCURRENCY_THRESHOLD_PCT then
            table.insert(metrics, tonumber(concurrency_pct))
            table.insert(trace_ids, k.id)
            table.insert(result_data, {
                tostring(k.gpu_node_id),
                tostring(k.args.queue_id),
                k.id,
                k.dur,
                concurrency_pct,
                ratelprof.utils.get_kernel_name(k.args.kernel_name, opt.trunc, opt.mangled),
            })
        end
    end

    local total_kernel_time = traces_data:get_compute_time()

    local app_concurrency_pct = (total_concurrent_time / total_kernel_time) * 100
    return result_data, app_concurrency_pct, trace_ids, metrics
end


return function(traces_data, report_id, opt)
    local kernel_data = traces_data:get(ratelprof.consts._ENV.DOMAIN_KERNEL, opt)

    if next(kernel_data) == nil then
        return {skip = "The report could not be analyzed because it does not contain the required kernel data."}
    end

    local CONCURRENCY_THRESHOLD_PCT = report_helper.get_report_opt_value(report_id, "pct_th", opt.report_opt)

    local data, app_concurrency_pct, trace_ids, metrics = compute_kernel_overlap_percentage(kernel_data, traces_data, CONCURRENCY_THRESHOLD_PCT, opt)

    local msg = ratelprof.consts._ALL_RULES_REPORT[report_id].desc

    msg = msg .. string.format(
        "Application kernel concurrency: %.2f%% of total kernel time overlaps with other kernels.\n",
        app_concurrency_pct
    )

    if #data == 0 then
        msg = msg .. "\nNone of your kernels have a concurrency pourcentage superior to "..CONCURRENCY_THRESHOLD_PCT.."%\n"
                  .. "Concurrency can improve performance if well done."
    else
        msg = msg .. "\nThe following kernels are running concurrently with others.\n"
                  .. "A kernel is considered concurrent if the percentage of its execution time that overlaps with other kernels exceeds "
                  .. CONCURRENCY_THRESHOLD_PCT .. "%.\n\n"

        table.sort(data, function(a, b)
            return a[5] > b[5]
        end)
    end

    local header = {
        "GPU ID",
        "Queue ID",
        "Trace ID",
        "Duration (ns)",
        "Concurrency (%)",
        "Kernel Name"
    }

    local vis = #trace_ids > 0 and {header, trace_ids, metrics} or nil

    return {
        NAME = "Concurrency",
        TYPE = "Analyze",
        HEADER = header,
        DATA = data,
        MSG = msg,
        score = app_concurrency_pct,

        -- Return data for visualize command
        vis = vis
    }
end
