-- visualize.lua
local settings  = require ("settings")
local Script    = require ("utils.Script")
local visualize = require ("visualize.visualize")

-- Main script logic
local function main(arg)
        
    local attribute = {
        name = "ratelprof visualize",
        version = settings._VERSION
    }
    local script = Script:new(attribute)

    script:set_desc("\n\tGenerate a HTML report view to see traces as a timeline.")

    script:set_execute_function(visualize.process_visualizing)

    script:add_argument("report", false, false, "\tThe JSON report path to visualize.")

    script:add_option("tmp", "t", "<DIR>", 
                      "Specify a temp directory to save CSV statistics output (default: /tmp)", true)

    script:execute(arg)
end

-- Run the main function
main(arg)
