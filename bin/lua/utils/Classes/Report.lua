-- Report.lua
local Report = {}
Report.utils = {}

local function print_if_not (cond, format, ...)
    if not cond then
        Message:print (format, ...)
    end
end

local function print_skip(cond, format, ...)
    print_if_not(cond, "SKIPPED: "..string.format(format, ...))
end

local function process_report_generation(report_ret_vals, chunk, rprof_rep_data, report_id, options_values, output_format, output, rprof_rep_files, report_path, progress_enabled, mpi_rank, opt)
    report_ret_vals = report_ret_vals or {}
    local ret = nil
    ret = chunk()(rprof_rep_data, report_id, opt)

    local report_obj = Report:new({
        format           = output_format,
        output           = output,
        rprof_rep_files  = rprof_rep_files,
        report_name      = ret.NAME,
        report_type      = ret.TYPE,
        report_id        = report_id,
        report_path      = report_path,
        max_col_width    = tonumber(options_values.max_col_width),
        max_lines        = options_values.max_lines,
        notation         = options_values.notation,
        header           = ret.HEADER,
        msg              = ret.MSG,
        data             = ret.DATA,
        progress_enabled = progress_enabled,
        mpi_rank         = mpi_rank,
    })

    if ret.skip then
        print_skip(progress_enabled, ret.skip or "No skip message provided.")
    else
        report_obj:generate()
    end

    if not report_ret_vals[mpi_rank] then
        report_ret_vals[mpi_rank] = {}
    end
    report_ret_vals[mpi_rank][report_id] = ret
end

local function get_report_opt_value(ALL_REPORT, report_id, report_opt, opt)
    report_opt = report_opt or {}
    if not ALL_REPORT[report_id].opt then return opt end
    for name, option in pairs(ALL_REPORT[report_id].opt) do
        local default = option.default
        if not default then
            error (string.format("No default report option value provided for %s in report %s", name, report_id))
        end
        if type(default) == "number" then
            opt[name] = tonumber(report_opt[name]) or default
        else
            opt[name] = report_opt[name] or default
        end
    end
    return opt
end

