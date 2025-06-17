local ratelprof_agent_query = require("ratelprof_agent_query")

local agent_helper = {}

-- Pretty helper to format numbers with hex
local function int_hex(val)
    return string.format("%d(0x%X)", val, val)
end

local function cache_format(tbl)
    return string.format("\n"..
        "       L1                        %s KB\n" ..
        "       L2                        %s KB\n" ..
        "       L3                        %s KB",
        int_hex(tbl[1]), int_hex(tbl[2]), int_hex(tbl[3]))
end

local function xyz_format(tbl)
    return string.format("\n"..
        "       x                        %s\n" ..
        "       y                        %s\n" ..
        "       z                        %s", 
        int_hex(tbl[1]), int_hex(tbl[2]), int_hex(tbl[3]))
end

local useful_info = {
    {title = "Name",                                key = "name",                   fmt = "s"},
    {title = "Marketing Name",                      key = "product_name",           fmt = "s"},
    {title = "Node",                                key = "node",                   fmt = "d"},
    {title = "Device Type",                         key = "device_type_name",       fmt = "s"},
    {title = "Uuid",                                key = "uuid",                   fmt = "s"},
    {title = "Feature",                             key = "feature",                fmt = "s"},
    {title = "Nearest CPU",                         key = "nearest_cpu_node_id",    fmt = "d"},
    {title = "Compute Unit",                        key = "cu_count",               fmt = "d"},
    {title = "SIMDs per CU",                        key = "num_simd_per_cu",        fmt = "d"},
    {title = "Shader Engines",                      key = "num_se",                 fmt = "d"},
    {title = "Shader Arrs. per Eng.",               key = "num_sa_per_se",          fmt = "d"},
    {title = "Wavefront Size",                      key = "wavefront_size",         fmt = "hex", fn = int_hex},
    {title = "Max Waves Per CU",                    key = "max_wave_per_cu",        fmt = "hex", fn = int_hex},
    {title = "Max Queue Number",                    key = "queues_max",             fmt = "hex", fn = int_hex},
    {title = "Queue Min Size",                      key = "queue_min_size",         fmt = "hex", fn = int_hex},
    {title = "Queue Max Size",                      key = "queue_max_size",         fmt = "hex", fn = int_hex},
    {title = "Queue Type",                          key = "queue_type",             fmt = "s"},
    {title = "Cache Info",                          key = "cache_size",             fmt = "tbl", fn = cache_format},
    {title = "Chip ID",                             key = "chip_id",                fmt = "hex", fn = int_hex},
    {title = "Cacheline Size",                      key = "cacheline_size",         fmt = "hex", fn = int_hex},
    {title = "Max Clock Freq. (MHz)",               key = "max_clock_freq",         fmt = "d"},
    {title = "Driver UID",                          key = "driver_uid",             fmt = "d"},
    {title = "Internal Node ID",                    key = "driver_node_id",         fmt = "d"},
    {title = "Max Work-item Per CU",                key = "workgroup_max_size",     fmt = "hex", fn = int_hex},
    {title = "Workgroup Max Size per Dimension",    key = "workgroup_max_dim",      fmt = "tbl", fn = xyz_format},
    {title = "Grid Max Size",                       key = "grid_max_size",          fmt = "hex", fn = int_hex},
    {title = "Grid Max Size per Dimension",         key = "grid_max_dim",           fmt = "tbl", fn = xyz_format},
    {title = "Max fbarriers/Workgrp",               key = "fbarrier_max_size",      fmt = "d"},
}

agent_helper.get_agents = ratelprof_agent_query.get_agents

function agent_helper.print_gpu_data()
    local agents, _ = agent_helper.get_agents()

    -- Print each agent's data
    for i, agent in pairs(agents) do
        if agent.device_type_name == "GPU" then
            Message:print(string.format("=== Agent #%d ===", i))
            for _, info in ipairs(useful_info) do
                local data = agent[info.key]
                if info.fn then
                    data = info.fn(data)
                end
                local fmt = info.fmt
                if fmt == "tbl" then fmt = "s" end
                Message:print(string.format("  %-25s %"..fmt, info.title..":", data))
            end
        end
    end
end


function agent_helper.set_gpu_props_to_msgpack(report_file)
    local agents, _ = agent_helper.get_agents()
    local size = 0

    for _, agent in pairs(agents) do
        if agent.device_type_name == "GPU" then
            size = size + 1
        end
    end

    local buf = ratelprof.msgpack.encoder.new(1024, ratelprof.msgpack.encoder.OVERFLOW_APPEND_TO_FILE, report_file)
    buf:encode_map(size)
    
    for node_id, agent in pairs(agents) do
        if agent.device_type_name == "GPU" then
            buf:encode_uint(node_id)
            buf:encode_array(#useful_info)

            for _, info in ipairs(useful_info) do
                local data = agent[info.key]
                local fmt = info.fmt
                if fmt == "tbl" then
                    buf:encode_array(#data)
                    for _, e in ipairs(data) do
                        buf:encode_uint(e)
                    end
                elseif fmt == "s" then
                    buf:encode_string(data)
                elseif fmt == "d" or fmt == "hex" then
                    buf:encode_uint(data)
                else
                    error("Unknown format in GPU properties encoding")
                end
            end
        end
    end
    buf:write()
    buf:free()
end


return agent_helper
