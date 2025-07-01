local stats_helper  = require ("utils.stats_helper")

return function(traces_data, _, opt)
    local data, header = stats_helper.process_api_raw_data_for_trace_report(
         traces_data, ratelprof.consts._ENV.DOMAIN_HSA, opt)

    return {
        NAME = "HSA API",
        TYPE = "Traces",
        DATA = data,
        HEADER = header
    }
end