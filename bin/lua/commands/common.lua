-- common.lua

local options_helper = require ("options_helper")
local ReportLauncher = require ("utils.Classes.ReportLauncher")
local RProfRep       = require ("utils.Classes.RProfRep")

local common = {
    stats     = {},
    analyze   = {},
    breakdown = {},
}

local DEFAULT_OUTPUT = "-"
local DEFAULT_FORMAT = function(output)
    return output == "-" and "column" or "csv"
end

local COMMAND_CONFIG = {
    stats = {
        reports = ratelprof.consts.STATS_REPORTS,
        help    = "help-reports",
        title   = "Reports",
    },
    analyze = {
        reports = ratelprof.consts.ANALYZE_REPORTS,
        help    = "help-rules",
        title   = "Rules",
    },
    breakdown = {
        reports = ratelprof.consts.BREAKDOWN_REPORTS,
        help    = "help-rules",
        title   = "Breakdown",
    },
}

local function get_report_option(report_id, report_options, reports_list)
    local report_const_data = reports_list[report_id] or {}
    local available_options = report_const_data.opt or {}

    local ret = table.copy(report_options)

    for opt_name, opt_info in pairs(available_options) do
        local opt_val = ret[opt_name]
        local default = opt_info.default

        if default == nil then
            error (string.format("No default report option value provided for %s in report %s", opt_name, report_id))
        end

        if opt_val == "" and type(default) ~= "boolean" then
            Message:error(string.format("Report option '%s' for report '%s' requires a value.", opt_name, report_id))
            os.exit(1)
        end
        if opt_info.type == "unit" then
            local allowed_units = opt_info.allowed or {}
            if opt_val and not allowed_units[opt_val] then
                Message:error(string.format("Report option '%s' for report '%s' requires a valid unit value.", opt_name, report_id))
                os.exit(1)
            end
            ret[opt_name] = opt_val or default

        elseif type(default) == "number" then
            if opt_val and not tonumber(opt_val) then
                Message:error(string.format("Report option '%s' for report '%s' requires a numeric value.", opt_name, report_id))
                os.exit(1)
            end
            ret[opt_name] = tonumber(opt_val) or default

        else
            ret[opt_name] = opt_val or default
        end
    end

    return ret
end

local function add_to_result(result, id, opt, path, output, format)
    result[#result+1] = {
        id = id,
        opt = opt,
        path = path,
        output = output,
        format = format,
    }
end

local function parse_config_data(data, command)
    local report_list = COMMAND_CONFIG[command].reports

    local result = {}

    for report_id, report_cfg in pairs(data[command] or {}) do
        if report_cfg.enabled then
            local report_const_data = report_list[report_id] or {}
            local report_path = report_const_data.path
            local report_opt  = get_report_option(report_id, report_cfg.opt or {}, report_list)
            local report_output = report_cfg.output or DEFAULT_OUTPUT
            local report_format = report_cfg.format or DEFAULT_FORMAT(report_output)

            add_to_result(result, report_id, report_opt, report_path, report_output, report_format)
        end
    end

    return result
end


