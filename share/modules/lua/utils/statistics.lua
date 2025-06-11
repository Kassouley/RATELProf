local statistics = {}


function statistics.compute_stats(entry, total_metric, app_total_dur)
    local values = entry.values
    local count = entry.count
    local total = entry.total

    -- Sort the values if not already sorted
    table.sort(values)
    
    -- Compute median
    local middleIndex = math.floor((count + 1) / 2)
    local med
    if count % 2 == 0 then
        med = (values[middleIndex] + values[middleIndex + 1]) / 2
    else
        med = values[middleIndex]
    end
    
    -- Compute min and max
    local min = values[1]
    local max = values[count]

    -- Compute average and standard deviation
    local avg = total / count
    local variance = (entry.sum_of_squares / count) - (avg * avg)
    local stdDev = math.sqrt(math.max(variance, 0))

    -- Compute percentage
    local local_percent  = (total / total_metric)  * 100
    local global_percent = (total / app_total_dur) * 100

    -- Round average to the nearest integer
    avg = math.floor(avg + 0.5)
    return {
        string.format("%.2f", global_percent),
        string.format("%.2f", local_percent),
        total,
        count,
        avg,
        med,
        min,
        max,
        stdDev
    }
end

function statistics.get_entry(entries, trace, get_entry_key_tab, get_metric, opt, total_metric)
    if not opt.is_only_main or trace.p == 1 then
        local key_tab = get_entry_key_tab(trace, opt)
        local key_str = string.format("%s", key_tab[1])
        for i = 2, #key_tab do
            key_str = key_str .. "," .. key_tab[i]
        end
        local metric = get_metric(trace, opt)

        local entry = entries[key_str]

        if not entry then
            entry = {
                key_tab = key_tab, 
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
        total_metric = total_metric + metric
    end
    
    return total_metric
end


function statistics.get_entries(data, get_entry_key_tab, get_metric, opt)
    local total_metric = 0
    local entries = {}

    for _, trace in pairs(data) do
        total_metric = statistics.get_entry(entries, trace, get_entry_key_tab, get_metric, opt, total_metric)
    end
    return entries, total_metric
end

function statistics.get_output_summary(entries, total_metric, app_total_dur)
    local output_data = {}

    for _, entry in pairs(entries) do
        local statistic_table = statistics.compute_stats(entry, total_metric, app_total_dur)
        for i = 1, #entry.key_tab do
            table.insert(statistic_table, entry.key_tab[i])
        end
        table.insert(output_data, statistic_table)
    end

    return output_data
end

return statistics