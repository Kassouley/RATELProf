local Report = require("utils.Classes.Report")

-- ReportLauncher.lua
local ReportLauncher = {}
ReportLauncher.__index = ReportLauncher

function ReportLauncher:new(rprofrep, opt)

    local instance = setmetatable({}, self)

    instance.rprofrep = rprofrep
    instance.reports  = opt.reports or {}
    instance.outputs  = opt.outputs or {}
    instance.formats  = opt.formats or {}

    instance.max_lines       = opt.max_lines
    instance.max_col_width   = opt.max_col_width
    instance.notation        = opt.notation
    instance.progress_enabled = opt.progress_enabled
    instance.progress_msg    = opt.progress_msg or "No progress message set"

    instance.report_objs = {}

    return instance
end

local function get_per_rank_suffix(per_data)
    if not per_data then return "" end

    local order = {"rank", "gpu_id", "pid"}
    local parts = {}

    for _, key in ipairs(order) do
        if per_data[key] ~= nil then
            local nparts = #parts
            parts[nparts+1] = key
            parts[nparts+2] = tostring(per_data[key])
        end
    end

    return "_" .. table.concat(parts, "_")
end

function ReportLauncher:get_output(output, id, per_data, format)

    if output == "-" or output:sub(1, 1) == "@" then
        return output
    end

    local format_extension = Report.format_extensions[format]

    local report_wo_ext
    local reports_filename = self.rprofrep:get_reports_filename()
    if #reports_filename == 1 then
        report_wo_ext = ratelprof.fs.remove_extension(reports_filename[1])
    else
        report_wo_ext = "aggregated_report"
    end


    local basename = output == "." and report_wo_ext or output
    local suffix = get_per_rank_suffix(per_data)
    
    return string.format("%s_%s%s.%s", basename, id, suffix, format_extension)
end


function ReportLauncher:process_report_generation(chunk, report_id, output, format, report_opt)
    local rprofrep      = self.rprofrep
    local max_lines     = self.max_lines
    local max_col_width = self.max_col_width
    local notation      = self.notation

    local report_obj = Report:new(report_id, report_opt, not self.progress_enabled)

    chunk()(report_obj)

    local function process_and_generate(user_args)
        local real_output = self:get_output(output, report_id, user_args, format)
        if report_obj:process(rprofrep, real_output, user_args) then
            report_obj:generate(real_output, format, max_lines, max_col_width, notation)
        end
    end

    if report_obj.PER_GPU then
        rprofrep:for_each_rank(function(rank)
            rprofrep:for_each_gpu(function(gpu_id)
                process_and_generate({rank = rank, gpu_id = gpu_id})
            end, report_opt.gpus)
        end)
    elseif report_obj.PER_PID then
        rprofrep:for_each_rank(function(rank)
            rprofrep:for_each_pid(function(pid)
                process_and_generate({rank = rank, pid = pid})
            end, report_opt.pids)
        end)
    else
        process_and_generate()
    end

    self.report_objs[report_id] = report_obj
end

local function get_report_opt_value(ALL_REPORT, report_data, command_options)
    local report_id  = report_data.id
    local report_opt = report_data.opt or {}
    local opt = {}
    opt.timeunit  = command_options.timeunit
    opt.sizeunit  = command_options.sizeunit
    opt.start     = command_options.start
    opt.stop      = command_options.stop
    opt.only_main = command_options.only_main
    opt.mangled   = command_options.mangled
    opt.trunc     = command_options.trunc
    opt.gpus      = command_options.gpus
    opt.pids      = command_options.pids

    if not ALL_REPORT[report_id].opt then return opt end

    for name, option in pairs(ALL_REPORT[report_id].opt) do
        local default = option.default
        if not default then
            error (string.format("No default report option value provided for %s in report %s", name, report_id))
        end
        if type(default) == "number" then
            opt[name] = tonumber(report_opt[name]) or default
        else
            opt[name] = report_opt[name] or default
        end
    end
    return opt
end

function ReportLauncher:print_header_msg(report_path)
    Message:print_if(not self.progress_enabled, string.format("Processing '%s' with '%s' . . .\n",
        table.concat(self.rprofrep:get_reports_filename(), ", "), report_path))
end


function ReportLauncher:print_progress(curr_idx, nreports, report_id)
    if self.progress_enabled then
        ratelprof.utils.print_progress(curr_idx, nreports, self.progress_msg, '('..report_id..')')
    end
end

function ReportLauncher:load_report_file(report_path)
    local chunk, err = loadfile(report_path)
    if not chunk then
        error("Error loading file: " .. err)
    end
    return chunk
end

function ReportLauncher:execute_reports(report_list, opt)
    local reports  = self.reports
    local outputs  = self.outputs
    local formats  = self.formats

    local nreports = #reports

    for i, report_data in ipairs(reports) do
        local report_id   = report_data.id
        local report_info = report_list[report_id]
        local report_path = report_info and report_info.path or "<No file provided>"

        self:print_header_msg(report_path)
        self:print_progress(i - 1, nreports, report_id)

        if report_info and ratelprof.fs.exists(report_info.path) then

            local output = outputs[i] or outputs[#outputs] or '-'
            local format = formats[i] or formats[#formats] or (output == "-" and "column" or "csv")

            local report_opt = get_report_opt_value(report_list, report_data, opt)

            local chunk = self:load_report_file(report_path)
            self:process_report_generation(chunk, report_id, output, format, report_opt)
        else
            Message:error(string.format("Report '%s' encountered an internal error: No valid report found\n", report_id))
        end
    end

    self:print_progress(nreports, nreports, 'Done')
end

return ReportLauncher