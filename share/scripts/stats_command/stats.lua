-- stats.lua
-- Set up the script directory and package paths
local script_dir = debug.getinfo(1, "S").source:match("@(.*[\\/]?.*)") or ""
script_dir = script_dir:gsub('\\', '/'):match("(.*[\\/])") or ""
local paths = {
    '',
    './ReportClass/',
    '../',
    '../utils/',
    '../utils/json/',
}

for _, path in ipairs(paths) do
    package.path = package.path .. ';' .. script_dir .. path .. '?.lua'
end

require("string_ext")
local common = require("common")
local lfs = require("lfs")
local conversion = require("conversion")
local Script = require("Script")
local Report = require("Report")
local settings = common.load_json(lfs.get_script_path(1).."stats_settings.json")

local function report_option(script, value)
    if value then script.options_values.reports = value:split(",")
    else script.options_values.reports = script.settings._DEFAULT_REPORT end
end

local function ouput_option(script, value)
    if value then script.options_values.outputs = value:split(",")
    else table.insert(script.options_values.outputs, "-") end
end

local function format_option(script, value)
    if value then script.options_values.formats = value:split(",") end
end

local function timeunit_option(script, value)
    if value then 
        if not conversion.time_units[value] then script:show_help() end 
        script.options_values.timeunit = value
    else
        script.options_values.timeunit = "ns"
    end
end

local function only_main_option(script, value)
    script.options_values.is_only_main = true
end


-- Default formats for each output type
local function get_default_formats(output)
    return output == "-" and "column" or "csv"
end

-- Function to process the input file
local function process_stats(positional_args, options_values)
    local input_file = positional_args[1]
    local reports = options_values.reports
    local outputs = options_values.outputs
    local formats = options_values.formats
    local timeunit = options_values.timeunit
    local is_only_main = options_values.is_only_main
    local input_data = common.load_json(input_file)

    for i, report in ipairs(reports) do
        if settings._ALL_REPORT[report] then
            local output = outputs[i] or outputs[#outputs]
            local output_format = formats[i] or formats[#formats] or get_default_formats(output)
            local r = Report:new({
                trace_file = input_file, 
                trace_data = input_data, 
                report = report, 
                report_path = settings._ALL_REPORT[report], 
                timeunit = timeunit,
                is_only_main = is_only_main
            })
            r:generate({format=output_format, output=output})
        else
            print(string.format("Error: Report '%s' encountered an internal error: No valid report file or class found", report))
        end
    end
end


-- Main script logic
local function main(arg)

    local attribute = {
        name = "ratelprof stats",
        version = settings._VERSION,
        default_options_values = { 
            reports = settings._DEFAULT_REPORT, outputs = {"-"}, 
            formats = {}, timeunit = "ns"
        }
    }
    local script = Script:new(attribute)

    script:set_desc("\n\tGenerate differents types of report based on trace file")

    script:set_execute_function(process_stats)

    script:add_argument("trace-file", false, false, "Path to the trace file.")

    -- TODO (11-11-2024) : Implement --help-report
    script:add_option("report", "r", "<name[,name...]>", 
[[                  
                            Specify the report(s) to generate.
                            This option may be used multiple times. If no reports are given, 
                            the following will be used as the default report set:

                                 ]]..table.concat(settings._DEFAULT_REPORT, "\n\t\t\t\t ")..[[ 

                            See --help-reports for a list of built-in reports, along with more
                            information on each report.]], 
                            true, report_option)

                            
    script:add_option("output", "o", "<output[,output...]>", 
[[                  
                            Specify the output mechanism. There are three output mechanisms:
                            print to console, output to file, or output to command. If no
                            outputs are designated, the default is to print reports to the
                            console.
                            This option may be used multiple times. Multiple outputs may also
                            be specified using a comma-separated list.
     
                            If the given output name is "-", the output will be displayed
                            on the console. 
                            If the output name starts with "@", the output designates a 
                            command to run. The command will be executed and the analysis 
                            output will be piped into the command. Any other output
                            is assumed to be the base path and name for a file.
     
                            If a file basename is given, the filename used will be:
                               <basename>_<report>.<output_format>
                            The output "." can be used to indicate the analysis should be output
                            to a file, and the default basename should be used.]], 
                            true, ouput_option)

    script:add_option("format", "f", "<format[,format...]>", 
[[                  
                            Specify the output format. The special name "." indicates the
                            default format for the given output.

                            The default format for console is:    column
                            The default format for files is:      csv
                            The default format for processes is:  csv

                            Available formats (and file extensions):

                                column     Human readable columns (.txt)
                                table      Human readable table (.txt)
                                csv        Comma Separated Values (.csv)
                                tsv        Tab Separated Values (.tsv)

                            This option may be used multiple times. Multiple formats may also
                            be specified using a comma-separated list.]], 
                            true, format_option)

                            
    script:add_option("timeunit", nil, "<time unit>", 
[[                  
                            Set basic unit of time. The default is nanoseconds.
                            Longest prefix matching is done on the following units:

                            ns -> nanoseconds
                            us -> microseconds
                            ms -> milliseconds
                            sec -> seconds]], 
                            true, timeunit_option)

                            
    script:add_option("only-main", nil, nil, 
    [[                  
                            Will compute only statistic for traces from main phase]], 
                            false, only_main_option)
                       
    script:execute(arg)
end

-- Run the main function
main(arg)