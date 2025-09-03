local function compute_kernel_overlap_percentage(traces_data, CONCURRENCY_THRESHOLD_PCT, opt)
    local concurrent_pct_per_gpu = {}
    local concurrent_cnt_per_gpu = {}
    local result_data = {}
    local trace_ids = {}
    local metrics = {}

    traces_data:for_each_gpu(function (gpu_node_id, _)
        local kernel_data = traces_data:get(ratelprof.consts._ENV.DOMAIN_KERNEL)
        local n = #kernel_data

        if n == 0 then return end

        for i = 1, n do
            local k = kernel_data[i]

            local intervals = {}

            -- Loop forward only while overlap is possible
            for j = i + 1, n do
                local other = kernel_data[j]
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
                local other = kernel_data[j]
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

            local concurrency_pct = tonumber(string.format("%.2f", (overlap_duration / k.dur) * 100))

            if concurrency_pct >= CONCURRENCY_THRESHOLD_PCT then
                local total_concurrent_pct = concurrent_pct_per_gpu[gpu_node_id]
                local total_concurrent_cnt = concurrent_cnt_per_gpu[gpu_node_id]
                if not total_concurrent_pct then 
                    total_concurrent_pct = 0
                    total_concurrent_cnt = 0
                end
                concurrent_pct_per_gpu[gpu_node_id] = total_concurrent_pct + concurrency_pct
                concurrent_cnt_per_gpu[gpu_node_id] = total_concurrent_cnt + 1
                
                table.insert(metrics, tonumber(concurrency_pct))
                table.insert(trace_ids, k.id)
                table.insert(result_data, {
                    tostring(gpu_node_id),
                    tostring(k.args.queue_id),
                    k.id,
                    k.dur,
                    concurrency_pct,
                    ratelprof.utils.get_kernel_name(k.args.kernel_name, opt.trunc, opt.mangled),
                })
            end
        end

    end)

    local app_concurrency_pct = {}
    for gpu_node_id, count in pairs(concurrent_cnt_per_gpu) do
        app_concurrency_pct[gpu_node_id] = string.format("%.2f", (concurrent_pct_per_gpu[gpu_node_id] / count))
    end

    return result_data, app_concurrency_pct, trace_ids, metrics
end


return function(traces_data, _, opt)
    local CONCURRENCY_THRESHOLD_PCT = opt.pct_th

    local data, app_concurrency_pct, trace_ids, metrics = compute_kernel_overlap_percentage(traces_data, CONCURRENCY_THRESHOLD_PCT, opt)

    local msg = ""
    local score = 0
    local nscore = 0

    if #data == 0 then
        msg = msg .. "None of your kernels have a concurrency pourcentage superior to "..CONCURRENCY_THRESHOLD_PCT.."%\n"
                  .. "Concurrency can improve performance if well done."
    else

        for gpu_id, percent in pairs(app_concurrency_pct) do
            msg = msg .. "On GPU ID " .. gpu_id .. ": " .. percent .. "% of total kernel time overlaps with other kernels.\n"
            nscore = nscore + 1
            score = score + (percent - score) / nscore
        end
        msg = msg .. "The following kernels are running concurrently with others.\n"
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
        score = score,

        -- Return data for visualize command
        vis = vis
    }
end
