local report_helper = require ("utils.report_helper")
local stats_helper  = require ("utils.stats_helper")
local statistics  = require ("utils.statistics")

local function get_entry_key_tab(trace, opt)
    return { 
        trace.args.grd[1],
        trace.args.grd[2],
        trace.args.grd[3],
        trace.args.wrg[1],
        trace.args.wrg[2],
        trace.args.wrg[3],
        trace.args.kernel_name
     }
end

local function get_metric_dur(trace, opt)
    return report_helper.get_duration(trace.dur, opt.timeunit)
end

local function get_metric_qdur(trace, opt)
    return report_helper.get_duration(trace.start - trace.args.dispatch_time, opt.timeunit)
end

return function(traces_data, report_obj, opt)
    local timeunit = opt.timeunit
    report_obj:set_name("GPU Kernel")
    report_obj:set_type("Summary")

    report_obj:set_headers({
        "Time (%)", 
        "Total Time ("..timeunit..")", 
        "Instances", 
        "Avg ("..timeunit..")", 
        "Med ("..timeunit..")", 
        "Min ("..timeunit..")", 
        "Max ("..timeunit..")", 
        "StdDev ("..timeunit..")",
        "Queue Time (%)", 
        "Total QTime ("..timeunit..")", 
        "QAvg ("..timeunit..")", 
        "QMed ("..timeunit..")", 
        "QMin ("..timeunit..")", 
        "QMax ("..timeunit..")", 
        "QStdDev ("..timeunit..")",
        "GridX", 
        "GridY", 
        "GridZ", 
        "BlockX", 
        "BlockY", 
        "BlockZ", 
        "Name" 
    })

    local gpu_traces = traces_data:get(ratelprof.consts._ENV.DOMAIN_KERNEL)


    local total_metrics_dur_time = 0
    local total_metrics_queue_time = 0
    local entries_dur_time = {}
    local entries_queue_time = {}
    for _, trace in pairs(gpu_traces) do
        total_metrics_dur_time = statistics.get_entry(
            entries_dur_time, trace, get_entry_key_tab, get_metric_dur, opt, total_metrics_dur_time)
        total_metrics_queue_time = statistics.get_entry(
            entries_queue_time, trace, get_entry_key_tab, get_metric_qdur, opt, total_metrics_queue_time)
    end
    
    local data = {}
    for key_str, entry_dur_time in pairs(entries_dur_time) do
        local entry_queue_time = entries_queue_time[key_str]
        local statistic_table_for_duration_time = stats_helper.compute_stats(entry_dur_time, total_metrics_dur_time)
        local statistic_table_for_queue_time = stats_helper.compute_stats(entry_queue_time, total_metrics_queue_time)
        
        local statistic_table = {
            statistic_table_for_duration_time[1], 
            statistic_table_for_duration_time[2],
            statistic_table_for_duration_time[3],
            statistic_table_for_duration_time[4], 
            statistic_table_for_duration_time[5],
            statistic_table_for_duration_time[6], 
            statistic_table_for_duration_time[7],
            statistic_table_for_duration_time[8],
            statistic_table_for_queue_time[1], 
            statistic_table_for_queue_time[2],
            statistic_table_for_queue_time[4], 
            statistic_table_for_queue_time[5],
            statistic_table_for_queue_time[6], 
            statistic_table_for_queue_time[7],
            statistic_table_for_queue_time[8],
            entry_dur_time.key_tab[1],
            entry_dur_time.key_tab[2],
            entry_dur_time.key_tab[3],
            entry_dur_time.key_tab[4],
            entry_dur_time.key_tab[5],
            entry_dur_time.key_tab[6],
            ratelprof.utils.get_kernel_name(entry_dur_time.key_tab[7], opt.is_trunc, opt.is_mangled)
        }

        table.insert(data, statistic_table)
    end
    
    table.sort(data, function(a, b)
        return tonumber(a[2]) > tonumber(b[2])
    end)

    report_obj:set_data(data)
end
