-- stats.lua
require ("globals")
local Script   = require ("utils.Classes.Script")
local analyze  = require ("commands.analyze")

-- Main script logic
local function main(arg)

    local attribute = {
        name = "ratelprof analyze",
        version = ratelprof.consts._VERSION,
    }
    local script = Script:new(attribute)

    script:set_desc(ratelprof.consts_helper.analyze.desc)
    script:set_execute_function(analyze.process_analyze)

    local args = ratelprof.consts_helper.analyze.args["report-file"]

    script:add_argument("report-file", args.is_optional, args.is_list, args.desc)

    for lname, opt in pairs(ratelprof.consts_helper.analyze.opt) do
        script:add_option(lname, opt.sname, opt.arg, opt.desc, opt.arg_required, opt.default)
    end

    script:execute(arg)
end
-- Run the main function
main(arg)