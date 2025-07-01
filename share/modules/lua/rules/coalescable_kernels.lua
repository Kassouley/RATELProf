local report_helper = require("utils.report_helper")

local function find_coalescable_kernels(kernel_data, trace_data, DURATION_THRESHOLD_NS, GAP_THRESHOLD_NS, MIN_SEQUENCE_LEN, opt)

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

    local kernel_table = {}
    for _, kernel in pairs(kernel_data) do
        local gpu_node_id = trace_data:get_gpu_id(kernel.args.gpu_id)
        local queue_id    = kernel.args.queue_id
        if not kernel_table[gpu_node_id] then kernel_table[gpu_node_id] = {} end
        if not kernel_table[gpu_node_id][queue_id] then kernel_table[gpu_node_id][queue_id]  = {} end
        table.insert(kernel_table[gpu_node_id][queue_id], kernel)
    end

    local last = nil

    for gpu_node_id, kernels_per_gpu in pairs(kernel_table) do
        for queue_id, kernels_per_queue in pairs(kernels_per_gpu) do
            local sequence = {}
            table.sort(kernels_per_queue, function(a, b) return a.start < b.start end)

            for _, k in ipairs(kernels_per_queue) do
                k.stop = k.start + k.dur
                if k.dur > DURATION_THRESHOLD_NS then
                    -- Skip large kernels
                    last = nil
                    sequence = {}
                elseif not last or
                    (k.args.kernel_name == last.args.kernel_name and k.start - last.stop  <= GAP_THRESHOLD_NS) then

                    -- Add to sequence
                    table.insert(sequence, k)
                else
                    -- Check and reset
                    on_sequence_end(sequence, gpu_node_id, queue_id, last.args.kernel_name)
                    sequence = { k }
                end
                last = k
            end
            -- Final check for the last sequence of the queue
            on_sequence_end(sequence, gpu_node_id, queue_id, last.args.kernel_name)
        end
    end

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

return function(traces_data, report_id, opt)

    local DURATION_THRESHOLD_NS = report_helper.get_report_opt_value(report_id, "th_dur", opt.report_opt)
    local GAP_THRESHOLD_NS      = report_helper.get_report_opt_value(report_id, "th_gap", opt.report_opt)
    local MIN_SEQUENCE_LEN      = report_helper.get_report_opt_value(report_id, "min_seq", opt.report_opt)

    local kernel_data = traces_data:get(ratelprof.consts._ENV.DOMAIN_KERNEL, opt)

    if next(kernel_data) == nil then
        return {skip = "The report could not be analyzed because it does not contain the required kernel data."}
    end

    local speedup_factor = 1

    local msg = ratelprof.consts._ALL_RULES_REPORT[report_id].desc

    local data, sequences_per_gpu = find_coalescable_kernels(kernel_data, traces_data, DURATION_THRESHOLD_NS, GAP_THRESHOLD_NS, MIN_SEQUENCE_LEN, opt)

    if #data ~= 0 then

        local app_duration = traces_data:get_app_dur()
        speedup_factor = compute_coalescable_kernels_speedup(data, app_duration)

        local advice_msg = [[
The following kernel launch sequences may benefit from coalescing into fewer, larger launches.
These sequences were identified as:
  - Having the same kernel name, on the same GPU, in the same queue,
  - Launched back-to-back with a gap smaller than ]] .. GAP_THRESHOLD_NS .. [[ ns,
  - Each individual kernel shorter than ]] .. DURATION_THRESHOLD_NS .. [[ ns,
  - Appearing at least ]] .. MIN_SEQUENCE_LEN .. [[ times in sequence.

Optimizing these kernel calls might speed up your application by ]] .. string.format("x%.3f.\n\n", speedup_factor)

        for gpu_id, count in pairs(sequences_per_gpu) do
            advice_msg = advice_msg .. "On GPU ID " .. gpu_id .. ", " .. count .. " repeated kernel launch sequence(s) detected.\n\n"
        end


        table.sort(data, function(a, b)
            return a[8] > b[8]
        end)

        msg = msg .. "\n" .. advice_msg

    else
        local no_advice_msg = "\nNo redundant or coalescable kernel launch sequences were found.\n"
        msg = msg .. no_advice_msg
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
