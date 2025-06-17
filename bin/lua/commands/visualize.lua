-- visualize.lua
local preprocess = require ("commands.visualize.preprocess")
local merge_csv  = require("commands.visualize.merge_csv")

local visualize = {}

function visualize.process_visualizing(positional_args, options_values)
    local report_file = positional_args[1]

    ratelprof.utils.check_report_file(report_file)
    
    local tmp_dir = ratelprof.get_opt_val(options_values, "tmp")
    ratelprof.fs.mkdir(tmp_dir)

    local html_file = ratelprof.fs.open_file(ratelprof.consts._HTML_REPORT_PATH, "r")
    local html_content = html_file:read("*all")
    html_file:close()

    local data = ratelprof.msgpack.decode(report_file)

    preprocess.init(data)
    preprocess.run(options_values)

    local stats_csv_content, analyze_csv_content = merge_csv.get_csv_data(report_file, tmp_dir, data, options_values)

    html_content = html_content:gsub('"@@CSV_STATS_DATA_HANDLER@@"', stats_csv_content)
    html_content = html_content:gsub('"@@CSV_ANALYZE_DATA_HANDLER@@"', analyze_csv_content)

    html_content = html_content:gsub('@@B64_DATA_HANDLER@@', preprocess.get_data())
    html_content = html_content:gsub('"@@LIFECYLE_TABLE_HANDLER@@"', preprocess.get_lifecycle_data())
    html_content = html_content:gsub('"@@STRING_EXT_TABLE_HANDLER@@"', preprocess.get_string_map())
    html_content = html_content:gsub('"@@DATA_DOMAIN_TABLE_HANDLER@@"', preprocess.get_domain_data())

    local output_file = ratelprof.get_opt_val(options_values, "output")
                            or ratelprof.fs.remove_extension(report_file)..'.html'
    
    local f = ratelprof.fs.open_file(output_file, "w")
    f:write(html_content)
    f:close()
    Message:print("RPROF: HTML report written to '" .. output_file.."'")
end

return visualize
