local convert   = require ("utils.convert")

local report_helper = {}

function report_helper.get_duration(dur, timeunit)
    if timeunit ~= "ns" then
        return convert.time(dur, "ns", timeunit)
    end
    return dur
end

function report_helper.get_size(size)
    return string.format("%.0f", convert.bytes(size, "bytes", "mb"))
end


function report_helper.get_report_opt_value(report_id, opt_name, report_opt)
    local default = ratelprof.consts._ALL_RULES_REPORT[report_id].opt[opt_name].default
    if not default then
        error (string.format("No default report option value provided for %s in report %s", opt_name, report_id))
    end
    if type(default) == "number" then
        return tonumber(report_opt[opt_name]) or default
    end
    return report_opt[opt_name] or default
end


return report_helper