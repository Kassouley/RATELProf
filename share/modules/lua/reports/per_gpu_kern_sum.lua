local Timewise = require ("utils.Timewise")
local Stats = require ("utils.Stats")
local report_helper = require ("utils.report_helper")

return function (report)
    local timeunit = report.opt.timeunit
    local trunc    = report.opt.trunc
    local mangled  = report.opt.mangled

    report.NAME = "Per-GPU Kernel"

    report.TYPE = "Summary"

    report.LINK_TO = "gpu_kern_sum"

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
    
    report.COL_IDX_NAME = 24
    report.COL_IDX_METRIC = 2

    report.PER_MODE = true

    report.LOOP_IN = { ratelprof.consts.DOMAIN_KERNEL_ID }

    report.SORT_BY = { "asc", 3 }

    report.PRE_EVENT_LOOP = function(self)
        self.time_ctx  = Timewise.new()
        self.qtime_ctx = Timewise.new()
        self.dur_ctx   = Stats.new()
        self.qdur_ctx  = Stats.new()
    end

    report.FOR_EACH = function(self, event)
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

        self.time_ctx:add_entry(key, start, stop)
        self.qtime_ctx:add_entry(key, dispatch, start)
        self.qdur_ctx:add_entry(key, qelapsed)
        self.dur_ctx:add_entry(key, elapsed)
    end

    report.POST_EVENT_LOOP = function(self, rprofrep)
        local analyzed_interval_dur = rprofrep:get_analyzed_interval_dur()

        local data = {}
        
        local time_ctx  = self.time_ctx
        local qtime_ctx = self.qtime_ctx
        local dur_ctx   = self.dur_ctx
        local qdur_ctx  = self.qdur_ctx

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

        self.data = data
    end

end

