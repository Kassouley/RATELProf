local function find_coalescable_kernels(traces_data, DURATION_THRESHOLD_NS, GAP_THRESHOLD_NS, MIN_SEQUENCE_LEN, opt)

    local items = {}
    local sequences_per_gpu = {}

    local function on_sequence_end(sequence, gpu_node_id, queue_id, name)
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
                tostring(queue_id),
                #sequence,
                sequence_start,
                sequence_dur,
                total_gap,
                tonumber(string.format("%.2f", speedup_factor)),
                ratelprof.utils.get_kernel_name(name, opt.trunc, opt.mangled),
            })

            if not sequences_per_gpu[gpu_node_id] then
                sequences_per_gpu[gpu_node_id] = 0
            end
            sequences_per_gpu[gpu_node_id] = sequences_per_gpu[gpu_node_id] + 1
        end
    end

    traces_data:for_each_gpu(function (gpu_node_id, _)
        local kernel_data = traces_data:get(ratelprof.consts._ENV.DOMAIN_KERNEL)

        if #kernel_data == 0 then return end

        local last_for_each_queue = {}
        local sequence_for_each_queue = {}

        for _, k in ipairs(kernel_data) do
            local queue_id  = k.args.queue_id
            local curr_last = last_for_each_queue[queue_id]
            local sequence  = sequence_for_each_queue[queue_id] or {}

            if k.dur > DURATION_THRESHOLD_NS then
                -- Skip large kernels
                if curr_last then
                    on_sequence_end(sequence, gpu_node_id, queue_id, curr_last.args.kernel_name)
                end
                sequence = {}
                curr_last = nil
            elseif not curr_last or (k.args.kernel_name == curr_last.args.kernel_name
                    and k.start - curr_last.stop < GAP_THRESHOLD_NS) then
                -- Add to sequence
                table.insert(sequence, k)
                curr_last = k
            else
                -- Check and reset
                on_sequence_end(sequence, gpu_node_id, queue_id, curr_last.args.kernel_name)
                sequence = {k}
                curr_last = k
            end
            last_for_each_queue[queue_id] = curr_last
            sequence_for_each_queue[queue_id] = sequence
        end

        -- Final check for each queue
        for queue_id, sequence in pairs(sequence_for_each_queue) do
            local last = last_for_each_queue[queue_id]
            if last then
                on_sequence_end(sequence, gpu_node_id, queue_id, last.args.kernel_name)
            end
        end
    end)

    return items, sequences_per_gpu
end


local function compute_coalescable_kernels_speedup(data, app_dur)
    local total_gaps_per_queue = {}

    for _, e in ipairs(data) do
        local queue_id = e[2]
        local gaps_duration = e[6]

        if not total_gaps_per_queue[queue_id] then
            total_gaps_per_queue[queue_id] = 0
        end
        total_gaps_per_queue[queue_id] = total_gaps_per_queue[queue_id] + gaps_duration
    end

    local max_gap_dur, _ = table.max(total_gaps_per_queue)

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

    local msg = ""

    local data, sequences_per_gpu = find_coalescable_kernels(traces_data, DURATION_THRESHOLD_NS, GAP_THRESHOLD_NS, MIN_SEQUENCE_LEN, opt)

    if #data ~= 0 then

        local app_duration = traces_data:get_app_dur()
        speedup_factor = compute_coalescable_kernels_speedup(data, app_duration)

        msg = [[
The following kernel launch sequences may benefit from coalescing into fewer, larger launches.
These sequences were identified as:
  - Having the same kernel name, on the same GPU, in the same queue,
  - Launched back-to-back with a gap smaller than ]] .. GAP_THRESHOLD_NS .. [[ ns,
  - Each individual kernel shorter than ]] .. DURATION_THRESHOLD_NS .. [[ ns,
  - Appearing at least ]] .. MIN_SEQUENCE_LEN .. [[ times in sequence.

Optimizing these kernel calls might speed up your application by ]] .. string.format("x%.3f.\n\n", speedup_factor)

        for gpu_id, count in pairs(sequences_per_gpu) do
            msg = msg .. "On GPU ID " .. gpu_id .. ", " .. count .. " repeated kernel launch sequence(s) detected.\n\n"
        end

        table.sort(data, function(a, b)
            return a[8] > b[8]
        end)
    else
        msg = "No redundant or coalescable kernel launch sequences were found.\n"
    end


    return {
        NAME = "Coalescable Kernel Launches",
        TYPE = "Analyze",
        HEADER = {
            "GPU ID",
            "Queue ID",
            "Seq Length",
            "Seq Start (ns)",
            "Seq Duration (ns)",
            "Seq Gap Duration (ns)",
            "Seq Speed Up",
            "Kernel Name",
        },
        DATA = data,
        MSG = msg,
        speedup = speedup_factor
    }
end
