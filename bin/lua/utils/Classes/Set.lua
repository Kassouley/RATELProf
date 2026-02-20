Set = {}
Set.__index = Set

-- Constructor
function Set:new()
    local obj = {
        _data = {},  -- stores keys
        size = 0     -- tracked count
    }
    setmetatable(obj, Set)
    return obj
end

-- Add element
function Set:add(value)
    if not self._data[value] then
        self._data[value] = true
        self.size = self.size + 1
        return true
    end
    return false
end

-- Remove element if exists
function Set:remove(value)
    if self._data[value] then
        self._data[value] = nil
        self.size = self.size - 1
        return true
    end
    return false
end

-- Check membership
function Set:has(value)
    return self._data[value] == true
end

-- Return number of elements
function Set:count()
    return self.size
end

-- Convert to array form
function Set:to_array()
    local arr = {}
    for k in pairs(self._data) do
        arr[#arr + 1] = k
    end
    return arr
end

-- tostring metamethod for printing
function Set:__tostring()
    local parts = {}
    for k in pairs(self._data) do
        parts[#parts+1] = tostring(k)
    end
    return "{" .. table.concat(parts, ", ") .. "}"
end