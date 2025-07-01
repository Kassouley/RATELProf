local stats_helper  = require ("utils.stats_helper")

local function get_entry_key_tab(trace)
    return { ratelprof.utils.get_copy_name(trace.args.src_type, trace.args.dst_type) }
end

local function get_metric(trace, opt)
    return trace.args.size
    -- return report_helper.get_size(trace.args.size --[[, opt.sizeunit -- Todo ? bytes to kb, mb etc ]])
end

return function(traces_data, _, opt)
    local NAME = "GPU MemOps"
    local TYPE = "Summary (by Size)"

    local sizeunit = "B"

    local HEADER = {
        "App Time (%)",
        "API Time (%)",
        "Total ("..sizeunit..")",
        "Count",
        "Avg ("..sizeunit..")",
        "Med ("..sizeunit..")",
        "Min ("..sizeunit..")",
        "Max ("..sizeunit..")",
        "StdDev ("..sizeunit..")",
        "Operation"
    }

    local gpu_traces = traces_data:get(ratelprof.consts._ENV.DOMAIN_COPY, opt)
    
    local entries, total_metrics = stats_helper.get_entries(gpu_traces, get_entry_key_tab, get_metric, opt)
    local DATA = stats_helper.get_output_summary(entries, total_metrics, traces_data:get_app_dur())

    table.sort(DATA, function(a, b)
        return tonumber(a[2]) > tonumber(b[2])
    end)

    return {NAME = NAME, TYPE = TYPE, HEADER = HEADER, DATA = DATA, total_bytes = total_metrics}
end