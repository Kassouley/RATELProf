local report_helper = require ("utils.report_helper")
local Overlapping = require("utils.Overlapping")
local GroupByLocation = require("utils.GroupByLocation")

local DEFAULT_NO_ADVICE_MSG = [[
All memory transfers were sufficiently overlapped by kernel execution. No visible latency (>%d%%) due to memory transfers was detected.
]]

local DEFAULT_ADVICE_MSG = [[
The following memory transfers have less than %d%% of their latency hidden by concurrent kernel execution.
Improving concurrency between memory transfers and kernels can help reduce total runtime and increase GPU utilization.
Note : 
  - Only memory transfers longer than %d ns are analyzed.
  - Not every memory transfers can be hidden.
  - Memory transfers can also be hidden with other tasks, such as CPU computations, not just kernel concurrency.

W/O concurency :
  +-------------+----------------+-------------+
  | Memcpy(H2D) |     Kernel     | Memcpy(D2H) |
  +-------------+----------------+-------------+
-------------------------------------------------> Time

With 2-way concurency :                        |
  +-------------+----+----+                    |
  | Memcpy(H2D) | K1 |DH1 |                    |
  +-------------+----+----+----+               |
                     | K2 |DH2 |               |
                     +----+----+----+ Speed up |
                          | K3 |DH3 | <------> |
                          +----+----+
-------------------------------------------------> Time

With 3-way concurency :                        |
  +----+----+----+                             |
  |HD1 | K1 |DH1 |                             |
  +----+----+----+----+                        |
       |HD2 | K2 |DH2 |                        |
       +----+----+----+----+     Speed up      |
            |HD3 | K3 |DH3 | <---------------> | 
            +----+----+----+
-------------------------------------------------> Time
 
Perfectly hide all memory transfers might speed up your GPU usage by x%.3f.
]]

local DEFAULT_PER_GPU_MSG = [[
    On GPU ID %s: an average of %.2f%% of memory transfer time is not hidden by kernel execution.
]]

return function(report)
    local timeunit = report.opt.timeunit
    local sizeunit = report.opt.sizeunit
    local HIDDEN_THRESHOLD_PCT = report.opt.th_hidden
    local TIME_THRESHOLD = report.opt.th_dur

    report.NAME = "Hidden transfers latency"

    report.TYPE = "Analyze"

    report.HEADER = { "Entry Point", "Operation", "Source", "Count", "Tot. Dur (" .. timeunit .. ")", "Tot. Covered Dur (" .. timeunit .. ")", "Avg Hidden (%)", "Tot. Size (" .. sizeunit .. ")" }

    report.LOOP_IN = { ratelprof.consts.DOMAIN_COPY_ID }

    report.REQUIRED_DOMAIN = { ratelprof.consts.DOMAIN_KERNEL_ID }

    report.SORT_BY = {"desc", 7}

    report.PRE_LOOP = function (self, rprofrep)

        self.grouped_event = GroupByLocation.new(rprofrep)

        self.total_percentage_per_gpu = {}
        self.max_not_hidden_copy_per_gpu = {}
        self.score = 0
        self.ngpus = 0
    end

    report.PRE_EVENT_LOOP = function (self, rprofrep)
        self.overlapped_total_time = 0
        self.overall_total_time = 0
        self.not_hidden_copy_dur_per_sdma = {}

        self.overlapping = Overlapping.new(rprofrep, { ratelprof.consts.DOMAIN_KERNEL_ID })
    end

    report.FOR_EACH = function (self, event, rprofrep)
        local copy_dur = event:dur()

        if copy_dur < TIME_THRESHOLD then return end

        local covered = self.overlapping:compute_overlap(event)
        local hidden_percentage = (covered / copy_dur) * 100

        if hidden_percentage < HIDDEN_THRESHOLD_PCT then
            self.overall_total_time    = self.overall_total_time + copy_dur
            self.overlapped_total_time = self.overlapped_total_time + covered

            local sdma = event:sdma_id()
            self.not_hidden_copy_dur_per_sdma[sdma] = (self.not_hidden_copy_dur_per_sdma[sdma] or 0) + copy_dur - covered

            local entry = rprofrep:find_entry_point(event)
            if not entry then return end
            self.grouped_event:add(entry, event:name(), {
                total_size        = event:args().size,
                total_dur         = copy_dur,
                total_covered_dur = covered,
                pct_sum           = hidden_percentage
            })
        end
    end

    report.POST_EVENT_LOOP = function (self, _, gpu_key)
        self.total_percentage_per_gpu[gpu_key] = 100 - (self.overlapped_total_time / self.overall_total_time) * 100
        self.max_not_hidden_copy_per_gpu[gpu_key] = table.max(self.not_hidden_copy_dur_per_sdma)
        self.ngpus = self.ngpus + 1
        if self.overall_total_time > 0 then
            self.score = self.score + self.overlapped_total_time/(self.overall_total_time)
        end
    end


    report.POST_LOOP = function (self, rprofrep)
        local grouped_event = self.grouped_event
        local total_percentage_per_gpu = self.total_percentage_per_gpu
        local max_ideal_hidden_dur, _ = table.max(self.max_not_hidden_copy_per_gpu)

        local actual_dur = rprofrep:get_analyzed_interval_dur()
        local ideal_dur = actual_dur - (max_ideal_hidden_dur or 0)

        self.speedup_factor = actual_dur / ideal_dur

        if self.ngpus > 0 then
            self.score = self.score / self.ngpus
        end

        local data = {}
        for _, group in pairs(grouped_event.groups) do
            table.insert(data, {
                group.entry_name,
                group.name,
                group.location_str,
                group.count,
                report_helper.get_duration(group.total_dur, timeunit),
                report_helper.get_duration(group.total_covered_dur, timeunit),
                group.pct_sum / group.count,
                report_helper.get_size(group.total_size, sizeunit),
            })
        end
        self.data = data

        if #data == 0 then
            self.MESSAGE = string.format(DEFAULT_NO_ADVICE_MSG, HIDDEN_THRESHOLD_PCT)
        else
            local msg = string.format(DEFAULT_ADVICE_MSG, HIDDEN_THRESHOLD_PCT, TIME_THRESHOLD, self.speedup_factor)

            for gpu_key, pct in pairs(total_percentage_per_gpu) do
                msg = msg .. string.format(DEFAULT_PER_GPU_MSG, ratelprof.utils.label_unit_with_rank(gpu_key), pct)
            end

            self.MESSAGE = msg
        end
    end
end