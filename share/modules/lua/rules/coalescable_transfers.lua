local report_helper = require("utils.report_helper")

local function find_coalescable_transfers(copy_data, trace_data, DURATION_THRESHOLD_NS, GAP_THRESHOLD_NS, MIN_SEQUENCE_LEN, opt)

    local items = {}
    local count = 0

    local function on_sequence_end(sequence, sdma, name)
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
                tostring(sdma),
                #sequence,
                sequence_start,
                sequence_dur,
                total_gap,
                tonumber(string.format("%.2f", speedup_factor)),
                name,
            })

            count = count + 1
        end
    end

    local copy_table = {}
    for _, copy in pairs(copy_data) do
        local sdma = copy.args.engine_id

        if not copy_table[sdma] then copy_table[sdma] = {} end
        table.insert(copy_table[sdma], copy)
    end

    local last = nil

    for sdma, copies in pairs(copy_table) do
        local sequence = {}
        table.sort(copies, function(a, b) return a.start < b.start end)

        for _, c in ipairs(copies) do
            c.stop = c.start + c.dur
            if c.dur > DURATION_THRESHOLD_NS then
                -- Skip large kernels
                last = nil
                sequence = {}
            elseif not last or
                (c.args.src_agent == last.args.src_agent and c.args.dst_agent == last.args.dst_agent and c.start - last.stop  <= GAP_THRESHOLD_NS) then
                -- Add to sequence
                table.insert(sequence, c)
            else
                -- Check and reset
                on_sequence_end(sequence, sdma, ratelprof.utils.get_copy_name_from_trace(last))
                sequence = { c }
            end
            last = c
        end
        -- Final check for the last sequence of the queue
        on_sequence_end(sequence, sdma, ratelprof.utils.get_copy_name_from_trace(last))
    end

    return items, count
end


local function compute_coalescable_transfers_speedup(data, app_dur)
    local total_gaps_per_sdma = {}

    for _, e in ipairs(data) do
        local sdma = e[1]
        local gaps_duration = e[5]

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

return function(traces_data, report_id, opt)

    local DURATION_THRESHOLD_NS = report_helper.get_report_opt_value(report_id, "th_dur", opt.report_opt)
    local GAP_THRESHOLD_NS      = report_helper.get_report_opt_value(report_id, "th_gap", opt.report_opt)
    local MIN_SEQUENCE_LEN      = report_helper.get_report_opt_value(report_id, "min_seq", opt.report_opt)


    local copy_data = traces_data:get(ratelprof.consts._ENV.DOMAIN_COPY, opt)

    if next(copy_data) == nil then
        return {skip = "The report could not be analyzed because it does not contain the required copy data."}
    end

    local speedup_factor = 1

    local msg = ratelprof.consts._ALL_RULES_REPORT[report_id].desc

    local data, count = find_coalescable_transfers(copy_data, traces_data, DURATION_THRESHOLD_NS, GAP_THRESHOLD_NS, MIN_SEQUENCE_LEN, opt)

    if #data ~= 0 then

        local app_duration = traces_data:get_app_dur()
        speedup_factor = compute_coalescable_transfers_speedup(data, app_duration)

        local advice_msg = [[
The following memory transfers sequences may benefit from coalescing into fewer, larger transfers.
These sequences were identified as:
  - Being the same transfers kind in the same SDMA,
  - Transfers back-to-back with a gap smaller than ]] .. GAP_THRESHOLD_NS .. [[ ns,
  - Each individual transfers shorter than ]] .. DURATION_THRESHOLD_NS .. [[ ns,
  - Appearing at least ]] .. MIN_SEQUENCE_LEN .. [[ times in sequence.

Optimizing these transfers might speed up your application by ]] .. string.format("x%.3f", speedup_factor) .. [[.
]].. count .. [[ repeated memory transfers sequence(s) detected.

]]

        table.sort(data, function(a, b)
            return a[7] > b[7]
        end)

        msg = msg .. "\n" .. advice_msg

    else
        local no_advice_msg = "\nNo redundant or coalescable memory transfers sequences were found.\n"
        msg = msg .. no_advice_msg
    end


    return {
        NAME = "Coalescable Memory Transfers",
        TYPE = "Analyze",
        HEADER = {
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
