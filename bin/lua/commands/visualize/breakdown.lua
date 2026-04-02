local breakdown = {}

local function extract_datasets(filename, xLabel, cols_idx, title)
    local data = {
        title = title,
        xLabel = xLabel,
        yLabel = "Active Time (%)",
        labels = {},
        datasets = {},
        map = {}
    }

    local file = ratelprof.fs.open_file(filename, "r")
    file:read("*l") -- Skip first line

    local header_line = file:read("*l")
    local header = JSON:decode(header_line:gsub(",$", ""))

    for _, idx in ipairs(cols_idx) do
        local label = header[idx]:gsub(" %(%%%)", "")
        local dataset = { label = label, data = {}}
        data.map[idx] = dataset.data
        table.insert(data.datasets, dataset)
    end

    local prev_line = file:read("*l")

    while prev_line do
        local line = file:read("*l")
        if not line then break end

        if prev_line then
            local current = prev_line:trim():gsub(",$", "")
            if current == "[" then
                repeat
                    prev_line = file:read("*l")
                    if not prev_line then break end
                    current = prev_line:trim():gsub(",$", "")
                until current == "]"
                line = file:read("*l")
            else
                local parsed = JSON:decode(current)

                if type(parsed) == "table" then
                    local label = parsed[1]:gsub(xLabel.." ", "")
                    table.insert(data.labels, label)
                    for _, idx in ipairs(cols_idx) do
                        table.insert(data.map[idx], parsed[idx])
                    end
                end
            end
        end

        prev_line = line
    end
    data.map = nil
    file:close()
    return data
end

function breakdown.get_summary_datasets(summary_data)
    local report_objs = summary_data.report_launcher.report_objs
    local summary_dataset = {
        [2] = { onClick = "renderHistogram"},
        [3] = { onClick = "renderHistogram", defaultPlot = true },
    }
    summary_dataset[2].data = extract_datasets(report_objs.cpu_breakdown.filename, "PID", {4, 5, 8}, "CPU interaction accross all rank")
    summary_dataset[3].data = extract_datasets(report_objs.gpu_breakdown.filename, "GPU", {4, 5, 7}, "GPU activity accross all rank")

    return summary_dataset
end

function breakdown.process_breakdown_report(fs, summary_data)
    local report_objs = summary_data.report_launcher.report_objs
    local cpu_breakdown = report_objs.cpu_breakdown
    local gpu_breakdown = report_objs.gpu_breakdown

    ratelprof.utils.json_to_js(cpu_breakdown.filename, "const __BREAKDOWN_DATA__", fs.data.cpu_breakdown:path())
    ratelprof.utils.json_to_js(gpu_breakdown.filename, "const __BREAKDOWN_DATA__", fs.data.gpu_breakdown:path())

    ratelprof.fs.rm(fs.data.csv:path().."/breakdown")
end

return breakdown