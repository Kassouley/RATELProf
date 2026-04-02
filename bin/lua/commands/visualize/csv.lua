local csv = {}

local function read_and_init_hot_event_dataset(filename, col_idx_name, max_lines)
    local datasets = {}
    local hot_events = {}
    local line_count = 0
    local file = ratelprof.fs.open_file(filename, "r")
    -- Skip the two first lines
    file:read("*l")
    file:read("*l")

    local prev_line = file:read("*l")

    for line in file:lines() do
        if prev_line then
            if line_count >= max_lines then break end
            local parsed = JSON:decode(prev_line:gsub(",$", ""))
            if type(parsed) == "table" then
                local name = parsed[col_idx_name]
                local dataset = { label = name, data = {} }
                datasets[#datasets + 1] = dataset
                hot_events[name] = dataset.data
            end

            line_count = line_count + 1
        end

        prev_line = line
    end

    file:close()
    return datasets, hot_events
end

local function get_csv_data(report_obj, report_id)
    local csv_data = {}
    local type = report_obj.TYPE
    local col_idx_name = report_obj.COL_IDX_NAME
    local is_gpu_report = report_obj.is_gpu_report
    local msg = report_obj.MESSAGE
    csv_data.name = report_obj.NAME

    for _, generated_report in ipairs(report_obj.generated) do
        local filename = generated_report.filename
        local skipped = generated_report.skip
         if type == "Summary" then
            local datasets, hot_events = read_and_init_hot_event_dataset(filename, col_idx_name, 6)
            csv_data.dataRendering = "renderHistogram"
            csv_data.data = {
                xLabel = is_gpu_report and "GPU ID" or "Rank",
                yLabel = "Time (%)",
                labels = {},
                datasets = datasets,
                hot_events = hot_events
            }
        else
            csv_data.dataRendering = "renderAdvice"
            csv_data.data = {
                desc = ratelprof.consts.ANALYZE_REPORTS[report_id].desc or "No description available.",
                advice = msg or "No advice available.",
            }
        end

        if not skipped then
            csv_data.file = ratelprof.utils.json_to_js(filename, "window.currentCSV")
        end
    end

    return csv_data
end

local function insert_datasets_data(csv_data, filename, col_idx_name, col_idx_metric)
    local hot_events = csv_data.data.hot_events
    local nhot_events = #csv_data.data.datasets

    local file = ratelprof.fs.open_file(filename, "r")
    file:read("*l")
    file:read("*l")

    local prev_line = file:read("*l")
    local filled = {}

    for line in file:lines() do
        if prev_line then
            if nhot_events <= 0 then break end
            local parsed = JSON:decode(prev_line:gsub(",$", ""))
            if type(parsed) == "table" then
                local name = parsed[col_idx_name]
                if hot_events[name] then
                    local metric = parsed[col_idx_metric]
                    table.insert(hot_events[name], metric)

                    filled[name] = true
                    nhot_events = nhot_events - 1
                end
            end
        end

        prev_line = line
    end

    file:close()
    for name, arr in pairs(hot_events) do
        if not filled[name] then
            table.insert(arr, 0)
        end
    end
end


local function insert_sub_csv(csv_data, report_obj)
    local is_gpu_report = report_obj.is_gpu_report
    local col_idx_name = report_obj.COL_IDX_NAME
    local col_idx_metric = report_obj.COL_IDX_METRIC
    for _, generated_report in ipairs(report_obj.generated) do
        local filename = generated_report.filename
        local user_args = generated_report.user_args

        local label = is_gpu_report and
            user_args.gpu_id or user_args.rank
        table.insert(csv_data.data.labels, label)

        insert_datasets_data(csv_data, filename, col_idx_name, col_idx_metric)

        csv_data.subCSV = csv_data.subCSV or {}
        local jsfile = ratelprof.utils.json_to_js(filename, "window.currentCSV")
        table.insert(csv_data.subCSV, {
            name = ratelprof.utils.label_unit_with_rank(user_args, true),
            file = jsfile,
            dataRendering = "renderPie",
        })
    end
end

function csv.process_csv_data(fs, summary_data)
    local report_objs = summary_data.report_launcher.report_objs

    local __CSV_DATA__ = {
        Summary = {},
        Analyze = {},
    }

    for report_id, report_obj in pairs(report_objs) do
        local type    = report_obj.TYPE
        local link_to = report_obj.LINK_TO
        if type ~= "Breakdown" then
            if link_to then
                local csv_data = __CSV_DATA__[type][link_to]
                if not csv_data then
                    csv_data = get_csv_data(report_objs[link_to], link_to)
                end

                if type == "Summary" then
                    insert_sub_csv(csv_data, report_obj)
                end

                __CSV_DATA__[type][link_to] = csv_data
            else
                local csv_data = __CSV_DATA__[type][report_id]
                if not csv_data then
                    __CSV_DATA__[type][report_id] = get_csv_data(report_obj, report_id)
                end
            end
        end
    end

    for _, data in pairs(__CSV_DATA__.Summary) do
        data.data.hot_events = nil
    end

    fs.data.stats:write("const __CSV_DATA__=", JSON:encode(__CSV_DATA__.Summary))
    fs.data.analyze:write("const __CSV_DATA__=", JSON:encode(__CSV_DATA__.Analyze))
end

return csv