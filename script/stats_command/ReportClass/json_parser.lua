local common = require("common")
local Report = require("Report")

function Report:get_hsa_traces()
    return self.trace_data.traceEvents[common.domainLookup[common.HSA_DOMAIN]]
end

function Report:get_hip_traces()
    return self.trace_data.traceEvents[common.domainLookup[common.HIP_DOMAIN]]
end

function Report:get_gpu_mem_traces()
    return self.trace_data.traceEvents[common.domainLookup[common.MEMOP_DOMAIN]]
end

function Report:get_gpu_kern_traces()
    return self.trace_data.traceEvents[common.domainLookup[common.KERNOP_DOMAIN]]
end