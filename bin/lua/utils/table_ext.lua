function table.min(tbl)
    local vmin = nil
    local kmin = nil
    for k, v in pairs(tbl) do
        if vmin == nil or v < vmin then
            vmin = v
            kmin = k
        end
    end

    return vmin, kmin
end

function table.max(tbl)
    local vmax = nil
    local kmax = nil
    for k, v in pairs(tbl) do
        if vmax == nil or v > vmax then
            vmax = v
            kmax = k
        end
    end

    return vmax, kmax
end

function table.merge_arr(t1, t2)
    if not t1 then return t2
    elseif not t2 then return t1 end
    local res = {}

    for _, e in ipairs(t1) do
        res[#res + 1] = e
    end

    for _, e in ipairs(t2) do
        res[#res + 1] = e
    end

    return res
end

function table.merge_map(t1, t2)
    if not t1 then return t2
    elseif not t2 then return t1 end
    for k, v in pairs(t2) do
        t1[k] = v
    end
    return t1
end

function table.get_value(tbl, path)
    local current = tbl
    for key in string.gmatch(path, "[^.]+") do
        if type(current) ~= "table" then
            return nil -- Stop if we hit a non-table before the end
        end
        current = current[key]
        if current == nil then
            return nil -- Key not found
        end
    end
    return current
end

function table.icopy(src)
    local dest = {}
    for i, v in ipairs(src) do
        dest[i] = v
    end
    return dest
end

function table.copy(src)
    local dest = {}
    for i, v in ipairs(src) do
        dest[i] = v
    end
    return dest
end


local function deep_copy(o)
    if type(o) ~= "table" then
        return o
    end

    local copy = {}
    for k, v in pairs(o) do
        copy[k] = deep_copy(v)
    end
    return copy
end
table.deep_copy = deep_copy

function table.concat_keys(t, sep)
    sep = sep or ""
    local result, i = {}, 1
    for k, _ in pairs(t) do
        result[i], i = k, i + 1
    end
    return table.concat(result, sep)
end


function table.popi(array, index)
    local value = array[index]        -- store the value to return
    for i = index, #array - 1 do      -- shift elements left
        array[i] = array[i + 1]
    end
    array[#array] = nil                -- remove the last duplicate
    return value
end

function table.map(tbl, fn)
    local result = {}
    for i, v in ipairs(tbl) do
        result[i] = fn(v, i)
    end
    return result
end