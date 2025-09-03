local agent_helper = require("commands.inspect.agent_helper")

local main_panel = {}

local function get_rows(data)
    local rows = {}
    for _, entry in ipairs(data) do
        local subrows
        if entry.subvalue then 
            subrows = get_rows(entry.subvalue)
        end
        table.insert(rows, {
            cells   = {entry.label, entry.value},
            tooltip = entry.desc,
            subrows = subrows,
        })
    end
    return rows
end

local function collect_entries(data, keys)
    local out = {}
    local keyset = {}
    for _, k in ipairs(keys) do
        keyset[k] = true
    end
    for _, entry in ipairs(data) do
        if keyset[entry.key] then
            out[#out+1] = {
                cells   = {entry.label, entry.value},
                tooltip = entry.desc
            }
        end
    end
    return out
end


local function rearrange_profiling_summary_rows(global_summary, analyzed_data)
    local rows = get_rows(global_summary)

    -- Longest activity & total bytes
    for _, e in ipairs(collect_entries(analyzed_data, { "longest_activity", "total_bytes" })) do
        rows[#rows+1] = e
    end

    -- Scores
    local score_data = {
        cells   = {"Scores"},
        colspan = {2},
        visible = true,
        subrows = collect_entries(analyzed_data, { "concurrency_score", "hidden_score" })
    }
    rows[#rows+1] = score_data

    -- Potential Speed Up
    local speedup_data = {
        cells   = {"Potentials Speed Up"},
        colspan = {2},
        visible = true,
        subrows = collect_entries(analyzed_data, {
            "speedup_hidden_copy",
            "speedup_async_copy",
            "speedup_copy_coalescing",
            "speedup_kernel_coalescing"
        })
    }
    rows[#rows+1] = speedup_data

    return rows
end


function main_panel.get_summary_data_as_js_string(data, analyzed_data)
    return JSON:encode({
        profilingSummary = {
            title = "Profiling Summary",
            title_colspan = 2,
            rows = rearrange_profiling_summary_rows(data.global_data, analyzed_data)
        },
        experimentInfo = {
            title = "Experiment Info",
            title_colspan = 2,
            rows = get_rows(data.experiment_info)
        }
    })
end

function main_panel.get_gpu_data_as_js_string(data)
    local gpu_labels, gpu_props = agent_helper.get_gpu_props(data.gpu_props)
    return JSON:encode(gpu_labels), JSON:encode(gpu_props)
end

return main_panel