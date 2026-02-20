-- main.lua
require ("globals")

local Script = require ("utils.Classes.Script")

local CMD = table.popi(arg, 1)

local helper = ratelprof.consts_helper

-- Main script logic
local function main(argv)

    local attribute = {
        name = "ratelprof " .. CMD,
        version = ratelprof.consts._VERSION,
    }
    local script = Script:new(attribute)

    script:set_desc(helper[CMD].desc)

    for _, arg in ipairs(helper[CMD].args) do
        script:add_argument(arg.name, arg.is_optional, arg.is_list, arg.desc)
    end

    for lname, opt in pairs(helper[CMD].opt) do
        script:add_option(lname, opt.sname, opt.arg, opt.desc, opt.arg_required, opt.default, opt.early_exit)
    end

    script:set_execute_function(ratelprof[CMD].process)

    script:execute(argv)
end

-- Run the main function
main(arg)