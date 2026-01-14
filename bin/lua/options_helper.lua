-- options_helper.lua
-- Module for providing helper functions related to options

local options_helper = {}

local function parse_report_option(options, reports_list)
    local option = ratelprof.get_opt_val(options, "report")
    if not option then return end

    local result = {}

    local mode_map = {
        ["all-agg-sum"] = "Aggregated-Mode",
        ["all-per-sum"] = "Per-Mode",
        ["all-trace"]   = "Trace-Mode",
    }

    for entry in string.gmatch(option, '([^,]+)') do
        local report_id, args = entry:match('^([^:]+):?(.*)$')
        local report_options = {}

        if args and args ~= "" then
            for arg in string.gmatch(args, '([^:]+)') do
                local key, val = arg:match('([^=]+)=?(.*)')
                if val == "" then
                    val = true
                end
                report_options[key] = val
            end
        end

        local function add_to_result(id, opt)
            result[#result+1] = { id = id, opt = opt }
        end

        local target_mode = mode_map[report_id]
        if target_mode then
            for id, data in pairs(reports_list) do
                if data.mode == target_mode then
                    add_to_result(id, report_options)
                end
            end

        elseif report_id == "all" then
            for id, data in pairs(reports_list) do
                if data.mode ~= "Trace-Mode" then
                    add_to_result(id, report_options)
                end
            end

        else
            add_to_result(report_id, report_options)
        end
    end

    return result
end


local function print_help_report(reports, title)
    print("Available "..title..":\n")

    for name, data in pairs(reports) do
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
    os.exit(0)
end


local function parse_list_option(options, name)
    local option = ratelprof.get_opt_val(options, name)
    if not option then return end
    return option:split(",")
end


local function parse_mask_option(options, name)
    local list = parse_list_option(options, name)
    if not list then return end
    local mask = {}
    for _, value in ipairs(list) do
        mask[tonumber(value)] = true
    end
    return mask
end

local function parse_unit_option(options, name, allowed)
    local value = ratelprof.get_opt_val(options, name)
    if not value then return end
    local unit = allowed[value]
    if not unit then
        Message:error("'"..name.."' value '"..value.."' not available.")
        os.exit(1)
    end
    return value
end


local function parse_number_option(options, name)
    return tonumber(ratelprof.get_opt_val(options, name))
end


local function parse_bool_option(options, name)
    return ratelprof.get_opt_val(options, name) and true or false
end

local function parse_string_option(options, name)
    return ratelprof.get_opt_val(options, name)
end



-- Function to handle the options for the analyze and stats command
function options_helper.handle_stats_analyze_option(options, command)

    local reports = nil

    if command == "stats" then
        if parse_bool_option(options, "help-reports") then
            print_help_report(ratelprof.consts.ALL_STATS_REPORT, "Reports") 
        end
        reports = parse_report_option(options, ratelprof.consts.ALL_STATS_REPORT)
    elseif command == "analyze" then
        if parse_bool_option(options, "help-rules") then
            print_help_report(ratelprof.consts.ALL_ANALYZE_REPORT, "Rules")
        end
        reports = parse_report_option(options, ratelprof.consts.ALL_ANALYZE_REPORT)
    end

    local outputs   = parse_list_option(options, "output")
    local formats   = parse_list_option(options, "format")
    local gpus      = parse_mask_option(options, "gpus")
    local pids      = parse_mask_option(options, "pids")
    local timeunit  = parse_unit_option(options, "timeunit", { sec = true, ms = true, us = true, ns = true })
    local sizeunit  = parse_unit_option(options, "sizeunit", { B = true, KB = true, MB = true, GB = true })

    local mangled       = parse_bool_option(options, "mangled")
    local trunc         = parse_bool_option(options, "trunc")
    local only_main     = parse_bool_option(options, "only-main")
    local notation      = parse_string_option(options, "notation")
    local max_lines     = parse_string_option(options, "max-lines")
    local max_col_width = parse_number_option(options, "max-col-width")
    local start         = parse_number_option(options, "start")
    local stop          = parse_number_option(options, "stop")

    return {
        reports = reports,
        outputs = outputs,
        formats = formats,
        timeunit = timeunit,
        sizeunit = sizeunit,
        only_main = only_main,
        mangled = mangled,
        trunc = trunc,
        max_col_width = max_col_width,
        max_lines = max_lines,
        notation = notation,
        start = start,
        stop = stop,
        gpus = gpus,
        pids = pids,
    }
end


return options_helper