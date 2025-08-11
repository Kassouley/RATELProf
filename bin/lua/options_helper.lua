-- options_helper.lua
-- Module for providing helper functions related to options

local options_helper = {}

local function parse_report_option(input)
    local result = {}

    for entry in string.gmatch(input, '([^,]+)') do
        local id, args = entry:match('^([^:]+):?(.*)$')
        local options = {}

        if args and args ~= "" then
            for arg in string.gmatch(args, '([^:]+)') do
                local key, val = arg:match('([^=]+)=?(.*)')
                if val == "" then
                    val = true
                end
                options[key] = val
            end
        end

        table.insert(result, {
            id = id,
            opt = options
        })
    end

    return result
end


local function print_help_report(reports, title)
    print("Available "..title..":\n")

    for name, data in pairs(reports) do
        if name ~= "__default_report_path" then
            print(string.format("== %s ==", name))

            -- Print description
            if data.desc then
                print(data.desc)
            end

            -- Print options if available
            if data.opt then
                print("  Options :")
                for opt_name, opt_data in pairs(data.opt) do
                    local desc = opt_data.desc or "No description."
                    local default = opt_data.default ~= nil and tostring(opt_data.default) or "None"
                    print(string.format("    %s=<value> (default: %s)\n      %s", opt_name, default, desc))
                end
                print("")
            end

            -- Print if is enabled by default
            if data.default ~= nil then
                print(string.format("  Enabled by default : %s", tostring(data.default)))
            end

            print("")
        end
    end
    os.exit(0)
end


-- Function to handle the options for the analyze and stats command
function options_helper.handle_stats_analyze_option(options)
    local help_reports = ratelprof.get_opt_val(options, "help-reports")
    if help_reports then print_help_report(ratelprof.consts._ALL_STATS_REPORT, "Reports") end

    local help_rules = ratelprof.get_opt_val(options, "help-rules")
    if help_rules then print_help_report(ratelprof.consts._ALL_RULES_REPORT, "Rules") end

    local reports = ratelprof.get_opt_val(options, "report")
    if reports then reports = parse_report_option(reports) end

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

    local per_rank      = ratelprof.get_opt_val(options, "per-rank")
    local only_main     = ratelprof.get_opt_val(options, "only-main")
    local mangled       = ratelprof.get_opt_val(options, "mangled")
    local trunc         = ratelprof.get_opt_val(options, "trunc")
    local max_col_width = ratelprof.get_opt_val(options, "max-col-width")
    local max_lines     = ratelprof.get_opt_val(options, "max-lines")
    local notation      = ratelprof.get_opt_val(options, "notation")
    local start         = tonumber(ratelprof.get_opt_val(options, "start"))
    local stop          = tonumber(ratelprof.get_opt_val(options, "stop"))

    return {
        reports = reports,
        outputs = outputs,
        formats = formats,
        timeunit = timeunit,
        only_main = only_main,
        mangled = mangled,
        trunc = trunc,
        max_col_width = max_col_width,
        max_lines = max_lines,
        notation = notation,
        start = start,
        stop = stop,
        per_rank = per_rank,
    }
end


return options_helper