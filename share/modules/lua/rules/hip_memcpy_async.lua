local report_helper = require ("utils.report_helper")

local function is_synchronized(gpuCpy, hipMemcpy)
    local gpu_start = gpuCpy["start"]
    local gpu_stop  = gpuCpy["stop"]
    local api_start = hipMemcpy["start"]
    local api_stop  = api_start + hipMemcpy["dur"]
    return gpu_start > api_start and gpu_stop < api_stop
end

local function compute_async_copy_speedup(data, app_dur)
    local total_useless_sync_time_per_tid = {}

    for _, e in ipairs(data) do
        local tid = e[4]
        local cpu_dur = e[7]
        local gpu_dur = e[8]

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


return function(traces_data, report_id, opt)
    local cpy_data = traces_data:get(ratelprof.consts._ENV.DOMAIN_COPY, opt)
    local hip_data = traces_data:get(ratelprof.consts._ENV.DOMAIN_HIP, opt)
    local hsa_data = traces_data:get(ratelprof.consts._ENV.DOMAIN_HSA, opt)

    if next(hsa_data) ~= nil then
        return {skip = "The report could not be analyzed because it contains HSA data. This version doesn't support this analysis while HSA traces are present."}
    end

    if next(cpy_data) == nil then
        return {skip = "The report could not be analyzed because it does not contain the required GPU data."}
    end
    
    if next(hip_data) == nil then
        return {skip = "The report could not be analyzed because it does not contain the required HIP API data."}
    end
    
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
                local first_start = group[1].start
                local last_stop   = first_start + group[1].dur
                local size = 0
                for _, gpuCpy in ipairs(group) do
                    local gpu_start = gpuCpy.start
                    local gpu_stop  = gpu_start + gpuCpy.dur
                    if gpu_start < first_start then first_start = gpu_start end
                    if gpu_stop > last_stop    then last_stop   = gpu_stop end
                    size = size + gpuCpy.args.size
                end
                local gpuCpy = {
                    start = first_start,
                    stop  = last_stop,
                    size = size,
                    src_type = group[1].args.src_type,
                    dst_type = group[1].args.dst_type
                }
                if is_synchronized(gpuCpy, corr_hip_trace) then
                    table.insert(data, {
                        tostring(corr_id),
                        hip_cpy,
                        tostring(corr_hip_trace.pid),
                        tostring(corr_hip_trace.tid),
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

    local msg = ratelprof.consts._ALL_RULES_REPORT[report_id].desc
    local speedup_factor = 1

    if #data == 0 then 
        local no_advice_msg = "\nThere were no problems detected related to asynchronous memcpy operations.\n"
        msg = msg .. no_advice_msg
    else

        local app_duration = traces_data:get_app_dur()

        speedup_factor = compute_async_copy_speedup(data, app_duration)

        local advice_msg = [[ 
The following memory transfers are synchronized with their corresponding HIP asynchronous memory copy trace.
It appears that the transferred memory is either using PAGEABLE memory or is not large enough to be processed asynchronously.

This correspond to ]]..string.format("%.2f", (((#data)/nb_api_cpy)*100))..[[% of your hipMemcpy*Async operations.

Suggestion: If applicable, use PINNED memory instead by using hipHostMalloc to allocate your host side memory.
Your application might speed up by ]] .. string.format("x%.3f.\n\n", speedup_factor).."\n"


        table.sort(data, function(a, b)
            return a[7] < b[7]
        end)

        msg = msg .. advice_msg
    end


    return {
        NAME = "Host/Device Async Memcpy",
        TYPE = "Analyze",
        HEADER = {
            "API ID",
            "API Name",
            "PID",
            "TID",
            "Operation",
            "Size (B)",
            "CPU Duration (ns)",
            "GPU Duration (ns)"
        },
        DATA = data,
        MSG = msg,
        speedup = speedup_factor
    }
end