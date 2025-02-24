return function(all_traces, attribute, opt)
    attribute.report_name = "HIP API Summary"

    local raw_data = report_common.fetch_traces(all_traces, "RATELPROF_DOMAIN_HIP", opt) or {}

    attribute.data = report_common.process_api_raw_data_for_sum_report(raw_data, opt.timeunit)
    attribute.data_size = #raw_data

    Report:new(attribute):generate(opt)
end