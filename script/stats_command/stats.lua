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

local common = require("common")
local args_parser = require("args_parser")
local Report = require("Report")
local settings = common.load_json("stats_settings.json")

-- Default formats for each output type
local function get_default_formats(output)
    return output == "-" and "column" or "csv"
end

-- Function to process the input file
local function process_file(args)
    local input_file = args.input_file
    local reports = args.reports
    local outputs = args.outputs
    local formats = args.formats
    local timeunit = args.timeunit
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
                timeunit = timeunit
            })
            r:generate({format=output_format, output=output})
        else
            print(string.format("Error: Report '%s' encountered an internal error: No valid report file or class found", report))
        end
    end
end


-- Main script logic
local function main()
    local args = args_parser.parse_args(arg, settings)

    if args.input_file then
        process_file(args)
    end
end

-- Run the main function
main()