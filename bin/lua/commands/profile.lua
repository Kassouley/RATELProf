local env            = require ("commands.profile.env")
local options_helper = require ("options_helper")

local profile = {}

-- Function to handle the options for the profile command
local function handle_profile_option(options)
    local output = ratelprof.get_opt_val(options, "output")
    if output then env.set_env(ratelprof.consts._ENV.OUTPUT_FILE, output) end

    local whitelist = ratelprof.get_opt_val(options, "whitelist")
    if whitelist then env.set_filter_env_var(whitelist, 2) end

    local blacklist = ratelprof.get_opt_val(options, "blacklist")
    if blacklist then env.set_filter_env_var(blacklist, 1) end

    local log_level = ratelprof.get_opt_val(options, "log-level")
    if log_level then env.set_env(ratelprof.consts._ENV.LOG_LEVEL, log_level) end

    
    local lib_path = options_helper.parse_list_option(options, "lib-path")

    local paths_to_set = {}
    
    for domain, path in pairs(ratelprof.consts._TRACED_LIB_PATH) do
        if path and ratelprof.fs.exists(path) then
            local domain_data = ratelprof.consts._TRACES[domain]
            if domain_data then 
                paths_to_set[domain_data.var] = path
            end
        end
    end

    for _, lib_data in ipairs(lib_path) do
        local domain, path = lib_data:match("([^:]+):([^:]+)")
        local domain_data = ratelprof.consts._TRACES[domain]
        local has_lib_path = ratelprof.consts._TRACED_LIB_PATH[domain]
        if domain_data and has_lib_path ~= nil then
            paths_to_set[domain_data.var] = path
        end
    end

    for var, path in pairs(paths_to_set) do
        env.set_env(var.."_LIB_PATH", path)
    end

    

    local function enable_domain(var)
        env.set_env(var, "1")
    end

    local enabled_domain = {}
    local traces_list = options_helper.parse_list_option(options, "trace")
    for _, trace_name in ipairs(traces_list) do
        local trace = ratelprof.consts._TRACES[trace_name]
        if trace then
            if type(trace.var) == "table" then
                for _, var in ipairs(trace.var) do
                    enable_domain(var)
                end
            else
                enable_domain(trace.var)
            end
            table.insert(enabled_domain, trace.name)
        else
            Message:warn("Trace '"..trace_name.."' is not supported. Skipping it.")
        end
    end

    local plugin_path = ratelprof.get_opt_val(options, "plugin")
    if plugin_path then
        if plugin_path == "stdout"        then plugin_path = ratelprof.consts._LIBS.PLUGIN_STDOUT
        elseif plugin_path == "msgpack"   then plugin_path = ratelprof.consts._LIBS.PLUGIN_MSGPACK
        elseif plugin_path == "rprofrep"  then plugin_path = ratelprof.consts._LIBS.PLUGIN_RPROFREP end
        if not ratelprof.fs.exists(plugin_path) then
            Message:error("Plugin library '"..plugin_path.."' not found.")
            os.exit(1)
        end
        env.set_env(ratelprof.consts._ENV.PLUGIN_PATH, plugin_path) 
    end

    local launch_script     = ratelprof.get_opt_val(options, "launch_script")
    local launch_command    = ratelprof.get_opt_val(options, "launch_command")
    local prefix            = ratelprof.get_opt_val(options, "prefix")

    
    return {
        launch_script = launch_script,
        launch_command = launch_command,
        prefix = prefix,
        plugin = plugin_path,
        enabled_domain = enabled_domain,
    }
end


local function normal_execution(cmd)
    local ret_code = os.execute(cmd)
    if ret_code ~= 0 then
        Message:error("Application execution failed - code("..ret_code..").")
        Message:error("Run command : '"..cmd.."'")
        os.exit(1)
    end
end

local function script_execution(cmd, launch_command, launch_script)
    local file = ratelprof.fs.open_file(launch_script, "r")
    local script_content = file:read("*all")
    file:close()
    
    file = ratelprof.fs.open_file(launch_script..".tmp", "w")
    file:write(script_content:gsub("<run_command>", cmd))
    file:close()

    normal_execution(launch_command .. " " .. launch_script..".tmp")
end


function profile.process(positional_args, options_values)
    local bin_command = positional_args

    local bin = ratelprof.get_bin_val(bin_command)
    local user_bin_with_args = table.concat(bin_command, " ")

    local opt = handle_profile_option(options_values)
    local launch_script     = opt.launch_script
    local launch_command    = opt.launch_command
    local prefix            = opt.prefix .. " "
    local plugin_path       = opt.plugin

    bin_command[1] = bin
    local bin_with_args = table.concat(bin_command, " ")

    local ld_library_path = os.getenv ("LD_LIBRARY_PATH")
    local preload_libs = ratelprof.consts._PRELOADED_LIBS
    local ld_preload = {}

    for _, lib in ipairs(preload_libs) do
        if not ratelprof.fs.exists(lib.path) then
            lib.path = nil
            if not ld_library_path then
                Message:error("LD_LIBRARY_PATH is not set.")
                os.exit (1)
            end
            for path in ld_library_path:gmatch ("([^:]+)") do
                local lib_path = path .. "/" .. lib.name
                if ratelprof.fs.exists (lib_path) then
                    lib.path = lib_path
                    break
                end
            end
            if not lib.path then
                Message:error("Required library '"..lib.name.."' can't be find.")
                os.exit (1)
            end
        end
        table.insert(ld_preload, lib.path)
    end

    Message:print ([[
     ____      _  _____ _____ _     ____             __ 
    |  _ \    / \|_   _| ____| |   |  _ \ _ __ ___  / _|
    | |_) |  / _ \ | | |  _| | |   | |_) | '__/ _ \| |_ 
    |  _ <  / ___ \| | | |___| |___|  __/| | | (_) |  _|
    |_| \_\/_/   \_\_| |_____|_____|_|   |_|  \___/|_|  
]])

    local app_cmd_w_prefix = prefix == " " and user_bin_with_args or prefix..user_bin_with_args

    Message:print ("RPROF: Application profiled :    '"..bin.."'")
    Message:print ("RPROF: Application Command :     '"..app_cmd_w_prefix.."'")
    Message:print ("RPROF: Preloaded tool :          '"..ld_preload[1].."'")
    Message:print ("RPROF: Plugin used :             '"..plugin_path.."'")
    Message:print ("RPROF: Profiling enabled for :   '"..table.concat(opt.enabled_domain, ", ").."'")

    env.set_number_of_kernel_env_var(bin)
    env.set_number_of_queue_env_var()
    env.set_env("LD_PRELOAD", table.concat(ld_preload, ":"))

    local env_var = env.get_env()
    local run_command = prefix.."env "..env_var.." "..bin_with_args
    if launch_command and launch_script and ratelprof.fs.exists(launch_script) then
        Message:print ("RPROF: Running :                 '"..launch_command.." "..launch_script.."'")
        script_execution (run_command, launch_command, launch_script)
    else
        normal_execution (run_command)
    end

    Message:print ("RPROF: Exiting tool . . .")
end

return profile