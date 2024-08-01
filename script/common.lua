local common = {}

local json = require("json")

function common.sortByColumn(a, b, columnName, sortType, valueType)
    local aVal, bVal
    
    if valueType == "int" then
        aVal, bVal = tonumber(a[columnName]), tonumber(b[columnName])
    elseif valueType == "str" then
        aVal, bVal = tostring(a[columnName]), tostring(b[columnName])
    else
        error("valueType " .. valueType .. " not supported.")
    end

    if sortType == "<" then
        return aVal < bVal
    elseif sortType == ">" then
        return aVal > bVal
    else
        error("sortType " .. sortType .. " not supported.")
    end
end

function common.has_extension(filename, extension)
    return filename:sub(-#extension) == extension
end

function common.load_json(__input_path__)
    if __input_path__ == nil then
        error ("Missing Rocprof JSON input file")
        return nil
    end
    local infile = io.open (__input_path__, "r")
    if infile == nil then
        error ("Rocprof JSON input file "..__input_path__.." can't be opened")
        return nil
    end
    local data = infile:read ("*a")
    infile:close ()
    return JSON:decode(data)
end

function common.check_arg(arg)
    if #arg < 2 then
        print("Usage: lua " .. arg[0] .. " <input.csv> <output.csv>")
        os.exit(1)
    end
end

function common.split(inputstr, sep)
    if sep == nil then
        sep = "%s"
    end
    local t = {}
    for str in string.gmatch(inputstr, "([^"..sep.."]+)") do
        table.insert(t, str)
    end
    return t
end

function common.getValueAtPath(table, path)
    local keys = common.split(path, ".")
    local currentValue = table

    for _, key in ipairs(keys) do
        local varName, index = key:match("^(%a+)%[(%d+)%]$")
        if index then
            currentValue = currentValue[varName][tonumber(index)]
        else
            currentValue = currentValue[key]
        end
        if currentValue == nil then
            return nil
        end
    end

    return currentValue
end


return common