local report_helper = require ("utils.report_helper")

local function is_synchronized(gpuCpy, hipMemcpy)
    return gpuCpy["start"] > hipMemcpy["start"] and gpuCpy["stop"] < hipMemcpy["stop"]
end

return function(traces_data, report_obj, opt)
    report_obj:set_name("Host/Device Async Memcpy")
    report_obj:set_type("Analyze")

    local cpy_data = traces_data:get(ratelprof.consts._ENV.DOMAIN_COPY)
    local hip_data = traces_data:get(ratelprof.consts._ENV.DOMAIN_HIP)
    local hsa_data = traces_data:get(ratelprof.consts._ENV.DOMAIN_HSA)

    if next(hsa_data) ~= nil then
        report_obj:skip("The report could not be analyzed because it contains HSA data. This version doesn't support this analysis while HSA traces are present.")
        return
    end

    if next(cpy_data) == nil then
        report_obj:skip("The report could not be analyzed because it does not contain the required GPU data.")
        return
    end
    
    if next(hip_data) == nil then
        report_obj:skip("The report could not be analyzed because it does not contain the required HIP API data.")
        return
    end
    
    report_obj:set_headers({
        "API ID",
        "API Name",
        "PID",
        "TID",
        "Operation",
        "Size (MB)",
        "CPU Duration (ns)",
        "GPU Duration (ns)"
    })    

    local data = {}
    local nb_api_cpy = 0
    local grouped_copies = {}

    for _, gpuCpy in pairs(cpy_data) do
        if not grouped_copies[gpuCpy.corr_id] then
            grouped_copies[gpuCpy.corr_id] = {}
        end
        table.insert(grouped_copies[gpuCpy.corr_id], gpuCpy)
    end

    for corr_id, group in pairs(grouped_copies) do
        local corr_hip_trace = hip_data[corr_id]
        if corr_hip_trace then
            local hip_cpy = corr_hip_trace.name
            if hip_cpy:match("^hipMemcpy") and hip_cpy:match("Async$") then
                local first_start = group[1].start_time
                local last_stop   = group[1].stop_time
                local size = 0
                for _, gpuCpy in ipairs(group) do
                    local gpu_start = gpuCpy.start_time
                    local gpu_stop  = gpuCpy.stop_time
                    if gpu_start < first_start then first_start = gpu_start end
                    if gpu_stop > last_stop    then last_stop   = gpu_stop end
                    size = size + gpuCpy.args.size
                end
                local gpuCpy = {
                    start_time = first_start,
                    stop_time  = last_stop,
                    size = size,
                    src_type = group[1].args.src_type,
                    dst_type = group[1].args.dst_type
                }
                if is_synchronized(gpuCpy, corr_hip_trace) then
                    table.insert(data, {
                        corr_id,
                        hip_cpy,
                        corr_hip_trace.pid,
                        corr_hip_trace.tid,
                        ratelprof.utils.get_copy_name(gpuCpy.src_type, gpuCpy.dst_type),
                        report_helper.get_size(gpuCpy.size),
                        report_helper.get_duration(corr_hip_trace.dur, opt.timeunit),
                        report_helper.get_duration(last_stop - first_start, opt.timeunit)
                    })
                end
                nb_api_cpy = nb_api_cpy + 1
            end
        end
    end


    local msg = ratelprof.consts._ALL_RULES_REPORT.hip_memcpy_async.desc
    local advice_msg = [[

The following memory transfers are synchronized with their corresponding HIP asynchronous memory copy trace.
It appears that the transferred memory is either using PAGEABLE memory or is not large enough to be processed asynchronously.

This correspond to ]]..string.format("%.2f", (((#data)/nb_api_cpy)*100))..[[% of your hipMemcpy*Async operations.

Suggestion: If applicable, use PINNED memory instead by using hipHostMalloc to allocate your host side memory.
]]
    local no_advice_msg = "There were no problems detected related to asynchronous memcpy operations.\n"

    table.sort(data, function(a, b)
        return a[7] < b[7]
    end)

    if #data == 0 then 
        msg = msg .. no_advice_msg
    else
        msg = msg .. advice_msg
    end
    
    report_obj:set_custom_message(msg)
    report_obj:set_data(data)
end