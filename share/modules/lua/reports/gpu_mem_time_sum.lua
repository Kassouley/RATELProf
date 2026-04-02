local Stats = require ("utils.Stats")
local report_helper = require ("utils.report_helper")

return function (report)
    local timeunit = report.opt.timeunit

    report.NAME = "GPU MemOps (by Time)"

    report.TYPE = "Summary"

    report.HEADER = {
        "API Time (%)", "Total Time ("..timeunit..")",
        "Count",
        "Avg ("..timeunit..")", "Med ("..timeunit..")",
        "Min ("..timeunit..")", "Max ("..timeunit..")",
        "StdDev ("..timeunit..")",
        "Operation",
        "GPU ID (Min)", "GPU ID (Max)",
        "GPU ID (Min Tot. Time)", "GPU ID (Max Tot. Time)"
    }
    
    report.COL_IDX_NAME = 9
    report.COL_IDX_METRIC = 1

    report.LOOP_IN = { ratelprof.consts.DOMAIN_COPY_ID }

    report.SORT_BY = { "asc", 2 }

    report.PRE_LOOP = function(self)
        self.ctx = Stats.new()
    end

    report.FOR_EACH = function(self, event, _, gpu_key)
        local key = report_helper.create_key({ event:name() })
        self.ctx:add_entry(key, event:dur(), gpu_key)
    end

    report.POST_LOOP = function(self)
        local ctx = self.ctx

        local data = {}

        ctx:for_each_entry(function(_, entry)

            local gpu_id_for_min = entry:get_min_subkey()
            local gpu_id_for_max = entry:get_max_subkey()
            local gpu_id_for_total_min = entry:get_min_total_subkey()
            local gpu_id_for_total_max = entry:get_max_total_subkey()

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
                ratelprof.utils.label_unit_with_rank(gpu_id_for_min),
                ratelprof.utils.label_unit_with_rank(gpu_id_for_max),
                ratelprof.utils.label_unit_with_rank(gpu_id_for_total_min),
                ratelprof.utils.label_unit_with_rank(gpu_id_for_total_max)
            })
        end)

        self.data = data
        self.ctx = nil
    end

end