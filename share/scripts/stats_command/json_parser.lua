local Report = require("Report")
local common = require("common")

local parser = {}

-- Cache table to store previously fetched traces
local trace_cache = {}

-- Optimized fetch_traces function
local function fetch_traces(report, domain_string)
    -- Check if traces for this domain_string are already cached
    if trace_cache[domain_string] then
        return trace_cache[domain_string]
    end

    -- If not cached, fetch and store in cache
    local ret = {}
    for _, trace in ipairs(report.trace_data.trace_events) do
        if report.trace_data.domain_id[tostring(trace.d)].name == domain_string
                and (not report.is_only_main or report.trace_data.phase_id[tostring(trace.p)] == "MAIN_PHASE") then
            
            if domain_string == "KERNEL_DISPATCH" then
                if report.is_trunc then
                    trace.args.kernel_name = common.execute_command("c++filt --no-params ".. trace.args.kernel_name)
                elseif not report.is_mangled then
                    trace.args.kernel_name = common.execute_command("c++filt ".. trace.args.kernel_name)
                end
            end
            table.insert(ret, trace)
        end
    end

    -- Cache the fetched traces
    trace_cache[domain_string] = ret
    return ret
end

function parser.get_hsa_traces(report)
    return fetch_traces(report, "RATELPROF_DOMAIN_HSA")
end

function parser.get_hip_traces(report)
    return fetch_traces(report, "RATELPROF_DOMAIN_HIP")
end

function parser.get_omp_traces(report)
    return fetch_traces(report, "RATELPROF_DOMAIN_OMP_TGT")
end

function parser.get_omp_target_traces(report)
    return fetch_traces(report, "RATELPROF_DOMAIN_OMP_TGT_RTL")
end

function parser.get_gpu_mem_traces(report)
    return fetch_traces(report, "MEMORY_COPY")
end

function parser.get_gpu_kern_traces(report)
    return fetch_traces(report, "KERNEL_DISPATCH")
end

function parser.get_gpu_barrieror_traces(report)
    return fetch_traces(report, "BARRIER_OR_DISPATCH")
end

function parser.get_gpu_barrierand_traces(report)
    return fetch_traces(report, "BARRIER_AND_DISPATCH")
end

return parser
