module ("profile.process", package.seeall)

require ("utils.lfs")

require ("profile.env")

local function handle_option(options)
    if options["blacklist"] then    profile:set_filter_env_var(options["blacklist"], 1) end
    if options["whitelist"] then    profile:set_filter_env_var(options["whitelist"], 2) end
    if options["output"] then       profile:set_env(settings._ENV.OUTPUT_FILE, options["output"]) end

    for _, trace_option in pairs(settings.settings._TRACES) do
        if options["all-trace"] or options[trace_option.option] then profile:set_env(trace_option.var, "1") end
    end 

    if options["hsa-trace-for-rprof"] then profile:set_env(settings._ENV.DOMAIN_PROFILING, "1") end

    local plugin_path = options["plugin"]
    if plugin_path then
        if plugin_path == "stdout"        then plugin_path = settings.settings._INSTALL_DIR..'/lib/libplugin_stdout.so'
        elseif plugin_path == "json"      then plugin_path = settings.settings._INSTALL_DIR..'/lib/libplugin_json.so'
        elseif plugin_path == "json-dyn"  then plugin_path = settings.settings._INSTALL_DIR..'/lib/libplugin_json_dyn.so' end
        if not lfs.file_exists(plugin_path) then
            print("Error: Plugin library '"..plugin_path.."' not found.")
            os.exit(1)
        end
        profile:set_env(settings._ENV.PLUGIN_PATH, plugin_path) 
    end
end


function profile:process_profiling(positional_args, options_values)
    local application_command = positional_args
    local application = application_command[1]
    print(application)
    handle_option(options_values)
    local output_file = options_values.output
    local plugin_path = options_values.plugin

    if not lfs.file_exists(application) then
        print("No application to profile.")
        os.exit(1)
    end

    local preload_libs = {
        settings.settings._INSTALL_DIR.."/lib/libratelprof.so",
        settings.settings._INSTALL_DIR.."/lib/libratelprof_wrapper.so"
    }
    
    for _, lib in ipairs(preload_libs) do
        if not lfs.file_exists(lib) then
            print("Error: Preload library '"..lib.."' not found.")
            os.exit(1)
        end
    end
    
    local preload_lib = table.concat(preload_libs, ":")

    profile:set_number_of_kernel_env_var(application)
    profile:set_number_of_queue_env_var()
    profile:set_env("LD_PRELOAD", preload_lib)
    local env_var = profile:get_env()

    print([[
     ____      _  _____ _____ _     ____             __ 
    |  _ \    / \|_   _| ____| |   |  _ \ _ __ ___  / _|
    | |_) |  / _ \ | | |  _| | |   | |_) | '__/ _ \| |_ 
    |  _ <  / ___ \| | | |___| |___|  __/| | | (_) |  _|
    |_| \_\/_/   \_\_| |_____|_____|_|   |_|  \___/|_|  
]])
    print("RPROF: Application profiled :    '"..application.."'")
    print("RPROF: Application Command :     '"..table.concat(application_command, " ").."'")
    print("RPROF: Preloaded tool :          '"..preload_libs[1].."'")
    print("RPROF: Preloaded wrapper :       '"..preload_libs[2].."'")
    print("RPROF: Plugin used :             '"..plugin_path.."'")
    print("RPROF: Profiling output file :   '"..output_file.."'")
    local ret_code = os.execute(env_var.." "..table.concat(application_command, " "))
    if ret_code ~= 0 then
        print("Error: Application execution failed - code("..ret_code..").")
        os.exit(ret_code)
    end
    local bytes_written = common.execute_command("cat "..output_file.." | wc -c")
    print("RPROF: Bytes written in '"..output_file.."' : "..bytes_written)
    print("RPROF: Exiting tool . . .")
end
