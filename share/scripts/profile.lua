-- profile.lua
module ("profile", package.seeall)

require ("settings")

require ("utils.Script")

require ("profile.process")

-- Main script logic
function main(arg)
        
    local attribute = {
        name = "ratelprof profile",
        version = settings._VERSION,
    }
    local script = Script.Script:new(attribute)

    script:set_desc("\n\tProfile an AMD GPU application and trace AMD Library functions")

    script:set_execute_function(process_profiling)

    script:add_argument("application", false, false, "\tThe application to profile.")
    script:add_argument("application-args", true, true, "Arguments of the application.")

    script:add_option("output", "o", "<FILE>", "Output report filename.", true, "report_"..os.date("%Y-%m-%d_%H-%M-%S")..".json")

    script:add_option("whitelist", "w", "<FILE>", "Specify an input file with functions to intercept", true)
    script:add_option("blacklist", "b", "<FILE>", "Specify an input file with functions to not intercept", true)
                            
    script:add_option("plugin", nil, "<PLUGIN>", "Specify the plugin path for RATELProf (options: stdout, json, or custom path)", true, settings.settings._INSTALL_DIR.."/lib/libplugin_json.so")
    
    for _, trace_option in pairs(settings.settings._TRACES) do
        script:add_option(trace_option.option, nil, nil, "\tEnable profiling of "..trace_option.name.." library functions", false)
    end

    script:add_option("hsa-trace-for-rprof", nil, nil, "\tEnable profiling of HSA library functions used in profiling system")
    
    script:add_option("all-trace", nil, nil, "\tEnable profiling of all library functions", false)
                       
    script:execute(arg)
end

-- Run the main function
main(arg)
