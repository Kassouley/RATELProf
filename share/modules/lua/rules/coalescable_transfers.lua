local function find_coalescable_transfers(traces_data, DURATION_THRESHOLD_NS, GAP_THRESHOLD_NS, MIN_SEQUENCE_LEN, opt)

    local items = {}
    local sequences_per_gpu = {}

    local function on_sequence_end(sequence, gpu_node_id, sdma, name)
        if #sequence >= MIN_SEQUENCE_LEN then
            local sequence_start = sequence[1].start
            local sequence_stop = sequence[#sequence].stop
            local sequence_dur = sequence_stop - sequence_start
            local total_gap = 0
            for i = 2, #sequence do
                total_gap = total_gap + (sequence[i].start - sequence[i-1].stop)
            end


            local ideal_duration = sequence_dur - total_gap
            local speedup_factor = ideal_duration > 0 and (sequence_dur / ideal_duration) or 1.0


            table.insert(items, {
                tostring(gpu_node_id),
                tostring(sdma),
                #sequence,
                sequence_start,
                sequence_dur,
                total_gap,
                tonumber(string.format("%.2f", speedup_factor)),
                name,
            })

            if not sequences_per_gpu[gpu_node_id] then
                sequences_per_gpu[gpu_node_id] = 0
            end
            sequences_per_gpu[gpu_node_id] = sequences_per_gpu[gpu_node_id] + 1
        end
    end

    traces_data:for_each_gpu(function (gpu_node_id, _)
        local copy_data = traces_data:get(ratelprof.consts._ENV.DOMAIN_COPY)

        if #copy_data == 0 then return end

        local last_for_each_sdma = {}
        local sequence_for_each_sdma = {}
        for _, c in ipairs(copy_data) do
            local sdma_id  = c.args.engine_id
            local curr_last = last_for_each_sdma[sdma_id]
            local sequence  = sequence_for_each_sdma[sdma_id] or {}

            if c.dur > DURATION_THRESHOLD_NS then
                -- Skip large kernels
                if curr_last then
                    on_sequence_end(sequence, gpu_node_id, sdma_id, ratelprof.utils.get_copy_name_from_trace(curr_last))
                end
                sequence = {}
                curr_last = nil
            elseif not curr_last or (c.args.src_agent == curr_last.args.src_agent and c.args.dst_agent == curr_last.args.dst_agent 
                    and c.start - curr_last.stop < GAP_THRESHOLD_NS) then
                -- Add to sequence
                table.insert(sequence, c)
                curr_last = c
            else
                -- Check and reset
                on_sequence_end(sequence, gpu_node_id, sdma_id, ratelprof.utils.get_copy_name_from_trace(curr_last))
                sequence = {c}
                curr_last = c
            end
            last_for_each_sdma[sdma_id] = curr_last
            sequence_for_each_sdma[sdma_id] = sequence
        end

        -- Final check for each queue
        for sdma_id, sequence in pairs(sequence_for_each_sdma) do
            local last = last_for_each_sdma[sdma_id]
            if last then
                on_sequence_end(sequence, gpu_node_id, sdma_id, ratelprof.utils.get_copy_name_from_trace(last))
            end
        end
    end)

    return items, sequences_per_gpu
end


local function compute_coalescable_transfers_speedup(data, app_dur)
    local total_gaps_per_sdma = {}

    for _, e in ipairs(data) do
        local sdma = e[2]
        local gaps_duration = e[6]

        if not total_gaps_per_sdma[sdma] then
            total_gaps_per_sdma[sdma] = 0
        end
        total_gaps_per_sdma[sdma] = total_gaps_per_sdma[sdma] + gaps_duration
    end

    local max_gap_dur, _ = table.max(total_gaps_per_sdma)

    if max_gap_dur == nil or max_gap_dur == 0 then
        error("Invalid max ideal duration")
    end

    return app_dur / (app_dur - max_gap_dur)
end

return function(traces_data, _, opt)

    local DURATION_THRESHOLD_NS = opt.th_dur
    local GAP_THRESHOLD_NS      = opt.th_gap
    local MIN_SEQUENCE_LEN      = opt.min_seq

    local speedup_factor = 1

    local data, sequences_per_gpu = find_coalescable_transfers(traces_data, DURATION_THRESHOLD_NS, GAP_THRESHOLD_NS, MIN_SEQUENCE_LEN, opt)

    local msg = ""

    if #data ~= 0 then

        local app_duration = traces_data:get_app_dur()
        speedup_factor = compute_coalescable_transfers_speedup(data, app_duration)

        msg = [[
The following memory transfers sequences may benefit from coalescing into fewer, larger transfers.
These sequences were identified as:
  - Being the same transfers kind in the same SDMA,
  - Transfers back-to-back with a gap smaller than ]] .. GAP_THRESHOLD_NS .. [[ ns,
  - Each individual transfers shorter than ]] .. DURATION_THRESHOLD_NS .. [[ ns,
  - Appearing at least ]] .. MIN_SEQUENCE_LEN .. [[ times in sequence.

Optimizing these transfers might speed up your application by ]] .. string.format("x%.3f", speedup_factor) .. [[.

]]

        for gpu_id, count in pairs(sequences_per_gpu) do
            msg = msg .. "On GPU ID " .. gpu_id .. ", " .. count .. " repeated memory transfers sequence(s) detected.\n\n"
        end


        table.sort(data, function(a, b)
            return a[7] > b[7]
        end)
    else
        msg = "No redundant or coalescable memory transfers sequences were found.\n"
    end


    return {
        NAME = "Coalescable Memory Transfers",
        TYPE = "Analyze",
        HEADER = {
            "GPU ID",
            "SDMA",
            "Seq Length",
            "Seq Start (ns)",
            "Seq Duration (ns)",
            "Seq Gap Duration (ns)",
            "Seq Speed Up",
            "Operation",
        },
        DATA = data,
        MSG = msg,
        speedup = speedup_factor
    }
end
