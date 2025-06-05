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

local function get_metric(trace, opt)
    return report_helper.get_duration(trace.dur, opt.timeunit)
end

return function(traces_data, report_obj, opt)
    report_obj:set_name("GPU")
    report_obj:set_type("Summary")

    local timeunit = opt.timeunit
    report_obj:set_headers({
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
    })

    local barror_traces  = traces_data:get(ratelprof.consts._ENV.DOMAIN_BARRIEROR)
    local barrand_traces = traces_data:get(ratelprof.consts._ENV.DOMAIN_BARRIERAND)
    local kern_traces    = traces_data:get(ratelprof.consts._ENV.DOMAIN_KERNEL)
    local mem_traces     = traces_data:get(ratelprof.consts._ENV.DOMAIN_COPY)

    local mem_entries,     mem_total_metric     = stats_helper.get_entries(mem_traces,     get_entry_key_tab1, get_metric, opt)
    local kern_entries,    kern_total_metric    = stats_helper.get_entries(kern_traces,    get_entry_key_tab2, get_metric, opt)
    local barrand_entries, barrand_total_metric = stats_helper.get_entries(barrand_traces, get_entry_key_tab3, get_metric, opt)
    local barror_entries,  barror_total_metric  = stats_helper.get_entries(barror_traces,  get_entry_key_tab4, get_metric, opt)

    for _, entry in pairs(mem_entries) do
        entry.key_tab[2] = ratelprof.utils.get_copy_name(entry.key_tab[2], entry.key_tab[3])
        entry.key_tab[3] = nil
    end
    for _, entry in pairs(kern_entries) do
        entry.key_tab[2] = ratelprof.utils.get_kernel_name(entry.key_tab[2], opt.is_trunc, opt.is_mangled)
    end

    local gpu_entries = {}
    for _, entries in ipairs({kern_entries, mem_entries, barrand_entries, barror_entries}) do
        for _, entry in pairs(entries) do
            table.insert(gpu_entries, entry)
        end
    end
    local gpu_total_metric = kern_total_metric + mem_total_metric + barrand_total_metric + barror_total_metric
    
    local data = stats_helper.get_output_summary(gpu_entries, gpu_total_metric)

    table.sort(data, function(a, b)
        return tonumber(a[2]) > tonumber(b[2])
    end)

    report_obj:set_data(data)
end