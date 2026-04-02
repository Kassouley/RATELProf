-- Report.lua
local Report = {}
Report.__index = Report

-- Available formats and their extensions
local format_extensions = {
    column  = "txt",
    table   = "txt",
    csv     = "csv",
    tsv     = "tsv",
    json    = "json"
}

Report.format_extensions = format_extensions

local default_number_notation = {
    json = "raw",
    column = "thousands-separator",
    table = "thousands-separator",
    csv = "scientific",
    tsv = "scientific"
}

-- Constructor: Initialize a new Report object
function Report:new(report_id, report_opt, output, format, disable_print)
    local instance = setmetatable({}, self)

    instance.report_id  = report_id
    instance.opt        = report_opt
    instance.output     = output
    instance.format     = format
    instance.NAME       = "<Not Available>"
    instance.TYPE       = "<Not Available>"
    instance.HEADER     = nil
    instance.REQUIRED_DOMAIN = nil
    instance.disable_print = disable_print or false
    instance.generated = {}

    return instance
end

local function get_per_rank_suffix(per_data)
    if not per_data then return "" end

    local order = {"rank", "gpu_id", "pid"}
    local parts = {}

    for _, key in ipairs(order) do
        if per_data[key] ~= nil then
            local nparts = #parts
            parts[nparts+1] = key
            parts[nparts+2] = tostring(per_data[key])
        end
    end

    return "_" .. table.concat(parts, "_")
end

function Report:get_output(rprofrep, per_data)
    local id     = self.report_id
    local format = self.format
    local output = self.output

    if output == "-" or output == "_" or output:sub(1, 1) == "@" then
        return output
    end

    local format_extension = format_extensions[format]

    local report_wo_ext
    local reports_filename = rprofrep:get_reports_filename()
    if #reports_filename == 1 then
        report_wo_ext = ratelprof.fs.remove_extension(reports_filename[1])
    else
        report_wo_ext = "aggregated_report"
    end

    -- If output is a directory (end with /) 
    -- then keep basename as output .. report_wo_ext
    if string.sub(output, -1) == "/" then
        output = output .. report_wo_ext
    end
    
    local basename = output == "." and report_wo_ext or output
    local suffix = get_per_rank_suffix(per_data)
    self.filename = string.format("%s_%s%s.%s", basename, id, suffix, format_extension)

    return self.filename
end


function Report:sort_data()
    local sort_by = self.SORT_BY
    if sort_by then
        local sort_dir = sort_by[1]
        local sort_idx = sort_by[2]
        if sort_dir == "asc" then
            table.sort(self.data, function(a, b) return a[sort_idx] > b[sort_idx] end)
        else
            table.sort(self.data, function(a, b) return a[sort_idx] < b[sort_idx] end)
        end
    end
end

function Report:insert_header()
    if self.HEADER then
        table.insert(self.data, 1, self.HEADER)
    end
end

function Report:process(rprofrep, output, user_args)
    local show_print = output ~= "_" and not self.disable_print

    -- Print header message
    Message:print_if(show_print, string.format("** %s %s (%s)%s%s:\n",
        self.NAME, self.TYPE, self.report_id, output == "-" and "" or " into '" .. output .. "'",
    user_args and " for " .. ratelprof.utils.label_unit_with_rank(user_args, true) or ""))

    -- Print "message" if exists
    if self.MESSAGE then
        Message:print_if(show_print, self.MESSAGE)
    end

    -- If no data only print "skip message" if no message was set then return
    local data = self.data
    if not data or #data == 0 then
        if not self.MESSAGE then
            Message:print_if(show_print, string.format(
                "SKIPPED: '%s' does not contain the required data.\n",
                rprofrep:get_reports_filename_str()))
        end
        return false
    end

    -- Sort data
    self:sort_data()

    -- Add header to array
    self:insert_header()

    -- Data is ready to be generated
    return true
end

function Report:set_generated(output, user_args, skip)
    table.insert(self.generated, {
        output = output,
        filename = self.filename,
        user_args = user_args,
        skip = skip
    })
end

