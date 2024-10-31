local common = {}

local json = require("json")

common.HSA_DOMAIN = 0
common.HIP_DOMAIN = 1
common.OMP_DOMAIN = 2

common.MEMOP_DOMAIN = 16
common.KERNOP_DOMAIN = 17

common.domainLookup = {
    [common.HSA_DOMAIN] = "hsaTraces",
    [common.HIP_DOMAIN] = "hipTraces",
    [common.MEMOP_DOMAIN] = "memoryTraces",
    [common.KERNOP_DOMAIN] = "kernelTraces"
}

function common.load_json(__input_path__)
    if __input_path__ == nil then
        error ("Missing JSON input file")
        return nil
    end
    local infile = io.open (__input_path__, "r")
    if infile == nil then
        error ("JSON input file "..__input_path__.." can't be opened")
        return nil
    end
    local data = infile:read ("*a")
    infile:close ()
    return JSON:decode(data)
end

function common.get_nested_value(tbl, path)
    local keys = path:split(".")
    local value = tbl
    for _, key in ipairs(keys) do
        local index = tonumber(key)
        if index then
            value = value[index]
        else
            value = value[key]
        end
        if value == nil then
            break
        end
    end
    return value
end

function common.get_copy_name(trace)
    return "Copy"..common.get_copy_name_from_kind(trace.args.src_type)..
            "To"..common.get_copy_name_from_kind(trace.args.dst_type)
end

function common.get_copy_name_from_kind(kind)
    if kind == 0 then 
        return "Host"
    elseif kind == 1 then 
        return "Device"
    end
    return "Unknown"
end

function common.merge_tab(t1, t2)
    for _, value in pairs(t2) do
        table.insert(t1, value)
    end
    return t1
end
    
return common