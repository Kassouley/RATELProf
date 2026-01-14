local report_helper = require("utils.report_helper")

local function find_coalescable_kernels(rprofrep, opt)
    local timeunit = opt.timeunit
    local trunc    = opt.trunc
    local mangled  = opt.mangled
    local gpus     = opt.gpus
    
    local DURATION_THRESHOLD_NS = opt.th_dur
    local GAP_THRESHOLD_NS      = opt.th_gap
    local MIN_SEQUENCE_LEN      = opt.min_seq

    local data = {}
    local sequences_per_gpu = {}
    local total_gaps_per_gpu = {}

    local function on_sequence_end(sequence, gpu_id, queue_id, name)
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
                tostring(gpu_id),
                tostring(queue_id),
                #sequence,
                report_helper.get_duration(sequence_start, timeunit),
                report_helper.get_duration(sequence_dur, timeunit),
                report_helper.get_duration(total_gap, timeunit),
                tonumber(string.format("%.2f", speedup_factor)),
                ratelprof.utils.get_kernel_name(name, trunc, mangled),
            })

            sequences_per_gpu[gpu_id] = (sequences_per_gpu[gpu_id] or 0) + 1
            
            total_gaps_per_gpu[gpu_id] = total_gaps_per_gpu[gpu_id] or {}
            total_gaps_per_gpu[gpu_id][queue_id] = (total_gaps_per_gpu[gpu_id][queue_id] or 0) + total_gap

        end
    end

    rprofrep:for_each_gpu(function(gpu_id)
        rprofrep:for_each_queue(function(queue_id)
            local sequence = {}
            local curr_last = nil

            rprofrep:for_each_event({ ratelprof.consts.DOMAIN_KERNEL_ID }, function(event)
                if event:dur() > DURATION_THRESHOLD_NS then
                    -- Skip large kernels
                    if curr_last then
                        on_sequence_end(sequence, gpu_id, queue_id, curr_last:name())
                    end
                    sequence = {}
                    curr_last = nil
                elseif not curr_last or (event:name() == curr_last:name()
                        and event:start() - curr_last:stop() < GAP_THRESHOLD_NS) then
                    -- Add to sequence
                    table.insert(sequence, event)
                    curr_last = event
                else
                    -- Check and reset
                    on_sequence_end(sequence, gpu_id, queue_id, curr_last:name())
                    sequence = {event}
                    curr_last = event
                end

            end)

            if curr_last then
                on_sequence_end(sequence, gpu_id, queue_id, curr_last:name())
            end
        end)
    end, gpus)


    local speedup_factor = 1
    local actual_dur = rprofrep:get_application_time()
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

    return data, sequences_per_gpu, speedup_factor
end



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

    report.NAME = "Coalescable Kernel Launches"

    report.TYPE = "Analyze"

    report.HEADER = { "GPU ID", "Queue ID", "Seq. Length", "Seq. Start (" .. timeunit .. ")", "Seq. Dur (" .. timeunit .. ")", "Seq. Gap Dur (" .. timeunit .. ")", "Seq. Speed Up", "Kernel Name" }

    report.REQUIRED_DOMAIN = { ratelprof.consts.DOMAIN_KERNEL_ID }

    report.NO_ADVICE_MSG = function(self)
        return DEFAULT_NO_ADVICE_MSG
    end

    report.ADVICE_MSG = function(self)
        local opt = self.opt
        local msg = string.format(DEFAULT_ADVICE_MSG, opt.th_gap, opt.th_dur, opt.min_seq, self.speedup_factor)
        for gpu_id, count in pairs(self.sequences_per_gpu) do
            msg = msg .. string.format(DEFAULT_PER_GPU_MSG, gpu_id, count)
        end
        return msg
    end

    report.SORT_BY = {"asc", 6}

    report.DATA = function (self, rprofrep)
        local data, sequences_per_gpu, speedup_factor = find_coalescable_kernels(rprofrep, self.opt)
        self.data = data
        self.sequences_per_gpu = sequences_per_gpu
        self.speedup_factor = speedup_factor
    end
end

