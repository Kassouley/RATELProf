local kernel_helper = {}

local function hex_to_bin(hex)
    return (hex:gsub('..', function(cc)
        return string.char(tonumber(cc, 16))
    end))
end

-- Helper: check if ELF section exists in a binary
local function has_gpu_section(bin)
    local llvm_section = ".llvm.offloading"
    local hip_section  = ".hip_fatbin"

    local check_cmd = "readelf -S " .. bin .. " | grep -q %s"
    if os.execute(string.format(check_cmd, llvm_section)) == 0 then
        return llvm_section
    elseif os.execute(string.format(check_cmd, hip_section)) == 0 then
        return hip_section
    else
        return nil
    end
end

local function extract_gpu_elf(bin, filename)
    local section = has_gpu_section(bin)
    if not section then
        return nil
    end
    local section_data = ratelprof.utils.execute_command(string.format(
        [[readelf -x %s %s | awk 'NR > 2 {print substr($0, 14, 36)}' | tr -d ' \n']],
        section, bin
    ))

    local start_index = 1
    local written_file = {}

    while true do
        local s, e = section_data:find("7f454", start_index, true)
        if not s then break end

        -- Find the start of the next match
        local next_s = section_data:find("7f454", e + 1, true)
        local bin_slice
        if next_s then
            bin_slice = section_data:sub(s, next_s - 1)  -- up to before next match
        else
            bin_slice = section_data:sub(s)  -- until end of string
        end

        local bin_data = hex_to_bin(bin_slice)

        local new_filename = filename .. ":" .. tostring(#written_file)
        table.insert(written_file, new_filename)
        local file = assert(io.open(new_filename, "wb"))
        file:write(bin_data)
        file:close()

        start_index = (next_s or (#section_data + 1))  -- continue after this match
    end

    return written_file
end


local function get_kernel_number(binary_app)
    local tmp_filename = "/tmp/rprof_inspect_gpu_elf"

    local gpu_elfs = extract_gpu_elf(binary_app, tmp_filename)

    if not gpu_elfs then return 0 end


    local array_size = 0
    local kernels_array_magic_bytes = "ae616d646873612e6b65726e656c73" -- amdhsa.kernels

    for _, elf_file in ipairs(gpu_elfs) do
        local msgpack_hex = ratelprof.utils.execute_command(string.format(
            [[readelf --notes %s | grep -A 1 'description data:' | cut -d ':' -f 2 | tr -d ' ']],
            elf_file
        ))

        local start_pos = msgpack_hex:find(kernels_array_magic_bytes, 1, true)
        if not start_pos then
            return 0
        end

        -- Move cursor right after the magic bytes
        local cursor = start_pos + #kernels_array_magic_bytes

        -- Get the next few bytes (enough to cover array32)
        local next_bytes_hex = msgpack_hex:sub(cursor, cursor + 10)  -- 5 bytes (10 hex chars)
        if #next_bytes_hex < 2 then
            return 0
        end
        msgpack_hex = nil

        local first_byte_hex = next_bytes_hex:sub(1, 2)
        local first_byte = tonumber(first_byte_hex, 16)

        if first_byte >= 0x90 and first_byte <= 0x9f then
            -- fixarray
            array_size = array_size + first_byte - 0x90

        elseif first_byte == 0xdc then
            -- array16
            local len_hex = next_bytes_hex:sub(3, 6) -- next 2 bytes
            if #len_hex == 4 then
                array_size = array_size + tonumber(len_hex, 16)
            end

        elseif first_byte == 0xdd then
            -- array32
            local len_hex = next_bytes_hex:sub(3, 10) -- next 4 bytes
            if #len_hex == 8 then
                array_size = array_size + tonumber(len_hex, 16)
            end
        end

    end

    return array_size
end

function kernel_helper.get_kernel_metadata(binary_app)
    print("FIX ME I'M BROKEN")
    os.exit(1)
    local tmp_filename = "/tmp/rprof_inspect_gpu_elf"

    local gpu_elfs = extract_gpu_elf(binary_app, tmp_filename)

    if not gpu_elfs then return nil end

    for _, elf_file in ipairs(gpu_elfs) do
        os.execute(string.format(
            [[readelf --notes %s | grep -A 1 'description data:' | cut -d ':' -f 2 | tr -d ' ' | xxd -r -p > %s.mp]],
            elf_file, elf_file
        ))
    end
    local data = ratelprof.msgpack.decode(tmp_filename .. ".mp", true)
    ratelprof.fs.rm(tmp_filename)
    return data
end


local function iterate_linked_lib(binary_app, func)

    local visited = {}
    local res = {}

    local function process_binary(bin)
        if visited[bin] then return end
        visited[bin] = true
        res[bin] = func(bin)

        -- Recurse into linked libraries
        local libs_output = ratelprof.utils.execute_command(string.format("ldd %s | awk '{print $3}'", bin))
        for lib in libs_output:gmatch("[^\r\n]+") do
            if lib and #lib > 0 and io.open(lib, "r") then
                io.close(io.open(lib))
                process_binary(lib)
            end
        end
    end

    process_binary(binary_app)

    return res
end



function kernel_helper.get_kernel_number(binary_app)
    print("FIX ME I'M BROKEN")
    return 5000
    -- local res = iterate_linked_lib(binary_app, function(bin)
    --     return get_kernel_number(bin)
    -- end)

    -- local nb_kernels = 0

    -- for _, nkernels in pairs(res or {}) do
    --     nb_kernels = nb_kernels + nkernels
    -- end

    -- if nb_kernels == 0 then
    --     Message:error("No kernels found in binary or any linked libraries" )
    --     os.exit(1)
    -- end

    -- return nb_kernels
end



return kernel_helper