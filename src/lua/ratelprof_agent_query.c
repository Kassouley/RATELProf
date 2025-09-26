#include <lua.h>
#include <lauxlib.h>
#include "lua_compatibility.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <hsa/hsa.h>
#include <hsa/hsa_ext_amd.h>

#include "ratelprof_agent_query.h"

static hsa_status_t query_agent_data(hsa_agent_t agent, void* data) 
{
    ratelprof_agent_data_t *agents_list = (ratelprof_agent_data_t*)data;

    static const char* device_types[] = { "CPU", "GPU", "DSP", "AIE" };
    static const char* feature_types[] = { "KERNEL DISPATCH", "AGENT DISPATCH" };
    static const char* machine_model_types[] = { "SMALL", "LARGE" };
    static const char* queue_types[] = { "MULTI", "SINGLE", "COOPERATIVE" };
    uint32_t feature;
    uint32_t machine_model;

    ratelprof_agent_data_t agent_data = {0};
    // Query agent attributes
    agent_data.agent = agent;
    QUERY(NAME, &agent_data.name);
    QUERY_AMD(PRODUCT_NAME, &agent_data.product_name);
    QUERY(DEVICE, &agent_data.device_type);

    STRCOPY((agent_data.device_type >= 0 && agent_data.device_type < 4), agent_data.device_type_name, device_types[agent_data.device_type]);
    QUERY(NODE, &agent_data.node);
    QUERY_AMD(DRIVER_NODE_ID, &agent_data.driver_node_id);
    QUERY(FEATURE, &feature);
    STRCOPY((feature > 0 && feature < 3), agent_data.feature, feature_types[feature-1]);
    QUERY(MACHINE_MODEL, &machine_model);
    STRCOPY((machine_model >= 0 && machine_model < 2), agent_data.machine_model, machine_model_types[machine_model]);
    QUERY(CACHE_SIZE, &agent_data.cache_size);
    QUERY_AMD(COMPUTE_UNIT_COUNT, &agent_data.cu_count);
    QUERY_AMD(CACHELINE_SIZE, &agent_data.cacheline_size);
    QUERY_AMD(MAX_CLOCK_FREQUENCY, &agent_data.max_clock_freq);
    QUERY_AMD(MEMORY_MAX_FREQUENCY, &agent_data.max_mem_clock);
    QUERY_AMD(UUID, &agent_data.uuid);
    QUERY(VERSION_MAJOR, &agent_data.version_major);
    QUERY(VERSION_MINOR, &agent_data.version_minor);

    if (agent_data.device_type == 1) {
        hsa_isa_t isa;
        uint32_t queue_type;

        // Query GPU attributes
        QUERY(ISA , &isa);
        uint32_t isa_name_lenght = 0;
        char* isa_name = NULL;
        hsa_isa_get_info_alt(isa, HSA_ISA_INFO_NAME_LENGTH, &isa_name_lenght);
        if (isa_name_lenght != 0) {
            isa_name = (char*) calloc(isa_name_lenght, sizeof(char));
            hsa_isa_get_info_alt(isa, HSA_ISA_INFO_NAME, isa_name);
        } 
        STRCOPY((isa_name_lenght != 0), agent_data.isa_name, isa_name);
        if (isa_name) free(isa_name);

        QUERY(WAVEFRONT_SIZE, &agent_data.wavefront_size);
        QUERY(WORKGROUP_MAX_DIM, &agent_data.workgroup_max_dim);
        QUERY(WORKGROUP_MAX_SIZE, &agent_data.workgroup_max_size);
        QUERY(GRID_MAX_DIM, &agent_data.grid_max_dim);
        QUERY(GRID_MAX_SIZE, &agent_data.grid_max_size);
        QUERY(FBARRIER_MAX_SIZE, &agent_data.fbarrier_max_size);
        QUERY(QUEUES_MAX, &agent_data.queues_max);
        QUERY(QUEUE_MIN_SIZE, &agent_data.queue_min_size);
        QUERY(QUEUE_MAX_SIZE, &agent_data.queue_max_size);
        QUERY(QUEUE_TYPE, &queue_type);
        STRCOPY((queue_type >= 0 && queue_type < 3), agent_data.queue_type, queue_types[queue_type]);
        QUERY_AMD(CHIP_ID, &agent_data.chip_id);
        QUERY_AMD(MAX_WAVES_PER_CU, &agent_data.max_wave_per_cu);
        QUERY_AMD(NUM_SIMDS_PER_CU, &agent_data.num_simd_per_cu);
        QUERY_AMD(NUM_SHADER_ENGINES, &agent_data.num_se);
        QUERY_AMD(NUM_SHADER_ARRAYS_PER_SE, &agent_data.num_sa_per_se);
        QUERY_AMD(NUM_SDMA_ENG, &agent_data.num_sdma_eng);
        QUERY_AMD(NUM_SDMA_XGMI_ENG, &agent_data.num_sdma_xgmi_eng);
        QUERY_AMD(NUM_XCC, &agent_data.num_xcc);
        QUERY_AMD(DRIVER_UID, &agent_data.driver_uid);
        QUERY_AMD(NEAREST_CPU, &agent_data.nearest_cpu);
        hsa_agent_get_info(agent_data.nearest_cpu, HSA_AGENT_INFO_NODE, &agent_data.nearest_cpu_node_id);
    }

    agents_list[agent_data.node] = agent_data;
    return HSA_STATUS_SUCCESS;
}

