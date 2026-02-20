local Report = require("utils.Classes.Report")

local function get_filter(start, stop, only_main, dur, filter_type)
    if not (dur or start or stop or only_main) then
        return nil
    end

    return {
        phase    = only_main and 1 or nil,
        start    = start,
        stop     = stop,
        dur      = dur,
        phase_EQ = only_main and true,
        start_GT = start and true,
        start_LT = false,
        stop_GT  = false,
        stop_LT  = stop and true,
        dur_GT   = filter_type == "gt",
        dur_LT   = filter_type == "lt"
    }
end

-- ReportLauncher.lua
local ReportLauncher = {}
ReportLauncher.__index = ReportLauncher

function ReportLauncher:new(rprofrep, opt)

    local instance = setmetatable({}, self)

    instance.rprofrep = rprofrep
    instance.reports  = opt.reports or {}

    instance.max_lines        = opt.max_lines
    instance.max_col_width    = opt.max_col_width
    instance.notation         = opt.notation

    instance.disable_print = opt.disable_print or false

    instance.gpus         = opt.gpus
    instance.pids         = opt.pids
    instance.event_filter = get_filter(opt.start, opt.stop, opt.only_main, nil, nil)

    instance.report_objs = {}

    instance.report_objs_per_domain = {}

    instance.gpu_report_objs_pre_loop = {}
    instance.gpu_report_objs_pre_event_loop = {}
    instance.gpu_report_objs_post_event_loop = {}
    instance.gpu_report_objs_post_loop = {}
    instance.cpu_report_objs_pre_loop = {}
    instance.cpu_report_objs_pre_event_loop = {}
    instance.cpu_report_objs_post_event_loop = {}
    instance.cpu_report_objs_post_loop = {}

    instance.cpu_loop_in_domain = Set:new()
    instance.gpu_loop_in_domain = Set:new()

    instance.analyzed_filename = rprofrep:get_reports_filename_str()

    return instance
end

function ReportLauncher:print_header_msg(report_path)
    if self.disable_print then return end
    Message:printf("Preparing to process '%s' with '%s' . . .\n", self.analyzed_filename, report_path or "<??>")
end

function ReportLauncher:print_skipped_msg(missing_domain)
    if self.disable_print then return end
    Message:printf("\tSKIPPED: '%s' does not contain the required %s data.\n", self.analyzed_filename, ratelprof.consts._DOMAIN_NAME[missing_domain])
end

function ReportLauncher:print_ready_msg(report_obj)
    if self.disable_print then return end
    Message:printf("\tREADY: %s %s is ready to be launch. Please wait.\n", report_obj.NAME, report_obj.TYPE, self.analyzed_filename)
end

function ReportLauncher:print_error_msg(report_data)
    if self.disable_print then return end
    Message:printf("\tERROR: Report '%s' encountered an internal error: No valid report found (%s). Skipping.\n", report_data.id, report_data.path or "<??>")
end

function ReportLauncher:load_report_file(report_path)
    local chunk, err = loadfile(report_path)
    if not chunk then
        error("Error loading file: " .. err)
    end
    return chunk()
end


