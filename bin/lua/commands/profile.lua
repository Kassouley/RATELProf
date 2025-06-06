local env = require ("commands.profile.env")

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

    local traces_list = ratelprof.get_opt_val(options, "trace"):split(",")
    for _, trace_name in ipairs(traces_list) do
        local trace = ratelprof.consts._TRACES[trace_name]
        if trace then
            if type(trace.var) == "table" then
                for _, var in ipairs(trace.var) do
                    env.set_env(var, "1")
                end
            else
                env.set_env(trace.var, "1")
            end
        else
            Message:error("Trace '"..trace_name.."' is not supported. Skipping it.")
        end
    end 

    local plugin_path = ratelprof.get_opt_val(options, "plugin")
    if plugin_path then
        if plugin_path == "stdout"        then plugin_path = ratelprof.consts._LIBS.PLUGIN_STDOUT
        elseif plugin_path == "msgpack"   then plugin_path = ratelprof.consts._LIBS.PLUGIN_MSGPACK
        elseif plugin_path == "json"      then plugin_path = ratelprof.consts._LIBS.PLUGIN_JSON
        elseif plugin_path == "json-dyn"  then plugin_path = ratelprof.consts._LIBS.PLUGIN_JSON_DYN end
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
        output = output,
        plugin = plugin_path,
    }
end


local function normal_execution(cmd)
    local ret_code = os.execute(cmd)
    if ret_code ~= 0 then
        Message:error("Application execution failed - code("..ret_code..").")
        Message:error("Run command : '"..cmd.."'")
        os.exit(ret_code)
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


function profile.process_profiling(positional_args, options_values)
    local application_command = positional_args
    local application = application_command[1]
    
    local opt = handle_profile_option(options_values)
    local launch_script     = opt.launch_script
    local launch_command    = opt.launch_command
    local prefix            = opt.prefix
    local output_file       = opt.output
    local plugin_path       = opt.plugin

    if not ratelprof.fs.exists(application) then
        Message:print("No application to profile or '"..application.."' doesn't exists.")
        os.exit(1)
    end
    
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


    env.set_number_of_kernel_env_var(application)
    env.set_number_of_queue_env_var()
    env.set_env("LD_PRELOAD", table.concat(ld_preload, ":"))

    local env_var = env.get_env()
    local app_cmd = table.concat(application_command, " ")
    local run_command = env_var.." "..prefix.." "..app_cmd

    Message:print ([[
     ____      _  _____ _____ _     ____             __ 
    |  _ \    / \|_   _| ____| |   |  _ \ _ __ ___  / _|
    | |_) |  / _ \ | | |  _| | |   | |_) | '__/ _ \| |_ 
    |  _ <  / ___ \| | | |___| |___|  __/| | | (_) |  _|
    |_| \_\/_/   \_\_| |_____|_____|_|   |_|  \___/|_|  
]])
    Message:print ("RPROF: Application profiled :    '"..application.."'")
    Message:print ("RPROF: Application Command :     '"..app_cmd.."'")
    Message:print ("RPROF: Preloaded tool :          '"..ld_preload[1].."'")
    Message:print ("RPROF: Preloaded wrapper :       '"..ld_preload[2].."'")
    Message:print ("RPROF: Plugin used :             '"..plugin_path.."'")
    Message:print ("RPROF: Profiling output file :   '"..output_file.."'")

    if launch_command and launch_script and ratelprof.fs.exists(launch_script) then
        Message:print ("RPROF: Running :                 '"..launch_command.." "..launch_script.."'")
        script_execution (run_command, launch_command, launch_script)
    else
        normal_execution (run_command)
    end

    local bytes_written = ratelprof.fs.get_size(output_file)
    Message:print ("RPROF: Bytes written in '"..output_file.."' : "..bytes_written)
    Message:print ("RPROF: Exiting tool . . .")
end

return profile