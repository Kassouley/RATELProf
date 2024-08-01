local statistics = {}
local common = require("common")

local function get_key_fom_cols(trace, paths)
    local key_str = ""
    local key_tab = {}
    for _, path in ipairs(paths) do
        key_value = common.getValueAtPath(trace, path)
        key_str = key_str.."_"..tostring(key_value)
        table.insert(key_tab, key_value)
    end
    return key_tab, key_str
end

local function compute_stats(entry, total_metric)
    table.sort(entry.values)
    local total = entry.total
    local count = entry.count
    local med
    local middleIndex = math.floor((count + 1) / 2)
    
    if count % 2 == 0 then
        med = (entry.values[middleIndex] + entry.values[middleIndex + 1]) / 2
    else
        med = entry.values[middleIndex]
    end
    
    local min = entry.values[1]
    local max = entry.values[count]

    local sumDeviation = 0
    local avg = total / count
    for _, value in ipairs(entry.values) do
        sumDeviation = sumDeviation + (value - avg)^2
    end
    local stdDev = math.sqrt(sumDeviation / count)

    avg = math.floor(avg)
    local percent = (total / total_metric) * 100

    return percent, total, count, avg, med, min, max, stdDev
end


function statistics.get_output_summary(data, key_cols, get_stat_metric)
    local output_data = {}

    local total_metric = 0
    local entries = {}

    for _, trace in ipairs(data) do
        local key, key_str = get_key_fom_cols(trace, key_cols)
        local metric = get_stat_metric(trace)

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
        local percent, total, count, avg, med, min, max, stdDev = compute_stats(entry, total_metric)
        local statistic_table = {
            string.format("%.2f", percent), -- 1
            total, -- 2
            count, -- 3
            avg, -- 4
            med, -- 5
            min, -- 6
            max, -- 7
            stdDev -- 8
        }
        table.move(entry.key, 1, #entry.key, #statistic_table + 1, statistic_table)
        table.insert(output_data, statistic_table)
    end

    return output_data
end

return statistics