function ReportLauncher:preprocess_reports()
    local rprofrep = self.rprofrep
    local reports  = self.reports

    for _, report_data in ipairs(reports) do
        local report_id     = report_data.id
        local report_path   = report_data.path
        local report_opt    = report_data.opt
        local report_output = report_data.output
        local report_format = report_data.format

        self:print_header_msg(report_path)

        if report_path and ratelprof.fs.exists(report_path) then
            local report_obj = Report:new(report_id, report_opt, report_output, report_format)

            local report_exe = self:load_report_file(report_path)
            report_exe(report_obj)

            -- Check if data is available in the report
            local is_or_required_mode = report_obj.OR_REQUIRED_MODE
            local has_required_domain = is_or_required_mode and false or true

            local merge_required_domains = table.merge_arr(report_obj.LOOP_IN, report_obj.REQUIRED_DOMAIN)

            local missing_domain = ""
            for _, domain in ipairs(merge_required_domains) do
                if rprofrep:is_domain_traced(domain) then
                    if is_or_required_mode then
                        has_required_domain = true
                        break
                    end
                else
                    if not is_or_required_mode then
                        has_required_domain = false
                        missing_domain = domain
                        break
                    end
                end
            end

            if has_required_domain then
                local report_objs = self.report_objs_per_domain
                local is_gpu_report = false
                local is_cpu_report = false

                -- classify domains
                for _, domain in ipairs(report_obj.LOOP_IN) do
                    if ratelprof.utils.is_gpu_domain(domain) then
                        if is_cpu_report then
                            error("A report cannot process GPU AND CPU events at the same time")
                        end
                        is_gpu_report = true
                        self.gpu_loop_in_domain:add(domain)
                    else
                        if is_gpu_report then
                            error("A report cannot process GPU AND CPU events at the same time")
                        end
                        is_cpu_report = true
                        self.cpu_loop_in_domain:add(domain)
                    end

                    -- attach to report_objs[domain]
                    local obj_list = report_objs[domain]
                    if not obj_list then
                        obj_list = {}
                        report_objs[domain] = obj_list
                    end
                    obj_list[#obj_list + 1] = report_obj
                end

                local target_tables
                if is_gpu_report then
                    target_tables = {
                        PRE_LOOP          = self.gpu_report_objs_pre_loop,
                        PRE_EVENT_LOOP    = self.gpu_report_objs_pre_event_loop,
                        POST_EVENT_LOOP   = self.gpu_report_objs_post_event_loop,
                        POST_LOOP         = self.gpu_report_objs_post_loop,
                    }
                else
                    target_tables = {
                        PRE_LOOP          = self.cpu_report_objs_pre_loop,
                        PRE_EVENT_LOOP    = self.cpu_report_objs_pre_event_loop,
                        POST_EVENT_LOOP   = self.cpu_report_objs_post_event_loop,
                        POST_LOOP         = self.cpu_report_objs_post_loop,
                    }
                end

                -- add to buckets
                for key, tbl in pairs(target_tables) do
                    if report_obj[key] then
                        tbl[#tbl + 1] = report_obj
                    end
                end

                self.report_objs[report_id] = report_obj

                self:print_ready_msg(report_obj)
            else
                self:print_skipped_msg(missing_domain)
            end
        else
            self:print_error_msg(report_data)
        end
    end
end

function ReportLauncher:launch()
    self:preprocess_reports()
    self:run_gpu_reports()
    self:run_cpu_reports()

    if self.disable_print then return end
    Message:printf("FINISHED: Reports has been generated.\n")
end


function ReportLauncher:__run_xpu_reports(requested_domains,
        report_objs_pre_loop, report_objs_post_loop,
        report_objs_pre_event_loop, report_objs_post_event_loop,
        unit_label, for_each_unit_function, filter_label)

    local rprofrep      = self.rprofrep
    local max_lines     = self.max_lines
    local max_col_width = self.max_col_width
    local notation      = self.notation
    local event_filter  = self.event_filter

    local report_objs = self.report_objs_per_domain

    for _, report_obj in ipairs(report_objs_pre_loop) do
        report_obj:PRE_LOOP(rprofrep)
    end

    rprofrep:for_each_rank(function(rank)
        rprofrep[for_each_unit_function](rprofrep, function(unit)
            local key = {rank = rank, [unit_label] = unit}

            for _, report_obj in ipairs(report_objs_pre_event_loop) do
                report_obj:PRE_EVENT_LOOP(rprofrep, key)
            end

            rprofrep:for_each_event(requested_domains, function(event)
                local event_domain = event:domain()
                for _, report_obj in ipairs(report_objs[event_domain]) do
                    report_obj:FOR_EACH(event, rprofrep, key)
                end
            end, event_filter, "Process events for " .. ratelprof.utils.label_unit_with_rank(key, true) .. ": ")

            for _, report_obj in ipairs(report_objs_post_event_loop) do
                report_obj:POST_EVENT_LOOP(rprofrep, key)
                if report_obj.PER_MODE then
                    report_obj:generate(rprofrep, max_lines, max_col_width, notation, key)
                end
            end

        end, self[filter_label])
    end)

    for _, report_obj in ipairs(report_objs_post_loop) do
        report_obj:POST_LOOP(rprofrep)
        if not report_obj.PER_MODE then
            report_obj:generate(rprofrep, max_lines, max_col_width, notation)
        end
    end
end


function ReportLauncher:run_cpu_reports()
    if self.cpu_loop_in_domain:count() == 0 then return end
    local report_objs_pre_loop = self.cpu_report_objs_pre_loop
    local report_objs_post_loop = self.cpu_report_objs_post_loop
    local report_objs_pre_event_loop = self.cpu_report_objs_pre_event_loop
    local report_objs_post_event_loop = self.cpu_report_objs_post_event_loop
    local requested_domains = self.cpu_loop_in_domain:to_array()
    self:__run_xpu_reports(requested_domains, report_objs_pre_loop, report_objs_post_loop,
        report_objs_pre_event_loop, report_objs_post_event_loop, "pid", "for_each_pid", "pids")
end

function ReportLauncher:run_gpu_reports()
    if self.gpu_loop_in_domain:count() == 0 then return end
    local report_objs_pre_loop = self.gpu_report_objs_pre_loop
    local report_objs_post_loop = self.gpu_report_objs_post_loop
    local report_objs_pre_event_loop = self.gpu_report_objs_pre_event_loop
    local report_objs_post_event_loop = self.gpu_report_objs_post_event_loop
    local requested_domains = self.gpu_loop_in_domain:to_array()
    self:__run_xpu_reports(requested_domains, report_objs_pre_loop, report_objs_post_loop,
        report_objs_pre_event_loop, report_objs_post_event_loop, "gpu_id", "for_each_gpu", "gpus")
end

return ReportLauncher