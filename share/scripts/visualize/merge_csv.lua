local lfs      = require("utils.lfs")
local stats    = require("stats.stats")
local settings = require("settings")

local merge_csv = {}

function merge_csv.get_csv_data(report_json, tmp_dir_path)
    local prefix = "rprof_visualize"

    local reports = {
        "omp_api_sum",
        "omp_target_api_sum",
        "hip_api_sum",
        "hsa_api_sum",
        "gpu_sum",
        "gpu_kern_sum",
        "gpu_mem_time_sum",
        "gpu_mem_size_sum"
    }

    local output = lfs.concat_path(tmp_dir_path, prefix)
    stats.execute_report(reports, {output}, {"csv"}, report_json, {trunc = true, timeunit = "ns"})

    local content_table = {}
    for _, report_name in ipairs(reports) do
        local file = output.."_"..report_name..".csv"
        if lfs.file_exists(file) then
            local file_handle = lfs.open_file(file, "r") 
            local csv_content = string.gsub(file_handle:read("*a"), "\n", "\\n")
            local tmp = '{name:"'..report_name..'",data:"'..csv_content..'"}'
            table.insert(content_table, tmp)
            file_handle:close()
            if tmp_dir_path == "/tmp" then
                os.remove(file)
            end
        end
    end
    local csv_content = table.concat(content_table, ",")
    return csv_content:gsub("%%", "%%%%")
end

return merge_csv