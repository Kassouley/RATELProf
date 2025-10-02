-- summarize_report.lua
local Report = require ("utils.Classes.Report")
local summarize_helper = require("commands.summarize.summarize_helper")

local summarize_report = {}

local analyzed_data = {
    {key = "concurrency_score",         label = "Concurrency Score (%)",  desc = "Percentage of kernel computation that are in parallel. High concurrency can improve performance."},
    {key = "hidden_score",              label = "Hidden Copy Score (%)",  desc = "Percentage of copy time hidden by kernel computation. "..
                                                                                 "Higher doesn't always mean better performance, "..
                                                                                 "but hide memory copy latency can improve GPU utilization. "..
                                                                                 "(This score doesn't take in consideration async copies hidden by CPU computation.)"},
    {key = "longest_activity",          label = "Longest GPU Activity",   desc = "Longest GPU activity. Can be a kernel, copy operation or a barrier."},
    {key = "total_bytes",               label = "Total bytes transfered", desc = "Total bytes transferred from/to GPU by memory transfers."},
    {key = "speedup_async_copy",        label = "Perfect HIP Async Copy (Speedup)", desc = "Speed up if all copies were 100% asynchronous"},
    {key = "speedup_hidden_copy",       label = "Perfect Hidden Copy (Speedup)",    desc = "Speed up if all copies were hidden by kernels"},
    {key = "speedup_copy_coalescing",   label = "Copy Coalescing (Speedup)",        desc = "Speed up if all coalescable copies were coalesced"},
    {key = "speedup_kernel_coalescing", label = "Kernel Coalescing (Speedup)",      desc = "Speed up if all coalescable kernels were coalesced"}
}


local function get_ret_val(ret_vals, report, key, default)
    local report_retval = ret_vals[-1][report]
    if report_retval and report_retval[key] then
        return report_retval[key]
    else
        return default or "N/A"
    end
end


function summarize_report.get_analyzed_data(data, opt)
    local stats_reports = {
        {id = "mpi_api_sum"},
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
        -- {id = "hidden_transfers"},
        {id = "gpu_idle"},
        {id = "hip_memcpy_sync"},
        {id = "hip_memcpy_async"},
        {id = "coalescable_transfers"},
        -- {id = "concurrency"}
    }

    local options = {
        ["outputs"]     = {"/tmp/rprof_summarize"},
        ["formats"]     = {"csv"},
        ["mangled"]     = opt.mangled,
        ["trunc"]       = opt.trunc,
        ["timeunit"]    = "ns",
        ["start"]       = opt.start,
        ["stop"]        = opt.stop,
    }
    
    options.reports = stats_reports
    local stats_ret_vals = Report.utils.execute_report(data, options, ratelprof.consts._ALL_STATS_REPORT, true, "Report statistics")

    options.reports = analyze_reports

    local analyze_ret_vals = Report.utils.execute_report(data, options, ratelprof.consts._ALL_RULES_REPORT, true, "Report analysis")


    local async_speedup                 = get_ret_val(analyze_ret_vals, "hip_memcpy_async",       "speedup", 1)
    local sync_speedup                  = get_ret_val(analyze_ret_vals, "hip_memcpy_sync",        "speedup", 1)
    local bytes_transferred             = get_ret_val(stats_ret_vals,   "gpu_mem_size_sum",       "total_bytes")
    local concurrency_score             = get_ret_val(analyze_ret_vals, "concurrency",            "score")
    local hidden_score                  = get_ret_val(analyze_ret_vals, "hidden_transfers",       "score")
    local longest_activity              = get_ret_val(stats_ret_vals,   "gpu_sum",                "longest_activity")
    local hidden_speedup                = get_ret_val(analyze_ret_vals, "hidden_transfers",       "speedup")
    local coalescable_kernels_speedup   = get_ret_val(analyze_ret_vals, "coalescable_kernels" ,   "speedup")
    local coalescable_transfers_speedup = get_ret_val(analyze_ret_vals, "coalescable_transfers" , "speedup")

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

    return analyzed_data, stats_ret_vals, analyze_ret_vals
end


return summarize_report