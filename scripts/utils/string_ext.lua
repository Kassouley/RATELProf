-- string.lua

-- Trim whitespace from both ends of a string
function string:trim()
    return self:match("^%s*(.-)%s*$")
end

-- Split a string by a given delimiter
function string:split(delimiter)
    delimiter = delimiter or " "
    local result = {}
    local pattern = string.format("([^%s]+)", delimiter)
    for match in string.gmatch(self, pattern) do
        table.insert(result, match)
    end
    return result
end

-- Check if a string starts with a given prefix
function string:startswith(prefix)
    return self:sub(1, #prefix) == prefix
end

-- Check if a string ends with a given suffix
function string:endswith(suffix)
    return self:sub(-#suffix) == suffix
end

-- Convert a string to title case
function string:titlecase()
    return self:gsub("(%a)([%w_']*)", function(first, rest)
        return first:upper() .. rest:lower()
    end)
end

-- Count the number of occurrences of a substring in a string
function string:count(substring)
    local count = 0
    local start = 1
    while true do
        local pos = self:find(substring, start, true)
        if not pos then break end
        count = count + 1
        start = pos + #substring
    end
    return count
end

-- Pad a string to a given length with a specified character (default is space)
function string:pad(length, char)
    char = char or " "
    if #self >= length then return self end
    local pad_length = length - #self
    local left_pad = string.rep(char, math.floor(pad_length / 2))
    local right_pad = string.rep(char, math.ceil(pad_length / 2))
    return left_pad .. self .. right_pad
end
