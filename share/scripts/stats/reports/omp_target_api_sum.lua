return function(all_traces, attribute, opt)
    attribute.report_name = "OMP TARGET RTL API Summary"

    local raw_data = stats:fetch_traces(all_traces, "RATELPROF_DOMAIN_OMP_TGT_RTL", opt) or {}

    attribute.data = stats:process_api_raw_data_for_sum_report(raw_data, opt.timeunit)
    attribute.data_size = #raw_data

    Report.Report:new(attribute):generate(opt)
end