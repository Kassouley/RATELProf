local Timewise = require ("utils.Timewise")
local Stats = require ("utils.Stats")
local report_helper = require ("utils.report_helper")

local function compute_statistics(rprofrep, opt)
    local trunc    = opt.trunc
    local mangled  = opt.mangled
    local timeunit = opt.timeunit

    local time_ctx  = Timewise.new()
    local qtime_ctx = Timewise.new()
    local dur_ctx  = Stats.new()
    local qdur_ctx = Stats.new()

    rprofrep:for_each_event({ ratelprof.consts.DOMAIN_KERNEL_ID }, function(event)
        local start      = event:start()
        local stop       = event:stop()
        local event_args = event:args()
        local dispatch   = event_args.dispatch_time
        local qelapsed   = start - dispatch
        local elapsed    = stop  - start

        local key = report_helper.create_key({
            event_args.grd[1],
            event_args.grd[2],
            event_args.grd[3],
            event_args.wgr[1],
            event_args.wgr[2],
            event_args.wgr[3],
            event:name()
        })

        time_ctx:add_entry(key, start, stop)
        qtime_ctx:add_entry(key, dispatch, start)
        qdur_ctx:add_entry(key, qelapsed)
        dur_ctx:add_entry(key, elapsed)
    end)

    local analyzed_interval_dur = rprofrep:get_analyzed_interval_dur()

    local data = {}

    dur_ctx:for_each_entry(function(key, dur_entry)
        local qdur_entry = qdur_ctx.entries[key]
        local time_entry = time_ctx.entries[key]
        local qtime_entry = qtime_ctx.entries[key]
        table.insert(data, {
            time_entry:compute_active_percentage(analyzed_interval_dur),

            dur_ctx:compute_percentage(dur_entry),
            dur_entry:compute_total_metric(timeunit),
            dur_entry:compute_metric_count(),
            dur_entry:compute_avg(timeunit),
            dur_entry:compute_med(timeunit),
            dur_entry:compute_min(timeunit),
            dur_entry:compute_max(timeunit),
            dur_entry:compute_stddev(timeunit),

            qtime_entry:compute_active_percentage(analyzed_interval_dur),

            qdur_ctx:compute_percentage(qdur_entry),
            qdur_entry:compute_total_metric(timeunit),
            qdur_entry:compute_avg(timeunit),
            qdur_entry:compute_med(timeunit),
            qdur_entry:compute_min(timeunit),
            qdur_entry:compute_max(timeunit),
            qdur_entry:compute_stddev(timeunit),

            dur_entry.key[1],
            dur_entry.key[2],
            dur_entry.key[3],
            dur_entry.key[4],
            dur_entry.key[5],
            dur_entry.key[6],
            ratelprof.utils.get_kernel_name(dur_entry.key[7], trunc, mangled),
        })
    end)

    return data, time_ctx:compute_active_time(), qtime_ctx:compute_active_time()
end


return function (report)
    local timeunit = report.opt.timeunit

    report.NAME = "Per-GPU Kernel"

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

        "Active QTime (%)",

        "API QTime (%)",
        "Tot. QTime ("..timeunit..")",
        "QAvg ("..timeunit..")",
        "QMed ("..timeunit..")",
        "QMin ("..timeunit..")",
        "QMax ("..timeunit..")",
        "QStdDev ("..timeunit..")",

        "GridX", "GridY", "GridZ",
        "BlockX", "BlockY", "BlockZ",
        "Name",
    }

    report.PER_GPU = true

    report.REQUIRED_DOMAIN = { ratelprof.consts.DOMAIN_KERNEL_ID }

    report.SORT_BY = { "asc", 3 }

    report.DATA = function (self, rprofrep, gpu_key)
        local data, active_time, active_qtime = compute_statistics(rprofrep, self.opt)
        self.data = data
        self.active_time_per_gpu  = self.active_time_per_gpu or {}
        self.active_qtime_per_gpu = self.active_qtime_per_gpu or {}
        self.active_time_per_gpu[gpu_key]  = active_time
        self.active_qtime_per_gpu[gpu_key] = active_qtime
    end
end

