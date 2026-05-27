#include <ratelprof.h>
#include "ratelprof_ext/ratelprof_object_tracking.h"
#include "ratelprof_ext/ratelprof_ext_status.h"

static ratelprof_object_tracking_pool_t* object_tracking_pool = NULL;

bool ratelprof_object_tracking_is_kernel_packet_tracked() {
    return object_tracking_pool 
        && (object_tracking_pool->is_kernel_packet_tracked 
        || object_tracking_pool->is_memory_blit_kernel_packet_tracked);
}

bool ratelprof_object_tracking_is_barrier_packet_tracked() {
    return object_tracking_pool && object_tracking_pool->is_barrier_packet_tracked;
}

bool ratelprof_object_tracking_is_memory_blit_kernel_packet_tracked() {
    return object_tracking_pool && object_tracking_pool->is_memory_blit_kernel_packet_tracked;
}

ratelprof_status_t 
ratelprof_object_tracking_pool_init()
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    uint32_t max_queues_av = envtoi("RATELPROF_MAX_QUEUE_AVAILABLE", 256);
    uint32_t max_agents_av = envtoi("RATELPROF_MAX_AGENT_AVAILABLE", 256);

    ratelprof_object_tracking_pool_t* otp = (ratelprof_object_tracking_pool_t*)malloc(sizeof(ratelprof_object_tracking_pool_t));
    if (!otp) return RATELPROF_STATUS_MALLOC_FAILED;

    otp->is_barrier_packet_tracked = is_set_domain("RATELPROF_DOMAIN_BARRIERAND") && is_set_domain("RATELPROF_DOMAIN_BARRIEROR");
    otp->is_kernel_packet_tracked  = is_set_domain("RATELPROF_DOMAIN_KERNEL");
    otp->is_memory_blit_kernel_packet_tracked = is_set_domain("RATELPROF_DOMAIN_MEMORY");

    RATELPROF_TRY(
        ratelprof_hashtable_init(&otp->agents_list, max_agents_av),
        LOG(LOG_LEVEL_ERROR, "Failed to init Agent hash table. %s (code %d)\n", get_error_string_ext(status), status)
    );

    if (otp->is_kernel_packet_tracked 
        || otp->is_barrier_packet_tracked
        || otp->is_memory_blit_kernel_packet_tracked) {
        RATELPROF_TRY(
            ratelprof_hashtable_init(&otp->queue_doorbell_map, max_queues_av),
            LOG(LOG_LEVEL_ERROR, "Failed to init Queue/Doorbell hash table. %s (code %d)\n", get_error_string_ext(status), status)
        );
        RATELPROF_TRY(
            ratelprof_hashtable_init(&otp->agent_queueId_map, max_queues_av),
            LOG(LOG_LEVEL_ERROR, "Failed to init Agent/Queue hash table. %s (code %d)\n", get_error_string_ext(status), status)
        );
    }
    
    uint32_t n = envtoi("RATELPROF_NB_KERNEL_AVAILABLE", 256);
    if (n < 32) n = 31;
    
    if (otp->is_kernel_packet_tracked || otp->is_memory_blit_kernel_packet_tracked) {
        
        RATELPROF_TRY(
            ratelprof_hashtable_init(&otp->kernelName_kernelObj_map, n),
            LOG(LOG_LEVEL_ERROR, "Failed to init KernelName/Object hash table. %s (code %d)\n", get_error_string_ext(status), status)
        );

        RATELPROF_TRY(
            ratelprof_hashtable_init(&otp->memop_kernelObj_map, n),
            LOG(LOG_LEVEL_ERROR, "Failed to init Memory Operation/Object hash table. %s (code %d)\n", get_error_string_ext(status), status)
        );
    }

    object_tracking_pool = otp;
    return status;
}

void free_value(void* value) {
    free(value);
}

ratelprof_status_t 
ratelprof_object_tracking_pool_fini()
{
    ratelprof_object_tracking_pool_t* otp = object_tracking_pool;
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    if (!otp) return status;

    if (otp->is_kernel_packet_tracked 
        || otp->is_barrier_packet_tracked
        || otp->is_memory_blit_kernel_packet_tracked) {
        RATELPROF_TRY(
            ratelprof_hashtable_free(&object_tracking_pool->queue_doorbell_map, free_value),
            LOG(LOG_LEVEL_ERROR, "Failed to free Queue/Doorbell hash table. %s (code %d)\n", get_error_string_ext(status), status)
        );
        RATELPROF_TRY(
            ratelprof_hashtable_free(&object_tracking_pool->agent_queueId_map, free_value),
            LOG(LOG_LEVEL_ERROR, "Failed to free Agent/Queue hash table. %s (code %d)\n", get_error_string_ext(status), status)
        );
    }

    if (otp->is_kernel_packet_tracked || otp->is_memory_blit_kernel_packet_tracked) {
        RATELPROF_TRY(
            ratelprof_hashtable_free(&object_tracking_pool->kernelName_kernelObj_map, free_value),
            LOG(LOG_LEVEL_ERROR, "Failed to free KernelName/Object hash table. %s (code %d)\n", get_error_string_ext(status), status)
        );

        RATELPROF_TRY(
            ratelprof_hashtable_free(&otp->memop_kernelObj_map, NULL),
            LOG(LOG_LEVEL_ERROR, "Failed to free Memory Operation/Object hash table. %s (code %d)\n", get_error_string_ext(status), status)
        );
    }

    RATELPROF_TRY(
        ratelprof_hashtable_free(&otp->agents_list, free_value),
        LOG(LOG_LEVEL_ERROR, "Failed to free agent hash table. %s (code %d)\n", get_error_string_ext(status), status)
    );

    free(otp);
    object_tracking_pool = NULL;

    return status;
}


