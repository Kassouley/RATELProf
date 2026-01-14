-- stats.lua
local options_helper = require ("options_helper")
local ReportLauncher = require ("utils.Classes.ReportLauncher")
local RProfRep       = require ("utils.Classes.RProfRep")

local stats = {}

-- Function to process the input file
function stats.process_stats (positional_args, options_values)
    local opt = options_helper.handle_stats_analyze_option(options_values, "stats")

    local rprofrep = RProfRep:new(positional_args)

    local report_launcher = ReportLauncher:new(rprofrep, opt)

    report_launcher:execute_reports(ratelprof.consts.ALL_STATS_REPORT, opt)
end

return stats