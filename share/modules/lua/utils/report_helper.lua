local convert   = require ("utils.convert")

local report_helper = {}

local _MEM_KIND = {"Host", "Device"}

function report_helper.get_copy_name_from_kind(kind)
    return _MEM_KIND[kind+1]
end

local get_name = report_helper.get_copy_name_from_kind

function report_helper.get_copy_name(src, dst)
    return ("Copy%sTo%s"):format(get_name(src), get_name(dst))
end

function report_helper.get_duration(dur, timeunit)
    if timeunit ~= "ns" then
        return convert.time(dur, "ns", timeunit)
    end
    return dur
end

function report_helper.get_size(size)
    return string.format("%.0f", convert.bytes(size, "bytes", "mb"))
end

return report_helper