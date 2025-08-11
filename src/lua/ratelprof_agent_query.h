#include <stdint.h>
#include <stdlib.h>
#include <hsa/hsa.h>
#include <hsa/hsa_ext_amd.h>

#define QUERY(INFO, var)     hsa_agent_get_info(agent, HSA_AGENT_INFO_##INFO, var)
#define QUERY_AMD(INFO, var) hsa_agent_get_info(agent, (hsa_agent_info_t)HSA_AMD_AGENT_INFO_##INFO, var)

#define STRCOPY(cond, dst, src) \
    do { \
        size_t size = sizeof(dst); \
        if (cond) { \
            strncpy((dst), (src), (size) - 1); \
            (dst)[(size) - 1] = '\0'; \
        } else { \
            (dst)[0] = '-'; \
            (dst)[1] = '\0'; \
        } \
    } while (0)


#define MAX_STRING_LENGTH 64

typedef struct ratelprof_agent_data_s {
    hsa_agent_t agent;
    char name[MAX_STRING_LENGTH];
    char product_name[MAX_STRING_LENGTH];
    uint32_t device_type;
    char device_type_name[4];
    uint32_t node;
    uint32_t driver_node_id;
    char feature[16];
    char machine_model[6];
    uint32_t cache_size[4];
    uint32_t cu_count;
    uint32_t cacheline_size;
    uint32_t max_clock_freq;
    uint32_t max_mem_clock;
    char uuid[21];
    uint16_t version_major;
    uint16_t version_minor;

    char isa_name[MAX_STRING_LENGTH];
    uint32_t wavefront_size;
    uint16_t workgroup_max_dim[3];
    uint32_t workgroup_max_size;
    uint32_t grid_max_dim[3];
    uint32_t grid_max_size;
    uint32_t fbarrier_max_size;
    uint32_t queues_max;
    uint32_t queue_min_size;
    uint32_t queue_max_size;
    char queue_type[12];
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
    uint32_t nearest_cpu_node_id;
} ratelprof_agent_data_t;


int ratelprof_query_agent_data(ratelprof_agent_data_t** agents_list, size_t* agents_count);
int ratelprof_query_agent_data_with_init(ratelprof_agent_data_t** agents_list, size_t* agents_count);
