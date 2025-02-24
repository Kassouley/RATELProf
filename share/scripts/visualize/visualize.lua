-- visualize.lua
require ("utils.string_ext")
local utils   = require ("utils.utils")
local lfs     = require ("utils.lfs")
local convert = require ("utils.convert")

local merge_json = require("visualize.merge_json")
local merge_csv  = require("visualize.merge_csv")

local visualize = {}


function visualize.process_visualizing(positional_args, options_values)
    local report_path = positional_args[1]
    local script_path = lfs.get_script_path(1)

    local tmp_dir = options_values.tmp or '/tmp'
    lfs.mkdir(tmp_dir)

    if not lfs.file_exists(report_path) then
        print("Error: Report file doesn't exist.")
        os.exit(1)
    end
    local output_file = lfs.remove_extension(report_path, "json")..'.html'

    local html_file = lfs.open_file(script_path.."index.min.html", "r")
    local html_content = html_file:read("*all")
    html_file:close()

    local json_content = merge_json.get_json_data(report_path)
    local csv_content  = merge_csv.get_csv_data(report_path, tmp_dir)

    html_content = html_content:gsub('"@@DATA_HANDLER@@"', json_content)
    html_content = html_content:gsub('"@@CSV_STATS_DATA_HANDLER@@"', csv_content)

    local f = io.open(output_file, "w")
    f:write(html_content)
    f:close()
    print("RPROF: HTML report written to " .. output_file)
end

return visualize
