local lfs = require("lfs")
local images_manager = {}

-- Base64 encoding table
local base64_chars = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/'

-- Function to encode a string in Base64
local function base64_encode(data)
    local encoded = ""
    local padding = 0

    -- Ensure the data length is a multiple of 3
    while #data % 3 ~= 0 do
        data = data .. "\0"
        padding = padding + 1
    end

    -- Process each 3-byte block
    local encoded = ""
    for i = 1, #data, 3 do
        local byte1 = string.byte(data, i) or 0
        local byte2 = string.byte(data, i + 1) or 0
        local byte3 = string.byte(data, i + 2) or 0

        -- Combine the bytes into a single 24-bit number
        local triple = (byte1 * 2^16) + (byte2 * 2^8) + byte3

        -- Extract 6-bit chunks and convert to Base64 characters
        encoded = encoded .. base64_chars:sub(math.floor(triple / 2^18) % 64 + 1, math.floor(triple / 2^18) % 64 + 1)
        encoded = encoded .. base64_chars:sub(math.floor(triple / 2^12) % 64 + 1, math.floor(triple / 2^12) % 64 + 1)
        encoded = encoded .. base64_chars:sub(math.floor(triple / 2^6) % 64 + 1, math.floor(triple / 2^6) % 64 + 1)
        encoded = encoded .. base64_chars:sub(triple % 64 + 1, triple % 64 + 1)
    end

    -- Handle padding
    if padding == 1 then
        encoded = encoded:sub(1, -2) .. "="
    elseif padding == 2 then
        encoded = encoded:sub(1, -3) .. "=="
    end

    return encoded
end

local function get_img_data(image_path)
    local file = lfs.open_file(image_path, "rb")
    local image_data = file:read("*all")
    file:close()
    return image_data
end

-- Function to read the image file and convert to Base64
local function img_to_b64(image_data)
    return base64_encode(image_data)
end

function images_manager.img_to_src(image_path)
        local image_fmt = image_path:match("^.+%.(.+)$")
        local image_data = get_img_data(image_path)
        local image_b64 = img_to_b64(image_data)
        return "data:image/"..image_fmt..";base64,"..image_b64
end

return images_manager