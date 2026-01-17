-- stats.lua
local options_helper = require ("options_helper")
local ReportLauncher = require ("utils.Classes.ReportLauncher")
local RProfRep       = require ("utils.Classes.RProfRep")

local stats = {}

function stats.process_stats_impl(rprofrep, options_values)
    local opt = options_helper.handle_stats_analyze_option(options_values, "stats")

    local report_launcher = ReportLauncher:new(rprofrep, opt)

    report_launcher:execute_reports(ratelprof.consts.ALL_STATS_REPORT, opt)

    return report_launcher.report_objs
end

-- Function to process the input file
function stats.process_stats (positional_args, options_values)
    stats.process_stats_impl(RProfRep:new(positional_args), options_values)
end

return stats