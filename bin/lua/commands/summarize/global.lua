-- global.lua
local helper = require("commands.summarize.helper")
local common = require("commands.common")
local ReportLauncher = require ("utils.Classes.ReportLauncher")
local options_helper = require ("options_helper")

local global = {}

local analyzed_data = {
    {key = "app_time",            label = "App Time",                         desc = "Application total time"},
    {key = "interaction_time",    label = "Max GPU/CPU Interaction Time (%)", desc = "Max Total Time spent in GPU-CPU interaction libraries or in MPI. "},
    {key = "gpu_time",            label = "Max GPU Active Time (%)",          desc = "Max Total GPU active time including all kernels and copies. "..
                                                                                     "This is the time when GPU was not idle, not the sum of all GPU activity time."},
    {key = "kernel_time",         label = "Max GPU Compute Time (%)",         desc = "Max total time spent in all kernels"},
    {key = "copy_time",           label = "Max GPU MemOp Time (%)",            desc = "Max Total time spent in all memory operations"},
    {key = "visible_copy_time",   label = "Max GPU Visible MemOp Time (%)",    desc = "Max Total time spent in all memory operations that are not hidden by GPU computation."},

    {key = "longest_activity",          label = "Longest GPU Activity",             desc = "Longest GPU activity. Can be a kernel, memory operation or a barrier."},
    {key = "total_bytes",               label = "Total bytes transfered",           desc = "Total bytes transferred from/to GPU by memory transfers."},
    {type = "sep", subrow = 2,          label = "Score"},
    {key = "concurrency_score",         label = "Concurrency Score (%)",            desc = "Percentage of kernel computation that are in parallel. High concurrency can improve performance."},
    {key = "hidden_score",              label = "Hidden Copy Score (%)",            desc = "Percentage of memory operation time hidden by kernel computation. "..
                                                                                           "Higher doesn't always mean better performance, "..
                                                                                           "but hide memory operation latency can improve GPU utilization. "..
                                                                                           "(This score doesn't take in consideration async copies hidden by CPU computation.)"},
    {type = "sep", subrow = 4,          label = "Potential Speedup"},
    {key = "speedup_async_copy",        label = "Perfect HIP Async Copy", desc = "Speed up if all copies were 100% asynchronous"},
    {key = "speedup_hidden_copy",       label = "Perfect Hidden Copy",    desc = "Speed up if all copies were hidden by kernels"},
    {key = "speedup_copy_coalescing",   label = "Copy Coalescing",        desc = "Speed up if all coalescable copies were coalesced"},
    {key = "speedup_kernel_coalescing", label = "Kernel Coalescing",      desc = "Speed up if all coalescable kernels were coalesced"}
}


function global.get_global_data(rprofrep, summarize_opt)
    local reports_lists = {
       ratelprof.consts.STATS_REPORTS,
       ratelprof.consts.ANALYZE_REPORTS,
       ratelprof.consts.BREAKDOWN_REPORTS,
    }
    local reports = {}

    local save_json = ratelprof.get_opt_val(summarize_opt, "save-json")
    local save_csv  = ratelprof.get_opt_val(summarize_opt, "save-csv")
    local start = options_helper.parse_number_option(summarize_opt, "start")
    local stop = options_helper.parse_number_option(summarize_opt, "stop")
    local pids = options_helper.parse_mask_option(summarize_opt, "pids")
    local gpus = options_helper.parse_mask_option(summarize_opt, "gpus")

    local format, path =
        save_json and "json" or
        save_csv  and "csv"  or
        "csv",
        save_json or save_csv

    local output_base = path and (path == "" and "./summarize" or path) or "_"

    local output_per_list = {
        [ratelprof.consts.STATS_REPORTS]     = "/statistics/",
        [ratelprof.consts.ANALYZE_REPORTS]   = "/analyze/",
        [ratelprof.consts.BREAKDOWN_REPORTS] = "/breakdown/",
    }

    for _, reports_list in ipairs(reports_lists) do
        local output = output_base
        if output_base ~= "_" then
            output = output .. output_per_list[reports_list]
            ratelprof.fs.mkdir(output)
        end
        local rpt = common.get_reports_data({ "all" }, { output }, { format }, { sizeunit = "B", timeunit = "ns" }, reports_list)

        reports = table.merge_arr(reports, rpt)
    end

    local report_launcher = ReportLauncher:new(rprofrep, {
        reports = reports,
        start   = start,
        stop    = stop,
        gpus    = gpus,
        pids    = pids,
        notation = "raw",
        disable_print = true,
    })
    report_launcher:launch()


    local function get_attr(report, key, default)
        local obj = report_launcher.report_objs[report]
        if obj and obj[key] then
            return obj[key]
        else
            return default or "N/A"
        end
    end

    local async_speedup                 = get_attr("hip_memcpy_async",       "speedup_factor", 1)
    local sync_speedup                  = get_attr("hip_memcpy_sync",        "speedup_factor", 1)
    local bytes_transferred             = get_attr("gpu_mem_size_sum",       "total_bytes")
    local concurrency_score             = get_attr("concurrency",            "score")
    local hidden_score                  = get_attr("hidden_transfers",       "score")
    local hidden_speedup                = get_attr("hidden_transfers",       "speedup_factor")
    local coalescable_kernels_speedup   = get_attr("coalescable_kernels" ,   "speedup_factor")
    local coalescable_transfers_speedup = get_attr("coalescable_transfers" , "speedup_factor")

    -- Fill analyzed_data
    local key_map = {
        app_time                     = helper.format_time(rprofrep:get_analyzed_interval_dur()),
        gpu_time                     = get_attr("gpu_breakdown",          "max_gpu_pct"),
        kernel_time                  = get_attr("gpu_breakdown",          "max_compute_pct"),
        copy_time                    = get_attr("gpu_breakdown",          "max_copy_pct"),
        visible_copy_time            = get_attr("gpu_breakdown",          "max_visible_copy_pct"),
        interaction_time             = get_attr("cpu_breakdown",          "max_interaction_pct"),
        longest_activity             = get_attr("gpu_sum",                "longest_activity"),
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

    return analyzed_data, report_launcher
end

return global