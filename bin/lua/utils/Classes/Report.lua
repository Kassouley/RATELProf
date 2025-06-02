-- Report.lua
local Report = {}
Report.__index = Report
Report.utils = {}

function Report.utils.execute_report(data, input_file, options_values, report_list, progress_enabled, progress_msg)
    local reports = options_values.reports or {}
    local outputs = options_values.outputs or {}
    local formats = options_values.formats or {}
    local nreports = #reports
    for i, report_id in ipairs(reports) do
        if progress_enabled then
            ratelprof.utils.print_progress(progress_msg, i-1, nreports)
        end

        local report_path = report_list.__default_report_path..report_id..".lua"
        if ratelprof.fs.exists(report_path) then
            local output = outputs[i] or outputs[#outputs]
            local output_format = formats[i] or formats[#formats] 
                                    or (output == "-" and "column" or "csv")

            local attribute = {
                format        = output_format,
                output        = output,
                trace_path    = input_file,
                report_id     = report_id,
                report_path   = report_path,
                max_col_width = options_values.max_col_width,
                notation      = options_values.notation,
                progress_enabled = progress_enabled
            }

            local opt = {
                timeunit     = options_values.timeunit,
                is_only_main = options_values.only_main,
                is_trunc     = options_values.trunc,
                is_mangled   = options_values.mangled,
            }

            local report_obj = Report:new(attribute)

            
            data.get = function(self, domain_name)
                local domain_id = self.domain_id[domain_name].id
                if domain_id then
                    return self.trace_events[domain_id] or {}
                else
                    error("Domain name unkown")
                end
            end

            data.get_gpu_id = function(self, handle)
                return self.node_id[handle] or 'Unknown'
            end

            local chunk, err = loadfile(report_path)
            if chunk then
                chunk()(data, report_obj, opt)
            else
                error("Error loading file: " .. err)
            end
            if not report_obj.is_skipped then
                report_obj:generate()
            end

        else
            print("\n")
            Message:error(string.format("Report '%s' encountered an internal error: No valid report file or class found", report_id))
        end
    end
    if progress_enabled then
        ratelprof.utils.print_progress(progress_msg, nreports, nreports)
    end
end

-- Available formats and their extensions
local format_extensions = {
    column = "txt",
    table = "txt",
    csv = "csv",
    tsv = "tsv"
}

local function print_if_not (cond, format, ...)
    if not cond then
        Message:print (format, ...)
    end
end

-- Constructor: Initialize a new Report object
function Report:new(attribute)
    if not attribute then error("Report Constructor need attributes") end

    local instance = setmetatable({}, self)

    instance.trace_path  = attribute.trace_path
    instance.report_id   = attribute.report_id
    instance.report_path = attribute.report_path

    instance.output = attribute.output
    instance.format = attribute.format

    instance.max_col_width = tonumber(attribute.max_col_width) or 32
    instance.notation = attribute.notation

    instance.report_name = "'No name set'"
    instance.report_type = "Report"

    instance.data = nil
    instance.headers = nil
    instance.msg = nil

    instance.is_skipped = false

    instance.progress_enabled = attribute.progress_enabled

    local filename = instance:get_output_filename()
    instance.filename = filename
    print_if_not(instance.progress_enabled, string.format(
        "\nProcessing '%s' with '%s'%s...\n",
        instance.trace_path, instance.report_path,
        (filename and (" to '" .. filename .. "'") or "")
    ))

    return instance
end

function Report:set_headers(headers)
    if type(headers) ~= "table" then
        error("Header argument must be a table")
    end
    self.headers = headers
end

function Report:set_custom_message(msg)
    if type(msg) ~= "string" then
        error("Custom message argument must be a string")
    end
    self.msg = msg
end

function Report:set_name(name)
    if type(name) ~= "string" then
        error("Name argument must be a string")
    end
    self.report_name = name
end

function Report:set_type(t)
    if type(t) ~= "string" then
        error("Type argument must be a string")
    end
    self.report_type = t
end

function Report:set_data(data)
    if type(data) ~= "table" then
        error("Data argument must be a table")
    end
    self.data = data
end

function Report:skip(format, ...)
    print_if_not(self.progress_enabled, "SKIPPED: "..string.format(format, ...))
    self.is_skipped = true
end

function Report:generate()
    if not self.data then
        error("Report doesn't have any data to process")
    end

    local has_msg = self.msg

    if #self.data == 0 then
        if has_msg then
            if self.output ~= "-" and self.output:sub(1, 1) ~= "@" and self.format == "csv" or self.format == "tsv" then
                local msg_filename = ratelprof.fs.remove_extension(self.filename).."_msg.txt"
                local msg_file = ratelprof.fs.open_file(msg_filename, "w")
                msg_file:write(self.msg)
                msg_file:close()
            else
                print_if_not(self.progress_enabled, self.msg) 
            end
        end
        self:skip("'%s' does not contain %s data.", self.trace_path, self.report_name)
        return
    end

    if self.headers then 
        table.insert(self.data, 1, self.headers)
    end

    local stream = self:get_output_stream()
    if self.output == "-" then
        print_if_not(self.progress_enabled, string.format(
            "** %s %s (%s):\n",
            self.report_name, self.report_type, self.report_id
        ))
    end

    if has_msg then 
        if self.output ~= "-" and self.output:sub(1, 1) ~= "@" and self.format == "csv" or self.format == "tsv" then
            local msg_filename = ratelprof.fs.remove_extension(self.filename).."_msg.txt"
            local msg_file = ratelprof.fs.open_file(msg_filename, "w")
            msg_file:write(self.msg)
            msg_file:close()
        else
            stream:write(self.msg)
        end
    end

    stream:write(self:get_formatted_data())
    if stream ~= io.stdout then
        stream:close()
    end

end

function Report:get_output_filename()
    if self.output == "-" or self.output:sub(1, 1) == "@" then
        return nil
    end

    local report_wo_ext = ratelprof.fs.remove_extension(self.trace_path)
    local file_extension = format_extensions[self.format] or "txt"
    local basename = (self.output == "." and report_wo_ext or self.output)

    return string.format("%s_%s.%s", basename, self.report_id, file_extension)
end

function Report:get_output_stream()
    local output   = self.output
    local filename = self.filename
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
    local format = self.format
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

local MAX_WIDTH = 32 

local function get_raw_number(n)
    return tonumber(n)
end

local function get_scientific_number(n)
    if n > 1000 then return string.format("%.3e", n):gsub("e", "E")
    elseif ratelprof.utils.is_integer(n) then return string.format("%d", n) end
    return string.format("%.3f", n)
end

local function get_separator_number(n)
    local int_part = math.floor(n)
    local num_digits_before = #tostring(int_part)

    -- Want to keep ~6 significant digits total
    local decimals = 6 - num_digits_before
    if decimals < 0 then decimals = 0 end

    -- Format with dynamic decimals
    s = string.format("%." .. decimals .. "f", n)

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
    ["thousands-separator"] = get_separator_number
}

local default_number_notation = {
    column = "thousands-separator",
    table = "thousands-separator",
    csv = "scientific",
    tsv = "scientific"
}

function Report:__get_notation_number(item)
    local default  = default_number_notation[self.format]
    local notation = self.notation or default
    local getter = get_notation_number[notation]
    if getter then return getter(item)
    else return get_notation_number[default](item) end
end

function Report:__get_formatted_item(item, width)
    local formatted_item = nil
    if type(item) == "number" then
        formatted_item = string.format("%"..width.."s", self:__get_notation_number(item))
    else
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
    for i = 1, #data do
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

function Report:__format_data(separator, bsep, msep, asep, columnWidths)
    local result = {}
    local widths = columnWidths or {}
    local data = self.data

    for i = 1, #data do
        local line = {}
        line[#line + 1] = bsep 
        local ncol = #data[i]
        for j = 1, ncol do
            line[#line + 1] = self:__get_formatted_item(data[i][j], widths[j] or 1) .. (ncol == j and "" or msep)
        end
        line[#line + 1] = asep
        result[#result + 1] = table.concat(line)
        
        if i == 1 and self.headers then
            result[#result + 1] = separator
        end
    end

    return table.concat(result, "\n") .. "\n"
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
    local content =  self:__format_data(separator, "| ", " | ", " |", columnWidths)
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
    return  self:__format_data(separator, nil, " ", nil, columnWidths)
end

function Report:toCSV(sep)
    sep = sep or ","
    return self:__format_data(nil, nil, sep, nil, nil)
end

function Report:toTSV()
    return self:toCSV(";")
end

return Report