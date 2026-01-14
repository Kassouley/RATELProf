local Stats = require ("utils.Stats")
local report_helper = require ("utils.report_helper")

local function compute_statistics(rprofrep, opt)
    local timeunit = opt.timeunit
    local gpus     = opt.gpus

    local ctx = Stats.new()

    rprofrep:for_each_rank(function(rank)
        rprofrep:for_each_gpu(function(gpu_id)
            local gpu_key = {rank = rank, gpu_id = gpu_id}
            rprofrep:for_each_event({ ratelprof.consts.DOMAIN_COPY_ID }, function(event)
                local key = report_helper.create_key({ event:name() })
                ctx:add_entry(key, event:dur(), gpu_key)
            end)
        end, gpus)
    end)

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

    return data
end


return function (report)
    local timeunit = report.opt.timeunit

    report.NAME = "GPU MemOps"

    report.TYPE = "Summary (by Time)"

    report.HEADER = {
        "API Time (%)",
        "Total Time ("..timeunit..")",
        "Count",
        "Avg ("..timeunit..")",
        "Med ("..timeunit..")",
        "Min ("..timeunit..")",
        "Max ("..timeunit..")",
        "StdDev ("..timeunit..")",
        "Operation",
        "GPU ID (Min)",
        "GPU ID (Max)",
        "GPU ID (Min Tot. Time)",
        "GPU ID (Max Tot. Time)"
    }

    report.REQUIRED_DOMAIN = { ratelprof.consts.DOMAIN_COPY_ID }

    report.SORT_BY = { "asc", 2 }

    report.DATA = function (self, rprofrep)
        self.data = compute_statistics(rprofrep, self.opt)
    end
end