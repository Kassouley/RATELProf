local Report = require("Report")
local report_common = require("report_common")
local conversion = require("conversion")

local function get_output_data(kern_traces, mem_traces, barrand_traces, barror_traces, timeunit)
    local data = {}

    -- Helper function to construct entries
    local function add_entry(trace, entry_type)
        local dur = report_common.get_duration(trace, timeunit)

        if entry_type == "mem" then
            local size = conversion.bytes(trace.args.size, "bytes", "mb")
            return {
                string.format("%.0f", trace.start),
                dur,
                "---",
                trace.id,
                trace.corr_id,
                "---", "---", "---", "---", "---", "---", "---", "---",
                size,
                string.format("%.2f", size / conversion.time(dur, timeunit, "sec")),
                report_common.get_copy_name_from_kind(trace.args.src_type),
                report_common.get_copy_name_from_kind(trace.args.dst_type),
                "---", "---",
                report_common.get_copy_name(trace)
            }
        elseif entry_type == "barrand" or entry_type == "barror" then
            local queue_dur = trace.start - trace.args.dispatch_time
            if timeunit ~= "ns" then queue_dur = conversion.time(queue_dur, "ns", timeunit) end
            return {
                string.format("%.0f", trace.start),
                dur,
                queue_dur,
                trace.id,
                trace.corr_id,
                "---", "---", "---", "---", "---", "---", "---", "---",
                "---", "---", "---", "---",
                trace.args.gpu_id,
                trace.args.queue_id,
                entry_type == "barrand" and "Barrier And" or "Barrier Or"
            }
        elseif entry_type == "kern" then
            local queue_dur = trace.start - trace.args.dispatch_time
            if timeunit ~= "ns" then queue_dur = conversion.time(queue_dur, "ns", timeunit) end
            return {
                string.format("%.0f", trace.start),
                dur,
                queue_dur,
                trace.id,
                trace.corr_id,
                trace.args.grd[1], trace.args.grd[2], trace.args.grd[3],
                trace.args.wrg[1], trace.args.wrg[2], trace.args.wrg[3],
                trace.args.group_segment_size,
                trace.args.private_segment_size,
                "---", "---", "---", "---",
                trace.args.gpu_id,
                trace.args.queue_id,
                trace.args.kernel_name
            }
        end
    end

    -- Add entries for each trace type
    for _, trace in ipairs(mem_traces) do
        table.insert(data, add_entry(trace, "mem"))
    end

    for _, trace in ipairs(barrand_traces) do
        table.insert(data, add_entry(trace, "barrand"))
    end

    for _, trace in ipairs(barror_traces) do
        table.insert(data, add_entry(trace, "barror"))
    end

    for _, trace in ipairs(kern_traces) do
        table.insert(data, add_entry(trace, "kern"))
    end

    return data
end



function Report:get_report_name()
    return "GPU Traces"
end


function Report:get_headers()
    return {
        "Start ("..self.timeunit..")", 
        "Duration ("..self.timeunit..")", 
        "Queue Time ("..self.timeunit..")", 
        "Id", 
        "CorrId", 
        "GrdX", 
        "GrdY", 
        "GrdZ", 
        "BlkX", 
        "BlkY", 
        "BlkZ",
        "GroupMem (MB)",
        "PrivateMem (MB)",
        "Bytes (MB)",
        "Throughput (MBps)",
        "SrcMemKd",
        "DstMemKd",
        "Device",
        "Queue",
        "Name"
    }
end


function Report:get_data()
    local kern_traces = report_common.get_gpu_kern_traces(self)
    local mem_traces = report_common.get_gpu_mem_traces(self)
    local barrand_traces = report_common.get_gpu_barrierand_traces(self)
    local barror_traces = report_common.get_gpu_barrieror_traces(self)

    local data = get_output_data(kern_traces, mem_traces, barrand_traces, barror_traces, self.timeunit)

    table.sort(data, function(a, b)
        return tonumber(a[1]) < tonumber(b[1])
    end)

    return data
end
