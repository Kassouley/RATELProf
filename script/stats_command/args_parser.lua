-- args_parser.lua
require("string_ext")
local helper = require("helper")
local conversion = require("conversion")

local args_parser = {}

-- Helper function to process arguments with values
local function parse_value_arg(arg, i, key, err_msg)
    i = i + 1
    if i > #arg then
        print("Error: " .. err_msg .. " after " .. arg[i-1])
        helper.print_help(settings)
    end
    return arg[i], i
end

-- Helper function to split and insert values into a table
local function parse_list_arg(arg_value, list)
    for _, value in ipairs(arg_value:split(",")) do
        table.insert(list, value)
    end
end

-- Function to manage command-line arguments
function args_parser.parse_args(arg, settings)
    local args = { 
        reports = {}, outputs = {}, formats = {},
        timeunit = "ns"
    }
    local i = 1

    while i <= #arg do
        local arg_str = arg[i]

        if arg_str == "-h" or arg_str == "--help" then
            helper.print_help(settings)
        elseif arg_str == "-v" or arg_str == "--version" then
            helper.print_version(settings)
        elseif arg_str == "-r" or arg_str == "--report" then
            local report = nil
            report, i = parse_value_arg(arg, i, "reports", "No report specified")
            if not report then helper.print_help(settings) end
            parse_list_arg(report, args.reports)
        elseif arg_str == "-o" or arg_str == "--output" then
            local output = nil
            output, i = parse_value_arg(arg, i, "outputs", "No output specified")
            if not output then helper.print_help(settings) end
            parse_list_arg(output, args.outputs)
        elseif arg_str == "-f" or arg_str == "--format" then
            local format = nil
            format, i = parse_value_arg(arg, i, "formats", "No format specified")
            if not format then helper.print_help(settings) end
            parse_list_arg(format, args.formats)
        elseif arg_str == "--timeunit" then
            args.timeunit, i = parse_value_arg(arg, i, "timeunit", "No timeunit specified")
            if not args.timeunit then helper.print_help(settings) end
            if not conversion.time_units[args.timeunit] then helper.print_help(settings) end
        elseif arg_str:sub(1, 1) ~= "-" then
            if not args.input_file then
                args.input_file = arg_str
            else
                print("Error: Multiple input files specified: '" .. args.input_file .. "' and '" .. arg_str .. "'")
                helper.print_help(settings)
            end
        else
            print("Error: Unknown argument: " .. arg_str)
            helper.print_help(settings)
        end
        
        i = i + 1
    end

    -- Use default reports if none were specified
    if #args.reports == 0 then
        args.reports = settings._DEFAULT_REPORT
    end

    -- Use console output if no outputs were specified
    if #args.outputs == 0 then
        table.insert(args.outputs, "-")
    end

    -- Ensure an input file is provided
    if not args.input_file then
        print("Error: No input file specified.")
        helper.print_help(settings)
    end

    return args
end

return args_parser
