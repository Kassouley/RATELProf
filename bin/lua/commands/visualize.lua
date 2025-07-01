-- visualize.lua
local preprocess    = require ("commands.visualize.preprocess")
local reports       = require ("commands.visualize.reports")
local main_panel    = require ("commands.visualize.main_panel")
local common_data   = require ("commands.visualize.common_data")

local visualize = {}

function visualize.process_visualizing(positional_args, options_values)
    local report_file = positional_args[1]

    ratelprof.utils.check_report_file(report_file)
    
    local tmp_dir = ratelprof.get_opt_val(options_values, "tmp")
    ratelprof.fs.mkdir(tmp_dir)

    local data = ratelprof.msgpack.decode(report_file)

    local csv_content = reports.get_csv_data(report_file, tmp_dir, data, options_values)

    local b64_data = preprocess.get_b64_buffer(data, options_values)

    local gpu_labels, gpu_props = main_panel.get_gpu_data_as_js_string()

    local string_ext_array = ratelprof.msgpack.encode.get_ext_string_table()

    local handlers = {
        {HANDLE = "HTML_TITLE",             sub = report_file},
        {HANDLE = "LIFECYCLE_TABLE",        sub = common_data.get_lifecycle_table_as_js_string(data)},
        {HANDLE = "EXTENSION_STRING_ARRAY", sub = JSON:encode(string_ext_array)},
        {HANDLE = "DOMAIN_TABLE",           sub = common_data.get_domain_table_as_js_string(data)},
        {HANDLE = "GPU_LABELS",             sub = gpu_labels},
        {HANDLE = "GPU_DATA",               sub = gpu_props},
        {HANDLE = "SUMMARY_DATA",           sub = main_panel.get_summary_data_as_js_string()},
        {HANDLE = "CSV_DATA_PER_TAB",       sub = csv_content},
        {HANDLE = "B64_DATA",               sub = b64_data},
    }

    local output_file    = ratelprof.get_opt_val(options_values, "output")
    local only_data_test = ratelprof.get_opt_val(options_values, "only-data-test")

    local file = nil
    if only_data_test then
        output_file = output_file or ratelprof.fs.remove_extension(report_file)..'.js'
        file = ratelprof.fs.open_file(ratelprof.consts._DATA_SET_TEST_PATH, "r")
    else
        output_file = output_file or ratelprof.fs.remove_extension(report_file)..'.html'
        file = ratelprof.fs.open_file(ratelprof.consts._HTML_REPORT_PATH, "r")
    end

    local content = file:read("*all")
    file:close()

    for _, h in ipairs(handlers) do
        content = content:gsub('"@@'..h.HANDLE..'@@"', h.sub)
    end

    local f = ratelprof.fs.open_file(output_file, "w")
    f:write(content)
    f:close()

    if only_data_test then
        Message:print("RPROF: Dataset for testing written to '" .. output_file.."'")
    else
        Message:print("RPROF: HTML report written to '" .. output_file.."'")
    end
end

return visualize
