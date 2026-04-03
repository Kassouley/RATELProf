local Timewise = require ("utils.Timewise")
local report_helper = require ("utils.report_helper")

local DOMAIN_COL_IDX = {
    [ ratelprof.consts.DOMAIN_KERNEL_ID ] = 5,
    [ ratelprof.consts.DOMAIN_COPY_ID ] = 6,
}

return function (report)
    local timeunit = report.opt.timeunit

    report.NAME = "GPU"

    report.TYPE = "Breakdown"

    report.HEADER = {
        "###", "Wall Time ("..timeunit..")", "GPU Time (%)", "Idle Time (%)", "Compute Time (%)", "Mem. Transfer Time (%)", "Visible Mem. Transfer Time (%)",
    }

    report.LOOP_IN = { ratelprof.consts.DOMAIN_COPY_ID, ratelprof.consts.DOMAIN_KERNEL_ID }

    local tmp_data = {}

    report.PRE_EVENT_LOOP = function(self)
        self.gpu_ctx = Timewise.new()
        self.ctx_per_qid  = {}
        self.ctx_per_sdma = {}
    end

    report.FOR_EACH = function(self, event)
        local start  = event:start()
        local stop   = event:stop()
        local domain = event:domain()
        local col_idx = DOMAIN_COL_IDX[domain]

        local key = report_helper.create_key({ col_idx })

        local gpu_ctx = self.gpu_ctx

        local sub_ctx = nil
        if domain == ratelprof.consts.DOMAIN_COPY_ID then
            local sdma = event:sdma_id()
            sub_ctx = self.ctx_per_sdma[sdma] or Timewise.new()
            self.ctx_per_sdma[sdma] = sub_ctx
        else
            local queue_id = event:queue_id()
            sub_ctx = self.ctx_per_qid[queue_id] or Timewise.new()
            self.ctx_per_qid[queue_id] = sub_ctx
        end

        gpu_ctx:add_entry(key, start, stop)
        sub_ctx:add_entry(key, start, stop)
    end

    local function add_new_row(rows, ctx, label, walltime, total_time)
        local gpu_pct = ctx:compute_active_percentage(total_time)

        local row = {}
        row[1] = label
        row[2] = ratelprof.utils.get_duration(walltime, timeunit)
        row[3] = gpu_pct
        row[4] = tostring(100 - gpu_pct)

        for _, idx in pairs(DOMAIN_COL_IDX) do
            row[idx] = "0.00"
        end

        ctx:for_each_entry(function(_, entry)
            local col_idx = entry.key[1]
            row[col_idx] = entry:compute_active_percentage(total_time)
        end)

        row[7] = string.format("%.2f", gpu_pct - row[5])

        table.insert(rows, row)

        return row
    end

    report.POST_EVENT_LOOP = function(self, rprofrep, cpu_key)
        local total_time   = rprofrep:get_analyzed_interval_dur()

        local queue_data = {}
        for queue_id, ctx in pairs(self.ctx_per_qid) do
            add_new_row(queue_data, ctx, " Queue ID " .. queue_id, ctx:compute_walltime(), total_time)
        end

        local sdma_data = {}
        for sdma_id, ctx in pairs(self.ctx_per_sdma) do
            add_new_row(sdma_data, ctx, " SDMA ID " .. sdma_id, ctx:compute_walltime(), total_time)
        end

        local row = add_new_row(tmp_data, self.gpu_ctx, ratelprof.utils.label_unit_with_rank(cpu_key, true), total_time, total_time)
        row["tmp_queue"] = queue_data
        row["tmp_sdma"]  = sdma_data

        self.gpu_ctx = nil
        self.ctx_per_qid = nil
    end

    report.POST_LOOP = function (self)
        local data = {}

        table.sort(tmp_data, function (a, b) return a[2] > b[2] end)

        local function insert_subdata(gpu_data, idx)
            local sub_data = gpu_data[idx]
            gpu_data[idx] = nil
            table.sort(sub_data, function (a, b) return tonumber(a[3]) > tonumber(b[3]) end)
            for _, e in ipairs(sub_data) do
                table.insert(data, e)
            end
        end

        local max_gpu_pct = 0
        local max_compute_pct = 0
        local max_copy_pct = 0
        local max_visible_copy_pct = 0

        for _, gpu_data in ipairs(tmp_data) do
            table.insert(data, gpu_data)

            max_gpu_pct = math.max(max_gpu_pct, gpu_data[3])
            max_compute_pct = math.max(max_compute_pct, gpu_data[5])
            max_copy_pct = math.max(max_copy_pct, gpu_data[6])
            max_visible_copy_pct = math.max(max_visible_copy_pct, gpu_data[7])

            insert_subdata(gpu_data, "tmp_queue")
            insert_subdata(gpu_data, "tmp_sdma")
        end

        self.data = data
        self.max_gpu_pct = max_gpu_pct
        self.max_compute_pct = max_compute_pct
        self.max_copy_pct = max_copy_pct
        self.max_visible_copy_pct = max_visible_copy_pct
        tmp_data = nil
    end
end