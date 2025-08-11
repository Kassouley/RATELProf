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

return function(traces_data, _, opt)
    local timeunit = opt.timeunit

    local HEADER = {
        "Active Time (%)", -- 1
        "API Time (%)", -- 2
        "Total Time ("..timeunit..")", -- 3
        "Instances",  -- 4
        "Avg ("..timeunit..")", -- 5
        "Med ("..timeunit..")", -- 6
        "Min ("..timeunit..")", -- 7
        "Max ("..timeunit..")",  --8
        "StdDev ("..timeunit..")", -- 9
        "Active QTime (%)", -- 1
        "API QTime (%)", -- 2
        "Total QTime ("..timeunit..")", -- 3
        "QAvg ("..timeunit..")", -- 5
        "QMed ("..timeunit..")", -- 6
        "QMin ("..timeunit..")", -- 7
        "QMax ("..timeunit..")", -- 8
        "QStdDev ("..timeunit..")", -- 9
        "GridX", 
        "GridY", 
        "GridZ", 
        "BlockX", 
        "BlockY", 
        "BlockZ", 
        "Name" 
    }

    local gpu_traces = traces_data:get(ratelprof.consts._ENV.DOMAIN_KERNEL)


    local total_metrics_dur_time = 0
    local total_metrics_queue_time = 0
    local entries_dur_time = {}
    local entries_queue_time = {}
    for _, trace in pairs(gpu_traces) do
        total_metrics_dur_time = statistics.get_entry(
            entries_dur_time, trace, get_entry_key_tab, {"start", "stop"}, opt, total_metrics_dur_time)
        total_metrics_queue_time = statistics.get_entry(
            entries_queue_time, trace, get_entry_key_tab, {"args.dispatch_time", "start"}, opt, total_metrics_queue_time)
    end
    
    local analyzed_interval_dur = traces_data:get_analyzed_interval_dur()
    local data = {}
    for key_str, entry_dur_time in pairs(entries_dur_time) do
        local entry_queue_time = entries_queue_time[key_str]
        local statistic_table_for_duration_time = stats_helper.compute_stats(entry_dur_time, total_metrics_dur_time, analyzed_interval_dur)
        local statistic_table_for_queue_time = stats_helper.compute_stats(entry_queue_time, total_metrics_queue_time, analyzed_interval_dur)
        
        local statistic_table = {
            statistic_table_for_duration_time[1], 
            statistic_table_for_duration_time[2],
            statistic_table_for_duration_time[3],
            statistic_table_for_duration_time[4], 
            statistic_table_for_duration_time[5],
            statistic_table_for_duration_time[6], 
            statistic_table_for_duration_time[7],
            statistic_table_for_duration_time[8],
            statistic_table_for_duration_time[9],
            statistic_table_for_queue_time[1], 
            statistic_table_for_queue_time[2],
            statistic_table_for_queue_time[3],
            statistic_table_for_queue_time[5],
            statistic_table_for_queue_time[6], 
            statistic_table_for_queue_time[7],
            statistic_table_for_queue_time[8],
            statistic_table_for_queue_time[9],
            entry_dur_time.key_tab[1],
            entry_dur_time.key_tab[2],
            entry_dur_time.key_tab[3],
            entry_dur_time.key_tab[4],
            entry_dur_time.key_tab[5],
            entry_dur_time.key_tab[6],
            ratelprof.utils.get_kernel_name(entry_dur_time.key_tab[7], opt.trunc, opt.mangled)
        }

        table.insert(data, statistic_table)
    end
    
    table.sort(data, function(a, b)
        return tonumber(a[2]) > tonumber(b[2])
    end)

    return {
        NAME = "GPU Kernel",
        TYPE = "Summary",
        DATA = data,
        HEADER = HEADER,
        total_time = total_metrics_dur_time,
        total_queue_time = total_metrics_queue_time,
    }
end
