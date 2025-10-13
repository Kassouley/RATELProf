local report_helper = require ("utils.report_helper")

return function(traces_data, _, opt)
    local cpy_data = traces_data:get(ratelprof.consts._ENV.DOMAIN_COPY)
    
    if next(cpy_data) == nil then
        return {skip = "The report could not be analyzed because it does not contain the required GPU data."}
    end
    
    local grouped_copy_by_entry_point = {}
    for _, gpu_trace in pairs(cpy_data) do
        local entry_trace, domain = traces_data:find_entry_point(gpu_trace)
        if entry_trace and domain == ratelprof.consts._ENV.DOMAIN_HIP then
            local grouped_trace = grouped_copy_by_entry_point[entry_trace] or {
                start = math.huge,
                stop  = 0,
                size  = 0,
                corr_id  = gpu_trace.corr_id,
                src_type = gpu_trace.args.src_type,
                dst_type = gpu_trace.args.dst_type
            }

            grouped_trace.start = math.min(grouped_trace.start, gpu_trace.start)
            grouped_trace.stop  = math.max(grouped_trace.stop,  gpu_trace.stop)
            grouped_trace.size  = grouped_trace.size + gpu_trace.args.size

            grouped_copy_by_entry_point[entry_trace] = grouped_trace
        end
    end
    
    local data = {}

    local total_useless_sync_time_table = {}

    local nb_api_cpy = 0
    for entry_trace, copy_trace in pairs(grouped_copy_by_entry_point) do
        nb_api_cpy = nb_api_cpy + 1
        local trace_name = entry_trace.name

        if trace_name:match("^hipMemcpy") and not trace_name:match("Async$") then
            local cpu_dur_ns = entry_trace.dur
            local gpu_dur_ns = copy_trace.stop - copy_trace.start
            local tid = tostring(entry_trace.tid)
            local pid = tostring(entry_trace.pid)

            local key = tid.."::"..pid
            local total_useless_sync_time = total_useless_sync_time_table[key] or 0
            total_useless_sync_time_table[key] = total_useless_sync_time + (cpu_dur_ns - gpu_dur_ns)

            table.insert(data, {
                tostring(copy_trace.corr_id),
                trace_name,
                pid,
                tid,
                ratelprof.utils.get_copy_name(copy_trace.src_type, copy_trace.dst_type),
                report_helper.get_size(copy_trace.size),
                report_helper.get_duration(cpu_dur_ns, opt.timeunit),
                report_helper.get_duration(gpu_dur_ns, opt.timeunit)
            })
        end
    end

    local msg = ""
    local speedup_factor = 1

    if #data == 0 then 
        msg = "There were no problems detected related to synchronous memcpy operations.\n"
    else

        local app_dur = traces_data:get_app_dur()

        local max_useless_time = table.max(total_useless_sync_time_table)

        if max_useless_time == nil or max_useless_time == 0 then
            error("Invalid max ideal duration")
        end

        speedup_factor = app_dur / (app_dur - max_useless_time)

        msg = [[ 
The following are synchronous memory transfers that block the host.
This correspond to ]]..string.format("%.2f", (((#data)/nb_api_cpy)*100))..[[% of your hipMemcpy*() operations.

Suggestion: Use hipMemcpy*Async() APIs instead.
Your application might speed up by ]] .. string.format("x%.3f.\n\n", speedup_factor).."\n"

        table.sort(data, function(a, b)
            return a[7] < b[7]
        end)
    end
    
    return {
        NAME = "Host/Device Sync Memcpy",
        TYPE = "Analyze",
        HEADER = {
            "API ID",
            "API Name",
            "PID",
            "TID",
            "Operation",
            "Size (B)",
            "CPU Duration (ns)",
            "GPU Duration (ns)",
        },
        DATA = data,
        MSG = msg,
        speedup = speedup_factor
    }
end