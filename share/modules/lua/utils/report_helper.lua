local convert   = require ("utils.convert")

local report_helper = {}

function report_helper.get_duration(dur, timeunit)
    if timeunit ~= "ns" then
        return convert.time(dur, "ns", timeunit)
    end
    return dur
end

function report_helper.get_size(size, sizeunit)
    if sizeunit ~= "B" then
        return convert.bytes(size, "B", sizeunit)
    end
    return size
end


function report_helper.label_gpu_with_rank(key)
    local rank   = key.rank
    local gpu_id = key.gpu_id
    if rank == -1 then
        return tostring(gpu_id)
    end
    return gpu_id .. string.format(" ( rank %d )", rank)
end

function report_helper.create_key(key_arr, uargs)
    local str = ""
    for _, k in ipairs(key_arr) do
        str = str .. "::" .. k
    end

    return {
        str = str,
        values = key_arr,
        uargs = uargs
    }
end

return report_helper