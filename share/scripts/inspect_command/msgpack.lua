local msgpack = {}

local function ordered_table()
    local ordered_table = {
        keys = {}, -- To keep track of the order of keys
        data = {}, -- To store the key-value pairs
    }

    setmetatable(ordered_table, {
        __index = function(t, k)
            return t.data[k] -- Redirect indexing to the data table
        end,
        __newindex = function(t, k, v)
            if v == nil then
                t.data[k] = nil
                for i, key in ipairs(t.keys) do
                    if k == key then
                        table.remove(t.keys, i)
                        break
                    end
                end
            else
                if t.data[k] == nil then
                    table.insert(t.keys, k) -- Add key to the order list if it's new
                end
                t.data[k] = v -- Store the value in the data table
            end
        end,
        __pairs = function(t)
            local i = 0
            return function()
                i = i + 1
                local k = t.keys[i]
                if k then
                    return k, t.data[k]
                end
            end
        end,
    })
    return ordered_table
end

-- Override pairs for Lua 5.1 / LuaJIT
local old_pairs = pairs
function pairs(tbl)
    local mt = getmetatable(tbl)
    if mt and mt.__pairs then
        return mt.__pairs(tbl)
    end
    return old_pairs(tbl)
end


function msgpack.decode(hex_string)
    local index = 1
    local data = ordered_table()
    
    -- Convert the hex string into a table of bytes
    local bytes = {}
    for hex in string.gmatch(hex_string, "%S+") do
        table.insert(bytes, hex)
    end

    -- Function to get the next byte and increment index
    local function next_byte()
        local byte = bytes[index]
        index = index + 1
        return tonumber(byte, 16)
    end
    -- Decode function for fixnum, fixmap, fixarray, etc.
    local function decode()
        local byte = next_byte()
        
        -- Determine the type of the current byte
        if byte >= 0x00 and byte <= 0x7f then
            -- pos_fixint (0x00 - 0x7f)
            return byte
        elseif byte >= 0x80 and byte <= 0x8f then
            -- fixmap (0x80 - 0x8f)
            local map_len = byte - 0x80
            local map = ordered_table()
            for i = 1, map_len do
                local key = decode()
                local value = decode()
                map[key] = value
            end
            return map
        elseif byte >= 0x90 and byte <= 0x9f then
            -- fixarray (0x90 - 0x9f)
            local array_len = byte - 0x90
            local array = {}
            for i = 1, array_len do
                table.insert(array, decode())
            end
            return array
        elseif byte >= 0xa0 and byte <= 0xbf then
            -- fixstr (0xa0 - 0xbf)
            local str_len = byte - 0xa0
            local str = ""
            for i = 1, str_len do
                str = str .. string.char(next_byte())
            end
            return str
        elseif byte == 0xc0 then
            -- nil
            return nil
        elseif byte == 0xc2 then
            -- false
            return false
        elseif byte == 0xc3 then
            -- true
            return true
        elseif byte == 0xca then
            -- float32
            local float = string.unpack(">f", string.char(next_byte(), next_byte(), next_byte(), next_byte()))
            return float
        elseif byte == 0xcb then
            -- float64
            local float = string.unpack(">d", string.char(next_byte(), next_byte(), next_byte(), next_byte(), next_byte(), next_byte(), next_byte(), next_byte()))
            return float
        elseif byte == 0xcc then
            -- uint8
            return next_byte()
        elseif byte == 0xcd then
            -- uint16
            return (next_byte() * 256) + next_byte()
        elseif byte == 0xce then
            -- uint32
            return (next_byte() * 16777216) + (next_byte() * 65536) + (next_byte() * 256) + next_byte()
        elseif byte == 0xcf then
            -- uint64
            local high = (next_byte() * 16777216) + (next_byte() * 65536) + (next_byte() * 256) + next_byte()
            local low = (next_byte() * 16777216) + (next_byte() * 65536) + (next_byte() * 256) + next_byte()
            return high * 4294967296 + low
        elseif byte == 0xd0 then
            -- int8
            local val = next_byte()
            if val >= 128 then val = val - 256 end
            return val
        elseif byte == 0xd1 then
            -- int16
            local val = (next_byte() * 256) + next_byte()
            if val >= 32768 then val = val - 65536 end
            return val
        elseif byte == 0xd2 then
            -- int32
            local val = (next_byte() * 16777216) + (next_byte() * 65536) + (next_byte() * 256) + next_byte()
            if val >= 2147483648 then val = val - 4294967296 end
            return val
        elseif byte == 0xd3 then
            -- int64
            local high = (next_byte() * 16777216) + (next_byte() * 65536) + (next_byte() * 256) + next_byte()
            local low = (next_byte() * 16777216) + (next_byte() * 65536) + (next_byte() * 256) + next_byte()
            if high >= 2147483648 then
                high = high - 4294967296
                low = low - 4294967296
            end
            return high * 4294967296 + low
        elseif byte == 0xd9 then
            -- str8
            local len = next_byte()
            local str = ""
            for i = 1, len do
                str = str .. string.char(next_byte())
            end
            return str
        elseif byte == 0xda then
            -- str16
            local len = (next_byte() * 256) + next_byte()
            local str = ""
            for i = 1, len do
                str = str .. string.char(next_byte())
            end
            return str
        elseif byte == 0xdb then
            -- str32
            local len = (next_byte() * 16777216) + (next_byte() * 65536) + (next_byte() * 256) + next_byte()
            local str = ""
            for i = 1, len do
                str = str .. string.char(next_byte())
            end
            return str
        elseif byte == 0xdc then
            -- array16
            local len = (next_byte() * 256) + next_byte()
            local array = {}
            for i = 1, len do
                table.insert(array, decode())
            end
            return array
        elseif byte == 0xdd then
            -- array32
            local len = (next_byte() * 16777216) + (next_byte() * 65536) + (next_byte() * 256) + next_byte()
            local array = {}
            for i = 1, len do
                table.insert(array, decode())
            end
            return array
        elseif byte == 0xde then
            -- map16
            local len = (next_byte() * 256) + next_byte()
            local map = ordered_table()
            for i = 1, len do
                local key = decode()
                local value = decode()
                map[key] = value
            end
            return map
        elseif byte == 0xdf then
            -- map32
            local len = (next_byte() * 16777216) + (next_byte() * 65536) + (next_byte() * 256) + next_byte()
            local map = ordered_table()
            for i = 1, len do
                local key = decode()
                local value = decode()
                map[key] = value
            end
            return map
        elseif byte >= 0xe0 and byte <= 0xff then
            -- neg_fixint (0xe0 - 0xff)
            return -(byte - 0xe0)
        end
    end

    return decode()
end

return msgpack