function Report:generate(rprofrep, max_lines, max_col_width, notation, user_args)
    local output = self:get_output(rprofrep, user_args)
    if output == "_" then self.data = nil return end

    local skipped = not self:process(rprofrep, output, user_args)
    self:set_generated(output, user_args, skipped)
    if skipped then return false end

    local format = self.format

    if max_lines ~= "all" then
        max_lines = tonumber(max_lines) or (output == "-" and 50 or "all")
    end
    self.max_lines     = max_lines
    self.max_col_width = math.min(tonumber(max_col_width) or 32, 99)
    self.notation      = notation or default_number_notation[format]

    local data_size = #self.data
    local is_all_data_shown = max_lines == "all" or data_size < max_lines
    local ndata = is_all_data_shown and data_size or max_lines
    self.shown_data_len = ndata

    local stream = self:get_output_stream(output)

    stream:write(self:get_formatted_data(format))
    if stream ~= io.stdout then
        stream:close()
    end

    if not is_all_data_shown and (format_extensions[format] == "txt" or output == "-") then
        Message:printf(
            "(%d lines has been truncated for visibility, please use option --max-lines or export to a file)",
            data_size - ndata)
    end

    Message:print_if(output == "-", "\n")

    self.data = nil -- Free memory after generation
end

function Report:get_output_stream(output)
    local out    = nil
    if output == "-" then
        out = io.stdout

    elseif output == "_" then
        out = io.open("/dev/null", "w")
        if not out then error("Failed to open null device") end

    elseif output:sub(1, 1) == "@" then
        local command = output:sub(2)
        out = io.popen(command, "w")
        if not out then error("Failed to popen command: " .. command) end
    else
        out = io.open(output, "w")
        if not out then error("Failed to open file: " .. output) end
    end
    return out
end

function Report:get_formatted_data(format)
    if format == "csv" then
        return self:toCSV()
    elseif format == "tsv" then
        return self:toTSV()
    elseif format == "table" then
        return self:toTable()
    elseif format == "json" then
        return self:toJSON()
    else
        return self:toColumn()
    end
end

local function get_engineering_notation(n)
    local function log10(x)
        return math.log(x) / math.log(10)
    end
    if n == 0 then
        return "0"
    end

    local exponent = math.floor(log10(math.abs(n)) / 3) * 3
    local scaled = n / (10 ^ exponent)

    local formatted_scaled = string.format("%.3f", scaled)

    formatted_scaled = formatted_scaled:gsub("(%..-)[0]+$", "%1")
    formatted_scaled = formatted_scaled:gsub("%.$", "")

    return formatted_scaled .. "e" .. tostring(exponent)
end

local function get_raw_number(n)
    return tonumber(n)
end

local function get_scientific_number(n)
    return string.format("%.3e", n)
end

local function get_separator_number(n)
    local int_part = math.floor(n)
    local num_digits_before = #tostring(int_part)

    -- Want to keep ~6 significant digits total
    local decimals = 6 - num_digits_before
    if decimals < 0 then decimals = 0 end
    -- Format with dynamic decimals
    local s = string.format("%." .. decimals .. "f", n)

    -- Remove trailing zeros and dot if needed
    s = s:gsub("(%..-)[0]+$", "%1")
    s = s:gsub("%.$", "")

    -- Split integer and fractional parts
    local before, after = s:match("^(%-?%d+)(%.?.*)$")
    -- Add thousand separators (.)
    before = before:reverse():gsub("(%d%d%d)", "%1,"):reverse()
    -- Remove leading dot if added at the start
    if before:sub(1,1) == "," then
        before = before:sub(2)
    end

    return before .. after
end

local get_notation_number = {
    ["raw"] = get_raw_number,
    ["scientific"] = get_scientific_number,
    ["engineering"] = get_engineering_notation,
    ["thousands-separator"] = get_separator_number
}

function Report:__get_notation_number(item)
    local notation = self.notation or "raw"
    local getter = get_notation_number[notation]
    if getter then return getter(item)
    else error(notation.." is not a valid notation") end
end

