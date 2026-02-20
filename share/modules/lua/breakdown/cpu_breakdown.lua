local Timewise = require ("utils.Timewise")
local report_helper = require ("utils.report_helper")

local DOMAIN_COL_IDX = {
    [ ratelprof.consts.DOMAIN_HIP_ID ] = 5,
    [ ratelprof.consts.DOMAIN_OMPT_ID ] = 6,
    [ ratelprof.consts.DOMAIN_OMP_TGT_RTL_ID ] = 6,
    [ ratelprof.consts.DOMAIN_OMP_TGT_ID ] = 6,
    [ ratelprof.consts.DOMAIN_MPI_ID ] = 7,
}

return function (report)
    local timeunit = report.opt.timeunit

    report.NAME = "CPU"

    report.TYPE = "Breakdown"

    report.HEADER = {
        "###", "Wall Time ("..timeunit..")", "Total Active Time (%)", "Non-Profiled (%)", "HIP Active Time (%)", "OMP Active Time (%)", "MPI Active Time (%)",
    }

    report.LOOP_IN = { ratelprof.consts.DOMAIN_HIP_ID, ratelprof.consts.DOMAIN_MPI_ID,
            ratelprof.consts.DOMAIN_OMPT_ID, ratelprof.consts.DOMAIN_OMP_TGT_RTL_ID, ratelprof.consts.DOMAIN_OMP_TGT_ID }

    report.OR_REQUIRED_MODE = true

    local tmp_data = {}

    report.PRE_EVENT_LOOP = function(self)
        self.pid_ctx = Timewise.new()
        self.ctx_per_tid = {}
    end

    report.FOR_EACH = function(self, event)
        local start  = event:start()
        local stop   = event:stop()
        local domain = event:domain()
        local tid    = event:tid()
        local col_idx = DOMAIN_COL_IDX[domain]

        local key = report_helper.create_key({ col_idx })

        local pid_ctx = self.pid_ctx
        local ctx_per_tid = self.ctx_per_tid[tid] or Timewise.new()

        pid_ctx:add_entry(key, start, stop)
        ctx_per_tid:add_entry(key, start, stop)

        self.ctx_per_tid[tid] = ctx_per_tid
    end

    local function add_new_row(rows, ctx, label, walltime, total_time)
        local active_pct = ctx:compute_active_percentage(total_time)
        local non_active_pct = 100 - active_pct

        local row = {}
        row[1] = label
        row[2] = ratelprof.utils.get_duration(walltime, timeunit)
        row[3] = active_pct
        row[4] = string.format("%.2f", non_active_pct)

        for _, idx in pairs(DOMAIN_COL_IDX) do
            row[idx] = "0.00"
        end

        ctx:for_each_entry(function(_, entry)
            local col_idx = entry.key[1]
            row[col_idx] = entry:compute_active_percentage(total_time)
        end)

        table.insert(rows, row)

        return row
    end

    report.POST_EVENT_LOOP = function(self, rprofrep, cpu_key)
        local total_time = rprofrep:get_analyzed_interval_dur()

        local sub_data = {}
        for tid, ctx in pairs(self.ctx_per_tid) do
            add_new_row(sub_data, ctx, " TID " .. tid, ctx:compute_walltime(), total_time)
        end

        local row = add_new_row(tmp_data, self.pid_ctx, ratelprof.utils.label_unit_with_rank(cpu_key, true), total_time, total_time)
        row["tmp"] = sub_data

        self.pid_ctx = nil
        self.ctx_per_tid = nil
    end

    report.POST_LOOP = function (self)
        local data = {}

        table.sort(tmp_data, function (a, b) return a[2] > b[2] end)

        local max_interaction_pct = 0

        for _, cpu_data in ipairs(tmp_data) do

            max_interaction_pct = math.max(max_interaction_pct, cpu_data[3])

            local sub_data = cpu_data["tmp"]
            cpu_data["tmp"] = nil

            table.sort(sub_data, function (a, b) return tonumber(a[3]) > tonumber(b[3]) end)

            table.insert(data, cpu_data)
            for _, e in ipairs(sub_data) do
                table.insert(data, e)
            end
        end

        self.max_interaction_pct = max_interaction_pct
        self.data = data
        tmp_data = nil
    end
end