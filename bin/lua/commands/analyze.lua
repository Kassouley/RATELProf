-- analyze.lua
local options_helper = require ("options_helper")
local Report         = require ("utils.Classes.Report")
local BinaryReport   = require ("utils.Classes.BinaryReport")

local analyze = {}

-- Function to process the input file
function analyze.process_analyze (positional_args, options_values)
    local report_files = ratelprof.utils.check_report_files(positional_args)

    local opt = options_helper.handle_stats_analyze_option(options_values)

    local data = BinaryReport:new(report_files, opt)
    Report.utils.execute_report(data, opt, ratelprof.consts._ALL_RULES_REPORT)
end

return analyze