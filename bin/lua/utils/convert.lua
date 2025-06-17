-- convert.lua
local convert = {}

-- Time Conversion Functions
convert.time_units = { sec = 1, ms = 1e3, us = 1e6, ns = 1e9 }
function convert.time(value, from_unit, to_unit)
    local units = convert.time_units
    return value * (units[to_unit] / units[from_unit])
end


-- Data Size Conversion Functions
convert.bytes_units = { bytes = 1, kb = 1024, mb = 1024^2, gb = 1024^3 }
function convert.bytes(value, from_unit, to_unit)
    local units = convert.bytes_units 
    return value * (units[from_unit] / units[to_unit])
end

-- Number Conversion Functions
function convert.num(value, from_format, to_format)
    if from_format == "dec" then
        if to_format == "hex" then
            return string.format("%X", value)
        elseif to_format == "bin" then
            return string.format("%b", value)
        end
    else
        local base = from_format == "hex" and 16 or 2
        local decimal_value = tonumber(value, base)
        if to_format == "dec" then
            return decimal_value
        elseif to_format == "hex" then
            return string.format("%X", decimal_value)
        elseif to_format == "bin" then
            return string.format("%b", decimal_value)
        end
    end
end

return convert