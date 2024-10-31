local Report = require("Report")
local report_common = require("report_common")
local common = require("common")
local statistics = require("statistics")

local function get_entry_key_tab1(trace)
    return { "MemoryOperation", common.get_copy_name(trace) }
end

local function get_entry_key_tab2(trace)
    return { "KernelDispatch", trace.args.kernel_name }
end

function Report:get_report_name()
    return "GPU Summary"
end

function Report:get_headers()
    return {
        "Time (%)", 
        "Total Time ("..self.timeunit..")", 
        "Instances", 
        "Avg ("..self.timeunit..")", 
        "Med ("..self.timeunit..")", 
        "Min ("..self.timeunit..")", 
        "Max ("..self.timeunit..")", 
        "StdDev ("..self.timeunit..")",
        "Category",
        "Operation" 
    }
end

function Report:get_data()
    local kern_traces = self:get_gpu_kern_traces()
    local mem_traces = self:get_gpu_mem_traces()

    local kern_entries, kern_total_metric = statistics.get_entries(kern_traces, get_entry_key_tab2, report_common.get_duration, self.timeunit)
    local mem_entries, mem_total_metric = statistics.get_entries(mem_traces, get_entry_key_tab1, report_common.get_duration, self.timeunit)
    local gpu_entries = common.merge_tab(kern_entries, mem_entries)
    local gpu_total_metric = kern_total_metric + mem_total_metric

    local data = statistics.get_output_summary(gpu_entries, gpu_total_metric)
    print(#data)
    
    table.sort(data, function(a, b)
        return tonumber(a[2]) > tonumber(b[2])
    end)
    return data
end