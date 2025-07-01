local Report = require ("utils.Classes.Report")
local main_panel = require("commands.visualize.main_panel")
local msgpack = ratelprof.msgpack


local reports = {}

function reports.get_csv_data(input_file, tmp_dir_path, data, opt)
    local output = ratelprof.fs.concat_path(tmp_dir_path, "rprof_visualize")

    local function process_reports(reports_list, reports_ret_vals)
        local content_table = {}

        for _, report in ipairs(reports_list) do
            local report_name = report.id
            local report_ret = reports_ret_vals[report_name]
            if not report_ret then
                error("A report need to have a return value")
            end
            if not report_ret.skip then
                local name    = report_ret.NAME .. " " .. report_ret.TYPE
                local content = report_ret.vis or report_ret.DATA
                local msg     = report_ret.MSG

                if (content and #content > 0) or msg then
                    local t = {}
                    if name then
                        table.insert(t, string.format('name:"%s"', name))
                    end

                    if #content > 0 then
                        table.insert(t, string.format('content:"%s"', msgpack.encode.auto_encode_to_b64(content)))
                    end

                    if msg then
                        table.insert(t, string.format('msg:"<pre>%s</pre>"', string.gsub(msg, "\n", "<br>")))
                    end

                    table.insert(content_table, string.format('%s:{%s}', report_name, table.concat(t, ",")))
                end
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
        {id = "hip_memcpy_async"},
        {id = "coalescable_transfers"},
        {id = "concurrency"}
    }

    local options = {
        ["outputs"]     = {output},
        ["formats"]     = {"csv"},
        ["mangled"]     = opt.mangled,
        ["trunc"]       = opt.trunc,
        ["timeunit"]    = "ns",
        ["start"]       = opt.start,
        ["stop"]        = opt.stop,
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