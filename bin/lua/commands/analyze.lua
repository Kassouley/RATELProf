-- analyze.lua
local options_helper = require ("options_helper")
local ReportLauncher = require ("utils.Classes.ReportLauncher")
local RProfRep       = require ("utils.Classes.RProfRep")

local analyze = {}

-- Function to process the input file
function analyze.process_analyze (positional_args, options_values)

    local rprofrep = RProfRep:new(positional_args)

    local opt = options_helper.handle_stats_analyze_option(options_values, "analyze")

    local report_launcher = ReportLauncher:new(rprofrep, opt)

    report_launcher:execute_reports(ratelprof.consts.ALL_ANALYZE_REPORT, opt)
end

return analyze