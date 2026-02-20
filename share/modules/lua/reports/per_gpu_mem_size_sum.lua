local Stats = require ("utils.Stats")
local report_helper = require ("utils.report_helper")

return function (report)
    local sizeunit = report.opt.sizeunit

    report.NAME = "Per-GPU MemOps"

    report.TYPE = "Summary (by Size)"

    report.HEADER = {
        "Total (%)", "Total ("..sizeunit..")",
        "Count",
        "Avg ("..sizeunit..")", "Med ("..sizeunit..")",
        "Min ("..sizeunit..")", "Max ("..sizeunit..")",
        "StdDev ("..sizeunit..")",
        "Operation",
    }

    report.PER_MODE = true

    report.LOOP_IN = { ratelprof.consts.DOMAIN_COPY_ID }

    report.SORT_BY = { "asc", 2 }

    report.PRE_EVENT_LOOP = function(self)
        self.ctx = Stats.new()
    end

    report.FOR_EACH = function(self, event)
        local event_args = event:args()
        local key = report_helper.create_key({ event:name() })
        self.ctx:add_entry(key, event_args.size)
    end

     report.POST_EVENT_LOOP = function(self)
        local data = {}
        local ctx = self.ctx

        ctx:for_each_entry(function(_, entry)
            table.insert(data, {
                ctx:compute_percentage(entry),
                entry:compute_total_metric(sizeunit),
                entry:compute_metric_count(),
                entry:compute_avg(sizeunit),
                entry:compute_med(sizeunit),
                entry:compute_min(sizeunit),
                entry:compute_max(sizeunit),
                entry:compute_stddev(sizeunit),

                entry.key[1],
            })
        end)

        self.ctx = nil
        self.data = data
    end
end