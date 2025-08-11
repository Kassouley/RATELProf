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
    local len1 = #t1
    local len2 = #t2
    for i = 1, len2 do
        t1[len1 + i] = t2[i]
    end
    return t1
end

function table.merge_map(t1, t2)
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
