-- stats.lua
-- Set up the script directory and package paths
local script_dir = debug.getinfo(1, "S").source:match("@(.*[\\/]?.*)") or ""
script_dir = script_dir:gsub('\\', '/'):match("(.*[\\/])") or ""
local paths = {
    '',
    '../',
    '../utils/',
    '../utils/json/',
}

for _, path in ipairs(paths) do
    package.path = package.path .. ';' .. script_dir .. path .. '?.lua'
end

require("string_ext")
local common = require("common")
local lfs = require("lfs")
local Script = require("Script")
local settings = common.load_json(lfs.get_script_path(1).."profile_settings.json")
local INSTALL_DIR = common.execute_command('realpath "' .. script_dir.."../../.." .. '" 2>/dev/null')

-- Function to set environment variable
local function set_env(env, var, value)
    return env .. " " .. var .. "=" .. value
end

local function process_profiling(positional_args, options_values)
    local application_command = positional_args
    if not lfs.file_exists(application_command[1]) then
        print("No application to profile.")
        os.exit(1)
    end

    
    local function export_filter_var(filename, filter_type)
        local file = io.open(filename, "r")
        if not file then
            print("Error: Could not open file " .. filename)
            return
        end
    
        local categories = {}
        local current_category = nil
    
        for line in file:lines() do
            line = line:trim()
    
            if line:find(":") then
                -- Found a new category
                local category, names = line:match("^(.-):%s*(.*)$")
                current_category = category:trim()
                categories[current_category] = {}
    
                if names and names ~= "" then
                    -- Add any names that are on the same line as the category
                    for name in names:gmatch("[^,]+") do
                        table.insert(categories[current_category], name:trim())
                    end
                end
            elseif current_category and line ~= "" then
                -- Add names to the current category if they are on separate lines
                for name in line:gmatch("[^,]+") do
                    table.insert(categories[current_category], name:trim())
                end
            end
        end
    
        file:close()
    
        local env = ""
        for category, names in pairs(categories) do
            local upper_category = string.upper(category)
            env = set_env(env, string.format(settings._ENV.FUNCTION_FILTERED, upper_category), table.concat(names,","))
            env = set_env(env, string.format(settings._ENV.FILTER_TYPE, upper_category), filter_type)
        end
        return env
    end
    local function get_number_of_kernel(app_arg)
        local num = tonumber(common.execute_command(
            "nm --demangle --defined-only " .. app_arg .. " | grep -iE \"__device_stub__|__omp_offloading\" | wc -l"
        ):match("%d+")) or 1
        local result = 32
        while result < num do
            result = result * 2
        end
    
        return result
    end

    local function get_number_of_queue()
        local output = common.execute_command(INSTALL_DIR.."/bin/ratelinfo --max-queue")
        return tonumber(output) + 1
    end

    local preload_tool    = INSTALL_DIR.."/lib/libratelprof.so"
    local preload_wrapper = INSTALL_DIR.."/lib/libratelprof_wrapper.so"
    local preload_lib     = preload_wrapper..":"..preload_tool
    if not lfs.file_exists(preload_tool) then
        print("Error: Preload library '"..preload_tool.."' not found.")
        os.exit(1)
    end
    if not lfs.file_exists(preload_wrapper) then
        print("Error: Preload library '"..preload_wrapper.."' not found.")
        os.exit(1)
    end
    local nb_kernel_available = get_number_of_kernel(application_command[1])
    local nb_queue_available = get_number_of_queue()
    local env = options_values.env
    if options_values.blacklist then env = export_filter_var(options_values.blacklist, 1) end
    if options_values.whitelist then env = export_filter_var(options_values.whitelist, 2) end
    if options_values.output then env = set_env(env, settings._ENV.OUTPUT_FILE, options_values.output) end
    env = set_env(env, settings._ENV.PLUGIN_PATH, "\""..options_values.plugin.."\"")
    env = set_env(env, settings._ENV.NB_KERNEL_AV, nb_kernel_available)
    env = set_env(env, settings._ENV.NB_QUEUE_AV, nb_queue_available)
    env = set_env(env, "LD_PRELOAD", preload_lib)

    print([[
     ____      _  _____ _____ _     ____             __ 
    |  _ \    / \|_   _| ____| |   |  _ \ _ __ ___  / _|
    | |_) |  / _ \ | | |  _| | |   | |_) | '__/ _ \| |_ 
    |  _ <  / ___ \| | | |___| |___|  __/| | | (_) |  _|
    |_| \_\/_/   \_\_| |_____|_____|_|   |_|  \___/|_|  
]])

    print("RPROF: Application profiled :    '"..application_command[1].."'")
    print("RPROF: Application Command :     '"..table.concat(application_command, " ").."'")
    print("RPROF: Preloaded tool :          '"..preload_tool.."'")
    print("RPROF: Preloaded wrapper :       '"..preload_wrapper.."'")
    print("RPROF: Plugin used :             '"..options_values.plugin.."'")
    print("RPROF: Profiling output file :   '"..options_values.output.."'")
    local ret_code = os.execute(env.." "..table.concat(application_command, " "))
    if ret_code ~= 0 then
        print("Error: Application execution failed - code("..ret_code..").")
        os.exit(ret_code)
    end
    local bytes_written = common.execute_command("cat "..options_values.output.." | wc -c")
    print("RPROF: Bytes written in '"..options_values.output.."' : "..bytes_written)
    print("RPROF: Exiting tool . . .")
