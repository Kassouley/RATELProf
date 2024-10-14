local Report = require("Report")
local report_common = require("report_common")
local statistics = require("statistics")

function Report:get_report_name()
    return "HSA API Summary"
end

function Report:get_headers()
    return report_common.get_header_api_sum(self.timeunit)
end

function Report:get_data()
    local traces = self:get_hsa_traces()
    local key_tab = {report_common.key.name}
    local data = statistics.get_output_summary(traces, key_tab, report_common.get_duration, self.timeunit)
    data = report_common.get_sort_api_sum(data)
    return data
end