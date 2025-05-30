-- analyze.lua
local options_helper = require ("options_helper")
local Report         = require ("utils.Classes.Report")
local msgpack        = require ("msgpack_decoder")

local analyze = {}

-- Function to process the input file
function analyze.process_analyze(positional_args, options_values)
    local input_file = positional_args[1]
    ratelprof.utils.check_report_file(input_file)

    local opt = options_helper.handle_stats_analyze_option(options_values)

    local data = msgpack.decode_msgpack_binary(input_file)
    Report.utils.execute_report(data, input_file, opt, ratelprof.consts._ALL_RULES_REPORT)
end

return analyze