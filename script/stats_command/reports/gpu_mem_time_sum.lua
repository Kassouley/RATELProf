local Report = require("Report")
local report_common = require("report_common")
local statistics = require("statistics")

local function get_entry_key_tab(trace)
    return { report_common.get_copy_name(trace) }
end

function Report:get_report_name()
    return "GPU MemOps Summary (by Time)"
end

function Report:get_headers()
    return {
        "Time (%)", 
        "Total Time ("..self.timeunit..")", 
        "Count", 
        "Avg ("..self.timeunit..")", 
        "Med ("..self.timeunit..")", 
        "Min ("..self.timeunit..")", 
        "Max ("..self.timeunit..")", 
        "StdDev ("..self.timeunit..")",
        "Operation" 
    }
end

function Report:get_data()
    local gpu_traces = report_common.get_gpu_mem_traces(self)

    local entries, total_metrics = statistics.get_entries(gpu_traces, get_entry_key_tab, report_common.get_duration, self.timeunit)
    local data = statistics.get_output_summary(entries, total_metrics)
    
    table.sort(data, function(a, b)
        return tonumber(a[2]) > tonumber(b[2])
    end)
    return data
end