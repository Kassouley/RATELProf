-- inspect.lua
module ("inspect", package.seeall)

require ("settings")

require ("utils.Script")

require ("inspect.process")

-- Main script logic
function main(arg)
        
    local attribute = {
        name = "ratelprof inspect",
        version = settings._VERSION,
    }
    local script = Script.Script:new(attribute)

    script:set_desc("\n\tInspect an application and output data about kernels from the application.")
    
    script:set_execute_function(process_inspecting)

    script:add_argument("application", false, false, "\tThe application to inspect.")

    script:add_option("save-json", "s", nil, 
                    "\tSave all metadata in a JSON file in addition to the CSV file.", false)

    script:add_option("output", "o", "<output_file>", 
                    "\tChange the CSV output file.", true)

                    
    script:add_option("mangled", "m", nil, 
                    "\tDo not demangled kernel name.", false)
                    
                    
    script:add_option("trunc", "t", nil, 
                    "\tTruncate function arguments from demangled kernel names.", false)

    script:execute(arg)
end

-- Run the main function
main(arg)
