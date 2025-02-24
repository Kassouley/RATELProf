-- Report.lua
local lfs = require ("utils.lfs")

local Report = {}
Report.__index = Report

-- Available formats and their extensions
local format_extensions = {
    column = "txt",
    table = "txt",
    csv = "csv",
    tsv = "tsv"
}

-- Constructor: Initialize a new Report object
function Report:new(attribute)
    if attribute == nil then return error("Report Constructor need attributes") end
    if attribute.report_id == nil then return error("Report Constructor need a report_id") end

    local instance = setmetatable({}, self)

    instance.trace_path = attribute.trace_path
    instance.report_id = attribute.report_id
    instance.report_name = attribute.report_name
    instance.report_path = attribute.report_path
    
    instance.data = attribute.data or {}
    instance.data_size = attribute.data_size or 0

    return instance
end

function Report:generate(opt)
    local output = opt.output
    local format = opt.format
    local timeunit = opt.timeunit
    local is_only_main = opt["only-main"]
    local is_trunc = opt.trunc
    local is_mangled = opt.mangled

    local filename = self:get_output_filename(output, format, self.trace_path)

    print(string.format(
        "\nProcessing '%s' with '%s'%s...\n",
        self.trace_path, self.report_path,
        (filename and (" to '" .. filename .. "'") or "")
    ))

    if self.data_size == 0 then
        print(string.format(
            "\nSKIPPED: '%s' does not contain %s data.\n",
            self.trace_path, self.report_name
        ))
        return
    end

    local stream = self:get_output_stream(output, filename)
    if output == "-" then
        print(string.format(
            "** %s (%s):\n",
            self.report_name, self.report_id
        ))
    end
    stream:write(self:get_formatted_data(format))
    if stream ~= io.stdout then
        stream:close()
    end

end

function Report:get_output_filename(output, format, input)
    if output == "-" or output:sub(1, 1) == "@" then
        return nil
    end

    local default_basename = lfs.remove_extension(input)
    local file_extension = format_extensions[format] or "txt"
    local basename = output == "." and default_basename or output

    return string.format("%s_%s.%s", basename, self.report_id, file_extension)
end

function Report:get_output_stream(output, filename)
    local out = nil
    if output == "-" then
        out = io.stdout
    elseif output:sub(1, 1) == "@" then
        local command = output:sub(2)
        out = io.popen(command, "w")
        if not out then error("Failed to execute command: " .. command) end
    else
        out = io.open(filename, "w")
        if not out then error("Failed to open file: " .. filename) end
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
    else
        return self:toColumn()
    end
end

function Report:toCSV(sep)
    sep = sep or ","
    local csv_formatted = ""
    for _, d in ipairs(self.data) do
        csv_formatted = csv_formatted..table.concat(d, sep).."\n"
    end
    return csv_formatted
end

function Report:toTSV()
    return self:toCSV(";")
end

local function calculateColumnWidths(data)
    local columnWidths = {}
    for i = 1, #data do
        for j = 1, #data[i] do
            local item = tostring(data[i][j])
            columnWidths[j] = math.max(columnWidths[j] or 0, #item)
        end
    end
    return columnWidths
end

function Report:toTable()
    local columnWidths = calculateColumnWidths(self.data)

    local function get_separator()
        local separator = {}
        for j = 1, #columnWidths do
            separator[#separator + 1] = "+"
            separator[#separator + 1] = string.rep("-", columnWidths[j] + 2)
        end
        separator[#separator + 1] = "+"
        return table.concat(separator)
    end

    local function get_row(row)
        local line = {}
        for j = 1, #row do
            local item = tostring(row[j])
            line[#line + 1] = "| " .. item .. string.rep(" ", columnWidths[j] - #item) .. " "
        end
        line[#line + 1] = "|"
        return table.concat(line)
    end

    local result = {}
    result[#result + 1] = get_separator()
    result[#result + 1] = get_row(self.data[1])
    result[#result + 1] = get_separator()

    for i = 2, #self.data do
        result[#result + 1] = get_row(self.data[i])
    end

    result[#result + 1] = get_separator()
    return table.concat(result, "\n") .. "\n"
end

function Report:toColumn()
    local columnWidths = calculateColumnWidths(self.data)

    local result = {}
    local first_line = {}
    local separator_line = {}

    for j = 1, #self.data[1] do
        local item = tostring(self.data[1][j])
        first_line[#first_line + 1] = item .. string.rep(" ", columnWidths[j] - #item)
        separator_line[#separator_line + 1] = string.rep("-", columnWidths[j])
    end

    result[#result + 1] = table.concat(first_line, " ")
    result[#result + 1] = table.concat(separator_line, " ")

    for i = 2, #self.data do
        local line = {}
        for j = 1, #self.data[i] do
            local item = tostring(self.data[i][j])
            line[#line + 1] = item .. string.rep(" ", columnWidths[j] - #item)
        end
        result[#result + 1] = table.concat(line, " ")
    end

    return table.concat(result, "\n") .. "\n"
end

return Report