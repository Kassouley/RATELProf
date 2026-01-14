local Stats = require ("utils.Stats")
local report_helper = require ("utils.report_helper")

local function compute_statistics(rprofrep, opt, domain_id)
    local timeunit = opt.timeunit
    local pids = opt.pids

    local ctx = Stats.new()

    rprofrep:for_each_rank(function(rank)
        rprofrep:for_each_pid(function(pid)
            local pid_key = {rank = rank, pid = pid}
            rprofrep:for_each_event({ domain_id }, function(event)
                local key = report_helper.create_key({ event:name() })
                ctx:add_entry(key, event:dur(), pid_key)
            end)
        end, pids)
    end)

    local data = {}

    ctx:for_each_entry(function(_, entry)

        local pid_for_min = entry:get_min_subkey()
        local pid_for_max = entry:get_max_subkey()
        local pid_for_total_min = entry:get_min_total_subkey()
        local pid_for_total_max = entry:get_max_total_subkey()

        table.insert(data, {
            ctx:compute_percentage(entry),
            entry:compute_total_metric(timeunit),
            entry:compute_metric_count(),
            entry:compute_avg(timeunit),
            entry:compute_med(timeunit),
            entry:compute_min(timeunit),
            entry:compute_max(timeunit),
            entry:compute_stddev(timeunit),

            entry.key[1],

            ratelprof.utils.label_unit_with_rank(pid_for_min),
            ratelprof.utils.label_unit_with_rank(pid_for_max),
            ratelprof.utils.label_unit_with_rank(pid_for_total_min),
            ratelprof.utils.label_unit_with_rank(pid_for_total_max)
        })
    end)

    return data
end

return function (report)
    local timeunit = report.opt.timeunit
    local domain_id = ratelprof.consts.DOMAIN_FOR_REPORT[report.report_id]

    report.NAME = ratelprof.consts._DOMAIN_NAME[domain_id]

    report.TYPE = "Summary"

    report.HEADER = {
        "API Time (%)",
        "Tot. Time ("..timeunit..")",
        "Num Calls",
        "Avg ("..timeunit..")",
        "Med ("..timeunit..")",
        "Min ("..timeunit..")",
        "Max ("..timeunit..")",
        "StdDev ("..timeunit..")",
        "Name",
        "PID (Min)",
        "PID (Max)",
        "PID (Min Tot. Time)",
        "PID (Max Tot. Time)"
    }

    report.REQUIRED_DOMAIN = { domain_id }

    report.SORT_BY = { "asc", 2 }

    report.DATA = function (self, rprofrep)
        self.data = compute_statistics(rprofrep, self.opt, domain_id)
    end
end