-- summarize_report.lua
local Report = require ("utils.Classes.Report")
local summarize_helper = require("commands.summarize.summarize_helper")

local stats = require("commands.stats")

local summarize_report = {}

local analyzed_data = {
    {key = "concurrency_score",         label = "Concurrency Score (%)",            desc = "Percentage of kernel computation that are in parallel. High concurrency can improve performance."},
    {key = "hidden_score",              label = "Hidden Copy Score (%)",            desc = "Percentage of copy time hidden by kernel computation. "..
                                                                                           "Higher doesn't always mean better performance, "..
                                                                                           "but hide memory copy latency can improve GPU utilization. "..
                                                                                           "(This score doesn't take in consideration async copies hidden by CPU computation.)"},
    {key = "longest_activity",          label = "Longest GPU Activity",             desc = "Longest GPU activity. Can be a kernel, copy operation or a barrier."},
    {key = "total_bytes",               label = "Total bytes transfered",           desc = "Total bytes transferred from/to GPU by memory transfers."},
    {key = "speedup_async_copy",        label = "Perfect HIP Async Copy (Speedup)", desc = "Speed up if all copies were 100% asynchronous"},
    {key = "speedup_hidden_copy",       label = "Perfect Hidden Copy (Speedup)",    desc = "Speed up if all copies were hidden by kernels"},
    {key = "speedup_copy_coalescing",   label = "Copy Coalescing (Speedup)",        desc = "Speed up if all coalescable copies were coalesced"},
    {key = "speedup_kernel_coalescing", label = "Kernel Coalescing (Speedup)",      desc = "Speed up if all coalescable kernels were coalesced"}
}


local function get_attribute(objs, report, key, default)
    local obj = objs[report]
    if obj and obj[key] then
        return obj[key]
    else
        return default or "N/A"
    end
end


function summarize_report.get_analyzed_data(rprofrep, sumarize_opt)
    local raw_option = {
        ["report"] = "all",
        ["output"] = "/tmp/rprof_summarize",
        ["format"] = "csv",
        ["mangled"] = false,
        ["trunc"]   = true,
        ["start"]   = sumarize_opt.start,
        ["stop"]    = sumarize_opt.stop,
        ["enable-progress"] = true
    }

    local stats_report_objs   = stats.process_stats_impl(rprofrep, raw_option)
    local analyze_report_objs = stats.process_analyze_impl(rprofrep, raw_option)

    local async_speedup                 = get_attribute(analyze_report_objs, "hip_memcpy_async",       "speedup_factor", 1)
    local sync_speedup                  = get_attribute(analyze_report_objs, "hip_memcpy_sync",        "speedup_factor", 1)
    local bytes_transferred             = get_attribute(stats_report_objs,   "gpu_mem_size_sum",       "total_transfered_bytes")
    local concurrency_score             = get_attribute(analyze_report_objs, "concurrency",            "score")
    local hidden_score                  = get_attribute(analyze_report_objs, "hidden_transfers",       "score")
    local longest_activity              = get_attribute(stats_report_objs,   "gpu_sum",                "longest_activity")
    local hidden_speedup                = get_attribute(analyze_report_objs, "hidden_transfers",       "speedup_factor")
    local coalescable_kernels_speedup   = get_attribute(analyze_report_objs, "coalescable_kernels" ,   "speedup_factor")
    local coalescable_transfers_speedup = get_attribute(analyze_report_objs, "coalescable_transfers" , "speedup_factor")

    -- Fill analyzed_data
    for _, entry in ipairs(analyzed_data) do
        if entry.key == "concurrency_score" then
            entry.value = summarize_helper.format_percentage(concurrency_score)
        elseif entry.key == "hidden_score" then
            entry.value = summarize_helper.format_percentage(hidden_score)
        elseif entry.key == "longest_activity" then
            entry.value = longest_activity
        elseif entry.key == "total_bytes" then
            entry.value = summarize_helper.format_bytes(bytes_transferred)
        elseif entry.key == "speedup_hidden_copy" then
            entry.value = summarize_helper.format_speedup(hidden_speedup)
        elseif entry.key == "speedup_async_copy" then
            entry.value = summarize_helper.format_speedup(async_speedup * sync_speedup)
        elseif entry.key == "speedup_copy_coalescing" then
            entry.value = summarize_helper.format_speedup(coalescable_transfers_speedup)
        elseif entry.key == "speedup_kernel_coalescing" then
            entry.value = summarize_helper.format_speedup(coalescable_kernels_speedup)
        end
    end

    return analyzed_data, stats_report_objs, analyze_report_objs
end


return summarize_report