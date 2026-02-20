local report_helper = require("utils.report_helper")

local DEFAULT_ADVICE_MSG = [[
The following are ranges where a GPU is idle for more than %s ms. 

Addressing these gaps might improve application performance.
]]

local DEFAULT_NO_ADVICE_MSG = [[
There were no problems detected with GPU utilization. GPU was not found to be idle for more than %s ms.
]]

local DEFAULT_PER_GPU_MSG = [[
    On GPU ID %s, gaps account for %.2f%%, of the total GPU time.
]]

return function (report)
    local timeunit = report.opt.timeunit

    report.NAME = "GPU Idle"

    report.TYPE = "Analyze"

    report.HEADER = { "GPU ID", "Range ID", "Start", "End", "Duration (" .. timeunit .. ")" }

    report.LOOP_IN = { ratelprof.consts.DOMAIN_KERNEL_ID }

    report.SORT_BY = {"asc", 5}

    report.PRE_LOOP = function (self)
        self.data = {}
        self.gap_th = self.opt.th_gap * 1e6
        self.total_pct_per_gpu = {}
    end

    report.PRE_EVENT_LOOP = function (self)
        self.first_start = 0
        self.current_stop = 0
        self.total_gap_dur = 0
    end

    report.FOR_EACH = function (self, event)
        local event_start = event:start()
        local event_stop  = event:stop()
        local current_stop  = self.current_stop
        local total_gap_dur = self.total_gap_dur

        if current_stop == 0 then
            current_stop = event_start
            self.first_start = event_start
        elseif event_start > current_stop then
            local gap_dur = event_stop - event_start
            if gap_dur > self.gap_th then
                table.insert(self.data, {
                    tostring(self.gpu_id),
                    tostring(#self.data + 1),
                    string.format("%.0f", event_stop),
                    string.format("%.0f", event_start),
                    report_helper.get_duration(gap_dur, timeunit),
                })
                total_gap_dur = total_gap_dur + gap_dur
            end
        end
        self.current_stop = math.max(current_stop, event_stop)
        self.total_gap_dur = total_gap_dur
    end

    report.POST_EVENT_LOOP = function (self, _, gpu_key)
        local total_time = self.current_stop - self.first_start
        local total_gap_dur = self.total_gap_dur
        self.total_pct_per_gpu[gpu_key]  = (total_gap_dur / total_time) * 100
    end

    report.POST_LOOP = function (self)
        if #self.data == 0 then
            self.MESSAGE = string.format(DEFAULT_NO_ADVICE_MSG, self.opt.th_gap)
        else
            local msg = string.format(DEFAULT_ADVICE_MSG, self.opt.th_gap)

            for gpu_key, pct in pairs(self.total_pct_per_gpu) do
                msg = msg .. string.format(DEFAULT_PER_GPU_MSG, ratelprof.utils.label_unit_with_rank(gpu_key), pct)
            end

            self.MESSAGE = msg
        end
    end
end

