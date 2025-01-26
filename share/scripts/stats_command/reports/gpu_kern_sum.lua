local Report = require("Report")
local report_common = require("report_common")
local statistics = require("statistics")
local common = require("common")

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

function Report:get_report_name()
    return "GPU Kernel Summary"
end

function Report:get_headers()
    return {
        "Time (%)", 
        "Total Time ("..self.timeunit..")", 
        "Instances", 
        "Avg ("..self.timeunit..")", 
        "Med ("..self.timeunit..")", 
        "Min ("..self.timeunit..")", 
        "Max ("..self.timeunit..")", 
        "StdDev ("..self.timeunit..")",
        "Queue Time (%)", 
        "Total QTime ("..self.timeunit..")", 
        "QAvg ("..self.timeunit..")", 
        "QMed ("..self.timeunit..")", 
        "QMin ("..self.timeunit..")", 
        "QMax ("..self.timeunit..")", 
        "QStdDev ("..self.timeunit..")",
        "GridX", 
        "GridY", 
        "GridZ", 
        "BlockX", 
        "BlockY", 
        "BlockZ", 
        "Name" 
    }
end

function Report:get_data()
    local gpu_traces = report_common.get_gpu_kern_traces(self)
    local entries_dur_time, total_metrics_dur_time = statistics.get_entries(gpu_traces, get_entry_key_tab, report_common.get_duration, self.timeunit)
    local entries_queue_time, total_metrics_queue_time = statistics.get_entries(gpu_traces, get_entry_key_tab, report_common.get_queue_time, self.timeunit)
    local data = {}

    for key_str, entry_dur_time in pairs(entries_dur_time) do
        local entry_queue_time = entries_queue_time[key_str]
        local statistic_table_for_duration_time = statistics.compute_stats(entry_dur_time, total_metrics_dur_time)
        local statistic_table_for_queue_time = statistics.compute_stats(entry_queue_time, total_metrics_queue_time)
        
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
    return data
end