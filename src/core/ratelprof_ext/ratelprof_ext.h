#ifndef RATELPROF_EXT_H
#define RATELPROF_EXT_H

#include <stdint.h>
#include "ratelprof.h"
#include "ratelprof_buffer_manager.h"

#define RATELPROF_DOMAIN_GPU 0x100

#define RATELPROF_STATUS_KEY_NOT_FOUND 0x80
#define RATELPROF_STATUS_QUEUE_EMPTY 0x81
#define RATELPROF_STATUS_BUFFER_IS_NULL 0x82
#define RATELPROF_STATUS_TABLE_IS_NULL 0x83
#define RATELPROF_STATUS_QUEUE_IS_NULL 0x84
#define RATELPROF_STATUS_HASH_TABLE_COLLISION 0x85
#define RATELPROF_STATUS_INVALID_FORMAT_SIZE 0x86
#define RATELPROF_STATUS_FAILED_OPEN_FILE 0x87
#define RATELPROF_STATUS_NO_CALLBACK_SET 0x88

#define get_error_string get_combined_error_string

typedef enum {
    RATELPROF_DISPATCH_OPERATION,
    RATELPROF_COPY_OPERATION,
    RATELPROF_KERNEL_OPERATION,
    RATELPROF_BARRIEROR_OPERATION,
    RATELPROF_BARRIERAND_OPERATION,
    RATELPROF_CPU_OPERATION
} ratelprof_op_t;

typedef union gpu_args_s {
    struct {
        ratelprof_timespec_t dispatch_time;
        hsa_agent_t agent;
        uint64_t queue_id;
        uint16_t workgroup_size_x;
        uint16_t workgroup_size_y;
        uint16_t workgroup_size_z;
        uint32_t grid_size_x;
        uint32_t grid_size_y;
        uint32_t grid_size_z;
        uint32_t private_segment_size;
        uint32_t group_segment_size;
        uint64_t kernel_object;
        void* kernarg_address;
    } kernel_launch;
    struct {
        hsa_agent_t src_agent;
        hsa_agent_t dst_agent;
        uint32_t src_type;
        uint32_t dst_type;
        size_t size;
    } mem_copy;
} gpu_args_t;

typedef struct ratelprof_gpu_activity_s {
    ratelprof_domain_t domain;
    ratelprof_op_t op;
    uint64_t corr_id;
    uint64_t start_time;
    uint64_t stop_time;
    hsa_signal_t completion_signal;
    gpu_args_t args;
    
} ratelprof_gpu_activity_t;

static inline const char* get_error_string_ext(ratelprof_status_t err) {
    switch ((int)err)
    {
        case RATELPROF_STATUS_KEY_NOT_FOUND:         return "Key in hashtable doesn't exist";
        case RATELPROF_STATUS_QUEUE_EMPTY:           return "The queue is empty";
        case RATELPROF_STATUS_BUFFER_IS_NULL:        return "The buffer is NULL";
        case RATELPROF_STATUS_TABLE_IS_NULL:         return "The hashtable is not initialized (NULL)";
        case RATELPROF_STATUS_QUEUE_IS_NULL:         return "The queue is not initialized (NULL)";
        case RATELPROF_STATUS_HASH_TABLE_COLLISION:  return "Insert collision in hash table";
        case RATELPROF_STATUS_INVALID_FORMAT_SIZE:   return "Invalid format size specified";
        case RATELPROF_STATUS_FAILED_OPEN_FILE:      return "Failed to open the file";
        case RATELPROF_STATUS_NO_CALLBACK_SET:       return "No callback has been set";
        default: break;
    }
    return NULL;
}

static inline const char* get_combined_error_string(ratelprof_status_t err) {
    const char* extended_msg = get_error_string_ext(err);
    if (extended_msg) {
        return extended_msg;
    }
    const char* original_msg = get_error_string(err);
    return original_msg ? original_msg : "Unknown error";
}

#include "ratelprof_activity_pool.h"

static inline const char* get_kernel_name(uint64_t kernel_object)
{
    char* kernel_name = NULL;
    CHECK_RATELPROF_CALL(
        ratelprof_activity_pool_get_kernelName_from_kernelObj(kernel_object, (void*)&kernel_name));
    return kernel_name;
}

#endif // RATELPROF_EXT_H
