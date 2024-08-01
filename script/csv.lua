local csv = {}

function csv.read(filename)
    local file = io.open(filename, "r")
    if not file then
        error("Could not open file " .. filename)
    end
    local data = {}
    local header = file:read("*l")
    for line in file:lines() do
        local fields = {}
        local pos = 1
        while pos <= #line do
            -- Handle quoted fields
            if line:sub(pos, pos) == '"' then
                local start_pos = pos + 1
                local end_pos = line:find('"', start_pos)
                while end_pos do
                    if line:sub(end_pos - 1, end_pos - 1) ~= '\\' then
                        break
                    end
                    end_pos = line:find('"', end_pos + 1)
                end
                if not end_pos then
                    error("Unclosed quote in line: " .. line)
                end
                table.insert(fields, line:sub(start_pos, end_pos - 1))
                pos = end_pos + 1
                if line:sub(pos, pos) == ',' then pos = pos + 1 end
            else
                -- Handle non-quoted fields
                local start_pos, end_pos = line:find('[^,]+', pos)
                if start_pos then
                    table.insert(fields, line:sub(start_pos, end_pos))
                    pos = end_pos + 1
                    if line:sub(pos, pos) == ',' then pos = pos + 1 end
                else
                    table.insert(fields, line:sub(pos))
                    break
                end
            end
        end
        for i, field in ipairs(fields) do
            fields[i] = field:match('^%s*(.-)%s*$') -- Trim leading/trailing whitespace
        end
        table.insert(data, fields)
    end
    file:close()
    return data
end

function csv.write(filename, data)
    local file = io.open(filename, "w")
    if not file then
        error("Could not open file " .. filename)
    end
    for _, row in pairs(data) do
        file:write(table.concat(row, ",") .. "\n")
    end
    file:close()
end

return csv