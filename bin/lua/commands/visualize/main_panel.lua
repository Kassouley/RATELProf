local agent_helper = require("commands.inspect.agent_helper")

local main_panel = {}

local profiling_summary = {}
local potential_speedup = {}
local experiment_info = {}

profiling_summary.title = "Profiling Summary"
potential_speedup.title = "Potential Speed Up"
experiment_info.title = "Experiment Info"


profiling_summary.rows = {
    {labels = "App Time (s)",            value = "N/A", tooltip = "Application total time"},
    {labels = "GPU Active Time (%%)",    value = "N/A", tooltip = "Total GPU active time including all kernels and copies. "..
                                                                  "This is the time when GPU was not idle, not the sum of all GPU activity time."},
    {labels = "GPU Compute Time (%%)",   value = "N/A", tooltip = "Total time spent in all kernels"},
    {labels = "GPU Copy Time (%%)",      value = "N/A", tooltip = "Total time spent in all memory transfers"},
    {labels = "Concurrency Score (%%)",  value = "N/A", tooltip = "Percentage of kernel computation that are in parallel. High concurrency can improve performance."},
    {labels = "Hidden Copy Score (%%)",  value = "N/A", tooltip = "Percentage of copy time hidden by kernel computation. "..
                                                                  "Higher doesn't always mean better performance, "..
                                                                  "but hide memory copy latency can improve GPU utilization. "..
                                                                  "(This score doesn't take in consideration async copies hidden by CPU computation.)"},
    {labels = "Longest GPU Activity",   value = "N/A", tooltip = "Longest GPU activity. Can be a kernel, copy operation or a barrier."},
    {labels = "Total bytes transfered", value = "N/A", tooltip = "Total bytes transferred from/to GPU by memory transfers."}
}


potential_speedup.rows = {
    {labels = "Perfect HIP Async Copy",  value = "N/A", tooltip = "Speed up if all copies were 100% asynchronous"},
    {labels = "Perfect Hidden Copy",     value = "N/A", tooltip = "Speed up if all copies were hidden by kernels"},
    {labels = "Copy Coalescing",         value = "N/A", tooltip = "Speed up if all coalescable copies were coalesced"},
    {labels = "Kernel Coalescing",       value = "N/A", tooltip = "Speed up if all coalescable kernels were coalesced"}
}

experiment_info.rows = {
    {labels = "Application",     value = "N/A"},
    {labels = "Date",            value = "N/A"},
    {labels = "Tool Version",    value = "N/A"},
    {labels = "Report File",     value = "N/A"},
    {labels = "Domain Traced",   value = "N/A"},
    -- {labels = "Domain Filtered", value = "N/A"},
    -- {labels = "Kernels Number",  value = "N/A"},
}


local function format_bytes(bytes)
    local units = {"B", "KB", "MB", "GB", "TB"}
    local unit_index = 1

    while bytes >= 1000 and unit_index < #units do
        bytes = bytes / 1000
        unit_index = unit_index + 1
    end

    return string.format("%.3f %s", bytes, units[unit_index])
end

local function format_speedup(speedup)
    if speedup < 1 then
        return "N/A"
    else
        return string.format("%.3fx", speedup)
    end
end

local function format_gpu_time(time, app_time)
    local percentage = (time / app_time) * 100
    local time_s = ratelprof.convert.time(time, "ns", "sec")
    return string.format("%.2f %%%% (%.3f s) of App Time", percentage, time_s)
end

local function get_ret_val(ret_vals, report, key, default)
    if ret_vals[report] and ret_vals[report][key] then
        return ret_vals[report][key]
    else
        return default or "N/A"
    end
end


function main_panel.set_profiling_summary(data, stats_ret_vals, analyze_ret_vals)
    local bytes_transferred = get_ret_val(stats_ret_vals,   "gpu_mem_size_sum", "total_bytes")
    local app_time          = data:get_app_dur()
    local app_time_sec      = ratelprof.convert.time(app_time, "ns", "sec")
    local gpu_time          = data:get_gpu_active_time()
    local gpu_compute_time  = data:get_compute_time()
    local gpu_copy_time     = data:get_copy_time()
    

    profiling_summary.rows[1].value = string.format("%.3f s", app_time_sec)
    profiling_summary.rows[2].value = format_gpu_time(gpu_time, app_time)
    profiling_summary.rows[3].value = format_gpu_time(gpu_compute_time, app_time)
    profiling_summary.rows[4].value = format_gpu_time(gpu_copy_time, app_time)
    profiling_summary.rows[5].value = get_ret_val(analyze_ret_vals, "concurrency", "score")
    profiling_summary.rows[6].value = get_ret_val(analyze_ret_vals, "hidden_transfers", "score")
    profiling_summary.rows[7].value = get_ret_val(stats_ret_vals,   "gpu_sum",          "longest_activity")
    profiling_summary.rows[8].value = bytes_transferred == "N/A" and "N/A" or format_bytes(bytes_transferred)
