-- stats.lua
require ("globals")
local Script   = require ("utils.Classes.Script")
local summarize  = require ("commands.summarize")

-- Main script logic
local function main(arg)

    local attribute = {
        name = "ratelprof summarize",
        version = ratelprof.consts._VERSION,
    }
    local script = Script:new(attribute)

    script:set_desc(ratelprof.consts_helper.summarize.desc)
    script:set_execute_function(summarize.process_summarize)

    local args = ratelprof.consts_helper.summarize.args["report-file"]

    script:add_argument("report-file", args.is_optional, args.is_list, args.desc)

    for lname, opt in pairs(ratelprof.consts_helper.summarize.opt) do
        script:add_option(lname, opt.sname, opt.arg, opt.desc, opt.arg_required, opt.default)
    end

    script:execute(arg)
end
-- Run the main function
main(arg)