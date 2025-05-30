-- options_helper.lua
-- Module for providing helper functions related to options

local options_helper = {}

-- Function to handle the options for the analyze and stats command
function options_helper.handle_stats_analyze_option(options)
    local reports = ratelprof.get_opt_val(options, "report")
    if reports and type(reports) == "string" then reports = reports:split(",") end

    local outputs = ratelprof.get_opt_val(options, "output")
    if outputs then outputs = outputs:split(",") end

    local formats = ratelprof.get_opt_val(options, "format")
    if formats then formats = formats:split(",") end

    local timeunit = ratelprof.get_opt_val(options, "timeunit")
    if timeunit then 
        local time_units = { sec = 1, ms = 1e3, us = 1e6, ns = 1e9 }
        if not time_units[timeunit] then 
            Message:error ("Time unit '"..timeunit.."' not available.") 
            os.exit(1)
        end 
    end

    local only_main = ratelprof.get_opt_val(options, "only-main")
    local mangled = ratelprof.get_opt_val(options, "mangled")
    local trunc = ratelprof.get_opt_val(options, "trunc")
    local max_col_width = ratelprof.get_opt_val(options, "max-col-width")
    local notation = ratelprof.get_opt_val(options, "notation")

    return {
        reports = reports,
        outputs = outputs,
        formats = formats,
        timeunit = timeunit,
        only_main = only_main,
        mangled = mangled,
        trunc = trunc,
        max_col_width = max_col_width,
        notation = notation
    }
end


return options_helper