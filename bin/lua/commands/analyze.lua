-- analyze.lua
local options_helper = require ("options_helper")
local Report         = require ("utils.Classes.Report")

local analyze = {}

-- Function to process the input file
function analyze.process_analyze(positional_args, options_values)
    local report_file = positional_args[1]
    ratelprof.utils.check_report_file(report_file)

    local opt = options_helper.handle_stats_analyze_option(options_values)

    local data = ratelprof.msgpack.decode(report_file)
    Report.utils.execute_report(data, report_file, opt, ratelprof.consts._ALL_RULES_REPORT)
end

return analyze