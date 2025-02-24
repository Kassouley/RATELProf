local utils   = require ("utils.utils")
local lfs     = require ("utils.lfs")
local msgpack = require ("inspect.msgpack")

local kernel_utils = {}

local function extract_gpu_elf(binary_app)
    local llvm_check = "readelf -S " .. binary_app .. " | grep -q .llvm.offloading"
    local hip_check  = "readelf -S " .. binary_app .. " | grep -q .hip_fatbin"

    local extract_command = ""
    if os.execute(llvm_check) == 0 then
        extract_command = "readelf -x .llvm.offloading " .. binary_app .. " | awk '/7f454/ {found=1} found {print $2 $3 $4 $5}' | tr -d ' \\n'"
    elseif os.execute(hip_check) == 0 then
        extract_command = "readelf -x .hip_fatbin " .. binary_app .. " | awk '/7f454/ {found=1} found {print $2 $3 $4 $5}' | tr -d ' \\n'"
    else
        print("No GPU ELF has been found in your application.")
        os.exit(1)
    end
    return utils.execute_command(extract_command)
end

local function get_kernel_metadata(gpu_elf)
    utils.execute_command("echo -n "..gpu_elf.." | xxd -r -p > /tmp/rprof_inspect_gpu_elf")
    local res = utils.execute_command("readelf --notes /tmp/rprof_inspect_gpu_elf")
    local encoded_metadata = res:match("description data:%s*([%x%s]+)")
    
    if not encoded_metadata then
        print("Error : No metadata found in GPU ELF.")
        os.exit(1)
    end

    return msgpack.decode(encoded_metadata)
end

function kernel_utils.inspect_kernels(application, options_values)
    if not lfs.file_exists(application) then
        print("No application to inspect.")
        os.exit(1)
    end

    local output_file = options_values.output or "inspect_"..lfs.basename(application)..".csv"
    if not lfs.has_extension(output_file, ".csv") then
        print("Error: output file need to be a CSV")
        os.exit(1)
    end
    
    print("RPROF: Inspecting '"..application.."' . . .")
    local gpu_elf = extract_gpu_elf(application)
    local application_metadata = get_kernel_metadata(gpu_elf)
    local kernels_metadata = application_metadata["amdhsa.kernels"]
    
    local csv_entries = {"Name, Wavefront Size, Private Segment Size, Group Segment Size, SGPR count, SGPR spill count, VGPR count, VGPR spill count, Language"}

    for _, kernel in pairs(kernels_metadata) do
        local kernel_name = kernel[".name"]
        if options_values.trunc then
            kernel_name = utils.execute_command("c++filt --no-params "..kernel_name)
        elseif not options_values.mangled then
            kernel_name = '"'..utils.execute_command("c++filt "..kernel_name)..'"'
        end

        local kernel_entry = {
            kernel_name,
            kernel[".wavefront_size"],
            kernel[".private_segment_fixed_size"],
            kernel[".group_segment_fixed_size"],
            kernel[".sgpr_count"],
            kernel[".sgpr_spill_count"],
            kernel[".vgpr_count"],
            kernel[".vgpr_spill_count"],
            kernel[".language"],
        }
        table.insert(csv_entries, table.concat(kernel_entry, ", "))
    end

    local file = lfs.open_file(output_file, "w")
    file:write(table.concat(csv_entries, "\n")) 
    file:close()
    print("RPROF: CSV output written to " .. output_file)

    if options_values["save-json"] then
        local json_output = utils.generate_json(application_metadata)
        output_file = lfs.remove_extension(output_file, ".csv")..".json"
        local file = lfs.open_file(output_file, "w")
        file:write(json_output)
        file:close()
        print("RPROF: JSON output written to " .. output_file)
    end
end

return kernel_utils