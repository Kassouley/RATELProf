local report_helper = require("utils.report_helper")

local statistics = {}

function statistics.compute_stats(entry, total_metric, global_interval_time)
    local values = entry.values
    local count = entry.count
    local total = entry.total
    local api_active_time = entry.api_active_time

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
    local local_percent  = string.format("%.2f", (total / total_metric)  * 100)

    local global_percent = nil
    if api_active_time and global_interval_time then
        api_active_time = api_active_time + (entry.cur_stop - entry.cur_start)
        global_percent = string.format("%.2f", (api_active_time / global_interval_time) * 100)
    end
    -- Round average to the nearest integer
    avg = math.floor(avg + 0.5)
    return {
        global_percent,
        local_percent,
        total,
        count,
        avg,
        med,
        min,
        max,
        stdDev
    }
end


function statistics.get_entry(entries, trace, get_entry_key_tab, metrics, opt, total_metric)
    local key_tab = get_entry_key_tab(trace, opt)
    local key_str = string.format("%s", key_tab[1])
    for i = 2, #key_tab do
        key_str = key_str .. "::" .. key_tab[i]
    end
    local start = table.get_value(trace, metrics[1])
    local stop = table.get_value(trace, metrics[2])
    local metric = report_helper.get_duration(stop - start, opt.timeunit)

    local entry = entries[key_str]

    if not entry then
        entry = {
            key_tab = key_tab, 
            count = 0,
            total = 0,
            sum_of_squares = 0,
            api_active_time = 0,
            cur_start = nil,
            cur_stop = nil,
            values = {}}
        entries[key_str] = entry
    end

    --
    if not entry.cur_start then
        entry.cur_start = start
        entry.cur_stop = stop
    elseif start <= entry.cur_stop then
        if stop > entry.cur_stop then
            entry.cur_stop = stop
        end
    else
        entry.api_active_time = entry.api_active_time + (entry.cur_stop - entry.cur_start)
        entry.cur_start = start
        entry.cur_stop = stop
    end
    --

    entry.count          = entry.count + 1
    entry.total          = entry.total + metric
    entry.sum_of_squares = entry.sum_of_squares + (metric * metric)
    entry.values[#entry.values + 1] = metric
    total_metric = total_metric + metric
    
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

function statistics.get_output_summary(entries, total_metric, global_interval_time)
    local output_data = {}

    for _, entry in pairs(entries) do
        local statistic_table = statistics.compute_stats(entry, total_metric, global_interval_time)
        for i = 1, #entry.key_tab do
            table.insert(statistic_table, entry.key_tab[i])
        end
        table.insert(output_data, statistic_table)
    end

    return output_data
end

return statistics