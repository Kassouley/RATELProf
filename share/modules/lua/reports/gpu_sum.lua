local Stats = require ("utils.Stats")
local report_helper = require ("utils.report_helper")

local function compute_statistics(rprofrep, opt)
    local timeunit = opt.timeunit
    local trunc    = opt.trunc
    local mangled  = opt.mangled
    local gpus     = opt.gpus

    local ctx = Stats.new()

    rprofrep:for_each_rank(function(rank)
        rprofrep:for_each_gpu(function(gpu_id)
            local gpu_key = {rank = rank, gpu_id = gpu_id}
            rprofrep:for_each_event({
                    ratelprof.consts.DOMAIN_COPY_ID,
                    ratelprof.consts.DOMAIN_KERNEL_ID,
                    ratelprof.consts.DOMAIN_BARRIERAND_ID,
                    ratelprof.consts.DOMAIN_BARRIEROR_ID },
            function(event)
                local key = report_helper.create_key({ event:name(), event:domain() })
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

        local name = entry.key[1]
        local domain_id = entry.key[2]
        local categorie = ratelprof.consts._DOMAIN_NAME[domain_id]
        if domain_id == ratelprof.consts.DOMAIN_KERNEL_ID then
            name = ratelprof.utils.get_kernel_name(name, trunc, mangled)
        end

        table.insert(data, {
            ctx:compute_percentage(entry),
            entry:compute_total_metric(timeunit),
            entry:compute_metric_count(),
            entry:compute_avg(timeunit),
            entry:compute_med(timeunit),
            entry:compute_min(timeunit),
            entry:compute_max(timeunit),
            entry:compute_stddev(timeunit),

            categorie,
            name,

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

    report.NAME = "GPU"

    report.TYPE = "Summary"

    report.HEADER = {
        "API Time (%)",
        "Tot. Time ("..timeunit..")",
        "Instances",
        "Avg ("..timeunit..")",
        "Med ("..timeunit..")",
        "Min ("..timeunit..")",
        "Max ("..timeunit..")",
        "StdDev ("..timeunit..")",
        "Category",
        "Operation",
        "GPU ID (Min)",
        "GPU ID (Max)",
        "GPU ID (Min Tot. Time)",
        "GPU ID (Max Tot. Time)"
    }

    report.REQUIRED_DOMAIN = { ratelprof.consts.DOMAIN_KERNEL_ID }

    report.DATA = function (self, rprofrep)
        self.data = compute_statistics(rprofrep, self.opt)
        table.sort(self.data, function(a, b) return a[2] > b[2] end)
        self.longest_activity = self.data[1]
    end
end