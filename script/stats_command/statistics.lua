require("string_ext")

local statistics = {}

local function get_nested_value(tbl, path)
    local keys = path:split(".")
    local value = tbl
    for _, key in ipairs(keys) do
        local index = tonumber(key)
        if index then
            value = value[index]
        else
            value = value[key]
        end
        if value == nil then
            break
        end
    end
    return value
end

local function get_key_fom_cols(trace, key_cols)
    local key_str = ""
    local key_tab = {}
    for _, col in ipairs(key_cols) do
        key_value = get_nested_value(trace, col)
        key_str = key_str.."_"..tostring(key_value)
        table.insert(key_tab, key_value)
    end
    return key_tab, key_str
end

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
    return {percent=percent, total=total, count=count, avg=avg, med=med, min=min, max=max, stdDev=stdDev}
end

function statistics.get_output_summary(data, key_cols, get_stat_metric, timeunit)
    local output_data = {}
    local total_metric = 0
    local entries = {}

    for _, trace in ipairs(data) do
        local key, key_str = get_key_fom_cols(trace, key_cols)
        local metric = get_stat_metric(trace, timeunit)

        if not entries[key_str] then
            entries[key_str] = {key = key, count = 0, total = 0, values = {}}
        end

        local entry = entries[key_str]
        entry.count = entry.count + 1
        entry.total = entry.total + metric
        table.insert(entry.values, metric)
        total_metric = total_metric + metric
    end

    for _, entry in pairs(entries) do
        local stats = compute_stats(entry, total_metric)
        local statistic_table = {
            string.format("%.2f", stats.percent),
            stats.total,
            stats.count,
            stats.avg,
            stats.med,
            stats.min,
            stats.max,
            string.format("%.2f", stats.stdDev)
        }
        
        table.move(entry.key, 1, #entry.key, #statistic_table + 1, statistic_table)
        table.insert(output_data, statistic_table)
    end

    return output_data
end


return statistics
