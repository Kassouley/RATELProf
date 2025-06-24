local report_helper = require ("utils.report_helper")


local function compute_sync_copy_speedup(data, app_dur)
    local total_useless_sync_time_per_tid = {}

    for _, e in ipairs(data) do
        local tid = e[5]
        local cpu_dur = e[8]
        local gpu_dur = e[9]

        if not total_useless_sync_time_per_tid[tid] then
            total_useless_sync_time_per_tid[tid] = 0
        end
        total_useless_sync_time_per_tid[tid] = total_useless_sync_time_per_tid[tid] + (cpu_dur - gpu_dur)
    end

    local max, _ = table.max(total_useless_sync_time_per_tid)

    if max == nil or max == 0 then
        error("Invalid max ideal duration")
    end

    return app_dur / (app_dur - max)
end


return function(traces_data, report_obj, opt)
    report_obj:set_name("Host/Device Sync Memcpy")
    report_obj:set_type("Analyze")
    report_obj:set_headers({
        "Copy ID",
        "API ID",
        "API Name",
        "PID",
        "TID",
        "Operation",
        "Size (MB)",
        "CPU Duration (ns)",
        "GPU Duration (ns)",
    })

    local cpy_data = traces_data:get(ratelprof.consts._ENV.DOMAIN_COPY, opt)
    local hip_data = traces_data:get(ratelprof.consts._ENV.DOMAIN_HIP, opt)

    if next(cpy_data) == nil then
        report_obj:skip("The report could not be analyzed because it does not contain the required GPU data.")
        return
    end
    
    if next(hip_data) == nil then
        report_obj:skip("The report could not be analyzed because it does not contain the required HIP API data.")
        return
    end

    local data = {}

    local nb_api_cpy = 0
    for id, gpuCpy in pairs(cpy_data) do
        local corr_hip_trace = hip_data[gpuCpy.corr_id]
        if corr_hip_trace then
            local hip_cpy = corr_hip_trace.name 
            nb_api_cpy = nb_api_cpy + 1
            if hip_cpy:match("^hipMemcpy") and not hip_cpy:match("Async$") then
                table.insert(data, {
                    tostring(id),
                    tostring(gpuCpy.corr_id),
                    hip_cpy,
                    tostring(corr_hip_trace.pid),
                    tostring(corr_hip_trace.tid),
                    ratelprof.utils.get_copy_name(gpuCpy.args.src_type, gpuCpy.args.dst_type),
                    report_helper.get_size(gpuCpy.args.size),
                    report_helper.get_duration(corr_hip_trace.dur, opt.timeunit),
                    report_helper.get_duration(gpuCpy.dur, opt.timeunit)
                })
            end
        end
    end

    local msg = ratelprof.consts._ALL_RULES_REPORT.hip_memcpy_sync.desc
    local speedup_factor = 1

    if #data == 0 then 
    local no_advice_msg = "\nThere were no problems detected related to synchronous memcpy operations.\n"
        msg = msg .. no_advice_msg
    else

        local app_duration = traces_data:get_app_dur()

        speedup_factor = compute_sync_copy_speedup(data, app_duration)


        local advice_msg = [[ 
The following are synchronous memory transfers that block the host.
This correspond to ]]..string.format("%.2f", (((#data)/nb_api_cpy)*100))..[[% of your hipMemcpy*() operations.

Suggestion: Use hipMemcpy*Async() APIs instead.
Your application might speed up by ]] .. string.format("x%.3f.\n\n", speedup_factor).."\n"

        table.sort(data, function(a, b)
            return a[8] < b[8]
        end)

        msg = msg .. advice_msg
    end
    
    report_obj:set_custom_message(msg)
    report_obj:set_data(data)
    
    return {speedup = speedup_factor, advice = msg}
end