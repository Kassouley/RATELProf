-- options_helper.lua
-- Module for providing helper functions related to options

local options_helper = {}

function options_helper.parse_list_option(options, name)
    local option = ratelprof.get_opt_val(options, name)
    if not option then return {} end
    return option:split(",")
end

function options_helper.parse_mask_option(options, name)
    local list = options_helper.parse_list_option(options, name)
    if not list or #list == 0 then return end
    local mask = {}
    for _, value in ipairs(list) do
        mask[tonumber(value)] = true
    end
    return mask
end

function options_helper.parse_unit_option(options, name, allowed)
    local value = ratelprof.get_opt_val(options, name)
    if not value then return end
    local unit = allowed[value]
    if not unit then
        Message:error("'"..name.."' value '"..value.."' not available.")
        os.exit(1)
    end
    return value
end

function options_helper.parse_number_option(options, name)
    return tonumber(ratelprof.get_opt_val(options, name))
end

function options_helper.parse_bool_option(options, name)
    return ratelprof.get_opt_val(options, name) and true or false
end

function options_helper.parse_string_option(options, name)
    return ratelprof.get_opt_val(options, name)
end

function options_helper.parse_file_option(options, name, ext)
    local filepath = ratelprof.get_opt_val(options, name)
    if not filepath then return nil end
    return ratelprof.fs.open_file(filepath, "r", ext), filepath
end

function options_helper.parse_json_option(options, name)
    local filepath = ratelprof.get_opt_val(options, name)
    if not filepath then return nil end
    return ratelprof.utils.load_json(filepath)
end

return options_helper