local conversion = require("conversion")
local report_common = {}

report_common.key = {
    name = "name",
    start = "start",
    stop = "end",
    pid = "pid",
    tid = "tid",
    corrId = "corrId",
    gpu_op = "operation",
    gpu_grd1 = "args.grd.1",
    gpu_grd2 = "args.grd.2",
    gpu_grd3 = "args.grd.3",
    gpu_blk1 = "args.wrg.1",
    gpu_blk2 = "args.wrg.2",
    gpu_blk3 = "args.wrg.3",
    gpu_shrdmem = "args.private_segment_size",
    copy_size = "args.size",
    copy_memCpyKind = "name",
    queue_id = "args.queue_id",
    gpu_id = "args.gpu_id"
}

function report_common.get_duration(trace, timeunit)
    local stop = trace[report_common.key.stop]
    local start = trace[report_common.key.start]
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
            trace[report_common.key.start],
            report_common.get_duration(trace, timeunit),
            trace[report_common.key.name],
            trace[report_common.key.corrId],
            trace[report_common.key.pid],
            trace[report_common.key.tid]
        }
        table.insert(data, entry)
    end
    return data
end

return report_common