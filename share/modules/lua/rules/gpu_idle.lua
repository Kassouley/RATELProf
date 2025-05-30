function find_gaps(kernel_traces, gap_th, gpu_node_id_map)
    local gaps = {}
    local percentage_per_gpu = {}

    -- Step 1: Group traces by gpu_id
    local gpu_traces = {}
    for _, trace in pairs(kernel_traces) do
        local gpu_agent = trace.args.gpu_id
        local gpu_id = gpu_node_id_map[tostring(gpu_agent)] or gpu_agent
        if not gpu_traces[gpu_id] then
            gpu_traces[gpu_id] = {}
        end
        table.insert(gpu_traces[gpu_id], trace)
    end

    -- Step 2: Process each gpu_id separately
    for gpu_id, traces in pairs(gpu_traces) do
        local total_gap_dur = 0
        local starts_sorted = {}
        local ends_sorted = {}

        -- Copy traces into sorting tables
        for _, t in ipairs(traces) do
            table.insert(starts_sorted, t)
            table.insert(ends_sorted, t)
        end

        -- Sort by start times
        table.sort(starts_sorted, function(a, b) 
            return a["start"] < b["start"] 
        end)

        -- Sort by end times
        table.sort(ends_sorted, function(a, b) 
            return a["stop"] < b["stop"] 
        end)

        -- Step 3: Reconstruct intervals [ERj, SRj+1]
        for i = 1, #ends_sorted - 1 do
            local ERj = ends_sorted[i]  -- End of current operation
            local SRj_plus_1 = starts_sorted[i + 1]  -- Start of the next operation

            -- Step 4: Keep only valid intervals (ERj < SRj+1)
            local gap_dur = SRj_plus_1["start"] - ERj["stop"]
            if gap_dur > gap_th then
                table.insert(gaps, {
                    gpu_id,
                    #gaps + 1,
                    string.format("%.0f", ERj["stop"]), 
                    string.format("%.0f", SRj_plus_1["start"]),
                    gap_dur
                })
                total_gap_dur = total_gap_dur + gap_dur
            end
        end

        -- Compute total time range for percentage calculation
        local total_time = ends_sorted[#ends_sorted]["stop"] - starts_sorted[1]["start"]
        local gap_percentage = string.format("%.2f", (total_gap_dur / total_time) * 100)

        -- Store results per GPU
        percentage_per_gpu[gpu_id] = gap_percentage
    end

    return gaps, percentage_per_gpu
end


return function(traces_data, report_obj, opt)
    report_obj:set_name("GPU Idle")
    report_obj:set_type("Analyze")

    local GAP_MS = 500 --TMP VALUE, NEED TO BE A USER INPUT
    
    local kernel_data = traces_data:get(ratelprof.consts._ENV.DOMAIN_KERNEL)

    if next(kernel_data) == nil then
        print ("SKIPPED: The report could not be analyzed because it does not contain the required GPU data.")
        return 1
    end

    report_obj:set_headers({
        "GPU Node ID",
        "Range ID",
        "Start",
        "End",
        "Duration (ns)"
    })

    local data, percentage_per_gpu = find_gaps(kernel_data, GAP_MS * 1e6, traces_data.node_id)

    local msg = [[
This rule identifies time regions where a GPU is idle for longer than a set threshold. 
For each GPU, gaps are found within the time range that starts with the beginning of the first GPU
operation on that device and ends with the end of the last GPU operation on that device.

]]
    local advice_msg = [[
The following are ranges where a GPU is idle for more than ]]..GAP_MS..[[ ms. 
Addressing these gaps might improve application performance.
]]
    for gpu_id, percent in pairs(percentage_per_gpu) do
        advice_msg = advice_msg .. "On GPU ID " .. gpu_id .. ", gaps account for " .. percent .. "% of the total GPU time.\n"
    end

    local no_advice_msg = "There were no problems detected with GPU utilization. GPU was not found to be idle for more than "..GAP_MS.." ms.\n"

    if #data == 0 then 
        msg = msg .. no_advice_msg
    else
        msg = msg .. advice_msg
    end
    
    report_obj:set_custom_message(msg)
    report_obj:set_data(data)
end