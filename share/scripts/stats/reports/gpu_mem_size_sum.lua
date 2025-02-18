local function get_entry_key_tab(trace)
    return { stats:get_copy_name(trace) }
end

return function(all_traces, attribute, opt)
    local headers = {
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

    local gpu_traces = stats:fetch_traces(all_traces, "MEMORY_COPY", opt) or {}
    
    local entries, total_metrics = stats:get_entries(gpu_traces, get_entry_key_tab, stats.get_size)
    local data = stats:get_output_summary(entries, total_metrics)

    table.sort(data, function(a, b)
        return tonumber(a[2]) > tonumber(b[2])
    end)

    table.insert(data, 1, headers)

    attribute.report_name = "GPU MemOps Summary (by Size)"
    attribute.data = data
    attribute.data_size = #data - 1
    
    Report.Report:new(attribute):generate(opt)
end