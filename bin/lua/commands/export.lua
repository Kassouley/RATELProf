local BinaryReport = require("utils.Classes.BinaryReport")
local export = {}

local function write_to_output_file(report_files, data, ext)
    local report_wo_ext = "aggregated_report"
    if #report_files == 1 then
        report_wo_ext = ratelprof.fs.remove_extension(report_files[1], ratelprof.consts._REPORT_EXT)
    end

    local output_file = report_wo_ext..ext
    local f = ratelprof.fs.open_file(output_file, "w")
    f:write(data)
    f:close()
    
    Message:print("RPROF: Export written to '" .. output_file.."'")
end

local function export_json(report_files)
    local data = BinaryReport:new(report_files)
    local json_data = ratelprof.utils.generate_json(data:to_json())

    write_to_output_file(report_files, json_data, ".json")
end

local function format_number(val)
    if type(val) == "number" and val % 1 == 0 then
        -- Integer: format without scientific notation
        return string.format("%.0f", val)
    else
        return tostring(val)
    end
end

local function format_value(name, data)
    if type(data.value) == "table" then
        -- Recursively format all subfields
        local sub_parts = {}
        for sub_name, sub_data in pairs(data.value) do
            table.insert(sub_parts, format_value(sub_name, sub_data))
        end
        return string.format("%s{%s}", name, table.concat(sub_parts, ", "))
    else
        return string.format("%s:%s", name, format_number(data.value))
    end
end

local function format_call(function_name, args)
    local arg_parts = {}
    local retval_value = "void"

    for name, data in pairs(args) do
        if name == "retval" then
            retval_value = data.value
        else
            table.insert(arg_parts, format_value(name, data))
        end
    end

    local args_str = table.concat(arg_parts, ", ")
    return string.format("%s(%s):%s", function_name, args_str, format_number(retval_value))
end


local function export_arg_info(report_files)
    local data = BinaryReport:new(report_files)
    local arg_info_data = {}

    data:for_each_traces(function(mpi_rank, domain_name, trace_id, trace)
        if trace.name then
            local name = trace.name
            local args = trace.args
            local arg_info = format_call(name, args)
            local entry = string.format("%-32s |%s %8s | %s", 
                    domain_name, mpi_rank == -1 and "" or " RANK "..mpi_rank.." |", trace_id, arg_info)
            arg_info_data[#arg_info_data + 1] = entry
        end
    end)

    write_to_output_file(report_files, table.concat(arg_info_data, "\n"), "_arg_info.txt")
end

function export.process_export(positional_args, opt)
    local export_type = ratelprof.get_opt_val(opt, "type")

    local report_files = ratelprof.utils.check_report_files(positional_args)

    if not export_type then
        Message:error("Export type is required.")
        os.exit(1)
    elseif export_type == "json" then
        export_json(report_files)
    elseif export_type == "arg-info" then
        export_arg_info(report_files)
    else
        Message:error("Unknown export type: "..export_type)
        os.exit(1)
    end
end

return export
