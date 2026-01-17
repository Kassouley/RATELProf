-- summarize_helper.lua

local summarize_helper = {}

local NCHAR_SEPARATOR = 72
summarize_helper.NCHAR_SEPARATOR = NCHAR_SEPARATOR


local function print_separator(sep_char)
    sep_char = sep_char or "="
    print((sep_char):rep(NCHAR_SEPARATOR))
end


function summarize_helper.format_gpu_time(time, app_time)
    local percentage = (time / app_time) * 100
    local time_s = ratelprof.convert.time(time, "ns", "sec")
    return string.format("%.2f %% (%.3f s) of App Time", percentage, time_s)
end


function summarize_helper.format_bytes(bytes)
    if not bytes or bytes == "N/A" then
        return 'N/A'
    end
    local units = {"B", "KB", "MB", "GB", "TB"}
    local unit_index = 1

    while bytes >= 1024 and unit_index < #units do
        bytes = bytes / 1024
        unit_index = unit_index + 1
    end

    return string.format("%.3f %s", bytes, units[unit_index])
end


function summarize_helper.format_speedup(speedup)
    if speedup == "N/A" or speedup < 1 then
        return "N/A"
    else
        return string.format("%.3fx", speedup)
    end
end

function summarize_helper.format_percentage(percentage)
    if not percentage or percentage == "N/A" then
        return "N/A"
    end
    return string.format("%.2f", percentage)
end


function summarize_helper.get_max_label_len(data)
    local max_len = 0
    local function scan(list)
        for _, v in ipairs(list) do
            if #v.label > max_len then max_len = #v.label end
            if v.subvalue then scan(v.subvalue) end
        end
    end
    scan(data)
    return max_len
end


local function print_data(list, depth, max_len)
    depth = depth or 0
    local indent = ("    "):rep(depth)

    for i, v in ipairs(list) do
        local label = string.format("%-" .. max_len .. "s", indent .. v.label)
        print(label .. " : " .. (v.value or "N/A"))
        if v.subvalue then
            print_data(v.subvalue, depth + 1, max_len)
        end
        if depth == 0 and i < #list then
            print_separator("-")
        end
    end
end


function summarize_helper.print_report(title, data)
    local max_len = summarize_helper.get_max_label_len(data)
    print(title)
    print_separator()
    print_data(data, 0, max_len)
    print_separator()
end


return summarize_helper