local function find_gaps(traces_data, gap_th)
    local gaps = {}
    local percentage_per_gpu = {}

    traces_data:for_each_gpu(function (gpu_node_id, _)
        local total_gap_dur = 0
        local starts_sorted = traces_data:get(ratelprof.consts._ENV.DOMAIN_KERNEL)

        if #starts_sorted > 0 then
            local ends_sorted = table.icopy(starts_sorted)

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
                        tostring(gpu_node_id),
                        tostring(#gaps + 1),
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
            percentage_per_gpu[gpu_node_id] = gap_percentage
        end
    end)


    return gaps, percentage_per_gpu
end


return function(traces_data, _, opt)
    local GAP_MS = opt.th_gap

    local data, percentage_per_gpu = find_gaps(traces_data, GAP_MS * 1e6)

    local msg
    if #data == 0 then 
        msg = "There were no problems detected with GPU utilization. GPU was not found to be idle for more than "..GAP_MS.." ms.\n"
    else
        msg = [[
The following are ranges where a GPU is idle for more than ]]..GAP_MS..[[ ms. 
Addressing these gaps might improve application performance.
]]

        for gpu_id, percent in pairs(percentage_per_gpu) do
            msg = msg .. "On GPU ID " .. gpu_id .. ", gaps account for " .. percent .. "% of the total GPU time.\n"
        end
        msg = msg .. "\n"

        table.sort(data, function(a, b) return a[2] < b[2] end)
    end

    return {
        NAME = "GPU Idle",
        TYPE = "Analyze",
        HEADER = {
            "GPU ID",
            "Range ID",
            "Start",
            "End",
            "Duration (ns)"
        },
        DATA = data,
        MSG = msg,
    }
end