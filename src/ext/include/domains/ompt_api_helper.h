#ifndef RATELPROF_OMPT_H
#define RATELPROF_OMPT_H

#include <stdlib.h>
#include <omp-tools.h>

typedef enum {
    OMPT_API_ID_TARGET_REGION               = 0,
    OMPT_API_ID_target                      = ompt_target,
    OMPT_API_ID_target_enter_data           = ompt_target_enter_data,
    OMPT_API_ID_target_exit_data            = ompt_target_exit_data,   
    OMPT_API_ID_target_update               = ompt_target_update,
    OMPT_API_ID_target_nowait               = ompt_target_nowait,
    OMPT_API_ID_target_enter_data_nowait    = ompt_target_enter_data_nowait,
    OMPT_API_ID_target_exit_data_nowait     = ompt_target_exit_data_nowait,
    OMPT_API_ID_target_update_nowait        = ompt_target_update_nowait,

    OMPT_API_ID_TARGET_DATA_REGION                      = 0x10,
    OMPT_API_ID_target_data_alloc                       = OMPT_API_ID_TARGET_DATA_REGION + ompt_target_data_alloc,
    OMPT_API_ID_target_data_transfer_to_device          = OMPT_API_ID_TARGET_DATA_REGION + ompt_target_data_transfer_to_device,
    OMPT_API_ID_target_data_transfer_from_device        = OMPT_API_ID_TARGET_DATA_REGION + ompt_target_data_transfer_from_device,
    OMPT_API_ID_target_data_delete                      = OMPT_API_ID_TARGET_DATA_REGION + ompt_target_data_delete,
    OMPT_API_ID_target_data_associate                   = OMPT_API_ID_TARGET_DATA_REGION + ompt_target_data_associate,
    OMPT_API_ID_target_data_disassociate                = OMPT_API_ID_TARGET_DATA_REGION + ompt_target_data_disassociate,
    OMPT_API_ID_target_data_alloc_async                 = OMPT_API_ID_TARGET_DATA_REGION + ompt_target_data_alloc_async,
    OMPT_API_ID_target_data_transfer_to_device_async    = OMPT_API_ID_TARGET_DATA_REGION + ompt_target_data_transfer_to_device_async,
    OMPT_API_ID_target_data_transfer_from_device_async  = OMPT_API_ID_TARGET_DATA_REGION + ompt_target_data_transfer_from_device_async,
    OMPT_API_ID_target_data_delete_async                = OMPT_API_ID_TARGET_DATA_REGION + ompt_target_data_delete_async,

    OMPT_API_ID_target_map,

    OMPT_API_ID_target_submit,

    OMPT_API_ID_NB_FUNCTION = 20,
    OMPT_API_ID_UNKNOWN = 0xffff
} ompt_api_id_t;


// Target Map Emi
struct map_t {
    void *host_addr;
    void *device_addr;
    size_t bytes;
    unsigned int mapping_flags;
};

typedef struct {
    unsigned int nitems;
    struct map_t * map;
} args_target_map_emi_t;

#define GET_ARGS_VALUE_target_map_emi(activity) { \
	args_target_map_emi_t* args = (args_target_map_emi_t*) activity->args; \
    args->nitems = nitems; \
    args->map = (struct map_t*) malloc(sizeof(struct map_t) * nitems); \
    for (int i = 0; i < nitems; i++) { \
        args->map[i].host_addr = host_addr[i]; \
        args->map[i].device_addr = device_addr[i]; \
        args->map[i].bytes = bytes[i]; \
        args->map[i].mapping_flags = mapping_flags[i]; \
    } \
};

// Target Submit Emi
typedef struct {
    ompt_id_t *host_op_id;
    unsigned int requested_num_teams;
} args_target_submit_emi_t;

#define GET_ARGS_VALUE_target_submit_emi(activity) { \
	args_target_submit_emi_t* args = (args_target_submit_emi_t*) activity->args; \
    args->host_op_id = host_op_id; \
    args->requested_num_teams = requested_num_teams; \
};


// Target Data
typedef struct {
    ompt_id_t *host_op_id;
    void *src_addr;
    int src_device_num;
    void *dest_addr;
    int dest_device_num;
    size_t bytes;
} args_target_data_op_t;

#define GET_ARGS_VALUE_target_data_op(activity) { \
	args_target_data_op_t* args = (args_target_data_op_t*) activity->args; \
    args->host_op_id = host_op_id; \
    args->src_addr = src_addr; \
    args->src_device_num = src_device_num; \
    args->dest_addr = dest_addr; \
    args->dest_device_num = dest_device_num; \
    args->bytes = bytes; \
};


// Target Emi
typedef struct {
    int device_num;
} args_target_emi_t;

#define GET_ARGS_VALUE_target_emi(activity) { \
	args_target_emi_t* args = (args_target_emi_t*) activity->args; \
    args->device_num = device_num; \
};


static inline const char* get_map_flag_name(ompt_target_map_flag_t flag)
{
    switch(flag) {
        case ompt_target_map_flag_to:             return "to";
        case ompt_target_map_flag_from:           return "from";
        case ompt_target_map_flag_alloc:          return "alloc";
        case ompt_target_map_flag_release:        return "release";
        case ompt_target_map_flag_delete:         return "delete";
        case ompt_target_map_flag_implicit:       return "implicit";
        default : return NULL;
    }
    return NULL;
}

static inline const char* get_ompt_funame_by_id(ompt_api_id_t id) 
{
    switch(id) {
        case OMPT_API_ID_target:                                    return "Target Region";
        case OMPT_API_ID_target_enter_data:                         return "Target Enter Data Region";
        case OMPT_API_ID_target_exit_data:                          return "Target Exit Data Region";
        case OMPT_API_ID_target_update:                             return "Target Update Region";
        case OMPT_API_ID_target_nowait:                             return "Target Nowait Region";
        case OMPT_API_ID_target_enter_data_nowait:                  return "Target Enter Data Nowait Region";
        case OMPT_API_ID_target_exit_data_nowait:                   return "Target Exit Data Nowait Region";
        case OMPT_API_ID_target_update_nowait:                      return "Target Update Nowait Region";
        case OMPT_API_ID_target_data_alloc:                         return "Data Alloc";
        case OMPT_API_ID_target_data_transfer_to_device:            return "Data Transfer To Device";
        case OMPT_API_ID_target_data_transfer_from_device:          return "Data Transfer From Device";
        case OMPT_API_ID_target_data_delete:                        return "Data Delete";
        case OMPT_API_ID_target_data_associate:                     return "Data Associate";
        case OMPT_API_ID_target_data_disassociate:                  return "Data Disassociate";
        case OMPT_API_ID_target_data_alloc_async:                   return "Data Alloc Async";
        case OMPT_API_ID_target_data_transfer_to_device_async:      return "Data Transfer To Device Async";
        case OMPT_API_ID_target_data_transfer_from_device_async:    return "Data Transfer From Device Async";
        case OMPT_API_ID_target_data_delete_async:                  return "Data Delete Async";
        case OMPT_API_ID_target_map:                                return "Target Data Map Region";
        case OMPT_API_ID_target_submit:                             return "Target Kernel Submit Region";
        default : return NULL;
    }
    return NULL;
}




#endif // RATELPROF_OMPT_H