-- summarize_global.lua
local summarize_helper = require ("commands.summarize.summarize_helper")

local summarize_global = {}

local global_data = {
    {key = "app_time",            label = "App Time (s)",                     desc = "Application total time"},
    {key = "gpu_time",            label = "Max GPU Active Time (%)",          desc = "Max Total GPU active time including all kernels and copies. "..
                                                                                     "This is the time when GPU was not idle, not the sum of all GPU activity time."},
    {key = "kernel_time",         label = "Max GPU Compute Time (%)",         desc = "Max total time spent in all kernels"},
    {key = "copy_time",           label = "Max GPU Copy Time (%)",            desc = "Max Total time spent in all memory transfers"},
    -- {key = "copy_no_hidden_time", label = "Max GPU Not Hidden Copy Time (%)", desc = "Max Total time spent in all memory transfers that are not hidden by GPU computation."},
}


function summarize_global.get_global_summary(data)
    local app_time = data:get_app_dur()
    local app_time_sec = ratelprof.convert.time(app_time, "ns", "sec")

    -- Define metrics in one place
    local metrics = {
        {
            key = "gpu_time",
            getter = function() return data:get_active_gpu_time() end
        },
        {
            key = "kernel_time",
            getter = function() return data:get_active_compute_time() end
        },
        {
            key = "copy_time",
            getter = function() return data:get_active_copy_time() end
        },
        -- {
        --     key = "copy_no_hidden_time",
        --     getter = function() return data:get_not_hidden_active_copy_time() end
        -- }
    }


    -- Process each metric
    for _, metric in ipairs(metrics) do
        metric.per_gpu  = {}
        metric.subvalue = {}

        data:for_each_gpu(function(gpu_node_id)
            local value = metric.getter()
            metric.per_gpu[gpu_node_id] = value
            table.insert(metric.subvalue, {
                label = "GPU ID. " .. gpu_node_id,
                value = summarize_helper.format_gpu_time(value, app_time)
            })
        end)

        metric.max_value = table.max(metric.per_gpu)
    end

    -- Fill summary_data
    for _, entry in ipairs(global_data) do
        if entry.key == "app_time" then
            entry.value = string.format("%.3f s", app_time_sec)
        else
            for _, metric in ipairs(metrics) do
                if entry.key == metric.key then
                    entry.value    = summarize_helper.format_gpu_time(metric.max_value, app_time)
                    entry.subvalue = metric.subvalue
                    break
                end
            end
        end
    end

    return global_data
end

return summarize_global