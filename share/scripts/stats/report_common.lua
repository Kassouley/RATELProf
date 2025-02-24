local utils    = require ("utils.utils")
local convert  = require ("utils.convert")
local settings = require ("settings")

local report_common = {}

report_common = require ("stats.statistics")

-- Cache table to store previously fetched traces
report_common.trace_cache = {}

-- Optimized fetch_traces function
function report_common.fetch_traces(data, domain_string, opt)
    -- Check if traces for this domain_string are already cached
    local trace_cache = report_common.trace_cache
    if trace_cache[domain_string] then
        return trace_cache[domain_string]
    end

    -- If not cached, fetch and store in cache
    local ret = {}
    for _, trace in ipairs(data.trace_events) do
        if data.domain_id[tostring(trace.d)].name == domain_string
                and (not opt.is_only_main or data.phase_id[tostring(trace.p)] == "MAIN_PHASE") then
            
            if domain_string == "KERNEL_DISPATCH" and not opt.is_mangled then
                if opt.is_trunc then
                    trace.args.kernel_name = utils.execute_command("c++filt --no-params ".. trace.args.kernel_name)
                elseif not opt.is_trunc then
                    trace.args.kernel_name = utils.execute_command("c++filt ".. trace.args.kernel_name)
                end
            end
            table.insert(ret, trace)
        end
    end

    -- Cache the fetched traces
    trace_cache[domain_string] = ret
    return ret
end

function report_common.process_api_raw_data_for_sum_report(raw_data, timeunit)
    local function get_entry_key_tab(trace)
        return { trace.name }
    end

    local entries, total_metrics = report_common.get_entries(raw_data, get_entry_key_tab, report_common.get_duration, timeunit)
    local data = report_common.get_output_summary(entries, total_metrics)

    local headers = {
        "Time (%)", -- 1
        "Total Time ("..timeunit..")", -- 2 
        "Num Calls", -- 3
        "Avg ("..timeunit..")", -- 4
        "Med ("..timeunit..")", -- 5
        "Min ("..timeunit..")", -- 6
        "Max ("..timeunit..")", -- 7
        "StdDev ("..timeunit..")", -- 8
        "Name" -- 9
    }

    table.sort(data, function(a, b)
        return tonumber(a[2]) > tonumber(b[2])
    end)

    table.insert(data, 1, headers)
    return data
end


function report_common.process_api_raw_data_for_trace_report(raw_data, timeunit)
    local data = {}
    for _, trace in ipairs(raw_data) do
        local entry = {
            string.format("%.0f", trace.start),
            report_common.get_duration(trace, timeunit),
            trace.name,
            trace.id,
            trace.corr_id,
            trace.pid,
            trace.tid
        }
        table.insert(data, entry)
    end

    local headers = {
        "Start ("..timeunit..")", -- 1
        "Duration ("..timeunit..")", -- 2
        "Name", -- 3
        "Id", -- 4
        "CorrId", -- 5
        "Pid", -- 6
        "Tid" -- 7
    }

    table.sort(data, function(a, b)
        return tonumber(a[4]) < tonumber(b[4])
    end)


    table.insert(data, 1, headers)
    return data
end

function report_common.get_copy_name_from_kind(kind)
    return settings._MEM_KIND[kind+1]
end

function report_common.get_copy_name(trace)
    return "Copy"..report_common.get_copy_name_from_kind(trace.args.src_type)..
            "To"..report_common.get_copy_name_from_kind(trace.args.dst_type)
end

function report_common.get_duration(trace, timeunit)
    local dur = trace.dur
    if timeunit ~= "ns" then
        return convert.time(dur, "ns", timeunit)
    end
    return  dur
end

function report_common.get_size(trace)
    return convert.bytes(trace.args.size, "bytes", "mb")
end


function report_common.get_queue_time(trace, timeunit)
    local dur = trace.start - trace.args.dispatch_time
    if timeunit ~= "ns" then
        return convert.time(dur, "ns", timeunit)
    end
    return  dur
end

return report_common