function Report.utils.execute_report(rprof_rep_data, options_values, report_list, progress_enabled, progress_msg)
    local report_ret_vals = {}

    local reports = options_values.reports or {}
    local outputs = options_values.outputs or {}
    local formats = options_values.formats or {}
    
    local nreports = #reports
    for i, report_data in ipairs(reports) do
        local report_id = report_data.id

        if progress_enabled then
            ratelprof.utils.print_progress(i-1, nreports, progress_msg, '('..report_id..')')
        end

        local report_path = report_list.__default_report_path..report_id..".lua"
        if ratelprof.fs.exists(report_path) then
            local output = outputs[i] or outputs[#outputs] or '-'
            local output_format = formats[i] or formats[#formats]
                                    or (output == "-" and "column" or "csv")

            options_values = get_report_opt_value(report_list, report_id, report_data.opt, options_values)
            
            local chunk, err = loadfile(report_path)
            if not chunk then
                error("Error loading file: " .. err)
            end

            if options_values.per_rank == true then
                rprof_rep_data:for_each_rank(function (mpi_rank, rprof_rep_file)
                    process_report_generation(report_ret_vals, chunk, rprof_rep_data, report_id, options_values, output_format, output, {rprof_rep_file}, report_path, progress_enabled, mpi_rank, options_values)
                end)
            else
                process_report_generation(report_ret_vals, chunk, rprof_rep_data, report_id, options_values, output_format, output, rprof_rep_data:get_rprof_rep_files(), report_path, progress_enabled, -1, options_values)
            end
        else
            print('\n')
            Message:error(string.format("Report '%s' encountered an internal error: No valid report file or class found", report_id))
        end
    end
    if progress_enabled then
        ratelprof.utils.print_progress(nreports, nreports, progress_msg, '(Done)')
    end

    return report_ret_vals
end

-- Available formats and their extensions
local format_extensions = {
    column  = "txt",
    table   = "txt",
    csv     = "csv",
    tsv     = "tsv"
}

local report_attribute_type = {
    format           = "string",
    output           = "string",
    rprof_rep_files  = "table",
    report_name      = "string",
    report_type      = "string",
    report_id        = "string",
    report_path      = "string",
    max_col_width    = "number",
    max_lines        = "string",
    notation         = "string",
    header           = "table",
    msg              = "string",
    data             = "table",
    progress_enabled = "boolean",
    mpi_rank         = "number",
}

Report.__index = Report

-- Constructor: Initialize a new Report object
function Report:new(attribute)
    if not attribute then error("Report Constructor need attributes") end

    local instance = setmetatable({}, self)

    for name, value in pairs(attribute) do
        local atype = report_attribute_type[name]
        if not atype then
            error(name.." is not a valid report attribute")
        end
        if value and type(value) ~= atype then
            error(name.." argument must be a "..atype)
        end
        instance[name] = value
    end

    instance:set_default_value()
    local filename = instance:get_output_filename()
    instance.filename = filename
    print_if_not(instance.progress_enabled, string.format(
        "\nProcessing '%s'%s with '%s'%s...\n",
        table.concat(instance.rprof_rep_files, ", "),
        (instance.mpi_rank > -1 and " (MPI RANK "..instance.mpi_rank..")" or ""),
        instance.report_path,
        (filename and (" to '" .. filename .. "'") or "")
    ))

    return instance
end


function Report:generate()
    local data = self.data
    if not data then
        error("Report doesn't have any data to process")
    end

    local has_msg = self.msg

    if #data == 0 then
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
        print_skip(self.progress_enabled, "'%s' does not contain %s data.", table.concat(self.rprof_rep_files, ", "), self.report_name)
        return
    end

    if self.header then 
        table.insert(data, 1, self.header)
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

function Report:set_default_value()
    self.max_col_width = tonumber(self.max_col_width) or 32
    
    local max_lines = self.max_lines
    if max_lines == "all" then return end
    if self.output == "-" then
        max_lines = tonumber(max_lines) or 50
    else
        max_lines = tonumber(max_lines) or "all"
    end
    self.max_lines = max_lines
end

function Report:get_output_filename()
    if self.output == "-" or self.output:sub(1, 1) == "@" then
        return
    end

    local report_wo_ext = "aggregated_report"
    if #self.rprof_rep_files == 1 then
        report_wo_ext = ratelprof.fs.remove_extension(self.rprof_rep_files[1])
    end

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
    ["engineering"] = get_engineering_notation,
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
    local max_lines = self.max_lines
    local data_size = #data
    local is_all_data_shown = max_lines == "all" or data_size < max_lines
    local ndata = is_all_data_shown and data_size or max_lines

    for i = 1, ndata do
        local line = {}
        line[#line + 1] = bsep
        local ncol = #data[i]
        for j = 1, ncol do
            line[#line + 1] = self:__get_formatted_item(data[i][j], widths[j] or 1) .. (ncol == j and "" or msep)
        end
        line[#line + 1] = asep
        result[#result + 1] = table.concat(line)
        
        if i == 1 and self.header then
            result[#result + 1] = separator
        end
    end

    if not is_all_data_shown and (format_extensions[self.format] == "txt" or self.output == "-") then
        result[#result + 1] = ". . . ("..data_size-ndata.." lines has been trunc for visibility, please use option --max-lines or export to a file)"
    end

    return table.concat(result, "\n") .. "\n", is_all_data_shown
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
    local content, is_all_data_shown = self:__format_data(separator, "| ", " | ", " |", columnWidths)
    if is_all_data_shown then content = separator .. "\n" .. content .. separator .. "\n"
    else content = separator .. "\n" .. content end
    return content
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
    local content, _ = self:__format_data(separator, nil, " ", nil, columnWidths)
    return content
end

function Report:toCSV(sep)
    sep = sep or ","
    local content, _ = self:__format_data(nil, nil, sep, nil, nil)
    return content
end

function Report:toTSV()
    return self:toCSV(";")
end

return Report