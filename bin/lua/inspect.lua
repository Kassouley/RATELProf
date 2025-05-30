-- inspect.lua
require ("globals")
local Script   = require ("utils.Classes.Script")
local inspect  = require ("commands.inspect")

-- Main script logic
function main(arg)
        
    local attribute = {
        name    = "ratelprof inspect",
        version = ratelprof.consts._VERSION,
    }
    local script = Script:new(attribute)

    script:set_desc(ratelprof.consts_helper.inspect.desc)
    script:set_execute_function(inspect.processinspecting)

    local args = ratelprof.consts_helper.inspect.args["application"]
    script:add_argument("application", args.is_optional, args.is_list, args.desc)

    for lname, opt in pairs(ratelprof.consts_helper.inspect.opt) do
        script:add_option(lname, opt.sname, opt.arg, opt.desc, opt.arg_required, opt.default)
    end

    script:execute(arg)
end

-- Run the main function
main(arg)
