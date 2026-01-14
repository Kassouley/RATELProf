local Timewise = require ("utils.Timewise")
local Stats = require ("utils.Stats")
local report_helper = require ("utils.report_helper")

local function compute_statistics(rprofrep, opt)
    local timeunit = opt.timeunit
    local trunc    = opt.trunc
    local mangled  = opt.mangled

    local time_ctx  = Timewise.new()
    local ctx = Stats.new()

    rprofrep:for_each_event({
            ratelprof.consts.DOMAIN_COPY_ID,
            ratelprof.consts.DOMAIN_KERNEL_ID,
            ratelprof.consts.DOMAIN_BARRIERAND_ID,
            ratelprof.consts.DOMAIN_BARRIEROR_ID },
    function(event)
        local key = report_helper.create_key({ event:name(), event:domain() })
        ctx:add_entry(key, event:dur())
        time_ctx:add_entry(key, event:start(), event:stop())
    end)
    
    local analyzed_interval_dur = rprofrep:get_analyzed_interval_dur()

    local data = {}

    ctx:for_each_entry(function(key, entry)
        local name = entry.key[1]
        local domain_id = entry.key[2]
        local categorie = ratelprof.consts._DOMAIN_NAME[domain_id]
        if domain_id == ratelprof.consts.DOMAIN_KERNEL_ID then
            name = ratelprof.utils.get_kernel_name(name, trunc, mangled)
        end

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

            categorie,
            name,
        })
    end)

    return data, time_ctx:compute_active_time()
end


return function (report)
    local timeunit = report.opt.timeunit

    report.NAME = "Per-GPU"

    report.TYPE = "Summary"

    report.HEADER = {
        "Active Time (%)",

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
    }

    report.PER_GPU = true

    report.REQUIRED_DOMAIN = { ratelprof.consts.DOMAIN_KERNEL_ID }

    report.SORT_BY = { "asc", 3 }

    report.DATA = function (self, rprofrep, gpu_key)
        local data, active_time = compute_statistics(rprofrep, self.opt)
        self.data = data
        self.active_time_per_gpu = self.active_time_per_gpu or {}
        self.active_time_per_gpu[gpu_key]  = active_time
    end
end