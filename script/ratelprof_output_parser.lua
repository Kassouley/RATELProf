local data_parser = {}

local common = require("common")


function data_parser.load_data_from(__input_path__)
    if common.has_extension(__input_path__, ".json") then
        return common.load_json(__input_path__)
    else
        error ("Load data from '" .. __input_path__ .. "', extension not supported")
    end
end

function data_parser.get_api_all_data_from(loaded_data)
    return loaded_data.HIP_TRACE
end

function data_parser.get_api_hip_data_from(loaded_data)
    return loaded_data.HIP_TRACE
end

function data_parser.get_gpu_all_data_from(loaded_data)
    return loaded_data.GPU_TRACE
end

function data_parser.get_gpu_mem_data_from(loaded_data)
    local arrays = {}

    for _, tbl in pairs(loaded_data.GPU_TRACE) do
        if tbl["domain"] == 1 then
            table.insert(arrays, tbl)
        end
    end

    return arrays
end

function data_parser.get_gpu_kern_data_from(loaded_data)
    local arrays = {}

    for _, tbl in pairs(loaded_data.GPU_TRACE) do
        if tbl["domain"] == 0 then
            table.insert(arrays, tbl)
        end
    end

    return arrays
end

function data_parser.get_correlated_data_from(gpu_traces, api_traces)
    local correlated_data = {}

    local gpu_trace_map = {}
    for _, trace in ipairs(gpu_traces) do
        gpu_trace_map[trace.corr_id] = trace
    end

    local api_trace_map = {}
    for _, trace in ipairs(api_traces) do
        api_trace_map[trace.corr_id] = trace
    end

    for corr_id, gpu_trace in pairs(gpu_trace_map) do
        local api_trace = api_trace_map[corr_id]
        if api_trace then
            table.insert(correlated_data, {gpu_data = gpu_trace, api_data = api_trace})
        end
    end
    return correlated_data
end


return data_parser
