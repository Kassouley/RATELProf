-- inspect.lua
-- Set up the script directory and package paths
local script_dir = debug.getinfo(1, "S").source:match("@(.*[\\/]?.*)") or ""
script_dir = script_dir:gsub('\\', '/'):match("(.*[\\/])") or ""
local paths = {
    '',
    '../',
    '../utils/',
    '../utils/json/',
}

for _, path in ipairs(paths) do
    package.path = package.path .. ';' .. script_dir .. path .. '?.lua'
end

require("string_ext")
local common = require("common")
local lfs = require("lfs")
local Script = require("Script")
local settings = common.load_json(lfs.get_script_path(1).."inspect_settings.json")
local msgpack = require("msgpack")

local INSTALL_DIR = os.getenv("RATELPROF_INSTALL_DIR")


local function execute_command(cmd)
    local handle = io.popen(cmd)
    local result = handle:read("*a")
    handle:close()
    return result
end


local function extract_gpu_elf(binary_app)
    local llvm_check = "readelf -S " .. binary_app .. " | grep -q .llvm.offloading"
    local hip_check = "readelf -S " .. binary_app .. " | grep -q .hip_fatbin"

    local extract_command = ""
    if os.execute(llvm_check) == 0 then
        extract_command = "readelf -x .llvm.offloading " .. binary_app .. " | awk '/7f454/ {found=1} found {print $2 $3 $4 $5}' | tr -d ' \\n'"
    elseif os.execute(hip_check) == 0 then
        extract_command = "readelf -x .hip_fatbin " .. binary_app .. " | awk '/7f454/ {found=1} found {print $2 $3 $4 $5}' | tr -d ' \\n'"
    else
        print("No GPU ELF has been found in your application.")
        os.exit(1)
    end
    return execute_command(extract_command)
end

local function get_kernel_metadata(gpu_elf)
    execute_command("echo -n "..gpu_elf.." | xxd -r -p > /tmp/rprof_inspect_gpu_elf")
    local res = execute_command("readelf --notes /tmp/rprof_inspect_gpu_elf")
    local encoded_metadata = res:match("description data:%s*([%x%s]+)")
    
    if not encoded_metadata then
        print("Error : No metadata found in GPU ELF.")
        os.exit(1)
    end

    return msgpack.decode(encoded_metadata)
end

function generate_json(value, indent)
    indent = indent or 0
    local indentation = string.rep(" ", indent)
    local json_parts = {}

    if type(value) ~= "table" then
        if type(value) == "string" then
            return string.format("%q", value) -- Escape strings for JSON
        else
            return tostring(value) -- Handle numbers, booleans, and nil
        end
    end

    -- Check if the table is an array (has sequential numeric indices)
    local is_array = true
    local count = 0
    for k, _ in pairs(value) do
        count = count + 1
        if type(k) ~= "number" or k ~= count then
            is_array = false
            break
        end
    end

    if is_array then
        -- Handle JSON list (array)
        table.insert(json_parts, "[\n")
        for i, v in ipairs(value) do
            if i > 1 then
                table.insert(json_parts, ",\n")
            end
            table.insert(json_parts, indentation .. "  " .. generate_json(v, indent + 2))
        end
        table.insert(json_parts, "\n" .. indentation .. "]")
    else
        -- Handle JSON object
        table.insert(json_parts, "{\n")
        local first = true
        for k, v in pairs(value) do
            if not first then
                table.insert(json_parts, ",\n")
            end
            first = false

            local key = tostring(k)
            if type(k) == "string" then
                key = string.format("%q", k) -- Escape string keys
            end

            table.insert(json_parts, indentation .. "  " .. key .. ": " .. generate_json(v, indent + 2))
        end
        table.insert(json_parts, "\n" .. indentation .. "}")
    end

    return table.concat(json_parts)
end


local function process_inspecting(positional_args, options_values)
    local application = positional_args[1]

    if not lfs.file_exists(application) then
        print("No application to inspect.")
        os.exit(1)
    end

    local output_file = options_values.output_file or "inspect_"..lfs.basename(application)..".csv"
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
        local kernel_entry = {
            kernel[".name"],
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

    if options_values.save_json then
        local json_output = generate_json(application_metadata)
        output_file = lfs.remove_extension(output_file, ".csv")..".json"
        local file = lfs.open_file(output_file, "w")
        file:write(json_output)
        file:close()
        print("RPROF: JSON output written to " .. output_file)
    end

end

local function json_option(script, _)
    script.options_values.save_json = true
end


local function output_option(script, value)
    script.options_values.output_file = value
end


-- Main script logic
local function main(arg)
        
    local attribute = {
        name = "ratelprof inspect",
        version = settings._VERSION,
        default_options_values = { 
            output_file = nil, 
        }
    }
    local script = Script:new(attribute)

    script:set_desc("\n\tInspect an application and output data about kernels from the application.")

    script:set_execute_function(process_inspecting)

    script:add_argument("application", false, false, "\tThe application to inspect.")

    script:add_option("save-json", "s", nil, 
                    "\tSave all metadata in a JSON file in addition to the CSV file.", 
                    false, json_option)

    script:add_option("output", "o", "<output_file>", 
                    "\tChange the CSV output file.", 
                    true, output_option)

    script:execute(arg)
end

-- Run the main function
main(arg)
