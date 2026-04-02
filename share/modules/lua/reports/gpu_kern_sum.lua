local Stats = require ("utils.Stats")
local report_helper = require ("utils.report_helper")

return function (report)
    local timeunit = report.opt.timeunit
    local trunc    = report.opt.trunc
    local mangled  = report.opt.mangled

    report.NAME = "GPU Kernel"

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
        "GPU ID (Min)",
        "GPU ID (Max)",
        "GPU ID (Min Tot. Time)",
        "GPU ID (Max Tot. Time)"
    }
    
    report.COL_IDX_NAME = 22
    report.COL_IDX_METRIC = 1

    report.LOOP_IN = { ratelprof.consts.DOMAIN_KERNEL_ID }

    report.SORT_BY = { "asc", 2 }

    report.PRE_LOOP = function(self)
        self.dur_ctx  = Stats.new()
        self.qdur_ctx = Stats.new()
    end

    report.FOR_EACH = function(self, event, _, gpu_key)
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

        self.qdur_ctx:add_entry(key, qelapsed)
        self.dur_ctx:add_entry(key, elapsed, gpu_key)
    end


    report.POST_LOOP = function(self)
        local data = {}
        local dur_ctx  = self.dur_ctx
        local qdur_ctx = self.qdur_ctx
        dur_ctx:for_each_entry(function(key, dur_entry)

            local gpu_id_for_min = dur_entry:get_min_subkey()
            local gpu_id_for_max = dur_entry:get_max_subkey()
            local gpu_id_for_total_min = dur_entry:get_min_total_subkey()
            local gpu_id_for_total_max = dur_entry:get_max_total_subkey()

            local qdur_entry = qdur_ctx.entries[key]
            table.insert(data, {
                dur_ctx:compute_percentage(dur_entry),
                dur_entry:compute_total_metric(timeunit),
                dur_entry:compute_metric_count(),
                dur_entry:compute_avg(timeunit),
                dur_entry:compute_med(timeunit),
                dur_entry:compute_min(timeunit),
                dur_entry:compute_max(timeunit),
                dur_entry:compute_stddev(timeunit),

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
                ratelprof.utils.label_unit_with_rank(gpu_id_for_min),
                ratelprof.utils.label_unit_with_rank(gpu_id_for_max),
                ratelprof.utils.label_unit_with_rank(gpu_id_for_total_min),
                ratelprof.utils.label_unit_with_rank(gpu_id_for_total_max)
            })
        end)
        self.data = data
    end
end

