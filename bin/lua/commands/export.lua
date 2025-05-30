local msgpack = require ("msgpack_decoder")

local preprocess = require ("commands.visualize.preprocess")

local export = {}

local function write_to_output_file(report_file, data, ext)
    local output_file = ratelprof.fs.remove_extension(report_file, ratelprof.consts._REPORT_EXT)..ext
    local f = io.open(output_file, "w")
    f:write(data)
    f:close()
    
    Message:print("RPROF: Export written to '" .. output_file.."'")
end

local function export_json(report_file)
    local data = msgpack.decode_msgpack_binary(report_file)
    local json_data = ratelprof.utils.generate_json(data)

    write_to_output_file(report_file, json_data, ".json")
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


local function export_arg_info(report_file)
    local data = msgpack.decode_msgpack_binary(report_file)
    local domain_map_name_id = data.domain_id
    local domain_map_id_name = {}
    for domain_name, domain in pairs(domain_map_name_id) do
        domain_map_id_name[domain.id] = domain_name
    end
    local arg_info_data = {}
    local trace_events = data.trace_events
    for domain_id, domain in pairs(trace_events) do
        for event_id, event in pairs(domain) do
            if event.name then
                local name = event.name
                local args = event.args
                local arg_info = format_call(name, args)
                local entry = string.format("%-32s | %8s | %s", domain_map_id_name[domain_id], event_id, arg_info)
                arg_info_data[#arg_info_data + 1] = entry
            end
        end
    end

    write_to_output_file(report_file, table.concat(arg_info_data, "\n"), "_arg_info.txt")
end

function export.process_export(positional_args, opt)
    local report_file = positional_args[1]
    local export_type = ratelprof.get_opt_val(opt, "type")

    ratelprof.utils.check_report_file(report_file)

    if not export_type then
        Message:error("Export type is required.")
        os.exit(1)
    elseif export_type == "json" then
        export_json(report_file)
    elseif export_type == "arg-info" then
        export_arg_info(report_file)
    else
        Message:error("Unknown export type: "..export_type)
        os.exit(1)
    end
end

return export
