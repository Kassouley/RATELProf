local kernel_helper = require ("commands.inspect.kernel_helper")

local inspect = {}

local function inspect_kernels(application, opt)
    if application == nil or not ratelprof.fs.exists(application) then
        local application_in_PATH = ratelprof.fs.exists_in_PATH(application)
        if application_in_PATH == nil then
            Message:print("No application to inspect or '"..application.."' doesn't exists.")
            os.exit(1)
        end
        application = application_in_PATH
    end

    local output_dir = ratelprof.get_opt_val(opt, "output_dir") or "."
    local mangled = ratelprof.get_opt_val(opt, "mangled")
    local trunc = ratelprof.get_opt_val(opt, "trunc")
    local save_json = ratelprof.get_opt_val(opt, "save-json")

    Message:print("RPROF: Inspecting '"..application.."' . . .")
    local application_metadatas = kernel_helper.get_kernel_metadata(application)

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
            local file = ratelprof.fs.open_file(output_file_json, "w")
            file:write(json_output)
            file:close()
            Message:print("RPROF: JSON output written to " .. output_file_json)
        end

    end
end

function inspect.process(positional_args, opt)
    inspect_kernels(positional_args[1], opt)
  
end

return inspect
