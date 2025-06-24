local Report = require ("utils.Classes.Report")
local main_panel = require("commands.visualize.main_panel")


local reports = {}


function reports.get_csv_data(input_file, tmp_dir_path, data, opt)
    local output = ratelprof.fs.concat_path(tmp_dir_path, "rprof_visualize")

    local function get_report_content(filename)
        if ratelprof.fs.exists(filename) then
            local file = ratelprof.fs.open_file(filename, "r") 
            local content = string.gsub(file:read("*a"), "%%", "%%%%")
            file:close()
            if tmp_dir_path == "/tmp" then
                os.remove(filename)
            end
            return content
        end
        return nil
    end
    
    
    local function process_reports(reports_list, reports_ret_vals)
        local content_table = {}

        for _, report in ipairs(reports_list) do
            local report_name = report.id
            local report_ret = reports_ret_vals[report_name]
            local filename = output.."_"..report_name
            local content = get_report_content(filename..".csv")
            local format = '"%s":{content:[%s]%s}'
            local msg_format = ',msg:"<pre>%s</pre>"'
            local msg = ""
            if report_ret and report_ret.advice then
                msg = string.format(msg_format, string.gsub(report_ret.advice, "\n", "<br>"))
            end
            if content then
                local rows = content:split("\n");
                local array_data = {}
                for _, col in ipairs(rows) do
                    table.insert(array_data, "'"..col.."'")
                end
                table.insert(content_table, string.format(format, report_name, table.concat(array_data, ","), msg))
            elseif msg ~= "" then
                table.insert(content_table, string.format(format, report_name, "", msg))
            end
        end
    
        return '{'..table.concat(content_table, ",")..'}'
    end

    local stats_reports = {
        {id = "omp_region_api_sum"},
        {id = "omp_api_sum"},
        {id = "omp_target_api_sum"},
        {id = "hip_api_sum"},
        {id = "hsa_api_sum"},
        {id = "gpu_sum"},
        {id = "gpu_kern_sum"},
        {id = "gpu_mem_time_sum"},
        {id = "gpu_mem_size_sum"}
    }

    local analyze_reports = {
        {id = "coalescable_kernels"},
        {id = "hidden_transfers"},
        {id = "gpu_idle"},
        {id = "hip_memcpy_sync"},
        {id = "hip_memcpy_async"}
    }

    local options = {
        outputs  = {output},
        formats  = {"csv"},
        mangled  = opt.mangled,
        trunc    = opt.trunc,
        timeunit = "ns"
    }

    options.reports = stats_reports
    local stats_ret_vals = Report.utils.execute_report(data, input_file, options, ratelprof.consts._ALL_STATS_REPORT, true, "Report statistics")

    options.reports = analyze_reports
    local analyze_ret_vals = Report.utils.execute_report(data, input_file, options, ratelprof.consts._ALL_RULES_REPORT, true, "Report analysis")

    local stats_content = process_reports(stats_reports, stats_ret_vals)
    local analyze_content = process_reports(analyze_reports, analyze_ret_vals)
   
    main_panel.set_profiling_summary(data, stats_ret_vals, analyze_ret_vals)
    main_panel.set_potential_speedup(data, stats_ret_vals, analyze_ret_vals)
    main_panel.set_experiment_info(data, input_file)

    return '{"stats":'..stats_content..', "analyze":'..analyze_content..'}'
end


return reports