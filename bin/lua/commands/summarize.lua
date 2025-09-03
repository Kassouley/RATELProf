-- summarize.lua
local BinaryReport = require ("utils.Classes.BinaryReport")

local summarize_helper     = require ("commands.summarize.summarize_helper")
local summarize_report     = require ("commands.summarize.summarize_report")
local summarize_experiment = require ("commands.summarize.summarize_experiment")
local summarize_plot       = require ("commands.summarize.summarize_plot")
local summarize_global     = require ("commands.summarize.summarize_global")

local summarize = {}

function summarize.get_summary(data)
    local experiment_info = summarize_experiment.get_experiment_info(data)
    local global_data     = summarize_global.get_global_summary(data)
    local plot_data       = summarize_plot.get_plot_data(data)

    return {
        experiment_info = experiment_info,
        global_data     = global_data,
        plot_data       = plot_data
    }
end

function summarize.process_summarize(positional_args, options_values)
    local data = BinaryReport:new(positional_args)

    local with_analysis = ratelprof.get_opt_val(options_values, "with-analysis")

    local summary = summarize.get_summary(data)

    summarize_helper.print_report("EXPERIMENT INFO", summary.experiment_info)
    summarize_helper.print_report("GLOBAL SUMMARY", summary.global_data)

    summarize_plot.print_plot("PLOT SUMMARY", summary.plot_data)

    if with_analysis then
        local analyzed_data = summarize_report.get_analyzed_data(data, options_values)
        summarize_helper.print_report("ANALYZED METRICS", analyzed_data)
    end


end

return summarize