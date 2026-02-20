-- global.lua
local helper = require("commands.summarize.helper")
local common = require("commands.common")
local ReportLauncher = require ("utils.Classes.ReportLauncher")

local global = {}

local analyzed_data = {
    {key = "app_time",            label = "App Time",                         desc = "Application total time"},
    {key = "interaction_time",    label = "Max Interaction Time (%)",         desc = "Max Total Time spent in GPU-CPU interaction libraries or in MPI. "},
    {key = "gpu_time",            label = "Max GPU Active Time (%)",          desc = "Max Total GPU active time including all kernels and copies. "..
                                                                                     "This is the time when GPU was not idle, not the sum of all GPU activity time."},
    {key = "kernel_time",         label = "Max GPU Compute Time (%)",         desc = "Max total time spent in all kernels"},
    {key = "copy_time",           label = "Max GPU Copy Time (%)",            desc = "Max Total time spent in all memory transfers"},
    {key = "visible_copy_time",   label = "Max GPU Visible Copy Time (%)",    desc = "Max Total time spent in all memory transfers that are not hidden by GPU computation."},

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


function global.get_global_data(rprofrep, summarize_opt)
    local reports_lists = {
       ratelprof.consts.STATS_REPORTS,
       ratelprof.consts.ANALYZE_REPORTS,
       ratelprof.consts.BREAKDOWN_REPORTS,
    }
    local reports = {}

    local output = "_"
    local save_csv = ratelprof.get_opt_val(summarize_opt, "save-csv")
    if save_csv then
        output = (save_csv == "" and "." or save_csv) .. "/summarize"
    end

    for _, reports_list in ipairs(reports_lists) do
        local rpt = common.get_reports_data({ "all" }, { output }, { "csv" }, nil, reports_list)

        reports = table.merge_arr(reports, rpt)
    end

    local report_launcher = ReportLauncher:new(rprofrep, {
        reports = reports,
        start   = summarize_opt.start,
        stop    = summarize_opt.stop,
        gpus    = summarize_opt.gpus,
        pids    = summarize_opt.pids,
        notation = "raw",
        disable_print = true,
    })
    report_launcher:launch()


    local function get_attribute(report, key, default)
        local obj = report_launcher.report_objs[report]
        if obj and obj[key] then
            return obj[key]
        else
            return default or "N/A"
        end
    end
    local async_speedup                 = get_attribute("hip_memcpy_async",       "speedup_factor", 1)
    local sync_speedup                  = get_attribute("hip_memcpy_sync",        "speedup_factor", 1)
    local bytes_transferred             = get_attribute("gpu_mem_size_sum",       "total_bytes")
    local concurrency_score             = get_attribute("concurrency",            "score")
    local hidden_score                  = get_attribute("hidden_transfers",       "score")
    local hidden_speedup                = get_attribute("hidden_transfers",       "speedup_factor")
    local coalescable_kernels_speedup   = get_attribute("coalescable_kernels" ,   "speedup_factor")
    local coalescable_transfers_speedup = get_attribute("coalescable_transfers" , "speedup_factor")

    -- Fill analyzed_data
    local key_map = {
        app_time                     = helper.format_time(rprofrep:get_analyzed_interval_dur()),
        gpu_time                     = get_attribute("gpu_breakdown",          "max_gpu_pct"),
        kernel_time                  = get_attribute("gpu_breakdown",          "max_compute_pct"),
        copy_time                    = get_attribute("gpu_breakdown",          "max_copy_pct"),
        visible_copy_time            = get_attribute("gpu_breakdown",          "max_visible_copy_pct"),
        interaction_time             = get_attribute("cpu_breakdown",          "max_interaction_pct"),
        longest_activity             = get_attribute("gpu_sum",                "longest_activity"),
        total_bytes                  = helper.format_bytes(bytes_transferred),
        concurrency_score            = helper.format_percentage(concurrency_score),
        hidden_score                 = helper.format_percentage(hidden_score),
        speedup_hidden_copy          = helper.format_speedup(hidden_speedup),
        speedup_async_copy           = helper.format_speedup(async_speedup * sync_speedup),
        speedup_copy_coalescing      = helper.format_speedup(coalescable_transfers_speedup),
        speedup_kernel_coalescing    = helper.format_speedup(coalescable_kernels_speedup),
    }

    -- Fill analyzed_data
    for _, entry in ipairs(analyzed_data) do
        entry.value = key_map[entry.key] or entry.value
    end

    return analyzed_data
end

return global