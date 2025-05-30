-- export.lua
require ("globals")
local export = require ("commands.export")
local Script = require ("utils.Classes.Script")

-- Main script logic
local function main(arg)

    local attribute = {
        name = "ratelprof export",
        version = ratelprof.consts._VERSION,
    }
    local script = Script:new(attribute)

    script:set_desc(ratelprof.consts_helper.export.desc)

    local args = ratelprof.consts_helper.export.args["report-file"]

    script:add_argument("report-file", args.is_optional, args.is_list, args.desc)

    for lname, opt in pairs(ratelprof.consts_helper.export.opt) do
        script:add_option(lname, opt.sname, opt.arg, opt.desc, opt.arg_required, opt.default)
    end

    script:set_execute_function(export.process_export)
    script:execute(arg)
end
-- Run the main function
main(arg)