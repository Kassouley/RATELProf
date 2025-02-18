local function get_entry_key_tab(trace)
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


return function(all_traces, attribute, opt)
    local timeunit = opt.timeunit
    local headers = {
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
    }

    local gpu_traces = stats:fetch_traces(all_traces, "KERNEL_DISPATCH", opt) or {}
    

    local entries_dur_time, total_metrics_dur_time = stats:get_entries(gpu_traces, get_entry_key_tab, stats.get_duration, timeunit)
    local entries_queue_time, total_metrics_queue_time = stats:get_entries(gpu_traces, get_entry_key_tab, stats.get_queue_time, timeunit)
    
    local data = {}
    for key_str, entry_dur_time in pairs(entries_dur_time) do
        local entry_queue_time = entries_queue_time[key_str]
        local statistic_table_for_duration_time = stats:compute_stats(entry_dur_time, total_metrics_dur_time)
        local statistic_table_for_queue_time = stats:compute_stats(entry_queue_time, total_metrics_queue_time)
        
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
        }

        for i, v in ipairs(entry_dur_time.key_tab) do
            table.insert(statistic_table, v)
        end
        table.insert(data, statistic_table)
    end
    
    table.sort(data, function(a, b)
        return tonumber(a[2]) > tonumber(b[2])
    end)

    table.insert(data, 1, headers)

    attribute.report_name = "GPU Kernel Summary"
    attribute.data = data
    attribute.data_size = #data - 1
    
    Report.Report:new(attribute):generate(opt)
end
