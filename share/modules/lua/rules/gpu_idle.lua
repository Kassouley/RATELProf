local function find_gaps(rprofrep, opt)
    local gpus   = opt.gpus
    local gap_th = opt.th_gap * 1e6

    local gaps = {}
    local percentage_per_gpu = {}

    rprofrep:for_each_gpu(function(gpu_id)
        local total_gap_dur = 0
        local current_stop = 0
        local first_start = 0
        rprofrep:for_each_event({ ratelprof.consts.DOMAIN_KERNEL_ID }, function(event)
            local event_start = event:start()
            local event_stop  = event:stop()
            if current_stop == 0 then
                current_stop = event_start
                first_start = event_start
            elseif event_start > current_stop then
                local gap_dur = event_stop - event_start
                if gap_dur > gap_th then
                    table.insert(gaps, {
                        tostring(gpu_id),
                        tostring(#gaps + 1),
                        string.format("%.0f", event_stop),
                        string.format("%.0f", event_start),
                        gap_dur
                    })
                    total_gap_dur = total_gap_dur + gap_dur
                end
            end
            current_stop = math.max(current_stop, event_stop)
        end)
        
        -- Compute total time range for percentage calculation
        local total_time = current_stop - first_start
        percentage_per_gpu[gpu_id] = (total_gap_dur / total_time) * 100
    end, gpus)

    return gaps, percentage_per_gpu
end

local DEFAULT_ADVICE_MSG = [[
The following are ranges where a GPU is idle for more than %s ms. 

Addressing these gaps might improve application performance.
]]

local DEFAULT_NO_ADVICE_MSG = [[
There were no problems detected with GPU utilization. GPU was not found to be idle for more than %s ms.
]]


local DEFAULT_PER_GPU_MSG = [[
    On GPU ID %s, gaps account for %.2f%%, of the total GPU time.".
]]

return function (report)
    report.NAME = "GPU Idle"

    report.TYPE = "Analyze"

    report.HEADER = { "GPU ID", "Range ID", "Start", "End", "Duration (" .. report.opt.timeunit .. ")" }

    report.REQUIRED_DOMAIN = { ratelprof.consts.DOMAIN_KERNEL_ID }

    report.NO_ADVICE_MSG = function(self)
        return string.format(DEFAULT_NO_ADVICE_MSG, self.opt.th_gap)
    end

    report.ADVICE_MSG = function(self)
        local msg = string.format(DEFAULT_ADVICE_MSG, self.opt.th_gap)
        for gpu_id, percent in pairs(self.percentage_per_gpu) do
            msg = msg .. string.format(DEFAULT_PER_GPU_MSG, gpu_id, percent)
        end
        return msg
    end

    report.SORT_BY = {"asc", 5}

    report.DATA = function (self, rprofrep)
        local data, percentage_per_gpu = find_gaps(rprofrep, self.opt)
        self.data = data
        self.percentage_per_gpu = percentage_per_gpu
    end
end

