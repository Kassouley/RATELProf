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


struct map_t {
    void *host_addr;
    void *device_addr;
    size_t bytes;
    unsigned int mapping_flags;
};

struct args_target_map_emi_t {
    unsigned int nitems;
    struct map_t * map;
};

#define GET_ARGS_VALUE_target_map_emi(activity) { \
    activity->args.target_map_emi.nitems = nitems; \
    activity->args.target_map_emi.map = (struct map_t*) malloc(sizeof(struct map_t) * nitems); \
    for (int i = 0; i < nitems; i++) { \
        activity->args.target_map_emi.map[i].host_addr = host_addr[i]; \
        activity->args.target_map_emi.map[i].device_addr = device_addr[i]; \
        activity->args.target_map_emi.map[i].bytes = bytes[i]; \
        activity->args.target_map_emi.map[i].mapping_flags = mapping_flags[i]; \
    } \
};

struct args_target_submit_emi_t {
    ompt_id_t *host_op_id;
    unsigned int requested_num_teams;
};

#define GET_ARGS_VALUE_target_submit_emi(activity) { \
    activity->args.target_submit_emi.host_op_id = host_op_id; \
    activity->args.target_submit_emi.requested_num_teams = requested_num_teams; \
};

struct args_target_data_op_t {
    ompt_id_t *host_op_id;
    void *src_addr;
    int src_device_num;
    void *dest_addr;
    int dest_device_num;
    size_t bytes;
};

#define GET_ARGS_VALUE_target_data_op(activity) { \
    activity->args.target_data_op.host_op_id = host_op_id; \
    activity->args.target_data_op.src_addr = src_addr; \
    activity->args.target_data_op.src_device_num = src_device_num; \
    activity->args.target_data_op.dest_addr = dest_addr; \
    activity->args.target_data_op.dest_device_num = dest_device_num; \
    activity->args.target_data_op.bytes = bytes; \
};

struct args_target_emi_t {
    int device_num;
};

#define GET_ARGS_VALUE_target_emi(activity) { \
    activity->args.target_emi.device_num = device_num; \
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