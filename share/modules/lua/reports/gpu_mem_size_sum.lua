local stats_helper  = require ("utils.stats_helper")

return function(traces_data, _, opt)
    local NAME = "GPU MemOps"
    local TYPE = "Summary (by Size)"

    local sizeunit = "B"

    local HEADER = {
        "Total (%)",
        "Total ("..sizeunit..")",
        "Count",
        "Avg ("..sizeunit..")",
        "Med ("..sizeunit..")",
        "Min ("..sizeunit..")",
        "Max ("..sizeunit..")",
        "StdDev ("..sizeunit..")",
        "Operation"
    }

    local memory_data = traces_data:get(ratelprof.consts._ENV.DOMAIN_COPY)

    local total_metrics = 0
    local entries = {}

    for _, trace in pairs(memory_data) do
        local key_str = ratelprof.utils.get_copy_name(trace.args.src_type, trace.args.dst_type)
        local metric = trace.args.size

        local entry = entries[key_str]

        if not entry then
            entry = {
                key_str = key_str,
                count = 0,
                total = 0,
                sum_of_squares = 0,
                values = {}}
            entries[key_str] = entry
        end

        entry.count          = entry.count + 1
        entry.total          = entry.total + metric
        entry.sum_of_squares = entry.sum_of_squares + (metric * metric)
        entry.values[#entry.values + 1] = metric
        total_metrics = total_metrics + metric
    end

    local DATA = {}

    for _, entry in pairs(entries) do
        local statistic_table = stats_helper.compute_stats(entry, total_metrics)
        table.remove(statistic_table, 1)
        table.insert(statistic_table, entry.key_str)
        table.insert(DATA, statistic_table)
    end


    table.sort(DATA, function(a, b)
        return tonumber(a[2]) > tonumber(b[2])
    end)

    return {NAME = NAME, TYPE = TYPE, HEADER = HEADER, DATA = DATA, total_bytes = total_metrics}
end