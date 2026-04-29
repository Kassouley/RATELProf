local options_helper = require ("options_helper")
local liborkh = require("liborkh_lua")

local inspect = {}

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


function inspect.get_kernel_number(binary_app)
    local res = iterate_linked_lib(binary_app, function(bin)
        return liborkh.get_kernel_count(bin, { id_mode = 1 })
    end)

    local nb_kernels = 0

    for _, nkernels in pairs(res or {}) do
        nb_kernels = nb_kernels + nkernels
    end

    if nb_kernels == 0 then
        Message:error("No kernels found in binary or any linked libraries" )
        os.exit(1)
    end

    print("RPROF: Found "..nb_kernels.." kernels in binary and linked libraries.")

    return nb_kernels
end


local function get_kernel_metadata(binary_app, archs)
    local data = {}
    local data_size = 0
    local function extract(arch)
        local metadata_list = liborkh.get_metadata_buffer(binary_app, {target_arch = arch})
        if metadata_list then
            for id, metadata in pairs(metadata_list) do
                if metadata.size > 0 then
                    data[id] = ratelprof.msgpack.decode_from_memory(metadata.data, metadata.size, true)
                    data_size = data_size + 1
                end
                liborkh.free_metadata_buffer(metadata.data)
            end
        end
    end
    if archs and #archs > 0 then
        for _, arch in ipairs(archs) do
            extract(arch)
        end
    else
        extract()
    end
    return data, data_size
end


local function inspect_kernels(application, opt)
    local output_dir = ratelprof.get_opt_val(opt, "output_dir") or "."
    local mangled    = ratelprof.get_opt_val(opt, "mangled")
    local trunc      = ratelprof.get_opt_val(opt, "trunc")
    local save_json  = ratelprof.get_opt_val(opt, "save-json")
    local archs      = options_helper.parse_list_option(opt, "archs")

    Message:print("RPROF: Inspecting '"..application.."' . . .")
    local application_metadatas, size = get_kernel_metadata(application, archs)
    if size == 0 then
        Message:print("RPROF: No kernels has been found.")
    end

    local csv_entries = {"Name, Wavefront Size, Private Segment Size, Group Segment Size, SGPR count, SGPR spill count, VGPR count, VGPR spill count, Language"}

    for id, application_metadata in pairs (application_metadatas) do
        local kernels_metadata = application_metadata["amdhsa.kernels"]
        Message:print("RPROF: "..#kernels_metadata.." kernels extracted for ELF "..id)

        for _, kernel in pairs(kernels_metadata) do
            local kernel_entry = {
                ratelprof.utils.get_kernel_name(kernel[".name"], trunc, mangled),
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

        local output_file_csv = ratelprof.fs.concat_path(output_dir, "inspect_"..id..".csv")
        local file = ratelprof.fs.open_file(output_file_csv, "w")
        file:write(table.concat(csv_entries, "\n")) 
        file:close()
        Message:print("RPROF: CSV output written to " .. output_file_csv)

        if save_json then
            local output_file_json = ratelprof.fs.concat_path(output_dir, "inspect_"..id..".json")
            local json_output = ratelprof.utils.generate_json(application_metadata)
            local f = ratelprof.fs.open_file(output_file_json, "w")
            f:write(json_output)
            f:close()
            Message:print("RPROF: JSON output written to " .. output_file_json)
        end

    end
end

function inspect.process(positional_args, opt)
    local application = ratelprof.get_bin_val(positional_args)
    inspect_kernels(application, opt)
end

return inspect
