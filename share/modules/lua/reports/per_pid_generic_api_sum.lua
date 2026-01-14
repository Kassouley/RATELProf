local Timewise = require ("utils.Timewise")
local Stats = require ("utils.Stats")
local report_helper = require ("utils.report_helper")

local function compute_statistics(rprofrep, opt, domain_id)
    local timeunit = opt.timeunit

    local time_ctx  = Timewise.new()
    local ctx = Stats.new()

    rprofrep:for_each_event({ domain_id }, function(event)
        local key = report_helper.create_key({ event:name() })
        ctx:add_entry(key, event:dur())
        time_ctx:add_entry(key, event:start(), event:stop())
    end)

    local analyzed_interval_dur = rprofrep:get_analyzed_interval_dur()
    local data = {}

    ctx:for_each_entry(function(key, entry)
        local time_entry = time_ctx.entries[key]
        table.insert(data, {
            time_entry:compute_active_percentage(analyzed_interval_dur),

            ctx:compute_percentage(entry),
            entry:compute_total_metric(timeunit),
            entry:compute_metric_count(),
            entry:compute_avg(timeunit),
            entry:compute_med(timeunit),
            entry:compute_min(timeunit),
            entry:compute_max(timeunit),
            entry:compute_stddev(timeunit),

            entry.key[1],
        })
    end)

    return data, time_ctx:compute_active_time()
end



return function (report)
    local timeunit = report.opt.timeunit
    local domain_id = ratelprof.consts.DOMAIN_FOR_REPORT[report.report_id]

    report.NAME = "Per-PID "..ratelprof.consts._DOMAIN_NAME[domain_id]

    report.TYPE = "Summary"

    report.HEADER = {
        "Active Time (%)",

        "API Time (%)",
        "Tot. Time ("..timeunit..")",
        "Num Calls",
        "Avg ("..timeunit..")",
        "Med ("..timeunit..")",
        "Min ("..timeunit..")",
        "Max ("..timeunit..")",
        "StdDev ("..timeunit..")",

        "Name",
    }

    report.REQUIRED_DOMAIN = { domain_id }

    report.PER_PID = true

    report.SORT_BY = { "asc", 3 }

    report.DATA = function (self, rprofrep, pid_key)
        local data, active_time = compute_statistics(rprofrep, self.opt, domain_id)
        self.data = data
        self.active_time_per_gpu = self.active_time_per_gpu or {}
        self.active_time_per_gpu[pid_key] = active_time
    end
end