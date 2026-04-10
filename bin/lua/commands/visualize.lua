-- visualize.lua
local summary   = require ("commands.visualize.summary")
local csv       = require ("commands.visualize.csv")
local breakdown = require ("commands.visualize.breakdown")
local summarize = require ("commands.summarize")
local RProfRep  = require ("utils.Classes.RProfRep")
local FileStructure = require ("utils.Classes.FileStructure")

local visualize = {}

function visualize.process(positional_args, options_values)
    local rprofrep = RProfRep:new(positional_args)

    local output = ratelprof.get_opt_val(options_values, "output") or rprofrep.basename

    local fs = FileStructure.new(output, {
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

    Message:print("RPROF: HTML report written in '" .. output .. "' dir.")
    Message:print("RPROF: Index file can be found at '" .. output .. "/index.html'.")
end

return visualize