local function get_reports_data(reports_ids, outputs, formats, options, reports_list)
    local result = {}
    local mode_map = {
        ["all-agg-sum"] = "Aggregated-Mode",
        ["all-per-sum"] = "Per-Mode",
        ["all-trace"]   = "Trace-Mode",
    }
    options = options or {}

    for i, report in ipairs(reports_ids) do
        local output = outputs[i] or outputs[#outputs] or DEFAULT_OUTPUT
        local format = formats[i] or formats[#formats] or DEFAULT_FORMAT(output)

        local user_report_options = report:split(":")
        local report_id = user_report_options[1]
        user_report_options[1] = nil

        for _, opt in pairs(user_report_options) do
            local opt_name, opt_val = opt:match('([^=]+)=?(.*)')
            options[opt_name] = opt_val or true
        end

        local target_mode = mode_map[report_id]
        if target_mode then
            for id, data in pairs(reports_list) do
                if data.mode == target_mode then
                    local report_opt = get_report_option(id, options, reports_list)
                    add_to_result(result, id, report_opt, data.path, output, format)
                end
            end

        elseif report_id == "all" then
            for id, data in pairs(reports_list) do
                if data.mode ~= "Trace-Mode" then
                    local report_opt = get_report_option(id, options, reports_list)
                    add_to_result(result, id, report_opt, data.path, output, format)
                end
            end

        else
            local report_const_data = reports_list[report_id] or {}
            local report_path = report_const_data.path
            local report_opt = get_report_option(report_id, options, reports_list)
            add_to_result(result, report_id, report_opt, report_path, output, format)
        end
    end

    return result
end

common.get_reports_data = get_reports_data

local function parse_report_option(options, reports_list)
    local reports  = options_helper.parse_list_option(options, "report")
    local outputs  = options_helper.parse_list_option(options, "output")
    local formats  = options_helper.parse_list_option(options, "format")
    local report_options = {
        timeunit = options_helper.parse_unit_option(options, "timeunit",
                     { sec=true, ms=true, us=true, ns=true }),
        sizeunit = options_helper.parse_unit_option(options, "sizeunit",
                     { B=true, KB=true, MB=true, GB=true }),
        mangled  = options_helper.parse_bool_option(options, "mangled"),
        trunc    = options_helper.parse_bool_option(options, "trunc"),
    }
    return get_reports_data(reports, outputs, formats, report_options, reports_list)
end

local function print_help_report(reports, title)
    print("Available "..title..":\n")

    for name, data in pairs(reports) do
        print(string.format("== %s ==\n", name))

        -- Print description
        if data.desc then
            print(data.desc)
        end

        -- Print options if available
        if data.opt then
            print("\n  Options :")
            for opt_name, opt_data in pairs(data.opt) do
                local desc = opt_data.desc or "No description."
                local default = opt_data.default ~= nil and tostring(opt_data.default) or "None"
                print(string.format("    %s=<value> (default: %s)\n%s", opt_name, default, desc))
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



local function generate_template_config_data()
    local config = {}
    for command, cfg in pairs(COMMAND_CONFIG) do
        local template = {}

        for report_id, report_data in pairs(cfg.reports) do
            local opt = {}
            for opt_name, opt_data in pairs(report_data.opt or {}) do
                opt[opt_name] = opt_data.default
            end

            template[report_id] = {
                enabled = report_data.default or false,
                output  = "-",
                format  = "column",
                opt = opt
            }
        end

        config[command] = template
    end
    return config
end

common.generate_template_config_data = generate_template_config_data

local function generate_template_config_file()
    local data = generate_template_config_data()
    local json = ratelprof.utils.generate_json(data)

    local infile = ratelprof.fs.open_file ("reports_config.json", "w", "json")
    infile:write (json)
    infile:close ()
    Message:info("Template configuration file 'reports_config.json' generated.")
    os.exit(0)
end

-- Function to handle the options for the analyze and stats command
local function handle_option(options, command)
    local cfg = COMMAND_CONFIG[command]

    if options_helper.parse_bool_option(options, cfg.help) then
        print_help_report(cfg.reports, cfg.title)
    end

    if options_helper.parse_bool_option(options, "template") then
        generate_template_config_file()
    end

    local reports = nil

    local json_data = options_helper.parse_json_option(options, "config")
    if json_data then
        reports = parse_config_data(json_data, command)
    else
        reports = parse_report_option(options, cfg.reports)
    end

    return {
        reports          = reports,
        only_main        = options_helper.parse_bool_option(options, "only-main"),
        max_col_width    = options_helper.parse_number_option(options, "max-col-width"),
        max_lines        = options_helper.parse_string_option(options, "max-lines"),
        notation         = options_helper.parse_string_option(options, "notation"),
        start            = options_helper.parse_number_option(options, "start"),
        stop             = options_helper.parse_number_option(options, "stop"),
        gpus             = options_helper.parse_mask_option(options, "gpus"),
        pids             = options_helper.parse_mask_option(options, "pids"),
    }
end

local function process(filenames, options_values, command)
    local opt = handle_option(options_values, command)

    local rprofrep = RProfRep:new(filenames)
    local report_launcher = ReportLauncher:new(rprofrep, opt)

    report_launcher:launch()
end

function common.analyze.process (positional_args, options_values)
    process(positional_args, options_values, "analyze")
end


function common.stats.process (positional_args, options_values)
    process(positional_args, options_values, "stats")
end


function common.breakdown.process (positional_args, options_values)
    process(positional_args, options_values, "breakdown")
end

return common