local stats_helper  = require ("utils.stats_helper")

return function(traces_data, report_obj, opt)
    report_obj:set_name("HSA API")
    report_obj:set_type("Traces")

    stats_helper.process_api_raw_data_for_trace_report(
        report_obj, traces_data, ratelprof.consts._ENV.DOMAIN_HSA, opt)
end