local stats_helper  = require ("utils.stats_helper")

return function(traces_data, report_obj, opt)
    report_obj:set_name("OpenMP Target Runtime Layer API")
    report_obj:set_type("Summary")

    stats_helper.process_api_raw_data_for_sum_report(
        report_obj, traces_data, ratelprof.consts._ENV.DOMAIN_OMP_TGT_RTL, opt)
end