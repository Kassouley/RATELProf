local report_helper = require ("utils.report_helper")
local Overlapping = require("utils.Overlapping")
local GroupByLocation = require("utils.GroupByLocation")

local function find_hidden_latency(rprofrep, opt, filter)
    local gpus = opt.gpus
    local HIDDEN_THRESHOLD_PCT = opt.th_hidden

    local grouped_event = GroupByLocation.new(rprofrep)

    local total_percentage_per_gpu = {}
    local max_not_hidden_copy_per_gpu = {}
    local score = 0
    local ngpus = 0

    rprofrep:for_each_gpu(function(gpu_id)

        local overlapped_total_time = 0
        local overall_total_time = 0
        local not_hidden_copy_dur_per_sdma = {}

        local overlapping = Overlapping.new(rprofrep, { ratelprof.consts.DOMAIN_KERNEL_ID })
        if not overlapping then return end

        rprofrep:for_each_event({ratelprof.consts.DOMAIN_COPY_ID}, function(copy_event)
            local copy_dur = copy_event:dur()
            local covered = overlapping:compute_overlap(copy_event)
            local hidden_percentage = (covered / copy_dur) * 100

            if hidden_percentage < HIDDEN_THRESHOLD_PCT then
                overall_total_time    = overall_total_time + copy_dur
                overlapped_total_time = overlapped_total_time + covered

                local sdma = copy_event:sdma_id()
                not_hidden_copy_dur_per_sdma[sdma] = (not_hidden_copy_dur_per_sdma[sdma] or 0) + copy_dur - covered

                local entry = rprofrep:find_entry_point(copy_event)
                if not entry then return end
                grouped_event:add(entry, copy_event:name(), {
                    total_size        = copy_event:args().size,
                    total_dur         = copy_dur,
                    total_covered_dur = covered,
                    pct_sum           = hidden_percentage
                })
            end
        end, filter)

        total_percentage_per_gpu[gpu_id] = 100 - (overlapped_total_time / overall_total_time) * 100
        max_not_hidden_copy_per_gpu[gpu_id] = table.max(not_hidden_copy_dur_per_sdma)
        ngpus = ngpus + 1
        score = score + overlapped_total_time/overall_total_time
    end, gpus)

    local max_ideal_hidden_dur, _ = table.max(max_not_hidden_copy_per_gpu)
    
    local actual_dur = rprofrep:get_application_time()
    local ideal_dur = actual_dur - (max_ideal_hidden_dur or 0)
    local speedup_factor = actual_dur / ideal_dur
    return grouped_event, total_percentage_per_gpu, speedup_factor, score/ngpus
end

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

    report.NAME = "Hidden transfers latency"

    report.TYPE = "Analyze"

    report.HEADER = { "Entry Point", "Operation", "Source", "Count", "Tot. Dur (" .. timeunit .. ")", "Tot. Covered Dur (" .. timeunit .. ")", "Avg Hidden (%)", "Tot. Size (" .. sizeunit .. ")" }

    report.REQUIRED_DOMAIN = { ratelprof.consts.DOMAIN_KERNEL_ID, ratelprof.consts.DOMAIN_COPY_ID }

    report.NO_ADVICE_MSG = function(self)
        return string.format(DEFAULT_NO_ADVICE_MSG, self.opt.th_hidden)
    end

    report.ADVICE_MSG = function(self)
        local msg = string.format(DEFAULT_ADVICE_MSG, self.opt.th_hidden, self.opt.th_dur, self.speedup_factor)
        for gpu_id, percent in pairs(self.percentage_per_gpu) do
            msg = msg .. string.format(DEFAULT_PER_GPU_MSG, gpu_id, percent)
        end
        return msg
    end

    report.SORT_BY = {"desc", 7}

    report.DATA = function (self, rprofrep)
        local opt = self.opt
        local TIME_THRESHOLD = opt.th_dur
        local filter = self:get_filter(TIME_THRESHOLD, "gt")
        local grouped_event, percentage_per_gpu, speedup_factor, score = find_hidden_latency(rprofrep, opt, filter)
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
        self.percentage_per_gpu = percentage_per_gpu
        self.speedup_factor = speedup_factor
        self.score = score
    end
end
