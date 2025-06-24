local report_helper = require ("utils.report_helper")

local stats_helper = require ("utils.statistics")

local function get_metric(trace, opt)
    return report_helper.get_duration(trace.dur, opt.timeunit)
end

local function get_entry_key_tab(trace)
    return { trace.name }
end

function stats_helper.process_api_raw_data_for_sum_report(report_obj, data, domain, opt)
    local timeunit = opt.timeunit
    local raw_data = data:get(domain, opt)
    local entries, total_metrics = stats_helper.get_entries(raw_data, get_entry_key_tab, get_metric, opt)
    local data = stats_helper.get_output_summary(entries, total_metrics, data:get_app_dur())

    table.sort(data, function(a, b)
        return tonumber(a[2]) > tonumber(b[2])
    end)

    report_obj:set_data(data)

    report_obj:set_headers({
        "App Time (%)", -- 1
        "API Time (%)", -- 1
        "Total Time ("..timeunit..")", -- 2 
        "Num Calls", -- 3
        "Avg ("..timeunit..")", -- 4
        "Med ("..timeunit..")", -- 5
        "Min ("..timeunit..")", -- 6
        "Max ("..timeunit..")", -- 7
        "StdDev ("..timeunit..")", -- 8
        "Name" -- 9
    })
end


function stats_helper.process_api_raw_data_for_trace_report(report_obj, data, domain, opt)
    local timeunit = opt.timeunit
    local raw_data = data:get(domain, opt)
    local data = {}
    for id, trace in pairs(raw_data) do
        table.insert(data, {
            string.format("%.0f", trace.start),
            report_helper.get_duration(trace.dur, timeunit),
            trace.name,
            tostring(id),
            tostring(trace.corr_id),
            tostring(trace.pid),
            tostring(trace.tid)
        })
    end
    
    table.sort(data, function(a, b)
        return tonumber(a[4]) < tonumber(b[4])
    end)

    report_obj:set_data(data)

    report_obj:set_headers({
        "Start ("..timeunit..")", -- 1
        "Duration ("..timeunit..")", -- 2
        "Name", -- 3
        "Id", -- 4
        "CorrId", -- 5
        "Pid", -- 6
        "Tid" -- 7
    })
end

return stats_helper