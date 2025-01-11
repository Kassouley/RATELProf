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
local path = require("path")
local Script = require("Script")
local settings = common.load_json(path.get_script_dir(1).."profile_settings.json")

-- Function to set environment variable
local function set_env(env, var, value)
    return env .. " " .. var .. "=" .. value
end

local function process_profiling(positional_args, options_values)
    local application_command = positional_args
    if not path.file_exists(application_command[1]) then
        print("No application to profile.")
        os.exit(1)
    end
    local function export_filter_var(filename)
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
            local var_name = "RATELPROF_DOMAIN_"..string.upper(category).."_FUNCTIONS"
            env = set_env(env, var_name, table.concat(names,","))
        end
        return env
    end
    local function get_number_of_kernel(app_arg)
        -- Run the shell command and capture its output
        local handle = io.popen("nm -C -U " .. app_arg .. " | grep __device_stub__ | wc -l")
        local num = tonumber(handle:read("*a"):match("%d+"))
        handle:close()
    
        -- Initialize result
        local result = 32
    
        -- Double result until it is greater than or equal to num
        while result < num do
            result = result * 2
        end
    
        return result
    end

    local preload_lib = settings._INSTALL_DIR.."/lib/libratelprof_core.so"
    if not path.file_exists(preload_lib) then
        print("Error: Preload library '"..preload_lib.."' not found.")
        os.exit(1)
    end
    local nb_kernel_available = get_number_of_kernel(application_command[1])

    local env = options_values.env
    if options_values.filter then env = export_filter_var(options_values.filter) end
    if options_values.output then env = set_env(env, "RATELPROF_OUTPUT_FILE", options_values.output) end
    env = set_env(env, "RATELPROF_PLUGIN_PATH", "\""..options_values.plugin.."\"")
    env = set_env(env, "RATELPROF_NB_KERNEL_AVAILABLE", nb_kernel_available)
    env = set_env(env, "LD_PRELOAD", preload_lib)

    os.execute(env.." "..table.concat(application_command, " "))

end

local function output_option(script, value) script.options_values.output = value end
local function enable_filter(script, value) script.options_values.filter = value end
local function enable_domain(script, value, domain_env) 
    script.options_values.env = set_env(script.options_values.env, domain_env, "1")
end
local function enable_prof_domain(script, value) 
    script.options_values.env = set_env(script.options_values.env, "RATELPROF_DOMAIN_PROFILING", "1")
end
local function enable_all_domain(script, value, domains) 
    for _, domain in ipairs(domains) do
        enable_domain(script, value, domain.var)
    end
end

local function plugin_option(self, value) 
    if value == "stdout" then
        self.options_values.plugin = self.settings._INSTALL_DIR.."/lib/libplugin_stdout.so"
    elseif value == "json" then
        self.options_values.plugin = self.settings._INSTALL_DIR.."/lib/libplugin_json.so"
    elseif value == "json-dyn" then
        self.options_values.plugin = self.settings._INSTALL_DIR.."/lib/libplugin_json_dyn.so"
    else
        self.options_values.plugin = value
    end
end

-- Main script logic
local function main(arg)
        
    local attribute = {
        name = "ratelprof profile",
        settings = settings,
        default_options_values = { 
            plugin = settings._INSTALL_DIR.."/lib/libplugin_json.so", 
            filter = nil, output = "report_"..os.date("%Y-%m-%d_%H-%M-%S")..".json",
            env = ""
        }
    }
    local script = Script:new(attribute)

    -- script:set_usage("ratelprof profile [<options>] -- [application] [<application args>]")
    script:set_desc("\n\tProfile")

    script:set_execute_function(process_profiling)

    script:add_argument("application", false, false, "\tThe application to profile.")
    script:add_argument("application-args", true, true, "Arguments of the application.")

    script:add_option("output", "o", "<FILE>", "Output report filename.", true, output_option)

    script:add_option("filter", "f", "<FILE>", "Specify the input file with functions to intercept", true, enable_filter)
                            
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