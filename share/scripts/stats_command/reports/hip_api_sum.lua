local Report = require("Report")
local report_common = require("report_common")
local statistics = require("statistics")

local function get_entry_key_tab(trace)
    return { trace.name }
end

function Report:get_report_name()
    return "HIP API Summary"
end

function Report:get_headers()
    return report_common.get_header_api_sum(self.timeunit)
end

function Report:get_data()
    local traces = report_common.get_hip_traces(self)
    local entries, total_metrics = statistics.get_entries(traces, get_entry_key_tab, report_common.get_duration, self.timeunit)
    local data = statistics.get_output_summary(entries, total_metrics)
    data = report_common.get_sort_api_sum(data)
    return data
end