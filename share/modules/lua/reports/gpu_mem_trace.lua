local convert       = require ("utils.convert")
local report_helper = require ("utils.report_helper")

local function get_output_data(mem_traces, timeunit)
    local data = {}

    for id, trace in pairs(mem_traces) do
        local dur = report_helper.get_duration(trace.dur, timeunit)
        local size = tonumber(convert.bytes(trace.args.size, "bytes", "mb"))
        local src_name = ratelprof.utils.get_copy_name_from_kind(trace.args.src_type)
        local dst_name = ratelprof.utils.get_copy_name_from_kind(trace.args.dst_type)
        local cpy_name = ratelprof.utils.get_copy_name(trace.args.src_type, trace.args.dst_type)
        data[#data + 1] = {
            string.format("%.0f", trace.start),
            dur,
            tostring(id),
            tostring(trace.corr_id),
            size,
            tonumber(size / convert.time(dur, timeunit, "sec")),
            src_name,
            dst_name,
            cpy_name
        }
    end

    return data
end

return function(traces_data, _, opt)
    local mem_traces = traces_data:get(ratelprof.consts._ENV.DOMAIN_COPY, opt)

    local data = get_output_data(mem_traces, opt.timeunit)

    table.sort(data, function(a, b)
        return tonumber(a[1]) < tonumber(b[1])
    end)

    return {
        NAME = "GPU Memory",
        TYPE = "Traces",
        HEADER = {
            "Start ("..opt.timeunit..")",
            "Duration ("..opt.timeunit..")",
            "Id",
            "CorrId",
            "GroupMem (MB)",
            "PrivateMem (MB)",
            "Bytes (MB)",
            "Throughput (MBps)",
            "SrcMemKd",
            "DstMemKd",
            "Name"
        },
        DATA = data
    }
end