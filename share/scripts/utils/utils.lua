require("utils.json.json")

local utils = {}

function utils.load_json(__input_path__)
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


function utils.merge_tab(t1, ...)
    for _, t in ipairs({...}) do
        for _, value in pairs(t) do
            table.insert(t1, value)
        end
    end
    return t1
end

function utils.execute_command(cmd)
    local handle = io.popen(cmd)
    local result = handle:read("*a")
    handle:close()
    return string.gsub(result, "\n$", "")
end


function utils.generate_json(value, indent)
    indent = indent or 0
    local indentation = string.rep(" ", indent)
    local json_parts = {}

    if type(value) ~= "table" then
        if type(value) == "string" then
            return string.format("%q", value) -- Escape strings for JSON
        else
            return tostring(value) -- Handle numbers, booleans, and nil
        end
    end

    -- Check if the table is an array (has sequential numeric indices)
    local is_array = true
    local count = 0
    for k, _ in pairs(value) do
        count = count + 1
        if type(k) ~= "number" or k ~= count then
            is_array = false
            break
        end
    end

    if is_array then
        -- Handle JSON list (array)
        table.insert(json_parts, "[\n")
        for i, v in ipairs(value) do
            if i > 1 then
                table.insert(json_parts, ",\n")
            end
            table.insert(json_parts, indentation .. "  " .. generate_json(v, indent + 2))
        end
        table.insert(json_parts, "\n" .. indentation .. "]")
    else
        -- Handle JSON object
        table.insert(json_parts, "{\n")
        local first = true
        for k, v in pairs(value) do
            if not first then
                table.insert(json_parts, ",\n")
            end
            first = false

            local key = tostring(k)
            if type(k) == "string" then
                key = string.format("%q", k) -- Escape string keys
            end

            table.insert(json_parts, indentation .. "  " .. key .. ": " .. generate_json(v, indent + 2))
        end
        table.insert(json_parts, "\n" .. indentation .. "}")
    end

    return table.concat(json_parts)
end

return utils