static hsa_status_t count_agents(hsa_agent_t agent, void* data) {
    (void)agent;
    size_t* counter = (size_t*)data;
    (*counter)++;
    return HSA_STATUS_SUCCESS;
}

int ratelprof_query_agent_data_with_init(ratelprof_agent_data_t** agents_list, size_t* agents_count) 
{
    int status = 0;
    
    // Initialize HSA runtime
    if (hsa_init() != HSA_STATUS_SUCCESS) return -1;

    status = ratelprof_query_agent_data(agents_list, agents_count);
    
    // Shut down HSA runtime
    if (hsa_shut_down() != HSA_STATUS_SUCCESS) return -1;

    return status;
}

int ratelprof_query_agent_data(ratelprof_agent_data_t** agents_list, size_t* agents_count) 
{
    hsa_status_t status = HSA_STATUS_SUCCESS;
    *agents_count = 0;

    // Iterate through all agents
    status = hsa_iterate_agents(count_agents, agents_count);
    if (status != HSA_STATUS_SUCCESS) {
        return -1;
    }

    *agents_list = (ratelprof_agent_data_t*) calloc(*agents_count, sizeof(ratelprof_agent_data_t));
    if (!*agents_list) {
        return -1;
    }

    status = hsa_iterate_agents(query_agent_data, *agents_list);
    if (status != HSA_STATUS_SUCCESS) {
        free(*agents_list);
        return -1;
    }

    return 0;
}


#define push_string(NAME)       lua_pushstring(L, data->NAME);  lua_setfield(L, -2, #NAME);
#define push_int(NAME)          lua_pushinteger(L, data->NAME); lua_setfield(L, -2, #NAME);
#define push_int_table(NAME, size)          \
    lua_createtable(L, size, 0);            \
    for (int i = 0; i < size; ++i) {        \
        lua_pushinteger(L, data->NAME[i]);  \
        lua_rawseti(L, -2, i + 1);          \
    }                                       \
    lua_setfield(L, -2, #NAME);             \


// === Converts a C agent struct into a Lua table ===
static void push_agent_data(lua_State* L, const ratelprof_agent_data_t* data) {
    lua_newtable(L);

    // Basic info
    push_string(name);
    push_string(product_name);
    push_int(device_type);
    push_string(device_type_name);
    push_int(node);
    push_int(driver_node_id);
    push_string(feature);
    push_string(machine_model);

    // Cache sizes (array of 4)
    push_int_table(cache_size, 4);

    // Remaining agent data
    push_int(cu_count);
    push_int(cacheline_size);
    push_int(max_clock_freq);
    push_int(max_mem_clock);
    push_string(uuid);
    push_int(version_major);
    push_int(version_minor);
    push_string(isa_name);
    push_int(wavefront_size);

    // Workgroup max dim (array of 3)
    push_int_table(workgroup_max_dim, 3);
    push_int(workgroup_max_size);

    // Grid max dim (array of 3)
    push_int_table(grid_max_dim, 3);
    push_int(grid_max_size);

    push_int(fbarrier_max_size);
    push_int(queues_max);
    push_int(queue_min_size);
    push_int(queue_max_size);
    push_string(queue_type);
    push_int(max_wave_per_cu);
    push_int(num_simd_per_cu);
    push_int(num_se);
    push_int(num_sa_per_se);
    push_int(num_sdma_eng);
    push_int(num_sdma_xgmi_eng);
    push_int(num_xcc);
    push_int(chip_id);
    push_int(driver_uid);

    push_int(nearest_cpu_node_id);
}

// === Lua entry point: get_agents() ===
int lua_get_agents(lua_State* L) {
    ratelprof_agent_data_t* agents_list;
    size_t agents_count;

    ratelprof_query_agent_data_with_init(&agents_list, &agents_count);

    lua_newtable(L);
    for (size_t i = 0; i < agents_count; i++) {
        push_agent_data(L, &agents_list[i]);
        lua_rawseti(L, -2, i);
    }
    lua_pushinteger(L, (lua_Integer)agents_count);

    free(agents_list);
    return 2;
}

// === Lua module loader ===
int luaopen_ratelprof_agent_query(lua_State* L) {
    luaL_Reg funcs[] = {
        {"get_agents", lua_get_agents},
        {NULL, NULL}
    };
    luaL_register(L, "ratelprof_query_agent", funcs);
    return 1;
}