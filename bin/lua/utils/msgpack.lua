local msgpack = {}

local msgpack_decoder = require ("msgpack_decoder")
local msgpack_encoder = require ("msgpack_encoder")

msgpack.encoder = msgpack_encoder

function msgpack.decode (file)
    return msgpack_decoder.decode_msgpack_binary(file)
end

msgpack.encode = {}

local str_map       = {}
local reverse_map   = {}
local counter       = 0

local function get_key(s)
    if reverse_map[s] then
        return reverse_map[s]
    end
    counter = counter + 1
    str_map[counter] = s
    reverse_map[s] = counter - 1
    return counter - 1
end

function msgpack.encode.get_ext_string_table()
    return str_map
end

local function encode_ext_string(buf, str)
    local key = get_key(str)
    local type_code = 1
    local data = msgpack_encoder.new(16, msgpack_encoder.OVERFLOW_REALLOC)
    data:encode_uint(key)
    buf:encode_ext(type_code, data)
    data:free()
end


local function encode_table(buf, tbl)
    local is_array = ratelprof.utils.is_array(tbl)
    if is_array then
        buf:encode_array(#tbl)
    else
        local count = 0
        for _ in pairs(tbl) do
            count = count + 1
        end
        buf:encode_map(count)
    end

    for k, v in pairs(tbl) do
        -- Encode key if map
        if not is_array then
            if type(k) == "string" then
                encode_ext_string(buf, k)
            elseif ratelprof.utils.is_integer(k) then
                buf:encode_int(k)
            else
                error("Unsupported key type: " .. type(k))
            end
        end

        -- Encode value
        if type(v) == "string" then
            -- buf:encode_string(v)
            encode_ext_string(buf, v)
        elseif type(v) == "boolean" then
            buf:encode_bool(v)
        elseif v == nil then
            buf:encode_nil()
        elseif type(v) == "table" then
            encode_table(buf, v) -- recursive
        elseif ratelprof.utils.is_integer(v) then
            buf:encode_int(v)
        elseif type(v) == "number" then
            buf:encode_double(v)
        else
            error("Unsupported value type: " .. type(v))
        end
    end
end


function msgpack.encode.auto_encode(data)
    if type (data) ~= "table" then
        error ("argument data need to be a table")
    end

    local buf =  msgpack_encoder.new(1024, msgpack_encoder.OVERFLOW_REALLOC)
    encode_table(buf, data)
    return buf
end


function msgpack.encode.auto_encode_to_b64(data)
    local buf = msgpack.encode.auto_encode(data)
    local b64_buffer = buf:to_b64()
    buf:free()
    return b64_buffer

end

msgpack.encode.encode_ext_string = encode_ext_string
msgpack.encode.encode_table      = encode_table

return msgpack