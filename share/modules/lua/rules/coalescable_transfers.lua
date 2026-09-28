local report_helper = require("utils.report_helper")

local DEFAULT_ADVICE_MSG = [[
The following memory transfers sequences may benefit from coalescing into fewer, larger transfers.
These sequences were identified as:
  - Being the same transfers kind in the same GPU channel (SDMA or queue),
  - Transfers back-to-back with a gap smaller than %s ns,
  - Each individual transfers shorter than %s ns,
  - Appearing at least %s times in sequence.

Optimizing these transfers might speed up your application by x%.3f.
]]

local DEFAULT_NO_ADVICE_MSG = [[
No redundant or coalescable memory transfers sequences were found.
]]

local DEFAULT_PER_GPU_MSG = [[
    On GPU ID %s: %d sequence(s) of repeated consecutive memory transfers have been detected.
]]


return function (report)
    local timeunit = report.opt.timeunit
    local DURATION_THRESHOLD_NS = report.opt.th_dur
    local GAP_THRESHOLD_NS      = report.opt.th_gap
    local MIN_SEQUENCE_LEN      = report.opt.min_seq

    report.NAME = "Coalescable Memory Transfers"

    report.TYPE = "Analyze"

    report.COL_IDX = { rank = 0, start = 3, dur = 4 }

    report.HEADER = { "GPU ID", "Channel", "Seq. Length", "Seq. Start (" .. timeunit .. ")", "Seq. Dur (" .. timeunit .. ")", "Seq. Gap Dur (" .. timeunit .. ")", "Seq. Speed Up", "Operation" }

    report.LOOP_IN = { ratelprof.consts.DOMAIN_MEMORY_ID }

    report.SORT_BY = {"asc", 6}

    local data = {}
    local nb_sequences_per_gpu = {}
    local total_gaps_per_gpu = {}

    local function on_sequence_end(sequence, total_gap, gpu_key, channel, name)
        if #sequence >= MIN_SEQUENCE_LEN then
            local sequence_start = sequence[#sequence]:start()
            local sequence_stop = sequence[1]:stop()
            local sequence_dur = sequence_stop - sequence_start
         
            local ideal_duration = sequence_dur - total_gap
            local speedup_factor = ideal_duration > 0 and (sequence_dur / ideal_duration) or 1.0

            table.insert(data, {
                ratelprof.utils.label_unit_with_rank(gpu_key),
                channel,
                #sequence,
                report_helper.get_duration(sequence_start, timeunit),
                report_helper.get_duration(sequence_dur, timeunit),
                report_helper.get_duration(total_gap, timeunit),
                tonumber(string.format("%.2f", speedup_factor)),
                name
            })

            nb_sequences_per_gpu[gpu_key] = (nb_sequences_per_gpu[gpu_key] or 0) + 1
            
            total_gaps_per_gpu[gpu_key] = total_gaps_per_gpu[gpu_key] or {}
            total_gaps_per_gpu[gpu_key][channel] = (total_gaps_per_gpu[gpu_key][channel] or 0) + total_gap

        end
    end

    report.PRE_EVENT_LOOP = function (self)
        self.sequence_per_sdma = {}
        self.curr_last_per_sdma = {}
        self.total_gap_per_sdma = {}
    end

    report.FOR_EACH = function (self, event, _, gpu_key)
        local sub_unit = event:sub_unit()
        local curr_last = self.curr_last_per_sdma[sub_unit]
        local sequence = self.sequence_per_sdma[sub_unit] or {}
        local total_gap = self.total_gap_per_sdma[sub_unit] or 0

        if event:dur() > DURATION_THRESHOLD_NS then
            -- Skip large kernels
            if curr_last then
                local channel_label, channel_id = curr_last:gpu_channel()
                local channel = channel_label .. " " .. channel_id
                on_sequence_end(sequence, total_gap, gpu_key, channel, curr_last:name())
            end
            sequence = {}
            curr_last = nil

        else
            local can_append = false
            local gap = 0
            if not curr_last then
                can_append = true
            else
                gap = curr_last:start() - event:stop()

                can_append = event:ufunid() == curr_last:ufunid()
                    and gap > 0 and gap < GAP_THRESHOLD_NS
            end

            if can_append then
                sequence[#sequence + 1] = event
                total_gap = total_gap + gap
            else
                local channel_label, channel_id = curr_last:gpu_channel()
                local channel = channel_label .. " " .. channel_id
                on_sequence_end(sequence, total_gap, gpu_key, channel, curr_last:name())
                sequence = { event }
                total_gap = 0
            end

            curr_last = event
        end

        self.curr_last_per_sdma[sub_unit] = curr_last
        self.sequence_per_sdma[sub_unit] = sequence
        self.total_gap_per_sdma[sub_unit] = total_gap
    end

    report.POST_EVENT_LOOP = function (self, _, gpu_key)
        for sub_unit, curr_last in pairs(self.curr_last_per_sdma) do
            if curr_last then
                local sequence = self.sequence_per_sdma[sub_unit]
                local total_gap = self.total_gap_per_sdma[sub_unit]
                local channel_label, channel_id = curr_last:gpu_channel()
                local channel = channel_label .. " " .. channel_id
                on_sequence_end(sequence, total_gap, gpu_key, channel, curr_last:name())
            end
        end
    end

    report.POST_LOOP = function (self, rprofrep)
        local speedup_factor = 1
        local actual_dur = rprofrep:get_analyzed_interval_dur()
        local max_ideal_dur = 0

        for _, total_gaps_per_sdma in pairs(total_gaps_per_gpu) do
            for _, total_gaps in pairs(total_gaps_per_sdma) do
                local ideal_dur = actual_dur - total_gaps
                if ideal_dur > max_ideal_dur then
                    max_ideal_dur = ideal_dur
                end
            end
        end
        if max_ideal_dur > 0 then speedup_factor = actual_dur / max_ideal_dur end

        if #data == 0 then
            self.MESSAGE = DEFAULT_NO_ADVICE_MSG
        else
            local msg = string.format(DEFAULT_ADVICE_MSG, GAP_THRESHOLD_NS, DURATION_THRESHOLD_NS, MIN_SEQUENCE_LEN, speedup_factor)

            for gpu_key, count in pairs(nb_sequences_per_gpu) do
                msg = msg .. string.format(DEFAULT_PER_GPU_MSG, ratelprof.utils.label_unit_with_rank(gpu_key), count)
            end

            self.MESSAGE = msg
        end

        self.data = data
        self.speedup_factor = speedup_factor
    end
end