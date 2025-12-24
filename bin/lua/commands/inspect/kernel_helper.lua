local liborkh      = require("liborkh_lua")
local agent_helper = require("commands.inspect.agent_helper")

local kernel_helper = {}

function kernel_helper.get_kernel_metadata(binary_app)
    local data = {}
    local arch_list = agent_helper.get_arch_list()
    for _, arch in ipairs(arch_list) do
        local metadata_list = liborkh.get_metadata_buffer(binary_app, {target_arch = arch})
        if metadata_list then
            for id, metadata in pairs(metadata_list) do
                if metadata.size > 0 then
                    data[id] = ratelprof.msgpack.decode_from_memory(metadata.data, metadata.size, true)
                end
                liborkh.free_metadata_buffer(metadata.data)
            end
        end
    end
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


return kernel_helper