-- visualize.lua
local summary   = require ("commands.visualize.summary")
local csv       = require ("commands.visualize.csv")
local breakdown = require ("commands.visualize.breakdown")
local summarize = require ("commands.summarize")
local RProfRep  = require ("utils.Classes.RProfRep")
local FileStructure  = require ("utils.Classes.FileStructure")

local visualize = {}

function visualize.process(positional_args, options_values)
    local rprofrep = RProfRep:new(positional_args)

    -- local output  = ratelprof.get_opt_val(options_values, "output") or rprofrep.basename
    local output = "dummy"

    local fs = FileStructure.new( output, {
        data = {
            csv = {},
            gpus = {},
            stats = "statistics.js",
            cpu_breakdown = "cpu_breakdown.js",
            gpu_breakdown = "gpu_breakdown.js",
            analyze = "analyze.js",
            summary = "summary.js"
        }
    })

    fs:generate()

    ratelprof.fs.cp(ratelprof.consts._HTML_DIR.."*", output, "-r")

    options_values["save-json"] = fs.data.csv:path()
    local summary_data = summarize.get_summary(rprofrep, options_values)
    local summary_dataset = breakdown.get_summary_datasets(summary_data)
    summary.process_summary_data(rprofrep, fs, summary_data, summary_dataset)
    csv.process_csv_data(fs, summary_data)
    breakdown.process_breakdown_report(fs, summary_data)



    -- local handlers = {
    --     {HANDLE = "HTML_TITLE",             data = '"'..data:get_report_basename()..'"'},
    --     {HANDLE = "TIMELINE_LIFECYCLE",     data = JSON:encode(timeline_lifecycle)},
    --     {HANDLE = "TIMELINE_MAX",           data = data:get_max_stop_time()},
    --     {HANDLE = "TIMELINE_DATA",          data = timeline_data},
    --     {HANDLE = "CHART_DATA",             data = JSON:encode(global_data.plot_data)},
    --     {HANDLE = "EXT_STRINGS",            data = JSON:encode(string_ext_array)},
    --     {HANDLE = "GPU_LABELS",             data = gpu_labels},
    --     {HANDLE = "GPU_DATA",               data = gpu_props},
    --     {HANDLE = "REPORT_DATA",            data = summary},
    --     {HANDLE = "CSV_DATA_PER_TAB",       data = csv_content},
    -- }


    -- ratelprof.fs.copy_file(ratelprof.consts._HTML_REPORT_PATH, html_output)

    -- local file = ratelprof.fs.open_file(data_output, "w")
    -- file:write(data_content)
    -- file:close()

    Message:print("RPROF: HTML report written in '" .. output .. "' dir.")
    Message:print("RPROF: Index file can be found at '" .. output .. "/index.html'.")
end

return visualize
