local kernel_helper = require ("commands.inspect.kernel_helper")
local agent_helper  = require ("commands.inspect.agent_helper")

local inspect = {}

local function inspect_kernels(application, opt)
    if application == nil or not ratelprof.fs.exists(application) then
        Message:print("No application to inspect.")
        os.exit(1)
    end

    local output = ratelprof.get_opt_val(opt, "output")
    local mangled = ratelprof.get_opt_val(opt, "mangled")
    local trunc = ratelprof.get_opt_val(opt, "trunc")
    local save_json = ratelprof.get_opt_val(opt, "save-json")

    local output_file = output or ("inspect_"..ratelprof.fs.basename(application)..".csv")
    if not ratelprof.fs.has_extension(output_file, ".csv") then
        Message:error("Output file need to be a CSV")
        os.exit(1)
    end
    
    Message:print("RPROF: Inspecting '"..application.."' . . .")
    local application_metadata = kernel_helper.get_kernel_metadata(application)

    local kernels_metadata = application_metadata["amdhsa.kernels"]
    
    Message:print("RPROF: "..#kernels_metadata.." kernels extracted from GPU ELF.")
    
    local csv_entries = {"Name, Wavefront Size, Private Segment Size, Group Segment Size, SGPR count, SGPR spill count, VGPR count, VGPR spill count, Language"}

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

    local file = ratelprof.fs.open_file(output_file, "w")
    file:write(table.concat(csv_entries, "\n")) 
    file:close()
    Message:print("RPROF: CSV output written to " .. output_file)

    if save_json then
        local json_output = ratelprof.utils.generate_json(application_metadata)
        output_file = ratelprof.fs.remove_extension(output_file, ".csv")..".json"
        local file = ratelprof.fs.open_file(output_file, "w")
        file:write(json_output)
        file:close()
        Message:print("RPROF: JSON output written to " .. output_file)
    end
end

local function inspect_agents()
    agent_helper.print_gpu_data()
end

function inspect.process_inspecting(positional_args, opt)

    if ratelprof.get_opt_val(opt, "info") == "gpu" then
        inspect_agents()
    elseif ratelprof.get_opt_val(opt, "info") == "kernels" then
        inspect_kernels(positional_args[1], opt)
    else
        Message:print ("Invalid inspect option. Use 'gpu' or 'kernels'.")
        os.exit(1)
    end
end

return inspect