end

local function output_option(script, value) script.options_values.output = value end
local function enable_whitelist(script, value) script.options_values.whitelist = value end
local function enable_blacklist(script, value) script.options_values.blacklist = value end
local function enable_domain(script, value, domain_env) 
    script.options_values.env = set_env(script.options_values.env, domain_env, "1")
end
local function enable_prof_domain(script, value) 
    script.options_values.env = set_env(script.options_values.env, settings._ENV.DOMAIN_PROFILING, "1")
end
local function enable_all_domain(script, value, domains) 
    for _, domain in ipairs(domains) do
        enable_domain(script, value, domain.var)
    end
end

local function plugin_option(self, value) 
    if value == "stdout" then
        self.options_values.plugin = INSTALL_DIR.."/lib/libplugin_stdout.so"
    elseif value == "json" then
        self.options_values.plugin = INSTALL_DIR.."/lib/libplugin_json.so"
    elseif value == "json-dyn" then
        self.options_values.plugin = INSTALL_DIR.."/lib/libplugin_json_dyn.so"
    else
        self.options_values.plugin = value
    end
end

-- Main script logic
local function main(arg)
        
    local attribute = {
        name = "ratelprof profile",
        version = settings._VERSION,
        default_options_values = { 
            plugin = INSTALL_DIR.."/lib/libplugin_json.so", 
            filter = nil, output = "report_"..os.date("%Y-%m-%d_%H-%M-%S")..".json",
            env = ""
        }
    }
    local script = Script:new(attribute)

    script:set_desc("\n\tProfile an AMD GPU application and trace AMD Library functions")

    script:set_execute_function(process_profiling)

    script:add_argument("application", false, false, "\tThe application to profile.")
    script:add_argument("application-args", true, true, "Arguments of the application.")

    script:add_option("output", "o", "<FILE>", "Output report filename.", true, output_option)

    script:add_option("--whitelist", "w", "<FILE>", "Specify an input file with functions to intercept", true, enable_whitelist)
    script:add_option("--blacklist", "b", "<FILE>", "Specify an input file with functions to not intercept", true, enable_blacklist)
                            
    script:add_option("plugin", nil, "<PLUGIN>", "Specify the plugin path for RATELProf (options: stdout, json, or custom path)", true, plugin_option)
    
    for _, trace_option in pairs(settings._TRACES) do
        script:add_option(trace_option.option, nil, nil, "\tEnable profiling of "..trace_option.name.." library functions", false, enable_domain, trace_option.var)
    end

    script:add_option("prof-trace", nil, nil, "\tEnable profiling of HSA library functions used in profiling system", false, enable_prof_domain)
    
    script:add_option("all-trace", nil, nil, "\tEnable profiling of all library functions", false, enable_all_domain, settings._TRACES)
                       
    script:execute(arg)
end

-- Run the main function
main(arg)
