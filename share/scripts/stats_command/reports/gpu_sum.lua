local Report = require("Report")
local report_common = require("report_common")
local common = require("common")
local statistics = require("statistics")

local function get_entry_key_tab1(trace)
    return { "MemoryOperation", report_common.get_copy_name(trace) }
end

local function get_entry_key_tab2(trace)
    return { "KernelDispatch", trace.args.kernel_name }
end

local function get_entry_key_tab3(trace)
    return { "BarrierDispatch", "BarrierAnd" }
end

local function get_entry_key_tab4(trace)
    return  { "BarrierDispatch", "BarrierOr" }
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
    local kern_traces = report_common.get_gpu_kern_traces(self)
    local mem_traces = report_common.get_gpu_mem_traces(self)
    local barrand_traces = report_common.get_gpu_barrierand_traces(self)
    local barror_traces = report_common.get_gpu_barrieror_traces(self)

    local mem_entries, mem_total_metric = statistics.get_entries(mem_traces, get_entry_key_tab1, report_common.get_duration, self.timeunit)
    local kern_entries, kern_total_metric = statistics.get_entries(kern_traces, get_entry_key_tab2, report_common.get_duration, self.timeunit)
    local barrand_entries, barrand_total_metric = statistics.get_entries(barrand_traces, get_entry_key_tab3, report_common.get_duration, self.timeunit)
    local barror_entries, barror_total_metric = statistics.get_entries(barror_traces, get_entry_key_tab4, report_common.get_duration, self.timeunit)

    local gpu_entries = {}
    for i, t in ipairs({kern_entries, mem_entries, barrand_entries, barror_entries}) do
        for j, value in pairs(t) do
            table.insert(gpu_entries, value)
        end
    end
    local gpu_total_metric = kern_total_metric + mem_total_metric + barrand_total_metric + barror_total_metric

    local data = statistics.get_output_summary(gpu_entries, gpu_total_metric)
    
    table.sort(data, function(a, b)
        return tonumber(a[2]) > tonumber(b[2])
    end)
    return data
end