local Report = require("Report")
local conversion = require("conversion")
local statistics = require("statistics")

local function get_metric(trace)
    local b = conversion.num(trace.args.copy_size, "hex", "dec")
    return conversion.bytes(b, "bytes", "mb")
end

local function get_entry_key_tab(trace)
    return { report_common.get_copy_name(trace) }
end

function Report:get_report_name()
    return "GPU MemOps Summary (by Size)"
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
    local gpu_traces = report_common.get_gpu_mem_traces(self)
    
    local entries, total_metrics = statistics.get_entries(gpu_traces, get_entry_key_tab, get_metric)
    local data = statistics.get_output_summary(entries, total_metrics)
    
    table.sort(data, function(a, b)
        return tonumber(a[2]) > tonumber(b[2])
    end)
    return data
end