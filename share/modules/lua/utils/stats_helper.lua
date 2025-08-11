local report_helper = require ("utils.report_helper")

local stats_helper = require ("utils.statistics")

local function get_entry_key_tab(trace)
    return { trace.name }
end

function stats_helper.process_api_raw_data_for_sum_report(data, domain, opt)
    local timeunit = opt.timeunit
    local raw_data = data:get(domain)
    local entries, total_metrics = stats_helper.get_entries(raw_data, get_entry_key_tab, {"start", "stop"}, opt)
    local data = stats_helper.get_output_summary(entries, total_metrics, data:get_analyzed_interval_dur())

    table.sort(data, function(a, b)
        return tonumber(a[3]) > tonumber(b[3])
    end)

    return data, {
        "Active Time (%)", -- 1
        "API Time (%)", -- 2
        "Total Time ("..timeunit..")", -- 3
        "Num Calls", -- 4
        "Avg ("..timeunit..")", -- 5
        "Med ("..timeunit..")", -- 6
        "Min ("..timeunit..")", -- 7
        "Max ("..timeunit..")", -- 8
        "StdDev ("..timeunit..")", -- 9
        "Name" -- 10
    }
end


function stats_helper.process_api_raw_data_for_trace_report(data, domain, opt)
    local timeunit = opt.timeunit
    local raw_data = data:get(domain)
    local data = {}
    for _, trace in ipairs(raw_data) do
        table.insert(data, {
            string.format("%.0f", trace.start),
            report_helper.get_duration(trace.dur, timeunit),
            trace.name,
            tostring(trace.id),
            tostring(trace.corr_id),
            tostring(trace.pid),
            tostring(trace.tid)
        })
    end

    return data, {
        "Start ("..timeunit..")", -- 1
        "Duration ("..timeunit..")", -- 2
        "Name", -- 3
        "Id", -- 4
        "CorrId", -- 5
        "Pid", -- 6
        "Tid" -- 7
    }
end

return stats_helper