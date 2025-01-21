local const = require("const")
local conversion = require("conversion")
local json_parser = require("json_parser")

local report_common = json_parser

function report_common.get_copy_name_from_kind(kind)
    return const._MEM_KIND[kind+1]
end

function report_common.get_copy_name(trace)
    return "Copy"..report_common.get_copy_name_from_kind(trace.args.src_type)..
            "To"..report_common.get_copy_name_from_kind(trace.args.dst_type)
end

function report_common.get_duration(trace, timeunit)
    local dur = trace.dur
    if timeunit ~= "ns" then
        return conversion.time(dur, "ns", timeunit)
    end
    return  dur
end


function report_common.get_queue_time(trace, timeunit)
    local dur = trace.start - trace.args.dispatch_time
    if timeunit ~= "ns" then
        return conversion.time(dur, "ns", timeunit)
    end
    return  dur
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
        "Id", -- 4
        "CorrId", -- 5
        "Pid", -- 6
        "Tid" -- 7
    }
end

function report_common.api_get_output_data(traces, timeunit)
    local data = {}

    for _, trace in ipairs(traces) do
        local entry = {
            trace.start,
            report_common.get_duration(trace, timeunit),
            trace.name,
            trace.id,
            trace.corr_id,
            trace.pid,
            trace.tid
        }
        table.insert(data, entry)
    end
    return data
end

return report_common