local function get_entry_key_tab1(trace)
    return { "MemoryOperation", report_common.get_copy_name(trace) }
end

local function get_entry_key_tab2(trace)
    return { "KernelDispatch", trace.args.kernel_name }
end

local function get_entry_key_tab3(trace)
    return { "BarrierDispatch", "BarrierAnd" }
end

local function get_entry_key_tab4(trace)
    return  { "BarrierDispatch", "BarrierOr" }
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
        "Category",
        "Operation" 
    }

    local kern_traces    = report_common.fetch_traces(all_traces, "KERNEL_DISPATCH",      opt) or {}
    local mem_traces     = report_common.fetch_traces(all_traces, "MEMORY_COPY",          opt) or {}
    local barrand_traces = report_common.fetch_traces(all_traces, "BARRIER_AND_DISPATCH", opt) or {}
    local barror_traces  = report_common.fetch_traces(all_traces, "BARRIER_OR_DISPATCH",  opt) or {}

    local mem_entries, mem_total_metric         = report_common.get_entries(mem_traces, get_entry_key_tab1, report_common.get_duration, timeunit)
    local kern_entries, kern_total_metric       = report_common.get_entries(kern_traces, get_entry_key_tab2, report_common.get_duration, timeunit)
    local barrand_entries, barrand_total_metric = report_common.get_entries(barrand_traces, get_entry_key_tab3, report_common.get_duration, timeunit)
    local barror_entries, barror_total_metric   = report_common.get_entries(barror_traces, get_entry_key_tab4, report_common.get_duration, timeunit)

    local gpu_entries = {}
    for i, t in ipairs({kern_entries, mem_entries, barrand_entries, barror_entries}) do
        for j, value in pairs(t) do
            table.insert(gpu_entries, value)
        end
    end
    local gpu_total_metric = kern_total_metric + mem_total_metric + barrand_total_metric + barror_total_metric
    
    local data = report_common.get_output_summary(gpu_entries, gpu_total_metric)

    table.sort(data, function(a, b)
        return tonumber(a[2]) > tonumber(b[2])
    end)

    table.insert(data, 1, headers)

    attribute.report_name = "GPU Summary"
    attribute.data = data
    attribute.data_size = #data - 1
    
    Report:new(attribute):generate(opt)
end