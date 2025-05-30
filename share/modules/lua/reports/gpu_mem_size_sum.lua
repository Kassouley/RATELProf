local report_helper = require ("utils.report_helper")
local stats_helper  = require ("utils.stats_helper")

local function get_entry_key_tab(trace)
    return { report_helper.get_copy_name(trace.args.src_type, trace.args.dst_type) }
end

local function get_metric(trace, opt)
    return trace.args.size
    -- return report_helper.get_size(trace.args.size --[[, opt.sizeunit -- Todo ? bytes to kb, mb etc ]])
end

return function(traces_data, report_obj, opt)
    report_obj:set_name("GPU MemOps")
    report_obj:set_type("Summary (by Size)")

    local sizeunit = "B"

    report_obj:set_headers({
        "Total (%)", 
        "Total ("..sizeunit..")", 
        "Count", 
        "Avg ("..sizeunit..")", 
        "Med ("..sizeunit..")", 
        "Min ("..sizeunit..")", 
        "Max ("..sizeunit..")", 
        "StdDev ("..sizeunit..")",
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