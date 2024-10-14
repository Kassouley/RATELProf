local Report = require("Report")
local report_common = require("report_common")
local statistics = require("statistics")

function Report:get_report_name()
    return "GPU MemOps Summary (by Size)"
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
    local gpu_traces = self:get_gpu_mem_traces()

    local key_tab = {report_common.key.name}

    local data = statistics.get_output_summary(gpu_traces, key_tab, report_common.get_duration, self.timeunit)
    
    table.sort(data, function(a, b)
        return tonumber(a[2]) > tonumber(b[2])
    end)
    return data
end