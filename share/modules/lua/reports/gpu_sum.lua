local report_helper = require ("utils.report_helper")
local stats_helper  = require ("utils.stats_helper")

local function get_entry_key_tab1(trace)
    return { "MemoryOperation", trace.args.src_type or "Unknown", trace.args.dst_type or "Unknown"}
end

local function get_entry_key_tab2(trace, opt)
    return { "KernelDispatch", trace.args.kernel_name }
end

local function get_entry_key_tab3(trace)
    return { "BarrierDispatch", "BarrierAnd" }
end

local function get_entry_key_tab4(trace)
    return  { "BarrierDispatch", "BarrierOr" }
end


return function(traces_data, _, opt)
    local timeunit = opt.timeunit

    local barror_traces  = traces_data:get(ratelprof.consts._ENV.DOMAIN_BARRIEROR)
    local barrand_traces = traces_data:get(ratelprof.consts._ENV.DOMAIN_BARRIERAND)
    local kern_traces    = traces_data:get(ratelprof.consts._ENV.DOMAIN_KERNEL)
    local mem_traces     = traces_data:get(ratelprof.consts._ENV.DOMAIN_COPY)

    local mem_entries,     mem_total_metric     = stats_helper.get_entries(mem_traces,     get_entry_key_tab1, {"start", "stop"}, opt)
    local kern_entries,    kern_total_metric    = stats_helper.get_entries(kern_traces,    get_entry_key_tab2, {"start", "stop"}, opt)
    local barrand_entries, barrand_total_metric = stats_helper.get_entries(barrand_traces, get_entry_key_tab3, {"start", "stop"}, opt)
    local barror_entries,  barror_total_metric  = stats_helper.get_entries(barror_traces,  get_entry_key_tab4, {"start", "stop"}, opt)

    for _, entry in pairs(mem_entries) do
        entry.key_tab[2] = ratelprof.utils.get_copy_name(entry.key_tab[2], entry.key_tab[3])
        entry.key_tab[3] = nil
    end
    for _, entry in pairs(kern_entries) do
        entry.key_tab[2] = ratelprof.utils.get_kernel_name(entry.key_tab[2], opt.trunc, opt.mangled)
    end

    local gpu_entries = {}
    for _, entries in ipairs({kern_entries, mem_entries, barrand_entries, barror_entries}) do
        for _, entry in pairs(entries) do
            table.insert(gpu_entries, entry)
        end
    end
    local gpu_total_metric = kern_total_metric + mem_total_metric + barrand_total_metric + barror_total_metric
    
    local data = stats_helper.get_output_summary(gpu_entries, gpu_total_metric, traces_data:get_analyzed_interval_dur())

    table.sort(data, function(a, b)
        return tonumber(a[2]) > tonumber(b[2])
    end)

    local longuest_activity = "N/A"
    if data[1] and data[1][11] then longuest_activity = data[1][11] end

    return {
        NAME = "GPU",
        TYPE = "Summary",
        DATA = data,
        HEADER = {
            "Active Time (%)",
            "API Time (%)",
            "Total Time ("..timeunit..")",
            "Instances",
            "Avg ("..timeunit..")",
            "Med ("..timeunit..")",
            "Min ("..timeunit..")",
            "Max ("..timeunit..")",
            "StdDev ("..timeunit..")",
            "Category",
            "Operation" 
        },
        longest_activity = longuest_activity
    }
end