function Report:__get_formatted_item(item, width, string_safe)
    local formatted_item = nil
    if type(item) == "number" then
        formatted_item = string.format("%"..width.."s", self:__get_notation_number(item))
    else
        if string_safe then
            item = '"'.. tostring(item):gsub('"', '').. '"'
        end
        formatted_item = string.format("%-"..width.."s", tostring(item))
    end
    if width ~= 1 and #formatted_item > width then
        formatted_item = formatted_item:sub(1, width - 3) .. "..."
    end
    return formatted_item
end

function Report:__calculate_column_widths()
    local columnWidths = {}
    local formatted_item = ""
    local data      = self.data
    local max_width = self.max_col_width
    for i = 1, self.shown_data_len do
        for j = 1, #data[i] do
            local item = data[i][j]
            if type(item) == "number" then
                formatted_item = tostring(self:__get_notation_number(item))
            else
                formatted_item = tostring(item)
            end
            local len = #formatted_item > max_width and max_width or #formatted_item
            columnWidths[j] = math.max(columnWidths[j] or 0, len)
        end
    end
    return columnWidths
end

function Report:__format_data(separator, bsep, msep, asep, columnWidths, line_sep, string_safe)
    local result = {}
    local widths = columnWidths or {}
    local data = self.data
    line_sep = line_sep or "\n"
    for i = 1, self.shown_data_len do
        local line = {}
        line[#line + 1] = bsep
        local ncol = #data[i]
        for j = 1, ncol do
            line[#line + 1] = self:__get_formatted_item(data[i][j], widths[j] or 1, string_safe) .. (ncol == j and "" or msep)
        end
        line[#line + 1] = asep
        result[#result + 1] = table.concat(line)
        
        if i == 1 and self.HEADER then
            result[#result + 1] = separator
        end
    end

    return table.concat(result, line_sep)
end

function Report:toTable()
    local columnWidths = self:__calculate_column_widths()

    local function get_separator()
        local separator = {}
        for j = 1, #columnWidths do
            separator[#separator + 1] = "+"
            separator[#separator + 1] = string.rep("-", columnWidths[j] + 2)
        end
        separator[#separator + 1] = "+"
        return table.concat(separator)
    end
    local separator = get_separator()
    local content = self:__format_data(separator, "| ", " | ", " |", columnWidths)
    return separator .. "\n" .. content .. separator .. "\n"
end

function Report:toColumn()
    local columnWidths = self:__calculate_column_widths()

    local function get_separator()
        local separator_line = {}
        for j = 1, #columnWidths do
            separator_line[#separator_line + 1] = string.rep("-", columnWidths[j])
        end
        return table.concat(separator_line, " ")
    end
    local separator = get_separator()
    local content = self:__format_data(separator, nil, " ", nil, columnWidths)
    return content
end

function Report:toCSV(sep)
    sep = sep or ","
    local content = self:__format_data(nil, nil, sep, nil, nil)
    return content
end

function Report:toTSV()
    return self:toCSV(";")
end

function Report:toJSON()
    local result = {}
    local data = self.data
    local shown_len = self.shown_data_len

    local function format_row(row, padded)
        local line = {}
        line[#line + 1] = '['
        for j = 1, #row do
            local item = row[j]
            if j == 1 and padded then
                item = item:gsub("^%s+", "")
            end
            line[#line + 1] = self:__get_formatted_item(item, 1, true)
            if j < #row then line[#line + 1] = ", " end
        end
        line[#line + 1] = ']'
        return table.concat(line)
    end

    local i = 1
    while i <= shown_len do
        local row = data[i]
        local padded = string.sub(row[1], 1, 1) == " "
        if padded then
            -- start a group
            local group = {}
            while i <= shown_len and string.sub(data[i][1], 1, 1) == " " do
                group[#group + 1] = "\t\t" .. format_row(data[i], true)
                i = i + 1
            end
            -- add group with indentation
            result[#result + 1] = "\t[\n" .. table.concat(group, ",\n") .. "\n\t]"
        else
            result[#result + 1] = "\t" .. format_row(row, false)
            i = i + 1
        end
    end

    return "[\n" .. table.concat(result, ",\n") .. "\n]"
end

return Report