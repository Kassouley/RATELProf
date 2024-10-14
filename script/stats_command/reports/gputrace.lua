local Report = require("Report")

local memCpyKindNames = {
    [1] = { src = "Host", dst = "Device" },
    [2] = { src = "Device", dst = "Host" }
}

local function get_copy_name_from_kind(memCpyKind, direction)
    return memCpyKindNames[memCpyKind] and memCpyKindNames[memCpyKind][direction] or "Unknown"
end

local function get_output_data(traces, timeunit)
    local data = {}

    for _, trace in ipairs(traces) do
        local entry = {
            trace[report_common.key.start],
            report_common.get_duration(trace, timeunit),
            trace[report_common.key.corrId],
            "---",
            "---",
            "---",
            "---",
            "---",
            "---",
            "---",
            "---",
            "---",
            "---",
            "---",
            trace[report_common.key.gpu_id],
            trace[report_common.key.queue_id],
            trace[report_common.key.name]
        }

        if trace[report_common.key.gpu_op] == 2 then
            entry[4] = trace[report_common.key.gpu_grd1]
            entry[5] = trace[report_common.key.gpu_grd2]
            entry[6] = trace[report_common.key.gpu_grd3]
            entry[7] = trace[report_common.key.gpu_blk1]
            entry[8] = trace[report_common.key.gpu_blk2]
            entry[9] = trace[report_common.key.gpu_blk3]
            entry[10] = trace[report_common.key.gpu_shrdmem]
        elseif trace[report_common.key.gpu_op] == 1 then
            entry[11] = trace[report_common.key.copy_size]
            entry[12] = entry[11] / conversion.time(entry[2], timeunit, "sec")
            entry[13] = get_copy_src_from_kind(report_common.key.copy_memCpyKind, "src")
            entry[14] = get_copy_dst_from_kind(report_common.key.copy_memCpyKind, "dst")
        end

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
        "SharedMem (MB)", -- 10
        "Bytes (MB)", -- 11
        "Throughput (MBps)", -- 12
        "SrcMemKd", -- 13
        "DstMemKd", -- 14
        "Device", -- 15
        "Queue", -- 16
        "Name" -- 18
    }
end


function Report:get_data()
    local gpu_traces = self:get_gpu_traces()

    local data = get_output_data(gpu_traces, self.timeunit)

    table.sort(data, function(a, b)
        return tonumber(a[3]) < tonumber(b[3])
    end)

    return data
end
