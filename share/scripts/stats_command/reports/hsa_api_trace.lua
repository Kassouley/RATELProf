local Report = require("Report")
local report_common = require("report_common")

function Report:get_report_name()
    return "HSA API Traces"
end

function Report:get_headers()
    return report_common.get_header_api_trace(self.timeunit)
end

function Report:get_data()
    local traces = report_common.get_hsa_traces(self)
    local data = report_common.api_get_output_data(traces, self.timeunit)
    data = report_common.get_sort_api_trace(data)
    return data
end