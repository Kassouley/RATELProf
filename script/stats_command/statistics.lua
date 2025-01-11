require("string_ext")

local statistics = {}

local function compute_stats(entry, total_metric)
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
    local sum = 0
    local sumDeviation = 0
    for _, value in ipairs(values) do
        sum = sum + value
    end
    local avg = sum / count

    for _, value in ipairs(values) do
        sumDeviation = sumDeviation + (value - avg) ^ 2
    end
    local stdDev = math.sqrt(sumDeviation / count)

    -- Compute percentage
    local percent = (total / total_metric) * 100

    -- Round average to the nearest integer
    avg = math.floor(avg + 0.5)
    return {string.format("%.2f", percent), total, count, avg, med, min, max, string.format("%.2f", stdDev)}
end


function statistics.get_entries(data, get_entry_key_tab, get_stat_metric, timeunit)
    local total_metric = 0
    local entries = {}
    for _, trace in ipairs(data) do
        local key_tab = get_entry_key_tab(trace)
        local key_str = table.concat(key_tab, "#__#")
        local metric = get_stat_metric(trace, timeunit)

        if not entries[key_str] then
            entries[key_str] = {key_tab = key_tab, count = 0, total = 0, values = {}}
        end

        local entry = entries[key_str]
        entry.count = entry.count + 1
        entry.total = entry.total + metric
        table.insert(entry.values, metric)
        total_metric = total_metric + metric
    end
    return entries, total_metric
end

function statistics.get_output_summary(entries, total_metric)
    local output_data = {}

    for _, entry in pairs(entries) do
        local statistic_table = compute_stats(entry, total_metric)
        for i = 1, #entry.key_tab do
            table.insert(statistic_table, entry.key_tab[i])
        end
        -- table.move(entry.key_tab, 1, #entry.key_tab, #statistic_table + 1, statistic_table)
        table.insert(output_data, statistic_table)
    end

    return output_data
end


return statistics
