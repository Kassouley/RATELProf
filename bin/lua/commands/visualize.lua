-- visualize.lua
local preprocess    = require ("commands.visualize.preprocess")
local reports       = require ("commands.visualize.reports")
local main_panel    = require ("commands.visualize.main_panel")

local summarize         = require ("commands.summarize")
local summarize_report  = require ("commands.summarize.summarize_report")

local BinaryReport  = require ("utils.Classes.BinaryReport")

local visualize = {}

function visualize.process_visualizing(positional_args, options_values)
    local data = BinaryReport:new(positional_args)


    local output_file    = ratelprof.get_opt_val(options_values, "output")
    local only_data_test = ratelprof.get_opt_val(options_values, "only-data-test")
    local tmp_dir        = ratelprof.get_opt_val(options_values, "tmp")
    ratelprof.fs.mkdir(tmp_dir)


    local timeline_data = preprocess.start(data, options_values)

    options_values["with-analysis"] = true

    local gpu_labels, gpu_props = main_panel.get_gpu_data_as_js_string(data)
    local global_data = summarize.get_summary(data)
    local analyzed_data, stats_ret_vals, analyze_ret_vals = summarize_report.get_analyzed_data(data, options_values)
    local summary = main_panel.get_summary_data_as_js_string(global_data, analyzed_data)

    local string_ext_array = ratelprof.msgpack.encode.get_ext_string_table()

    local csv_content = reports.get_csv_data(stats_ret_vals, analyze_ret_vals)

    local timeline_lifecycle = {}
    data:for_each_rank(function (mpi_rank, _)
        timeline_lifecycle[tostring(mpi_rank)] = {
            data:get_main_start(mpi_rank),
            data:get_main_stop(mpi_rank)
        }
    end)

    local handlers = {
        {HANDLE = "HTML_TITLE",             data = '"'..data:get_report_basename()..'"'},
        {HANDLE = "TIMELINE_LIFECYCLE",     data = JSON:encode(timeline_lifecycle)},
        {HANDLE = "TIMELINE_MAX",           data = data:get_max_stop_time()},
        {HANDLE = "TIMELINE_DATA",          data = timeline_data},
        {HANDLE = "CHART_DATA",             data = JSON:encode(global_data.plot_data)},
        {HANDLE = "EXT_STRINGS",            data = JSON:encode(string_ext_array)},
        {HANDLE = "GPU_LABELS",             data = gpu_labels},
        {HANDLE = "GPU_DATA",               data = gpu_props},
        {HANDLE = "REPORT_DATA",            data = summary},
        {HANDLE = "CSV_DATA_PER_TAB",       data = csv_content},
    }

    local data_content = "let "
    for i, h in ipairs(handlers) do
        data_content = data_content .. h.HANDLE.. '=' .. h.data..(i ~= #handlers and ',' or '')
    end

    local mode = "a"
    if only_data_test then
        output_file = output_file or data:get_report_basename()..'.js'
        mode = "w"
    else
        output_file = output_file or data:get_report_basename()..'.html'
        ratelprof.fs.copy_file(ratelprof.consts._HTML_REPORT_PATH, output_file)
        data_content = "<script>" .. data_content .. "</script>"
    end

    local file = ratelprof.fs.open_file(output_file, mode)
    file:write(data_content)
    file:close()

    if only_data_test then
        Message:print("RPROF: Dataset for testing written to '" .. output_file.."'")
    else
        Message:print("RPROF: HTML report written to '" .. output_file.."'")
    end
end

return visualize
