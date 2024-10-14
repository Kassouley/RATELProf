local Report = require("Report")

function Report:get_hsa_traces()
    return self.trace_data.traceEvents.hsaTraces
end

function Report:get_hip_traces()
    return self.trace_data.traceEvents.hipTraces
end

function Report:get_gpu_traces()
    return self.trace_data.traceEvents.gpuTraces
end

function Report:get_gpu_mem_traces()
    local r = {}
    for _, t in pairs(self:get_gpu_traces()) do
        if t["operation"] == 1 then
            table.insert(r, t)
        end
    end
    return r
end

function Report:get_gpu_kern_traces()
    local r = {}
    for _, t in pairs(self:get_gpu_traces()) do
        if t["operation"] == 2 then
            table.insert(r, t)
        end
    end
    return r
end

