-- summarize.lua
local RProfRep = require ("utils.Classes.RProfRep")

local helper     = require ("commands.summarize.helper")
local global     = require ("commands.summarize.global")
local experiment = require ("commands.summarize.experiment")

local summarize = {}

function summarize.get_summary(rprofrep, options_values)
    local global_data, report_launcher = global.get_global_data(rprofrep, options_values)
    return {
        experiment_info = experiment.get_experiment_info(rprofrep),
        global_data     = global_data,
        report_launcher = report_launcher
    }
end

function summarize.process(positional_args, options_values)
    local rprofrep = RProfRep:new(positional_args)

    local summary = summarize.get_summary(rprofrep, options_values)

    helper.print_report("Experiment Summary", summary.experiment_info)
    helper.print_report("Global Summary", summary.global_data)
end

return summarize