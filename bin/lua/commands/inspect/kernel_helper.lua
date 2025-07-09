local msgpack = require ("msgpack_decoder")

local kernel_helper = {}

local function hex_to_bin(hex)
    return (hex:gsub('..', function(cc)
        return string.char(tonumber(cc, 16))
    end))
end

function kernel_helper.get_kernel_metadata(binary_app)
    local tmp_filename = "/tmp/rprof_inspect_gpu_elf"

    local llvm_check = "readelf -S " .. binary_app .. " | grep -q .llvm.offloading"
    local hip_check  = "readelf -S " .. binary_app .. " | grep -q .hip_fatbin"

    local section = nil
    if os.execute(llvm_check) == 0 then
        section = ".llvm.offloading"
    elseif os.execute(hip_check) == 0 then
        section = ".hip_fatbin"
    else
        Message:error("No GPU ELF has been found in your application.")
        os.exit(1)
    end

    local s = ratelprof.utils.execute_command(string.format(
        [[readelf -x %s %s | awk 'NR > 2 {print substr($0, 14, 36)}' | tr -d ' \n']],
        section, binary_app 
    ))
    
    local start_pos = s:find("7f454", 1, true) 
    if start_pos then
        s = s:sub(start_pos)
    else
        error("Failed to find the magic bytes of the ELF header.")
    end

    local bin = hex_to_bin(s)
    
    local file = assert(io.open(tmp_filename, "wb"))
    file:write(bin)
    file:close()

    os.execute(string.format(
        [[readelf --notes %s | grep -A 1 'description data:' | cut -d ':' -f 2 | tr -d ' ' | xxd -r -p > %s.mp]],
        tmp_filename, tmp_filename
    ))
    
    local data = msgpack.decode_msgpack_binary(tmp_filename..".mp", true)
    
    if not data then
        Message:error("No metadata found in GPU ELF.")
        os.exit(1)
    end

    return data
end

-- TODO 03/05/2025 : Optimize this function
-- Currently, it reads the entire ELF file and extracts the section
-- containing the GPU ELF. This is inefficient and can be improved.
function kernel_helper.get_kernel_number(binary_app)
    local data = kernel_helper.get_kernel_metadata(binary_app)
    return #data["amdhsa.kernels"]
end

return kernel_helper