local consts_helper = {}

local trace_list = {}
for k, _ in pairs(ratelprof.consts._TRACES) do
    table.insert(trace_list, k)
end
table.sort(trace_list)

local function collect_defaults(reports)
    local result = {}
    for id, report in pairs(reports) do
        if report.default then
            result[#result + 1] = id
        end
    end
    return result
end

local default_reports   = collect_defaults(ratelprof.consts.STATS_REPORTS)
local default_rules     = collect_defaults(ratelprof.consts.ANALYZE_REPORTS)
local default_breakdown = collect_defaults(ratelprof.consts.BREAKDOWN_REPORTS)


consts_helper.profile = {
    desc = "\n\tProfile an AMD GPU application and trace AMD Library functions",
    args = {
        {
            name = "application",
            desc = "The application binary to profile.",
            is_optional = false,
            is_list = false
        },
        {
            name = "application-args",
            desc = "Arguments of the application.",
            is_optional = true,
            is_list = true
        }
    },
    opt = {
        output = {
            desc            = "Output report filename.",
            sname           = "o",
            arg             = "<FILE>",
            arg_required    = true,
            default         = "report_"..os.date("%Y-%m-%d_%H-%M-%S").."."..ratelprof.consts._REPORT_EXT
        },
        whitelist = {
            desc            = "Specify an input file with functions to intercept",
            sname           = "w",
            arg             = "<FILE>",
            arg_required    = true,
        },
        blacklist = {
            desc            = "Specify an input file with functions to not intercept",
            sname           = "b",
            arg             = "<FILE>",
            arg_required    = true,
        },
        plugin = {
            desc            = "Specify the plugin path for RATELProf (options: msgpack, stdout, or custom path)",
            sname           = nil,
            arg             = "<PLUGIN>",
            arg_required    = true,
            default         = ratelprof.consts._DEFAULT_PLUGIN
        },
        trace = {
            desc            = string.format([[ 

                Possible values are %s.
                Select the API(s) to trace. Multiple APIs can be selected, separated by commas only (no spaces).
                If 'none' is selected, no API is traced.
                'gpu' is equivalent to 'kernel,memory,barrier'.
                'cpu' is equivalent to all other APIs.
                'omp' is equivalent to 'omp-routine,omp-region,omp-tgt-rtl'.
                'all' is equivalent to 'cpu,gpu'.
                Default is 'kernel,memory,hip'.]], "'" .. table.concat(trace_list, "', '") .. "'"),
            sname           = "t",
            arg             = "<API>[,<API>]",
            arg_required    = true,
            default         = "kernel,memory,hip"
        },
        ['log-level'] = {
            desc            = [[ 

                Enable log printing (default: 9 [info+fatal])
                            0000 0001 : info
                            0000 0010 : warning
                            0000 0100 : error
                            0000 1000 : fatal
                            0001 0000 : debug 
                            0001 1111 : all]],
            sname           = nil,
            arg             = "<LOG-LEVEL>",
            arg_required    = true,
            default         = 9
        },
        prefix = {
            desc            = "Add a prefix to the command application. (e.g. --prefix='mpirun -np 4').",
            sname           = "p",
            arg             = "<CMD PREFIX>",
            arg_required    = true,
            default         = ""
        },
        ['launch-script'] = {
            desc            = [[ 

                Script used to launch application. Executes <launch-command> <launch-script>.
                In this script, replace application run command with "<run_command>".]],
            sname           = "ls",
            arg             = "<path to launch script>",
            arg_required    = true,
            default         = nil
        },
        ['launch-command'] = {
            desc            = [[ 

                Interpreter (e.g bash, python) or batch submission command (e.g sbatch, qsub)
                to launch <launch-script> (as prefix). If omitted, run normally.]],
            sname           = "lc",
            arg             = "<launch command>",
            arg_required    = true,
            default         = nil
        }
    }
}

consts_helper.stats = {
    cmd = "stats",
    args = {
        {
            name = "report-file",
            desc = "Path(s) to the "..ratelprof.consts._REPORT_EXT.." report file(s).",
            is_optional = false,
            is_list = true
        },
    },
    desc = "\n\tGenerate differents types of statistical report based on report file",
    opt = {
        report = {
            desc            = [[ 
                Specify the report(s) to generate.
                This option may be used multiple times. If no reports are given, 
                the following will be used as the default report set:

                        ]]..table.concat(default_reports, "\n\t\t\t")..[[ 

                See --help-reports for a list of built-in reports, along with more
                information on each report.

                Alias are:
                    - all-agg-sum: Generate all Aggregated reports (<api>_api_sum, gpu_sum, ...)
                    - all-per-sum: Generate all Per-Mode reports (per_pid_<api>_api_sum, per_gpu_sum, ...)
                    - all-trace: Generate all Trace reports
                    - all: Generate all summary reports]],
            sname           = "r",
            arg             = "<name[:args...][,name[:args...]...]>",
            arg_required    = true,
            default         = table.concat(default_reports, ",")
        },
        output = {
            desc            = [[ 
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
            sname           = "o",
            arg             = "<output[,output...]>",
            arg_required    = true,
            default         = "-"
        },
        format = {
            desc            = [[ 
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
            sname           = "f",
            arg             = "<format[,format...]>",
            arg_required    = true,
            default         = nil
        },
        ['help-reports'] = {
            desc            = [[ 
                Display help information about the available reports.]],
            sname           = nil,
            arg             = nil,
            arg_required    = false,
            default         = nil,
            early_exit      = true
        },
        timeunit = {
            desc            = [[ 
                Set basic unit of time. The default is nanoseconds.
                Possible values are: ns, us, ms, sec.]],
            sname           = nil,
            arg             = "<time unit>",
            arg_required    = true,
            default         = "ns"
        },
        sizeunit = {
            desc            = [[ 
                Set basic unit of size. The default is KB.
                Possible values are: B, KB, MB, GB.]],
            sname           = nil,
            arg             = "<size unit>",
            arg_required    = true,
            default         = "KB"
        },
        ['only-main'] = {
            desc            = [[ 
                Process only events from main phase.]],
            sname           = nil,
            arg             = nil,
            arg_required    = false,
            default         = nil
        },
        mangled = {
            desc            = [[ 
                Use the mangled name of the function in the report.]],
            sname           = "m",
            arg             = nil,
            arg_required    = false,
            default         = nil
        },
        trunc = {
            desc            = [[ 
                Truncate function arguments from demangled kernel names.]],
            sname           = "t",
            arg             = nil,
            arg_required    = false,
            default         = nil
        },
        ['max-col-width'] = {
            desc            = [[ 
                Define the columns max width for table and column format.]],
            sname           = "C",
            arg             = "<width>",
            arg_required    = true,
            default         = 32
        },
        ['max-lines'] = {
            desc            = [[ 
                Define the maximum lines to show inside the report.
                Note : Default for file output is 'all'.
                ]],
            sname           = "L",
            arg             = "<number|all>",
            arg_required    = true,
            default         = nil
        },
        notation = {
            desc            = [[ 
                Change number notation of output reports.
                Possible values : 'raw', 'scientific', 'engineering' or 'thousands-separator'
                Default is 'scientific' for csv/tsv format, and 'thousands-separator' for other.
                If value is invalid, option is skipped and default is used.]],
            sname           = nil,
            arg             = "<notation>",
            arg_required    = true,
            default         = nil
        },
        start = {
            desc            = [[ 
                Process only trace after 'start' argument (in nanoseconds). 
                Default 'start' is 0 (Application start).]],
            sname           = nil,
            arg             = "<value>",
            arg_required    = true,
            default         = nil
        },
        stop = {
            desc            = [[ 
                Process only trace before 'stop' argument (in nanoseconds). 
                Default 'stop' is until application end.]],
            sname           = nil,
            arg             = "<value>",
            arg_required    = true,
            default         = nil
        },
        gpus = {
            desc            = [[ 
                List of the GPUs to analyzed. Can be useful in per-gpu mode for statistics reports or in analyze command to focus on specific GPUs.
                If not specify, analyze all GPUs.]],
            sname           = nil,
            arg             = "<gpu id>[,<gpu_id>]",
            arg_required    = true,
            default         = nil
        },
        pids = {
            desc            = [[ 
                List of the Process to analyzed. Can be useful in per-pid mode for statistics reports or in analyze command to focus on specific PIDs.
                If not specify, analyze all Process.]],
            sname           = nil,
            arg             = "<pid>[,<pid>]",
            arg_required    = true,
            default         = nil
        },
        template = {
            desc            = [[ 
                Generate a template config file that can be used in --config option to customize reports generation.]],
            sname           = nil,
            arg             = nil,
            arg_required    = false,
            default         = nil,
            early_exit      = true
        },
        config = {
            desc            = [[ 
                Path to a JSON configuration file that specifies the reports to generate and their options.
                If this option is provided, it overrides any --timeunit, --sizeunit, --mangled, --trunc, --report, --format, and --output options.]],
            sname           = "c",
            arg             = "<config file>",
            arg_required    = true,
            default         = nil
        },
    }
}


consts_helper.analyze = {
    cmd = "analyze",
    args = {
        {
            name = "report-file",
            desc = "Path to the "..ratelprof.consts._REPORT_EXT.." report file.",
            is_optional = false,
            is_list = true
        },
    },
    desc = "\n\tAnalyze a report file and give advice about possible optimizations.",
    opt = table.deep_copy(consts_helper.stats.opt)
}
consts_helper.analyze.opt.report = {
            desc            = [[ 
                Specify the rule(s) to generate.
                This option may be used multiple times. If no rules are given, 
                the following will be used as the default rule set:

                        ]]..table.concat(default_rules, "\n\t\t\t")..[[ 

                See --help-rules for a list of built-in rules, along with more
                information on each rule.
                
                Alias are:
                    - all: Generate all rules analyze]],
            sname           = "r",
            arg             = "<name[:args...][,name[:args...]...]>",
            arg_required    = true,
            default         = table.concat(default_rules, ",")
        }

consts_helper.analyze.opt['help-reports'] = nil
consts_helper.analyze.opt['help-rules'] = {
            desc            = [[ 
                Display help information about the available rules.]],
            sname           = nil,
            arg             = nil,
            arg_required    = false,
            default         = nil,
            early_exit      = true
        }



consts_helper.breakdown = {
    cmd = "breakdown",
    args = {
        {
            name = "report-file",
            desc = "Path to the "..ratelprof.consts._REPORT_EXT.." report file.",
            is_optional = false,
            is_list = true
        },
    },
    desc = "\n\tGive a time breakdown of the profiling report.",
    opt = table.deep_copy(consts_helper.stats.opt)
}
consts_helper.breakdown.opt.report = {
            desc            = [[ 
                Specify the breakdown(s) to generate.
                This option may be used multiple times. If no breakdowns are given, 
                the following will be used as the default breakdown set:

                        ]]..table.concat(default_breakdown, "\n\t\t\t")..[[ 

                See --help-reports for a list of built-in rules, along with more
                information on each rule.
                
                Alias are:
                    - all: Generate all rules analyze]],
            sname           = "r",
            arg             = "<name[:args...][,name[:args...]...]>",
            arg_required    = true,
            default         = table.concat(default_breakdown, ",")
        }

consts_helper.breakdown.opt['help-reports'] = nil
consts_helper.breakdown.opt['help-breakdown'] = {
            desc            = [[ 
                Display help information about the available breakdowns.]],
            sname           = nil,
            arg             = nil,
            arg_required    = false,
            default         = nil,
            early_exit      = true
        }
consts_helper.breakdown.opt['timeunit'].desc = [[ 
                Set basic unit of time. The default is milliseconds.
                Possible values are: ns, us, ms, sec.]]
consts_helper.breakdown.opt['timeunit'].default = "ms"
consts_helper.breakdown.opt['sizeunit'] = nil
consts_helper.breakdown.opt['mangled']  = nil
consts_helper.breakdown.opt['trunc']    = nil



consts_helper.inspect = {
    cmd = "inspect",
    args = {
        {
            name = "application",
            desc = "Path to the application to inspect.",
            is_optional = true,
            is_list = false
        }
    },
    desc = "\n\tInspect an AMD GPU application and output data about kernels from the application.",
    opt = {
        info = {
            desc            = [[
                Specify the information to inspect.
                Possible values are: 'gpu', 'kernels'.
                Default is 'kernels'.]],
            sname           = "i",
            arg             = "<info>",
            arg_required    = true,
            default         = "kernels"
        },
        ['save-json'] = {
            desc            = [[ 
                Save all metadata in a JSON file in addition to the CSV file.]],
            sname           = "s",
            arg             = nil,
            arg_required    = false,
            default         = nil
        },
        output_dir = {
            desc            = [[ 
                Change the directory of the CSV output file.]],
            sname           = "o",
            arg             = "<output_dir>",
            arg_required    = true,
            default         = nil
        },
        mangled = {
            desc            = [[ 
                Use the mangled kernel name.]],
            sname           = "m",
            arg             = nil,
            arg_required    = false,
            default         = nil
        },
        trunc = {
            desc            = [[ 
                Truncate function arguments from demangled kernel names.]],
            sname           = "t",
            arg             = nil,
            arg_required    = false,
            default         = nil
        }
    }
}

consts_helper.visualize = {
    cmd = "visualize",
    args = {
        {
            name = "report-file",
            desc = "Path to the "..ratelprof.consts._REPORT_EXT.." report file.",
            is_optional = false,
            is_list = false
        }
    },
    desc = "\n\tGenerate a HTML report view to see traces as a timeline.",
    opt = {
        tmp = {
            desc            = [[ 
                Specify a temp directory to save CSV statistics output (default: /tmp)]],
            sname           = "t",
            arg             = "<DIR>",
            arg_required    = true,
            default         = "/tmp"
        },
        output = {
            desc            = [[ 
                Change the path to the output html report.]],
            sname           = "o",
            arg             = "<output_file>",
            arg_required    = true,
            default         = nil
        },
        start = {
            desc            = [[ 
                Visualize only trace after 'start' argument (in nanoseconds). 
                Default 'start' is 0 (Application start).]],
            sname           = nil,
            arg             = "<value>",
            arg_required    = true,
            default         = nil
        },
        stop = {
            desc            = [[ 
                Visualize only trace before 'stop' argument (in nanoseconds). 
                Default 'stop' is until application end.]],
            sname           = nil,
            arg             = "<value>",
            arg_required    = true,
            default         = nil
        }
    }
}

consts_helper.export = {
    cmd = "export",
    args = {
        {
            name = "report-file",
            desc = "Path to the "..ratelprof.consts._REPORT_EXT.." report file.",
            is_optional = false,
            is_list = true
        }
    },
    desc = "\n\tGenerate an export file from an existing "..ratelprof.consts._REPORT_EXT.." report.",
    opt = {
        type = {
            desc            = [[ 
                Possible values are: json, arg-info.
                Export format type.]],
            sname           = "t",
            arg             = "<type>",
            arg_required    = true,
            default         = nil
        }
    }
}


consts_helper.summarize = {
    cmd = "summarize",
    args = {
        {
            name = "report-file",
            desc = "Path to the "..ratelprof.consts._REPORT_EXT.." report file.",
            is_optional = false,
            is_list = true
        }
    },
    desc = "\n\tSummarize global metrics about a report file.",
    opt = {
        ["save-csv"] = {
            desc            = [[ 
                Save report outputs as CSV format in <DIR>.]],
            sname           = "s",
            arg             = "<DIR>",
            arg_required    = false,
            default         = false
        },
        gpus = {
            desc            = [[ 
                List of the GPUs to analyzed. Can be useful in per-gpu mode for statistics reports or in analyze command to focus on specific GPUs.
                If not specify, analyze all GPUs.]],
            sname           = nil,
            arg             = "<gpu id>[,<gpu_id>]",
            arg_required    = true,
            default         = nil
        },
        pids = {
            desc            = [[ 
                List of the Process to analyzed. Can be useful in per-pid mode for statistics reports or in analyze command to focus on specific PIDs.
                If not specify, analyze all Process.]],
            sname           = nil,
            arg             = "<pid>[,<pid>]",
            arg_required    = true,
            default         = nil
        },
    },
}


return consts_helper