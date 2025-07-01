local stats_helper = require ("utils.stats_helper")

return function(traces_data, _, opt)
    local data, header = stats_helper.process_api_raw_data_for_sum_report(
         traces_data, ratelprof.consts._ENV.DOMAIN_OMP_TGT_RTL, opt)

    return {
        NAME = "OpenMP Target Runtime Layer API",
        TYPE = "Summary",
        DATA = data,
        HEADER = header
    }
end