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