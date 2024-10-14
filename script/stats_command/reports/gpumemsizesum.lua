local Report = require("Report")
local conversion = require("conversion")
local statistics = require("statistics")

local function get_metric(trace)
    local b = conversion.num(trace[report_common.key.copy_size], "hex", "dec")
    return conversion.bytes(b, "bytes", "mb")
end


function Report:get_report_name()
    return "GPU MemOps Summary (by Time)"
end

function Report:get_headers()
    return {
        "Total (%)", 
        "Total (MB)", 
        "Count", 
        "Avg (MB)", 
        "Med (MB)", 
        "Min (MB)", 
        "Max (MB)", 
        "StdDev (MB)",
        "Operation" 
    }
end

function Report:get_data()
    local gpu_traces = self:get_gpu_mem_traces()

    local key_tab = {report_common.key.name}

    local data = statistics.get_output_summary(gpu_traces, key_tab, get_metric)
    
    table.sort(data, function(a, b)
        return tonumber(a[2]) > tonumber(b[2])
    end)
    return data
end