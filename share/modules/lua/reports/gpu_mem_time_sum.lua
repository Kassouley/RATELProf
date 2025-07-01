local report_helper = require ("utils.report_helper")
local stats_helper  = require ("utils.stats_helper")

local function get_entry_key_tab(trace)
    return { ratelprof.utils.get_copy_name(trace.args.src_type, trace.args.dst_type) }
end

local function get_metric(trace, opt)
    return report_helper.get_duration(trace.dur, opt.timeunit)
end

return function(traces_data, report_obj, opt)

    local timeunit = opt.timeunit
    local HEADER = {
        "App Time (%)",
        "API Time (%)",
        "Total Time ("..timeunit..")",
        "Count",
        "Avg ("..timeunit..")",
        "Med ("..timeunit..")",
        "Min ("..timeunit..")",
        "Max ("..timeunit..")",
        "StdDev ("..timeunit..")",
        "Operation" 
    }

    local gpu_traces = traces_data:get(ratelprof.consts._ENV.DOMAIN_COPY, opt)
    
    local entries, total_metrics = stats_helper.get_entries(gpu_traces, get_entry_key_tab, get_metric, opt)
    local data = stats_helper.get_output_summary(entries, total_metrics, traces_data:get_app_dur())

    table.sort(data, function(a, b)
        return tonumber(a[2]) > tonumber(b[2])
    end)


    return {
        NAME = "GPU MemOps",
        TYPE = "Summary (by Time)",
        DATA = data,
        HEADER = HEADER,
        total_time = total_metrics,
    }

end