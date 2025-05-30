local convert       = require ("utils.convert")
local report_helper = require ("utils.report_helper")
local stats_helper  = require ("utils.stats_helper")

local function get_output_data(traces_data, opt)
    local data = {}
    local timeunit = opt.timeunit
    
    local barror_traces  = traces_data:get(ratelprof.consts._ENV.DOMAIN_BARRIEROR)
    local barrand_traces = traces_data:get(ratelprof.consts._ENV.DOMAIN_BARRIERAND)
    local kern_traces    = traces_data:get(ratelprof.consts._ENV.DOMAIN_KERNEL)
    local mem_traces     = traces_data:get(ratelprof.consts._ENV.DOMAIN_COPY)

    -- Helper function to construct entries
    local function add_entry(trace, id, entry_type)
        local dur = report_helper.get_duration(trace.dur, timeunit)

        if entry_type == 0 then
            local size = tonumber(convert.bytes(trace.args.size, "bytes", "mb"))
            return {
                string.format("%.0f", trace.start),
                dur,
                "---",
                tostring(id),
                tostring(trace.corr_id),
                "---", "---", "---", "---", "---", "---", "---", "---",
                size,
                tonumber(size / convert.time(dur, timeunit, "sec")),
                report_helper.get_copy_name_from_kind(trace.args.src_type),
                report_helper.get_copy_name_from_kind(trace.args.dst_type),
                "---", "---",
                report_helper.get_copy_name(trace.args.src_type, trace.args.dst_type)
            }
        elseif entry_type == 1 or entry_type == 2 then
            local queue_dur = trace.start - trace.args.dispatch_time
            if timeunit ~= "ns" then queue_dur = convert.time(queue_dur, "ns", timeunit) end
            return {
                string.format("%.0f", trace.start),
                dur,
                queue_dur,
                tostring(id),
                tostring(trace.corr_id),
                "---", "---", "---", "---", "---", "---", "---", "---",
                "---", "---", "---", "---",
                traces_data:get_gpu_id(trace.args.gpu_id),
                tostring(trace.args.queue_id),
                entry_type == 2 and "Barrier And" or "Barrier Or"
            }
        elseif entry_type == 3 then
            return {
                string.format("%.0f", trace.start),
                dur,
                report_helper.get_duration(trace.start - trace.args.dispatch_time, timeunit),
                tostring(id),
                tostring(trace.corr_id),
                trace.args.grd[1], trace.args.grd[2], trace.args.grd[3],
                trace.args.wrg[1], trace.args.wrg[2], trace.args.wrg[3],
                trace.args.group_segment_size,
                trace.args.private_segment_size,
                "---", "---", "---", "---",
                traces_data:get_gpu_id(trace.args.gpu_id),
                tostring(trace.args.queue_id),
                ratelprof.utils.get_kernel_name(trace.args.kernel_name, opt.is_trunc, opt.is_mangled)
            }
        end
    end

    -- Add entries for each trace type
    for id, trace in pairs(mem_traces) do
        table.insert(data, add_entry(trace, id, 0))
    end

    for id, trace in pairs(barrand_traces) do
        table.insert(data, add_entry(trace, id, 1))
    end

    for id, trace in pairs(barror_traces) do
        table.insert(data, add_entry(trace, id, 2))
    end

    for id, trace in pairs(kern_traces) do
        table.insert(data, add_entry(trace, id, 3))
    end

    return data
end

return function(traces_data, report_obj, opt)
    report_obj:set_name("GPU")
    report_obj:set_type("Traces")

    report_obj:set_headers({
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
    })
    
    

    local data = get_output_data(traces_data, opt)
    
    table.sort(data, function(a, b)
        return tonumber(a[1]) < tonumber(b[1])
    end)

    report_obj:set_data(data)
end