local convert   = require ("utils.convert")

local report_helper = {}

function report_helper.get_duration(dur, timeunit)
    if timeunit ~= "ns" then
        return convert.time(dur, "ns", timeunit)
    end
    return dur
end

function report_helper.get_size(size)
    return size
    -- return string.format("%.0f", convert.bytes(size, "bytes", "mb"))
end


return report_helper