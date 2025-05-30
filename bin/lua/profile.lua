-- profile.lua
require ("globals")
local Script   = require ("utils.Classes.Script")
local profile  = require ("commands.profile")

-- Main script logic
local function main(arg)
        
    local attribute = {
        name = "ratelprof profile",
        version = ratelprof.consts._VERSION,
    }
    local script = Script:new(attribute)

    script:set_desc(ratelprof.consts_helper.profile.desc)

    script:set_execute_function(profile.process_profiling)

    script:add_argument("application", false, false, 
                        "\tThe application to profile.")

    script:add_argument("application-args", true, true, 
                        "Arguments of the application.")

    for lname, opt in pairs(ratelprof.consts_helper.profile.opt) do
        script:add_option(lname, opt.sname, opt.arg, opt.desc, opt.arg_required, opt.default)
    end

    script:execute(arg)
end

-- Run the main function
main(arg)
