local helper = {}

-- Function to handle version info
function helper.print_version(settings)
    print("stats version "..settings._VERSION)
    os.exit(0)
end

-- Function to print the help message
function helper.print_help(settings)
    print(string.format([[
Usage: stats [<args>] <input-file>

Arguments:
    -h, --help           Show this help message and exit

    -v, --version        Show the version of this script

    -r, --report <name[,name...]>
                       Specify the report(s) to generate.
                       This option may be used multiple times. If no reports are given, 
                       the following will be used as the default report set:

                                 %s

                       See --help-reports for a list of built-in reports, along with more
                       information on each report.

    -o, --output <output>
                       Specify the output mechanism. There are three output mechanisms:
                       print to console, output to file, or output to command. If no
                       outputs are designated, the default is to print reports to the
                       console.
                       This option may be used multiple times. Multiple outputs may also
                       be specified using a comma-separated list.

                       If the given output name is "-", the output will be displayed
                       on the console. If the output name starts with "@", the output
                       designates a command to run. The command will be executed and
                       the analysis output will be piped into the command. Any other output
                       is assumed to be the base path and name for a file.

                       If a file basename is given, the filename used will be:
                          <basename>_<report>.<output_format>
                       The output "." can be used to indicate the analysis should be output
                       to a file, and the default basename should be used.
                       If the output starts with "@", the output is piped to the given command.

    -f, --format <name[,name...]>
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
                       be specified using a comma-separated list.
    --timeunit <time unit>

                       Set basic unit of time. The default is nanoseconds.
                       Longest prefix matching is done on the following units:
              
                          ns -> nanoseconds
                          us -> microseconds
                          ms -> milliseconds
                          sec -> seconds
]], table.concat(settings._DEFAULT_REPORT, "\n\t\t\t\t ")))
    os.exit(0)
end

return helper