ratelprof_object_tracking_pool_t*
ratelprof_object_tracking_pool_get_pool()
{
    return object_tracking_pool;
}

ratelprof_status_t 
ratelprof_object_tracking_pool_map_new_agent_to_queueId(
    uint64_t id, 
    hsa_agent_t agent
) {
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    hsa_agent_t* agent_ptr = (hsa_agent_t*) malloc(sizeof(hsa_agent_t));
    if (!agent_ptr) return RATELPROF_STATUS_MALLOC_FAILED;
    *agent_ptr = agent;
    RATELPROF_TRY(
        ratelprof_insert_hash(&object_tracking_pool->agent_queueId_map, id, agent_ptr),
        LOG(LOG_LEVEL_ERROR, "Failed to map a new agent. %s (code %d)\n", get_error_string_ext(status), status)
    );
    return status;
}

ratelprof_status_t 
ratelprof_object_tracking_pool_get_agent_from_queueId(
    uint64_t id, 
    hsa_agent_t* agent
) {
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    RATELPROF_TRY(
        ratelprof_find_hash(&object_tracking_pool->agent_queueId_map, id, (void*)agent),
        LOG(LOG_LEVEL_ERROR, "Failed to get an agent from hash table. %s (code %d)\n", get_error_string_ext(status), status)
    );
    return status;
}

ratelprof_status_t 
ratelprof_object_tracking_pool_map_new_queue_to_signal(
    uint64_t sig, 
    hsa_queue_t queue
) {
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    hsa_queue_t* queue_ptr = (hsa_queue_t*) malloc(sizeof(hsa_queue_t));
    if (!queue_ptr) return RATELPROF_STATUS_MALLOC_FAILED;
    *queue_ptr = queue;
    RATELPROF_TRY(
        ratelprof_insert_hash(&object_tracking_pool->queue_doorbell_map, sig, queue_ptr),
        LOG(LOG_LEVEL_ERROR, "Failed to map a new queue. %s (code %d)\n", get_error_string_ext(status), status)
    );
    return status; 
}

ratelprof_status_t 
ratelprof_object_tracking_pool_get_queue_from_signal(
    uint64_t sig, 
    hsa_queue_t** queue
) {
    return ratelprof_find_hash(&object_tracking_pool->queue_doorbell_map, sig, (void**)queue);
}

ratelprof_status_t 
ratelprof_object_tracking_pool_map_new_kernelName_to_kernelObj(
    uint64_t kernel_object, 
    const char* kernel_name
) {
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    char *kernel_name_copy = strdup(kernel_name);
    if (kernel_name_copy == NULL) return RATELPROF_STATUS_MALLOC_FAILED;
    RATELPROF_TRY(
        ratelprof_insert_hash(&object_tracking_pool->kernelName_kernelObj_map, kernel_object, kernel_name_copy),
        LOG(LOG_LEVEL_ERROR, "Failed to map a new kernel name. %s (code %d)\n", get_error_string_ext(status), status)
    );
    return status;
}

ratelprof_status_t 
ratelprof_object_tracking_pool_get_kernelName_from_kernelObj(
    uint64_t kernel_object, 
    const char** kernel_name
) {
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    RATELPROF_TRY(
        ratelprof_find_hash(&object_tracking_pool->kernelName_kernelObj_map, kernel_object, (void*)kernel_name),
        LOG(LOG_LEVEL_ERROR, "Failed to get a kernel name from hash table. %s (code %d)\n", get_error_string_ext(status), status)
    );
    return status;
}

ratelprof_status_t
ratelprof_object_tracking_pool_map_new_agent_to_handle(
    uint64_t handle, 
    ratelprof_agent_object_t* agent
) {
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    RATELPROF_TRY(
        ratelprof_insert_hash(&object_tracking_pool->agents_list, handle, agent),
        LOG(LOG_LEVEL_ERROR, "Failed to map a new agent. %s (code %d)\n", get_error_string_ext(status), status)
    );
    return status;
}

ratelprof_status_t
ratelprof_object_tracking_pool_get_agent_from_handle(
    uint64_t handle,
    ratelprof_agent_object_t** agent
) {
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    RATELPROF_TRY(
        ratelprof_find_hash(&object_tracking_pool->agents_list, handle, (void*)agent),
        LOG(LOG_LEVEL_ERROR, "Failed to get an agent from hash table. %s (code %d)\n", get_error_string_ext(status), status)
    );
    return status;
}

ratelprof_status_t
ratelprof_object_tracking_pool_map_new_MemOp_to_kernelObj(
    uint64_t kernel_object, 
    ratelprof_memory_op_t memop
) {
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    RATELPROF_TRY(
        ratelprof_insert_hash(&object_tracking_pool->memop_kernelObj_map, kernel_object, (void*)memop),
        LOG(LOG_LEVEL_ERROR, "Failed to map a new memory operation to kernel object. %s (code %d)\n", get_error_string_ext(status), status)
    );
    return status;
}

ratelprof_status_t
ratelprof_object_tracking_pool_get_MemOp_from_kernelObj(
    uint64_t kernel_object,
    ratelprof_memory_op_t* memop
) {
    *memop = RATELPROF_MEMORY_OP_UNKNOWN;
    ratelprof_status_ext_t status = ratelprof_find_hash(&object_tracking_pool->memop_kernelObj_map, kernel_object, (void*)memop);
    if ((ratelprof_status_t) status != RATELPROF_STATUS_SUCCESS && status != RATELPROF_STATUS_KEY_NOT_FOUND) {
        LOG(LOG_LEVEL_ERROR, "Failed to get a memory operation from hash table. %s (code %d)\n", get_error_string_ext(status), status);
    }
    return RATELPROF_STATUS_SUCCESS;
}