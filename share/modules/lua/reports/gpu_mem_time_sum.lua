local report_helper = require ("utils.report_helper")
local stats_helper  = require ("utils.stats_helper")

local function get_entry_key_tab(trace)
    return { report_helper.get_copy_name(trace.args.src_type, trace.args.dst_type) }
end

local function get_metric(trace, opt)
    return report_helper.get_duration(trace.dur, opt.timeunit)
end

return function(traces_data, report_obj, opt)
    report_obj:set_name("GPU MemOps")
    report_obj:set_type("Summary (by Time)")

    local timeunit = opt.timeunit
    report_obj:set_headers({
        "Time (%)", 
        "Total Time ("..timeunit..")", 
        "Count", 
        "Avg ("..timeunit..")", 
        "Med ("..timeunit..")", 
        "Min ("..timeunit..")", 
        "Max ("..timeunit..")", 
        "StdDev ("..timeunit..")",
        "Operation" 
    })

    local gpu_traces = traces_data:get(ratelprof.consts._ENV.DOMAIN_COPY)
    
    local entries, total_metrics = stats_helper.get_entries(gpu_traces, get_entry_key_tab, get_metric, opt)
    local data = stats_helper.get_output_summary(entries, total_metrics)

    table.sort(data, function(a, b)
        return tonumber(a[2]) > tonumber(b[2])
    end)

    report_obj:set_data(data)
end