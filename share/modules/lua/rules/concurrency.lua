local report_helper   = require("utils.report_helper")
local Overlapping     = require("utils.Overlapping")
local GroupByLocation = require("utils.GroupByLocation")

local function compute_kernel_overlap_percentage(rprofrep, opt)
    local trunc    = opt.trunc
    local mangled  = opt.mangled
    local timeunit = opt.timeunit
    local gpus     = opt.gpus
    local pct_th   = opt.pct_th

    local concurrent_pct_per_gpu = {}
    local grouped_events_per_gpu = {}
    local score = 0
    local ngpus = 0

    rprofrep:for_each_gpu(function(gpu_id)
        local grouped_events = GroupByLocation.new(rprofrep)
        local concurrent_pct = 0
        local concurrent_cnt = 0

        local overlapping = Overlapping.new(rprofrep, {ratelprof.consts.DOMAIN_KERNEL_ID})
        if not overlapping then return end

        rprofrep:for_each_event({ratelprof.consts.DOMAIN_KERNEL_ID}, function(event)

            local kernel_dur = event:dur()
            local covered = overlapping:compute_overlap(event)
            local concurrency_pct = (covered / kernel_dur) * 100

            if concurrency_pct >= pct_th then
                concurrent_pct = concurrent_pct + concurrency_pct
                concurrent_cnt = concurrent_cnt + 1

                local entry = rprofrep:find_entry_point(event)
                if not entry then return end
                grouped_events:add(entry, event:name(), {
                    total_dur         = kernel_dur,
                    total_covered_dur = covered,
                    pct_sum           = concurrency_pct
                })
            end
        end)

        local concurrency_per_gpu = concurrent_pct / concurrent_cnt
        grouped_events_per_gpu[gpu_id] = grouped_events
        concurrent_pct_per_gpu[gpu_id] = concurrency_per_gpu
        ngpus = ngpus + 1
        score = score + concurrency_per_gpu
    end, gpus)


    local data = {}
    
    for gpu_id, grouped_event in pairs(grouped_events_per_gpu) do
        for _, group in pairs(grouped_event.groups) do
            table.insert(data, {
                gpu_id,
                ratelprof.utils.get_kernel_name(group.name, trunc, mangled),
                group.location_str,
                group.count,
                report_helper.get_duration(group.total_dur, timeunit),
                report_helper.get_duration(group.total_covered_dur, timeunit),
                string.format("%.2f", group.pct_sum/group.count),
            })
        end
    end

    return data, concurrent_pct_per_gpu, score/ngpus/100
end



local DEFAULT_NO_ADVICE_MSG = [[
None of your kernels have a concurrency percentage above %d%%.
Concurrency can improve performance if well done.
]]

local DEFAULT_ADVICE_MSG = [[
The following kernels are running concurrently with others.
A kernel is considered concurrent if the percentage of its execution time that overlaps with other kernels exceeds %d%%.
]]

local DEFAULT_PER_GPU_MSG = [[
    On GPU ID %s: an average of %.2f%% of kernel time overlaps with other kernels.
]]

return function(report)
    local timeunit = report.opt.timeunit

    report.NAME = "Concurrency"

    report.TYPE = "Analyze"

    report.HEADER = { "GPU ID", "Kernel", "Source", "Count", "Tot. Dur (" .. timeunit .. ")", "Tot. Covered Dur (" .. timeunit .. ")", "Concurrency (%)" }

    report.REQUIRED_DOMAIN = { ratelprof.consts.DOMAIN_KERNEL_ID }

    report.NO_ADVICE_MSG = function(self)
        return string.format(DEFAULT_NO_ADVICE_MSG, self.opt.pct_th)
    end

    report.ADVICE_MSG = function(self)
        local msg = string.format(DEFAULT_ADVICE_MSG, self.opt.pct_th)
        for gpu_id, percent in pairs(self.percentage_per_gpu) do
            msg = msg .. string.format(DEFAULT_PER_GPU_MSG, gpu_id, percent)
        end
        return msg
    end

    report.SORT_BY = {"desc", 7}

    report.DATA = function (self, rprofrep)
        local opt = self.opt
        local data, percentage_per_gpu, score = compute_kernel_overlap_percentage(rprofrep, opt)
        self.data = data
        self.percentage_per_gpu = percentage_per_gpu
        self.score = score
    end
end
