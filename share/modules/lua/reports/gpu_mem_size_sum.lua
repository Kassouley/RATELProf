local Stats = require ("utils.Stats")
local report_helper = require ("utils.report_helper")

return function (report)
    local sizeunit = report.opt.sizeunit

    report.NAME = "GPU MemOps"

    report.TYPE = "Summary (by Size)"

    report.HEADER = {
        "Total (%)", "Total ("..sizeunit..")",
        "Count",
        "Avg ("..sizeunit..")", "Med ("..sizeunit..")",
        "Min ("..sizeunit..")", "Max ("..sizeunit..")",
        "StdDev ("..sizeunit..")",
        "Operation",
        "GPU ID (Min)", "GPU ID (Max)",
        "GPU ID (Min Tot. Time)", "GPU ID (Max Tot. Time)"
    }

    report.LOOP_IN = { ratelprof.consts.DOMAIN_COPY_ID }

    report.SORT_BY = { "asc", 2 }

    report.PRE_LOOP = function(self)
        self.ctx = Stats.new()
    end

    report.FOR_EACH = function(self, event, _, gpu_key)
        local event_args = event:args()
        local size   = event_args.size

        local key = report_helper.create_key({ event:name() })

        self.ctx:add_entry(key, size, gpu_key)
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
                entry:compute_total_metric(sizeunit),
                entry:compute_metric_count(),
                entry:compute_avg(sizeunit),
                entry:compute_med(sizeunit),
                entry:compute_min(sizeunit),
                entry:compute_max(sizeunit),
                entry:compute_stddev(sizeunit),

                entry.key[1],
                ratelprof.utils.label_unit_with_rank(gpu_id_for_min),
                ratelprof.utils.label_unit_with_rank(gpu_id_for_max),
                ratelprof.utils.label_unit_with_rank(gpu_id_for_total_min),
                ratelprof.utils.label_unit_with_rank(gpu_id_for_total_max)
            })
        end)

        self.data = data
        self.total_bytes = ctx.total_metric
        self.ctx = nil
    end
end