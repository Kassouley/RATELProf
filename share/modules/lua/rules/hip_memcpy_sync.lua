local report_helper = require ("utils.report_helper")

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

    local cpy_data = traces_data:get(ratelprof.consts._ENV.DOMAIN_COPY)
    local hip_data = traces_data:get(ratelprof.consts._ENV.DOMAIN_HIP)

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
    local advice_msg = [[ 
The following are synchronous memory transfers that block the host.
This correspond to ]]..string.format("%.2f", (((#data)/nb_api_cpy)*100))..[[% of your hipMemcpy*() operations.

Suggestion: Use hipMemcpy*Async() APIs instead.
]]
    local no_advice_msg = "\nThere were no problems detected related to synchronous memcpy operations.\n"

    table.sort(data, function(a, b)
        return a[8] < b[8]
    end)

    if #data == 0 then 
        msg = msg .. no_advice_msg
    else
        msg = msg .. advice_msg
    end
    
    report_obj:set_custom_message(msg)
    report_obj:set_data(data)
end