-- stats.lua
module ("stats", package.seeall)

require ("settings")

require ("stats.process")

require ("utils.Script")

-- Main script logic
local function stats(arg)

    local attribute = {
        name = "ratelprof stats",
        version = settings._VERSION,
    }
    local script = Script.Script:new(attribute)

    script:set_desc("\n\tGenerate differents types of report based on report file")

    script:set_execute_function(process_stats)

    script:add_argument("report-file", false, false, "Path to the report file.")

    local default_reports = {}
    for _, report in ipairs(settings.settings._ALL_REPORT) do
        if report.default == true then
            table.insert(default_reports, report.name)
        end
    end

    -- TODO (11-11-2024) : Implement --help-report
    script:add_option("report", "r", "<name[,name...]>", 
[[                  
                            Specify the report(s) to generate.
                            This option may be used multiple times. If no reports are given, 
                            the following will be used as the default report set:

                                 ]]..table.concat(default_reports, "\n\t\t\t\t ")..[[ 

                            See --help-reports for a list of built-in reports, along with more
                            information on each report.]], 
                            true, default_reports)

                            
    script:add_option("output", "o", "<output[,output...]>", 
[[                  
                            Specify the output mechanism. There are three output mechanisms:
                            print to console, output to file, or output to command. If no
                            outputs are designated, the default is to print reports to the
                            console.
                            This option may be used multiple times. Multiple outputs may also
                            be specified using a comma-separated list.
     
                            If the given output name is "-", the output will be displayed
                            on the console. 
                            If the output name starts with "@", the output designates a 
                            command to run. The command will be executed and the analysis 
                            output will be piped into the command. Any other output
                            is assumed to be the base path and name for a file.
     
                            If a file basename is given, the filename used will be:
                               <basename>_<report>.<output_format>
                            The output "." can be used to indicate the analysis should be output
                            to a file, and the default basename should be used.]], 
                            true, "-")

    script:add_option("format", "f", "<format[,format...]>", 
[[                  
                            Specify the output format. The special name "." indicates the
                            default format for the given output.

                            The default format for console is:    column
                            The default format for files is:      csv
                            The default format for processes is:  csv

                            Available formats (and file extensions):

                                column     Human readable columns (.txt)
                                table      Human readable table (.txt)
                                csv        Comma Separated Values (.csv)
                                tsv        Tab Separated Values (.tsv)

                            This option may be used multiple times. Multiple formats may also
                            be specified using a comma-separated list.]], 
                            true)

                            
    script:add_option("timeunit", nil, "<time unit>", 
[[                  
                            Set basic unit of time. The default is nanoseconds.
                            Longest prefix matching is done on the following units:

                            ns -> nanoseconds
                            us -> microseconds
                            ms -> milliseconds
                            sec -> seconds]], 
                            true, "ns")

                            
    script:add_option("only-main", nil, nil, 
[[                  
                            Will compute only statistic for traces from main phase.]], 
                            false)

                            
    script:add_option("mangled", "m", nil, 
[[                  
                            Do not demangled kernel name.]], 
                            false)
    
    
    script:add_option("trunc", "t", nil, 
[[                  
                            Truncate function arguments from demangled kernel names.]], 
                            false)
                       
    script:execute(arg)
end

-- Run the main function
stats(arg)