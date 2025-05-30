-- visualize.lua
require ("globals")
local Script    = require ("utils.Classes.Script")
local visualize = require ("commands.visualize")

-- Main script logic
local function main(arg)
        
    local attribute = {
        name = "ratelprof visualize",
        version = ratelprof.consts._VERSION
    }
    local script = Script:new(attribute)

    script:set_desc(ratelprof.consts_helper.visualize.desc)

    script:set_execute_function(visualize.process_visualizing)

    local args = ratelprof.consts_helper.visualize.args["report"]
    script:add_argument("report", args.is_optional, args.is_list, args.desc)

    for lname, opt in pairs(ratelprof.consts_helper.visualize.opt) do
        script:add_option(lname, opt.sname, opt.arg, opt.desc, opt.arg_required, opt.default)
    end

    script:execute(arg)
end

-- Run the main function
main(arg)
