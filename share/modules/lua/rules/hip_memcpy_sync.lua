local report_helper = require ("utils.report_helper")
local GroupByLocation = require("utils.GroupByLocation")

local DEFAULT_ADVICE_MSG = [[
The following are synchronous memory transfers that block the host.

This correspond to %.2f%% of your hipMemcpy* operations.

Suggestion: Use hipMemcpy*Async() APIs instead.

Your application might speed up by x%.3f.
]]

local DEFAULT_NO_ADVICE_MSG = [[
There were no problems detected related to synchronous memcpy operations.
]]

return function (report)
    local sizeunit = report.opt.sizeunit
    local timeunit = report.opt.timeunit

    report.NAME = "Host/Device Sync Memcpy"

    report.TYPE = "Analyze"

    report.HEADER = { "API Name", "Operation", "Source", "Count", "Tot. Size ("..sizeunit..")", "Tot. CPU Dur ("..timeunit..")", "Tot. GPU Dur ("..timeunit..")", "Tot. Sync Dur ("..timeunit..")" }

    report.LOOP_IN = { ratelprof.consts.DOMAIN_MEMORY_ID }

    report.REQUIRED_DOMAIN = { ratelprof.consts.DOMAIN_HIP_ID }

    report.SORT_BY = {"asc", 8}

    report.PRE_LOOP = function (self, rprofrep)
        self.grouped_copies_by_loc = GroupByLocation.new(rprofrep)
        self.nb_copy  = 0
        self.nb_sync_copy = 0
    end

    report.FOR_EACH = function (self, event, rprofrep)
        local cpu_event = rprofrep:find_entry_point(event)
        if cpu_event and cpu_event:domain() == ratelprof.consts.DOMAIN_HIP_ID then
            local api_name = cpu_event:name()
            self.nb_copy = self.nb_copy + 1
            if api_name:match("^hipMemcpy") and not api_name:match("Async$") then
                self.nb_sync_copy = self.nb_sync_copy + 1

                self.grouped_copies_by_loc:add(cpu_event, event:name(), {
                    total_size    = event:args().size,
                    total_gpu_dur = event:dur(),
                    total_cpu_dur = cpu_event:dur(),
                })
            end
        end
    end

    report.POST_LOOP = function (self, rprofrep)
        local data = {}
        local max_useless_time = 0
        for _, grouped_by_loc_event in pairs(self.grouped_copies_by_loc.groups) do

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

        local actual_dur = rprofrep:get_analyzed_interval_dur()
        local ideal_dur = actual_dur - max_useless_time
        self.speedup_factor = actual_dur / ideal_dur
        self.copy_pct = (self.nb_sync_copy / (self.nb_copy or 1)) * 100
        self.data = data

        if #data == 0 then
            self.MESSAGE = DEFAULT_NO_ADVICE_MSG
        else
            self.MESSAGE = string.format(DEFAULT_ADVICE_MSG, self.copy_pct, self.speedup_factor)
        end
    end
end
