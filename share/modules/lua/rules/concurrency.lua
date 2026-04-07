local report_helper   = require("utils.report_helper")
local Overlapping     = require("utils.Overlapping")
local GroupByLocation = require("utils.GroupByLocation")


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
    local trunc    = report.opt.trunc
    local mangled  = report.opt.mangled
    local timeunit = report.opt.timeunit
    local pct_th   = report.opt.pct_th

    report.NAME = "Concurrency"

    report.TYPE = "Analyze"

    report.HEADER = { "GPU ID", "Kernel", "Source", "Count", "Tot. Dur (" .. timeunit .. ")", "Tot. Covered Dur (" .. timeunit .. ")", "Concurrency (%)" }

    report.LOOP_IN = { ratelprof.consts.DOMAIN_KERNEL_ID }

    report.SORT_BY = {"desc", 7}

    report.PRE_LOOP = function (self)
        self.data = {}

        self.concurrent_pct_per_gpu = {}
        self.sum_concurrency = 0
        self.ngpus = 0
    end

    report.PRE_EVENT_LOOP = function (self, rprofrep)
        self.grouped_events = GroupByLocation.new(rprofrep)
        self.concurrent_pct = 0
        self.concurrent_cnt = 0
        self.overlapping = Overlapping.new(rprofrep, { ratelprof.consts.DOMAIN_KERNEL_ID })
    end

    report.FOR_EACH = function (self, event, rprofrep)
        local kernel_dur = event:dur()
        local covered = self.overlapping:compute_overlap(event)
        local concurrency_pct = (covered / kernel_dur) * 100

        if concurrency_pct >= pct_th then
            self.concurrent_pct = self.concurrent_pct + concurrency_pct
            self.concurrent_cnt = self.concurrent_cnt + 1

            local entry = rprofrep:find_entry_point(event)
            if not entry then return end
            self.grouped_events:add(entry, event:name(), {
                total_dur         = kernel_dur,
                total_covered_dur = covered,
                pct_sum           = concurrency_pct
            })
        end
    end

    report.POST_EVENT_LOOP = function (self, _, gpu_key)
        local concurrency_per_gpu = self.concurrent_pct / self.concurrent_cnt

        for _, group in pairs(self.grouped_events.groups) do
            table.insert(self.data, {
                ratelprof.utils.label_unit_with_rank(gpu_key),
                ratelprof.utils.get_kernel_name(group.name, trunc, mangled),
                group.location_str,
                group.count,
                report_helper.get_duration(group.total_dur, timeunit),
                report_helper.get_duration(group.total_covered_dur, timeunit),
                string.format("%.2f", group.pct_sum/group.count),
            })
        end


        self.concurrent_pct_per_gpu[gpu_key] = concurrency_per_gpu
        self.ngpus = self.ngpus + 1
        self.sum_concurrency = self.sum_concurrency + concurrency_per_gpu
    end

    report.POST_LOOP = function (self, rprofrep)
        local concurrent_pct_per_gpu = self.concurrent_pct_per_gpu
        self.score = 0
        if self.ngpus > 0 then
            self.score = self.sum_concurrency / self.ngpus
        end

        if #self.data == 0 then
            self.MESSAGE = string.format(DEFAULT_NO_ADVICE_MSG, pct_th)
        else
            local msg = string.format(DEFAULT_ADVICE_MSG, pct_th)

            for gpu_key, pct in pairs(concurrent_pct_per_gpu) do
                msg = msg .. string.format(DEFAULT_PER_GPU_MSG, ratelprof.utils.label_unit_with_rank(gpu_key), pct)
            end

            self.MESSAGE = msg
        end
    end
end