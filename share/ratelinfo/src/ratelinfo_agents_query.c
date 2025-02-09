#include <stdint.h>
#include <stdlib.h>
#include <hsa/hsa.h>
#include <hsa/hsa_ext_amd.h>
#include "ratelinfo_agents_query.h"

hsa_status_t query_agent_data(hsa_agent_t agent, void* data) 
{
    ratelinfo_agent_data_t *agents_list = (ratelinfo_agent_data_t*)data;

    static const char* device_types[] = { "CPU", "GPU", "DSP", "AIE" };
    static const char* feature_types[] = { "KERNEL DISPATCH", "AGENT DISPATCH" };
    static const char* machine_model_types[] = { "SMALL", "LARGE" };
    static const char* queue_types[] = { "MULTI", "SINGLE", "COOPERATIVE" };
    uint32_t feature;
    uint32_t machine_model;

    ratelinfo_agent_data_t agent_data = {};
    // Query agent attributes
    QUERY(NAME, &agent_data.name);
    QUERY_AMD(PRODUCT_NAME, &agent_data.product_name);
    QUERY(DEVICE, &agent_data.device_type);
    agent_data.device_type_name = (agent_data.device_type >= 0 && agent_data.device_type < 4) ? device_types[agent_data.device_type] : "-";
    QUERY(NODE, &agent_data.node);
    QUERY_AMD(DRIVER_NODE_ID, &agent_data.driver_node_id);
    QUERY(FEATURE, &feature);
    agent_data.feature = (feature > 0 && feature < 3) ? feature_types[feature-1] : "-";
    QUERY(MACHINE_MODEL, &machine_model);
    agent_data.machine_model = (machine_model >= 0 && machine_model < 2) ? machine_model_types[machine_model] : "-";
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
        hsa_isa_get_info_alt(isa, HSA_ISA_INFO_NAME_LENGTH, &isa_name_lenght);
        if (isa_name_lenght != 0) {
            agent_data.isa_name = (char*) calloc(isa_name_lenght, sizeof(char));
            hsa_isa_get_info_alt(isa, HSA_ISA_INFO_NAME, agent_data.isa_name);
        } else {
            agent_data.isa_name = (char*) calloc(2, sizeof(char));
            agent_data.isa_name[0] = '-';
        }
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
        agent_data.queue_type = (queue_type >= 0 && queue_type < 3) ? queue_types[queue_type] : "-";
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
    }

    agents_list[agent_data.node] = agent_data;
    return HSA_STATUS_SUCCESS;
}


hsa_status_t count_agents(hsa_agent_t agent, void* data) {
    (void)agent;
    size_t* counter = (size_t*)data;
    (*counter)++;
    return HSA_STATUS_SUCCESS;
}


hsa_status_t get_agent_max_queues(hsa_agent_t agent, void* data) {
    hsa_status_t status = HSA_STATUS_SUCCESS;
    uint32_t* max_queues_size = (uint32_t*)data;
    uint32_t max_queues = 0;

    status =  QUERY(QUEUES_MAX, &max_queues);
    if (status != HSA_STATUS_SUCCESS) return status;

    *max_queues_size += max_queues;

    return HSA_STATUS_SUCCESS;
}

ratelinfo_status_t ratelinfo_query_agent_data(ratelinfo_agent_data_t** agents_list, size_t* agents_count) 
{
    *agents_count = 0;
    // Initialize HSA runtime
    hsa_status_t status = hsa_init();
    if (status != HSA_STATUS_SUCCESS) return RATELPROF_STATUS_HSA_INIT_FAILED;

    // Iterate through all agents
    status = hsa_iterate_agents(count_agents, agents_count);
    if (status != HSA_STATUS_SUCCESS) return RATELPROF_STATUS_HSA_ITERATE_AGENTS_FAILED;

    *agents_list = (ratelinfo_agent_data_t*) calloc(*agents_count, sizeof(ratelinfo_agent_data_t));
    if(!*agents_list) return RATELINFO_STATUS_MALLOC_FAILED;

    status = hsa_iterate_agents(query_agent_data, *agents_list);
    if (status != HSA_STATUS_SUCCESS) return RATELPROF_STATUS_HSA_ITERATE_AGENTS_FAILED;

    // Shut down HSA runtime
    hsa_shut_down();

    return RATELINFO_STATUS_SUCCESS;
}


ratelinfo_status_t ratelinfo_get_max_queue(uint32_t* max_queues_size)
{
    *max_queues_size = 0;
    // Initialize HSA runtime
    hsa_status_t status = hsa_init();
    if (status != HSA_STATUS_SUCCESS) return RATELPROF_STATUS_HSA_INIT_FAILED;

    status = hsa_iterate_agents(get_agent_max_queues, max_queues_size);

    // Shut down HSA runtime
    hsa_shut_down();

    return RATELINFO_STATUS_SUCCESS;
}
