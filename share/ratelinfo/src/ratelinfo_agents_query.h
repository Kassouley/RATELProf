
#ifndef RATELINFO__AGENTS_QUERY_H 
#define RATELINFO__AGENTS_QUERY_H 

#include <stdint.h>
#include <hsa/hsa.h>
#include <hsa/hsa_ext_amd.h>

#define MAX_STRING_LENGTH 64

#define QUERY(INFO, var) hsa_agent_get_info(agent, HSA_AGENT_INFO_##INFO, var)
#define QUERY_AMD(INFO, var) hsa_agent_get_info(agent, (hsa_agent_info_t)HSA_AMD_AGENT_INFO_##INFO, var)

typedef enum {
    RATELINFO_STATUS_SUCCESS,
    RATELPROF_STATUS_HSA_INIT_FAILED,
    RATELINFO_STATUS_MALLOC_FAILED,
    RATELPROF_STATUS_HSA_ITERATE_AGENTS_FAILED,
} ratelinfo_status_t;

typedef struct ratelprof_agent_data_s {
    char name[MAX_STRING_LENGTH];
    char product_name[MAX_STRING_LENGTH];
    uint32_t device_type;
    const char* device_type_name;
    uint32_t node;
    uint32_t driver_node_id;
    const char* feature;
    const char* machine_model;
    uint32_t cache_size[4];
    uint32_t cu_count;
    uint32_t cacheline_size;
    uint32_t max_clock_freq;
    uint32_t max_mem_clock;
    char uuid[21];
    uint16_t version_major;
    uint16_t version_minor;

    char* isa_name;
    uint32_t wavefront_size;
    uint16_t workgroup_max_dim[3];
    uint32_t workgroup_max_size;
    uint32_t grid_max_dim[3];
    uint32_t grid_max_size;
    uint32_t fbarrier_max_size;
    uint32_t queues_max;
    uint32_t queue_min_size;
    uint32_t queue_max_size;
    const char* queue_type;
    uint32_t max_wave_per_cu;
    uint32_t num_simd_per_cu;
    uint32_t num_se;
    uint32_t num_sa_per_se;
    uint32_t num_sdma_eng;
    uint32_t num_sdma_xgmi_eng;
    uint32_t num_xcc;
    uint32_t chip_id;
    uint32_t driver_uid;
    hsa_agent_t nearest_cpu;
} ratelinfo_agent_data_t;

hsa_status_t query_agent_data(hsa_agent_t agent, void* data);
ratelinfo_status_t ratelinfo_get_max_queue(uint32_t* max_queues_size);
ratelinfo_status_t ratelinfo_query_agent_data(ratelinfo_agent_data_t** agents_list, size_t* agents_count);


#endif // RATELINFO__AGENTS_QUERY_H