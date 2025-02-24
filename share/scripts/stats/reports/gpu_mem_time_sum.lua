local function get_entry_key_tab(trace)
    return { report_common.get_copy_name(trace) }
end

return function(all_traces, attribute, opt)
    local timeunit = opt.timeunit
    local headers = {
        "Time (%)", 
        "Total Time ("..timeunit..")", 
        "Count", 
        "Avg ("..timeunit..")", 
        "Med ("..timeunit..")", 
        "Min ("..timeunit..")", 
        "Max ("..timeunit..")", 
        "StdDev ("..timeunit..")",
        "Operation" 
    }

    local gpu_traces = report_common.fetch_traces(all_traces, "MEMORY_COPY", opt) or {}
    
    local entries, total_metrics = report_common.get_entries(gpu_traces, get_entry_key_tab, report_common.get_duration, timeunit)
    local data = report_common.get_output_summary(entries, total_metrics)

    table.sort(data, function(a, b)
        return tonumber(a[2]) > tonumber(b[2])
    end)

    table.insert(data, 1, headers)

    attribute.report_name = "GPU MemOps Summary (by Time)"
    attribute.data = data
    attribute.data_size = #data - 1
    
    Report:new(attribute):generate(opt)
end