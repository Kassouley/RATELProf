local convert = require ("utils.convert")

local function get_output_data(kern_traces, mem_traces, barrand_traces, barror_traces, timeunit)
    local data = {}

    -- Helper function to construct entries
    local function add_entry(trace, entry_type)
        local dur = report_common.get_duration(trace, timeunit)

        if entry_type == "mem" then
            local size = convert.bytes(trace.args.size, "bytes", "mb")
            return {
                string.format("%.0f", trace.start),
                dur,
                "---",
                trace.id,
                trace.corr_id,
                "---", "---", "---", "---", "---", "---", "---", "---",
                size,
                string.format("%.2f", size / convert.time(dur, timeunit, "sec")),
                report_common.get_copy_name_from_kind(trace.args.src_type),
                report_common.get_copy_name_from_kind(trace.args.dst_type),
                "---", "---",
                report_common.get_copy_name(trace)
            }
        elseif entry_type == "barrand" or entry_type == "barror" then
            local queue_dur = trace.start - trace.args.dispatch_time
            if timeunit ~= "ns" then queue_dur = convert.time(queue_dur, "ns", timeunit) end
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
            local kernel_name = trace.args.kernel_name
            if timeunit ~= "ns" then queue_dur = convert.time(queue_dur, "ns", timeunit) end
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
                kernel_name
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

return function(all_traces, attribute, opt)
    local headers = {
        "Start ("..opt.timeunit..")", 
        "Duration ("..opt.timeunit..")", 
        "Queue Time ("..opt.timeunit..")", 
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

    local kern_traces    = report_common.fetch_traces(all_traces, "KERNEL_DISPATCH", opt) or {}
    local mem_traces     = report_common.fetch_traces(all_traces, "MEMORY_COPY", opt) or {}
    local barrand_traces = report_common.fetch_traces(all_traces, "BARRIER_AND_DISPATCH", opt) or {}
    local barror_traces  = report_common.fetch_traces(all_traces, "BARRIER_OR_DISPATCH", opt) or {}

    attribute.report_name = "GPU Traces"
    attribute.data = get_output_data(kern_traces, mem_traces, barrand_traces, barror_traces, opt.timeunit)
    attribute.data_size = #attribute.data

    
    table.sort(attribute.data, function(a, b)
        return tonumber(a[1]) < tonumber(b[1])
    end)

    table.insert(attribute.data, 1, headers)

    Report:new(attribute):generate(opt)
end