local Stats = require ("utils.Stats")
local report_helper = require ("utils.report_helper")

return function (report)
    local timeunit = report.opt.timeunit
    local trunc    = report.opt.trunc
    local mangled  = report.opt.mangled

    report.NAME = "GPU"

    report.TYPE = "Summary"

    report.HEADER = {
        "API Time (%)", "Tot. Time ("..timeunit..")",
        "Instances",
        "Avg ("..timeunit..")", "Med ("..timeunit..")",
        "Min ("..timeunit..")", "Max ("..timeunit..")",
        "StdDev ("..timeunit..")",
        "Category", "Operation",
        "GPU ID (Min)", "GPU ID (Max)",
        "GPU ID (Min Tot. Time)", "GPU ID (Max Tot. Time)"
    }
    
    report.COL_IDX_NAME = 10
    report.COL_IDX_METRIC = 1

    report.LOOP_IN = {
        ratelprof.consts.DOMAIN_KERNEL_ID, ratelprof.consts.DOMAIN_MEMORY_ID,
        ratelprof.consts.DOMAIN_BARRIERAND_ID, ratelprof.consts.DOMAIN_BARRIEROR_ID
    }

    report.OR_REQUIRED_MODE = true

    report.PRE_LOOP = function(self)
        self.ctx = Stats.new()
    end

    report.FOR_EACH = function(self, event, _, gpu_key)
        local key = report_helper.create_key({ event:ufunid() }, { fname = event:name(), domain = event:domain() })
        self.ctx:add_entry(key, event:dur(), gpu_key)
    end

    report.POST_LOOP = function(self, rprofrep)
        local data = {}
        local ctx = self.ctx

        ctx:for_each_entry(function(_, entry)

            local gpu_id_for_min = entry:get_min_subkey()
            local gpu_id_for_max = entry:get_max_subkey()
            local gpu_id_for_total_min = entry:get_min_total_subkey()
            local gpu_id_for_total_max = entry:get_max_total_subkey()

            local name = entry.uargs.fname
            local domain_id = entry.uargs.domain
            local category = ratelprof.consts._DOMAIN_NAME[domain_id]
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

                category,
                name,

                ratelprof.utils.label_unit_with_rank(gpu_id_for_min),
                ratelprof.utils.label_unit_with_rank(gpu_id_for_max),
                ratelprof.utils.label_unit_with_rank(gpu_id_for_total_min),
                ratelprof.utils.label_unit_with_rank(gpu_id_for_total_max)
            })
        end)

        table.sort(data, function (a, b) return tonumber(a[2]) > tonumber(b[2]) end)

        self.ctx = nil
        self.data = data
        self.longest_activity = data and data[1] and data[1][10]
    end
end