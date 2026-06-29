local Stats = require ("utils.Stats")
local report_helper = require ("utils.report_helper")

return function (report)
    local sizeunit = report.opt.sizeunit

    report.NAME = "GPU MemOps (by Size)"

    report.TYPE = "Summary"

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

    report.COL_IDX_NAME = 9
    report.COL_IDX_METRIC = 1

    report.LOOP_IN = { ratelprof.consts.DOMAIN_MEMORY_ID }

    report.SORT_BY = { "asc", 2 }

    report.PRE_LOOP = function(self)
        self.ctx = Stats.new()
    end

    report.FOR_EACH = function(self, event, _, gpu_key)
        local event_args = event:args()
        local fname = event:name()
        local size = event_args.size

        local key = report_helper.create_key({ fname }, { fname = fname })

        self.ctx:add_entry(key, size, gpu_key)
    end

    report.POST_LOOP = function(self)
        local ctx = self.ctx

        local data = {}
        self.total_bytes = 0

        ctx:for_each_entry(function(_, entry)

            local fname = entry.uargs.fname or ""
            if fname:sub(1, 4) == "Copy" then
                self.total_bytes = self.total_bytes + entry:compute_total_metric()
            end

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

                fname,
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