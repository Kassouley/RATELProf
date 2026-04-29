local report_helper = require("utils.report_helper")

local DEFAULT_ADVICE_MSG = [[
The following kernel launch sequences may benefit from coalescing into fewer, larger launches.
These sequences were identified as:
  - Having the same kernel name, on the same GPU, in the same queue,
  - Launched back-to-back with a gap smaller than %s ns,
  - Each individual kernel shorter than %s ns,
  - Appearing at least %s times in sequence.

Optimizing these kernel calls might speed up your application by x%.3f.
]]

local DEFAULT_NO_ADVICE_MSG = [[
No redundant or coalescable kernel launch sequences were found.
]]

local DEFAULT_PER_GPU_MSG = [[
    On GPU ID %s: %d sequence(s) of repeated consecutive kernel launch have been detected.
]]

return function (report)
    local timeunit = report.opt.timeunit
    local trunc    = report.opt.trunc
    local mangled  = report.opt.mangled
    local DURATION_THRESHOLD_NS = report.opt.th_dur
    local GAP_THRESHOLD_NS      = report.opt.th_gap
    local MIN_SEQUENCE_LEN      = report.opt.min_seq

    report.NAME = "Coalescable Kernel Launches"

    report.TYPE = "Analyze"

    report.HEADER = { "GPU ID", "Queue ID", "Seq. Length", "Seq. Start (" .. timeunit .. ")", "Seq. Dur (" .. timeunit .. ")", "Seq. Gap Dur (" .. timeunit .. ")", "Seq. Speed Up", "Kernel Name" }

    report.LOOP_IN = { ratelprof.consts.DOMAIN_KERNEL_ID }

    report.SORT_BY = {"asc", 6}

    local data = {}
    local nb_sequences_per_gpu = {}
    local total_gaps_per_gpu = {}

    local function on_sequence_end(sequence, gpu_key, queue_id, name)
        if #sequence >= MIN_SEQUENCE_LEN then
            local sequence_start = sequence[1]:start()
            local sequence_stop = sequence[#sequence]:stop()
            local sequence_dur = sequence_stop - sequence_start
            local total_gap = 0
            for i = 2, #sequence do
                total_gap = total_gap + (sequence[i]:start() - sequence[i-1]:stop())
            end

            local ideal_duration = sequence_dur - total_gap
            local speedup_factor = ideal_duration > 0 and (sequence_dur / ideal_duration) or 1.0

            table.insert(data, {
                ratelprof.utils.label_unit_with_rank(gpu_key),
                tostring(queue_id),
                #sequence,
                report_helper.get_duration(sequence_start, timeunit),
                report_helper.get_duration(sequence_dur, timeunit),
                report_helper.get_duration(total_gap, timeunit),
                tonumber(string.format("%.2f", speedup_factor)),
                ratelprof.utils.get_kernel_name(name, trunc, mangled),
            })

            nb_sequences_per_gpu[gpu_key] = (nb_sequences_per_gpu[gpu_key] or 0) + 1
            
            total_gaps_per_gpu[gpu_key] = total_gaps_per_gpu[gpu_key] or {}
            total_gaps_per_gpu[gpu_key][queue_id] = (total_gaps_per_gpu[gpu_key][queue_id] or 0) + total_gap

        end
    end

    report.PRE_EVENT_LOOP = function (self)
        self.sequence_per_queue = {}
        self.curr_last_per_queue = {}
    end

    report.FOR_EACH = function (self, event, _, gpu_key)
        local queue_id = event:queue_id()
        local curr_last = self.curr_last_per_queue[queue_id]
        local sequence = self.sequence_per_queue[queue_id] or {}

        if event:dur() > DURATION_THRESHOLD_NS then
            -- Skip large kernels
            if curr_last then
                on_sequence_end(sequence, gpu_key, queue_id, curr_last:name())
            end
            sequence = {}
            curr_last = nil

        elseif not curr_last or (event:ufunid() == curr_last:ufunid()
                and event:start() - curr_last:stop() < GAP_THRESHOLD_NS) then
            -- Add to sequence
            table.insert(sequence, event)
            curr_last = event
        else
            -- Check and reset
            on_sequence_end(sequence, gpu_key, queue_id, curr_last:name())
            sequence = {event}
            curr_last = event
        end

        self.curr_last_per_queue[queue_id] = curr_last
        self.sequence_per_queue[queue_id] = sequence
    end

    report.POST_EVENT_LOOP = function (self, _, gpu_key)
        for queue_id, curr_last in pairs(self.curr_last_per_queue) do
            if curr_last then
                local sequence = self.sequence_per_queue[queue_id]
                on_sequence_end(sequence, gpu_key, queue_id, curr_last:name())
            end
        end
    end

    report.POST_LOOP = function (self, rprofrep)
        local speedup_factor = 1
        local actual_dur = rprofrep:get_analyzed_interval_dur()
        local max_ideal_dur = 0

        for _, total_gaps_per_queue in pairs(total_gaps_per_gpu) do
            for _, total_gaps in pairs(total_gaps_per_queue) do
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

