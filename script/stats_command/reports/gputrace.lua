local Report = require("Report")

local function get_output_data(kern_traces, mem_traces, timeunit)
    local data = {}

    for _, trace in ipairs(kern_traces) do
        local dur = report_common.get_duration(trace, timeunit)
        local size = trace.args.size
        local entry = {
            trace.start,
            dur,
            trace.corr_id,
            "---",
            "---",
            "---",
            "---",
            size,
            size / conversion.time(dur, timeunit, "sec"),
            common.get_copy_name_from_kind(trace.args.src_type),
            common.get_copy_name_from_kind(trace.args.dst_type),
            "---",
            "---",
            common.get_copy_name(trace),
            trace[report_common.key.name]
        }
        table.insert(data, entry)
    end

    for _, trace in ipairs(mem_traces) do
        local entry = {
            trace.start,
            report_common.get_duration(trace, timeunit),
            trace.corr_id,
            trace.args.grd[1],
            trace.args.grd[2],
            trace.args.grd[3],
            trace.args.wrg[1],
            trace.args.wrg[2],
            trace.args.wrg[3],
            trace.args.group_segment_size,
            trace.args.private_segment_size,
            "---",
            "---",
            "---",
            "---",
            trace.args.gpu_id,
            trace.args.queue_id,
            trace.args.kernel_name,
        }
        table.insert(data, entry)
    end
    return data
end


function Report:get_report_name()
    return "GPU Traces"
end


function Report:get_headers()
    return {
        "Start ("..self.timeunit..")", -- 1
        "Duration ("..self.timeunit..")", -- 2
        "CorrId", -- 3
        "GrdX", -- 4
        "GrdY", -- 5
        "GrdZ", -- 6
        "BlkX", -- 7
        "BlkY", -- 8
        "BlkZ", -- 9
        "GroupMem (MB)", -- 10
        "PrivateMem (MB)", -- 11
        "Bytes (MB)", -- 12
        "Throughput (MBps)", -- 13
        "SrcMemKd", -- 14
        "DstMemKd", -- 15
        "Device", -- 16
        "Queue", -- 17
        "Name" -- 18
    }
end


function Report:get_data()
    local kern_traces = self:get_gpu_kern_traces()
    local mem_traces = self:get_gpu_mem_traces()

    local data = get_output_data(kern_traces, mem_traces, self.timeunit)

    table.sort(data, function(a, b)
        return tonumber(a[1]) < tonumber(b[1])
    end)

    return data
end
