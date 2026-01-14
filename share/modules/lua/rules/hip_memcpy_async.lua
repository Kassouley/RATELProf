local report_helper = require ("utils.report_helper")
local GroupByLocation = require("utils.GroupByLocation")

local function is_synchronized(gpu_event, cpu_event)
    return gpu_event:start() > cpu_event:start() and  gpu_event:stop() < cpu_event:stop()
end

local function find_sync_hipmemcpy(rprofrep, opt)
    local sizeunit = opt.sizeunit
    local timeunit = opt.timeunit
    local gpus     = opt.gpus

    local grouped_copies_by_loc = GroupByLocation.new(rprofrep)
    local nb_copy  = 0
    local nb_sync_copy = 0

    rprofrep:for_each_gpu(function(_)
        rprofrep:for_each_event({ratelprof.consts.DOMAIN_COPY_ID}, function(gpu_event)
            local cpu_event = rprofrep:find_entry_point(gpu_event)
            if cpu_event and cpu_event:domain() == ratelprof.consts.DOMAIN_HIP_ID then
                local api_name = cpu_event:name()
                nb_copy = nb_copy + 1
                if api_name:match("^hipMemcpy[%w_]*Async$") and is_synchronized(gpu_event, cpu_event) then
                    nb_sync_copy = nb_sync_copy + 1

                    grouped_copies_by_loc:add(cpu_event, gpu_event:name(), {
                        total_size    = gpu_event:args().size,
                        total_gpu_dur = gpu_event:dur(),
                        total_cpu_dur = cpu_event:dur(),
                    })
                end
            end
        end)
    end, gpus)

    local data = {}
    local max_useless_time = 0
    for _, grouped_by_loc_event in pairs(grouped_copies_by_loc.groups) do

        local total_cpu_dur = grouped_by_loc_event.total_cpu_dur
        local total_gpu_dur = grouped_by_loc_event.total_gpu_dur
        local useless_sync_time = total_cpu_dur - total_gpu_dur

        max_useless_time = math.max(max_useless_time, useless_sync_time)
        table.insert(data, {
            grouped_by_loc_event.entry_name,
            grouped_by_loc_event.name,
            grouped_by_loc_event.location_str,
            grouped_by_loc_event.count,
            report_helper.get_size(grouped_by_loc_event.total_size, sizeunit),
            report_helper.get_duration(total_cpu_dur, timeunit),
            report_helper.get_duration(total_gpu_dur, timeunit),
            report_helper.get_duration(useless_sync_time, timeunit),
        })
    end

    local actual_dur = rprofrep:get_application_time()
    local ideal_dur = actual_dur - max_useless_time
    local speedup_factor = actual_dur / ideal_dur
    local copy_pct = (nb_sync_copy / (nb_copy or 1)) * 100

    return data, speedup_factor, copy_pct
end

local DEFAULT_ADVICE_MSG = [[
The following memory transfers are synchronized with their corresponding HIP asynchronous memory copy trace.
It appears that the transferred memory is either using PAGEABLE memory or is not large enough to be processed asynchronously.

This correspond to %.2f%% of your hipMemcpy*Async operations.

Suggestion: If applicable, use PINNED memory instead by using hipHostMalloc to allocate your host side memory.

Your application might speed up by x%.3f.
]]

local DEFAULT_NO_ADVICE_MSG = [[
There were no problems detected related to asynchronous memcpy operations.
]]

return function (report)
    local timeunit = report.opt.timeunit
    local sizeunit = report.opt.sizeunit

    report.NAME = "Host/Device Async Memcpy"

    report.TYPE = "Analyze"

    report.HEADER = { "API Name", "Operation", "Source", "Count", "Tot. Size ("..sizeunit..")", "Tot. CPU Dur ("..timeunit..")", "Tot. GPU Dur ("..timeunit..")", "Tot. Sync Dur ("..timeunit..")" }

    report.REQUIRED_DOMAIN = { ratelprof.consts.DOMAIN_HIP_ID, ratelprof.consts.DOMAIN_COPY_ID }

    report.NO_ADVICE_MSG = function(self)
        return DEFAULT_NO_ADVICE_MSG
    end

    report.ADVICE_MSG = function(self)
        return string.format(DEFAULT_ADVICE_MSG, self.copy_pct, self.speedup_factor)
    end

    report.SORT_BY = {"asc", 8}

    report.DATA = function (self, rprofrep)
        local data, speedup_factor, copy_pct = find_sync_hipmemcpy(rprofrep, self.opt)
        self.data = data
        self.speedup_factor = speedup_factor
        self.copy_pct = copy_pct
    end
end
