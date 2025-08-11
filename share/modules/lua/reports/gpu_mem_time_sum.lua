local report_helper = require ("utils.report_helper")
local stats_helper  = require ("utils.stats_helper")

local function get_entry_key_tab(trace)
    return { ratelprof.utils.get_copy_name(trace.args.src_type, trace.args.dst_type) }
end

return function(traces_data, _, opt)

    local timeunit = opt.timeunit
    local HEADER = {
        "Active Time (%)",
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

    local gpu_traces = traces_data:get(ratelprof.consts._ENV.DOMAIN_COPY)
    
    local entries, total_metrics = stats_helper.get_entries(gpu_traces, get_entry_key_tab, {"start", "stop"}, opt)
    local data = stats_helper.get_output_summary(entries, total_metrics, traces_data:get_analyzed_interval_dur())

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