local conversion = require("conversion")
local report_common = {}

function report_common.get_duration(trace, timeunit)
    local stop = trace["end"]
    local start = trace.start
    if timeunit ~= "ns" then
        return conversion.time(stop, "ns", timeunit) - conversion.time(start, "ns", timeunit)
    end
    return  stop - start
end

function report_common.get_sort_api_sum(data)
    table.sort(data, function(a, b)
        return tonumber(a[2]) > tonumber(b[2])
    end)
    return data
end

function report_common.get_sort_api_trace(data)
    table.sort(data, function(a, b)
        return tonumber(a[4]) < tonumber(b[4])
    end)
    return data
end

function report_common.get_header_api_sum(timeunit)
    return {
        "Time (%)", -- 1
        "Total Time ("..timeunit..")", -- 2 
        "Num Calls", -- 3
        "Avg ("..timeunit..")", -- 4
        "Med ("..timeunit..")", -- 5
        "Min ("..timeunit..")", -- 6
        "Max ("..timeunit..")", -- 7
        "StdDev ("..timeunit..")", -- 8
        "Name" -- 9
    }
end

function report_common.get_header_api_trace(timeunit)
    return {
        "Start ("..timeunit..")", -- 1
        "Duration ("..timeunit..")", -- 2
        "Name", -- 3
        "CorrId", -- 4
        "Pid", -- 5
        "Tid" -- 6
    }
end

function report_common.api_get_output_data(traces, timeunit)
    local data = {}

    for _, trace in ipairs(traces) do
        local entry = {
            trace.start,
            report_common.get_duration(trace, timeunit),
            trace.name,
            trace.corr_id,
            trace.pid,
            trace.tid
        }
        table.insert(data, entry)
    end
    return data
end

return report_common