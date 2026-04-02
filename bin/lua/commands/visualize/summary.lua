
local summary = {}

local function rearrange_data(data)
    local rows = {}
    local current_parent = nil
    local subrows_remaining = 0

    for _, entry in ipairs(data) do

        if entry.type == "sep" then
            subrows_remaining = entry.subrow or 0

            current_parent = {
                cells   = {entry.label},
                tooltip = entry.desc,
                colspan = {2},
                visible = true,
                subrows = {}
            }

            table.insert(rows, current_parent)

        else
            local row = {
                cells   = {entry.label, entry.value},
                tooltip = entry.desc,
            }

            if subrows_remaining > 0 and current_parent then
                table.insert(current_parent.subrows, row)
                subrows_remaining = subrows_remaining - 1
            else
                table.insert(rows, row)
            end
        end
    end

    return rows
end


function summary.process_summary_data(rprofrep, fs, summary_data, summary_dataset)
    local __SUMMARY_DATA__ = {}
    local gpu_path = fs.data.gpus:path()

    local profiling_rows = rearrange_data(summary_data.global_data)
    for idx, data in pairs(summary_dataset) do
        profiling_rows[idx] = table.merge_map(profiling_rows[idx], data)
    end

    __SUMMARY_DATA__.PROFILING = {
        rows = profiling_rows,
    }

    __SUMMARY_DATA__.EXPERIMENT = {
        rows = rearrange_data(summary_data.experiment_info),
    }

    __SUMMARY_DATA__.GPU = {}

    rprofrep:gpu_to_json(gpu_path.."/attribute")

    local gpu_file_list = ratelprof.fs.scanfile(gpu_path)
    for _, file in ipairs(gpu_file_list) do
        if ratelprof.fs.has_extension(file, "json") then
            local output_file = ratelprof.utils.json_to_js(file, "window.currentGPU")
            local node = string.match(output_file, "%d+")
            __SUMMARY_DATA__.GPU[node] = output_file
        end
    end

    fs.data.summary:write("const __SUMMARY_DATA__=", JSON:encode(__SUMMARY_DATA__))
end

return summary