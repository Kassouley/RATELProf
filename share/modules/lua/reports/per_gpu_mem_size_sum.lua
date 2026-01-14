local Stats = require ("utils.Stats")
local report_helper = require ("utils.report_helper")

local function compute_statistics(rprofrep, opt)
    local sizeunit = opt.sizeunit

    local ctx = Stats.new()

    rprofrep:for_each_event({ ratelprof.consts.DOMAIN_COPY_ID }, function(event)
        local event_args = event:args()
        local size   = event_args.size
        local key = report_helper.create_key({ event:name() })
        ctx:add_entry(key, size)
    end)

    local data = {}

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

    return data, ctx.total_metric
end


return function (report)
    local sizeunit = report.opt.sizeunit

    report.NAME = "Per-GPU MemOps"

    report.TYPE = "Summary (by Size)"

    report.HEADER = {
        "Total (%)",
        "Total ("..sizeunit..")",
        "Count",
        "Avg ("..sizeunit..")",
        "Med ("..sizeunit..")",
        "Min ("..sizeunit..")",
        "Max ("..sizeunit..")",
        "StdDev ("..sizeunit..")",
        "Operation",
    }

    report.PER_GPU = true

    report.REQUIRED_DOMAIN = { ratelprof.consts.DOMAIN_COPY_ID }

    report.SORT_BY = { "asc", 2 }

    report.DATA = function (self, rprofrep, gpu_key)
        local data, total_transfered_bytes = compute_statistics(rprofrep, self.opt)
        self.data = data
        self.total_transfered_bytes_per_gpu  = self.total_transfered_bytes_per_gpu or {}
        self.total_transfered_bytes_per_gpu[gpu_key] = total_transfered_bytes
    end
end