local Timewise = require ("utils.Timewise")
local Stats = require ("utils.Stats")
local report_helper = require ("utils.report_helper")

return function (report)
    local timeunit = report.opt.timeunit
    local domain_id = ratelprof.consts.DOMAIN_FOR_REPORT[report.report_id]

    report.NAME = "Per-PID "..ratelprof.consts._DOMAIN_NAME[domain_id]

    report.TYPE = "Summary"

    report.HEADER = {
        "Active Time (%)",
        "API Time (%)", "Tot. Time ("..timeunit..")",
        "Num Calls",
        "Avg ("..timeunit..")", "Med ("..timeunit..")",
        "Min ("..timeunit..")", "Max ("..timeunit..")",
        "StdDev ("..timeunit..")",
        "Name",
    }

    report.LOOP_IN = { domain_id }

    report.PER_MODE = true

    report.SORT_BY = { "asc", 3 }

    report.PRE_EVENT_LOOP = function(self)
        self.time_ctx = Timewise.new()
        self.ctx = Stats.new()
    end

    report.FOR_EACH = function(self, event)
        local key = report_helper.create_key({ event:name() })
        self.ctx:add_entry(key, event:dur())
        self.time_ctx:add_entry(key, event:start(), event:stop())
    end

    report.POST_EVENT_LOOP = function(self, rprofrep)
        local data = {}
        local ctx = self.ctx
        local time_ctx = self.time_ctx
        local analyzed_interval_dur = rprofrep:get_analyzed_interval_dur()

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

        self.ctx = nil
        self.time_ctx = nil
        self.data = data
    end
end