end

function main_panel.set_potential_speedup(data, stats_ret_vals, analyze_ret_vals)
    local async_speedup = get_ret_val(analyze_ret_vals, "hip_memcpy_async", "speedup", 1)
    local sync_speedup  = get_ret_val(analyze_ret_vals, "hip_memcpy_sync",  "speedup", 1)

    potential_speedup.rows[1].value = format_speedup(async_speedup * sync_speedup)
    potential_speedup.rows[2].value = format_speedup(get_ret_val(analyze_ret_vals, "hidden_transfers",  "speedup"))
    potential_speedup.rows[3].value = format_speedup(get_ret_val(analyze_ret_vals, "coalescable_kernels" , "speedup"))
    potential_speedup.rows[4].value = format_speedup(get_ret_val(analyze_ret_vals, "coalescable_transfers" , "speedup"))
end

function main_panel.set_experiment_info(data, report_file)
    local domain_traced = data:get_domain_traced()
    local domain_traced_name = {}
    for _, domain in ipairs(domain_traced) do
        table.insert(domain_traced_name, ratelprof.consts._DOMAIN_NAME[domain])
    end

    experiment_info.rows[1].value = data:get_app_name() or "N/A"
    experiment_info.rows[2].value = data:get_app_date() or "N/A"
    experiment_info.rows[3].value = data:get_tool_version() or "N/A"
    experiment_info.rows[4].value = report_file
    experiment_info.rows[5].value = table.concat(domain_traced_name, ", ") or "N/A"
    -- experiment_info.rows[6].value = data:get_domain_filtered() or "N/A"
    -- experiment_info.rows[7].value = data:get_kernels_number() or "N/A"
end


local function return_panel_data_as_js_string(panel_name, summary)
    local js_string = panel_name..":{"..
                        "title:'" .. summary.title .. "',"..
                        "rows:["

    for i, row in ipairs(summary.rows) do
        js_string = js_string .. "{" ..
                        "label:'" .. row.labels .. "'," ..
                        "value:'" .. row.value .. "'"
        if row.tooltip then
            js_string = js_string .. "," ..
                        'tooltip:"' .. row.tooltip .. '"'
        end
        js_string = js_string ..  "}"

        if i < #summary.rows then
            js_string = js_string .. ","
        end
    end

    js_string = js_string .. "]}"
    return js_string
end


local function get_profiling_summary_as_js_string()
    return return_panel_data_as_js_string("profilingSummary", profiling_summary)
end

local function get_potential_speedup_as_js_string()
    return return_panel_data_as_js_string("potentialSpeedUp", potential_speedup)
end

local function get_experiment_info_as_js_string()
    return return_panel_data_as_js_string("experimentInfo", experiment_info)
end

function main_panel.get_summary_data_as_js_string()
    local profiling_summary_js = get_profiling_summary_as_js_string()
    local potential_speedup_js = get_potential_speedup_as_js_string()
    local experiment_info_js = get_experiment_info_as_js_string()
    return '{'..table.concat({profiling_summary_js, potential_speedup_js, experiment_info_js}, ",")..'}'
end

function main_panel.get_gpu_data_as_js_string()
    
    local gpu_labels, gpu_props = agent_helper.get_gpu_props()

    local gpu_labels_as_js_string = '["'..table.concat(gpu_labels, '","')..'"]'

    local gpu_props_as_js_string = ""
    for node_id, props in pairs(gpu_props) do
        gpu_props_as_js_string = gpu_props_as_js_string .. 
            "{'Node " .. node_id .. "':[" .. table.concat(props, ",") .. "]},"
    end

    return gpu_labels_as_js_string, gpu_props_as_js_string
end

return main_panel