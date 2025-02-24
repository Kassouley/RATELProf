-- stats.lua
require ("utils.string_ext")
local utils   = require ("utils.utils")
local lfs     = require ("utils.lfs")
local convert = require ("utils.convert")

Report           = require ("stats.Classes.Report")
report_common    = require ("stats.report_common")

local settings = require ("settings")

local stats = {}

local function handle_option(options)
    local value = nil
    value = options["report"]
    if value then 
        if type(value) == "table" then options.report = value
        else options.report = value:split(",") end
    end

    value = options["output"]
    if value then 
        options.output = value:split(",")
    end

    value = options["format"]
    if value then 
        options.format = value:split(",")
    end

    value = options["timeunit"]
    if value then 
        if not convert.time_units[value] then 
            print("Time unit '"..value.."' not available.") 
            os.exit(1)
        end 
        options.timeunit = value
    end
end


-- Default formats for each output type
local function get_default_formats(output)
    return output == "-" and "column" or "csv"
end


function stats.execute_report(reports, outputs, formats, input_file, options_values)
    local data = utils.load_json(input_file)

    for i, report_id in ipairs(reports) do
        if settings._REPORT_PATH[report_id] then
            local output = outputs[i] or outputs[#outputs]
            local output_format = formats[i] or formats[#formats] or get_default_formats(output)

            local report_path = lfs.get_script_path(1)..settings._REPORT_PATH[report_id]
            report_path = utils.execute_command("realpath "..report_path)

            local attribute = {
                trace_path = input_file,
                report_id = report_id,
                report_path = report_path
            }

            local opt = {
                format=output_format,
                output=output,
                timeunit = options_values.timeunit,
                is_only_main = options_values["only-main"],
                is_trunc = options_values.trunc,
                is_mangled = options_values.mangled
            }
            local chunk, err = loadfile(report_path)
            if chunk then
                chunk()(data, attribute, opt)
            else
                print("Error loading file: " .. err)
            end
        else
            print(string.format("Error: Report '%s' encountered an internal error: No valid report file or class found", report_id))
        end
    end
end

-- Function to process the input file
function stats.process_stats(positional_args, options_values)
    handle_option(options_values)
    local input_file = positional_args[1]
    if not lfs.file_exists(input_file) or not lfs.has_extension(input_file, "json") then
        print("Error : Incorrect report file in input.")
        os.exit(1)
    end
    
    local default_reports = {}
    for _, report in ipairs(settings._ALL_REPORT) do
        if report.default == true then
            table.insert(default_reports, report.name)
        end
    end
    local reports = options_values.report or default_reports
    local outputs = options_values.output or {"-"}
    local formats = options_values.format or {}

    stats.execute_report(reports, outputs, formats, input_file, options_values)
end

return stats