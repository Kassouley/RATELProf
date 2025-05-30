local Report        = require ("utils.Classes.Report")

local merge_csv = {}

function merge_csv.get_csv_data(input_file, tmp_dir_path, data, opt)
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
    
    
    local function process_reports(reports_list, has_advice) 
        local content_table = {}
        
        for _, report_name in ipairs(reports_list) do
            local filename = output.."_"..report_name
            local content = get_report_content(filename..".csv")
            local format = '{name:"%s",data:[%s]%s}'
            local msg_format = ',msg:"%s"'
            local msg = ""
            if has_advice then
                local filename_advice = filename.."_msg.txt"
                local content_advice = get_report_content(filename_advice)
                if content_advice then
                    content_advice = string.gsub(content_advice, "\n", "<br>")
                    msg = string.format(msg_format, content_advice)
                end
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
    
        return table.concat(content_table, ",")
    end

    local stats_reports = {
        "omp_region_api_sum",
        "omp_api_sum",
        "omp_target_api_sum",
        "hip_api_sum",
        "hsa_api_sum",
        "gpu_sum",
        "gpu_kern_sum",
        "gpu_mem_time_sum",
        "gpu_mem_size_sum"
    }

    local analyze_reports = {
        "gpu_idle",
        "hip_memcpy_sync",
        "hip_memcpy_async"
    }

    local options = {
        outputs  = {output},
        formats  = {"csv"},
        mangled  = opt.mangled,
        trunc    = opt.trunc,
        timeunit = "ns"
    }

    options.reports = stats_reports
    Report.utils.execute_report(data, input_file, options, ratelprof.consts._ALL_STATS_REPORT)

    options.reports = analyze_reports
    Report.utils.execute_report(data, input_file, options, ratelprof.consts._ALL_RULES_REPORT)

    local stats_content = process_reports(stats_reports, false)
    local analyze_content = process_reports(analyze_reports, true)

    return stats_content, analyze_content
end


return merge_csv