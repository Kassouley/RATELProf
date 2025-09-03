-- summarize_plot.lua
local summarize_helper = require("commands.summarize.summarize_helper")

local summarize_plot = {}

local NCHAR_SEPARATOR = summarize_helper.NCHAR_SEPARATOR

local plot_data = {
    {key = "per_rank_api_time", label = "CPU Time Proportion for Rank %s"}
}


local function compute_percentages(total, parts, rest_label)
    rest_label = rest_label or "Other"
    local entries = {}
    local sum = 0

    -- Calculate sum and percentages of all subtimes
    for key, val in pairs(parts) do
        if val > 0 then
            sum = sum + val
            entries[key] = {
                pct = (val / total) * 100,
                val = val
            }
        end
    end

    -- Calculate "rest" percentage
    local rest_val = total - sum
    if rest_val > 0 then
        local rest_pct = (rest_val / total) * 100
        entries[rest_label] = {
            pct = rest_pct,
            val = rest_val
        }
    end

    return entries
end


local function ascii_pie_chart(data, radius)
    radius = radius or 10

    -- Extract labels and percentages from the table
    local labels = {}
    local percentages = {}
    local total = 0
    for label, entry in pairs(data) do
        table.insert(labels, label)
        table.insert(percentages, entry.pct)
        total = total + entry.pct
    end

    -- Normalize percentages
    local proportions = {}
    for i, p in ipairs(percentages) do
        proportions[i] = p / total
    end

    -- Convert proportions to angles
    local angles = {}
    local start_angle = 0
    for i, p in ipairs(proportions) do
        local end_angle = start_angle + p * 2 * math.pi
        angles[i] = {start_angle, end_angle}
        start_angle = end_angle
    end

    -- Characters for each segment
    local chars = {"░", "▒", "▓", "█", "●", "◼"}
    local segment_chars = {}
    for i = 1, #percentages do
        segment_chars[i] = chars[((i - 1) % #chars) + 1]
    end

    -- Draw the circle row by row
    for y = -radius, radius do
        local line = ""
        for x = -2 * radius, 2 * radius do
            local dx = x / 2
            local dist = math.sqrt(dx * dx + y * y)
            if dist <= radius then
                local angle = math.atan2(y, dx)
                if angle < 0 then
                    angle = angle + 2 * math.pi
                end
                for idx, ang in ipairs(angles) do
                    local start_a, end_a = ang[1], ang[2]
                    if angle >= start_a and angle < end_a then
                        line = line .. segment_chars[idx]
                        break
                    end
                end
            else
                line = line .. " "
            end
        end
        print(line)
    end

    -- Legend
    print("\nLegend:")
    local legend = {}
    for i, label in ipairs(labels) do
        table.insert(legend, {
            label = label,
            pct = percentages[i],
            ch = segment_chars[i]
        })
    end

    table.sort(legend, function(a, b) return a.pct > b.pct end)

    for _, entry in ipairs(legend) do
        print(string.format(" %s  %s (%.1f%%)", entry.ch, entry.label, entry.pct))
    end
end


function summarize_plot.print_plot(title, data)
    print(("="):rep(NCHAR_SEPARATOR))
    print(title)
    print(("="):rep(NCHAR_SEPARATOR))
    for label, entries in pairs(data) do
        print(label.. " :\n")
        ascii_pie_chart(entries)
    end
    print(("="):rep(NCHAR_SEPARATOR))
end



function summarize_plot.get_plot_data(data)
    local entries = {}

    data:for_each_rank(function (mpi_rank, _)
        local app_time = data:get_app_dur()
        local hip_time = data:compute_total_covered_duration(ratelprof.consts._ENV.DOMAIN_HIP)
        local mpi_time = data:compute_total_covered_duration(ratelprof.consts._ENV.DOMAIN_MPI)
        local omp_time = data:compute_total_covered_duration(ratelprof.consts._ENV.DOMAIN_OMP_TGT,
                                                             ratelprof.consts._ENV.DOMAIN_OMP_TGT_RTL,
                                                             ratelprof.consts._ENV.DOMAIN_OMPT)

        for _, plot in ipairs(plot_data) do
            if plot.key == "per_rank_api_time" then
                entries[string.format(plot.label, mpi_rank)] = compute_percentages(app_time, {
                                                                    ["HIP API"] = hip_time,
                                                                    ["MPI API"] = mpi_time,
                                                                    ["OMP API"] = omp_time
                                                                })
            end
        end
    end)


    return entries
end


return summarize_plot
