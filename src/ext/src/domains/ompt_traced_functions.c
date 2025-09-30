#include <stdio.h>
#include <omp-tools.h>

#include <ratelprof.h>
#include "ratelprof_ext.h"

#include "domains/ompt_api_helper.h"

#define ratelprof_ompt_set_callback(name) \
    LOG(LOG_LEVEL_DEBUG, "[OMPT] ompt_set_callback on "#name" return %d\n", \
        ompt_set_callback(name, (ompt_callback_t)&on_##name));
    

// --------------------- Target Execution Callbacks ---------------------


void on_ompt_callback_target_emi(
    ompt_target_t kind,
    ompt_scope_endpoint_t endpoint,
    int device_num,
    ompt_data_t *task_data,
    ompt_data_t *target_task_data,
    ompt_data_t *target_data,
    const void *codeptr_ra)
{
    if (endpoint == ompt_scope_begin) {
        ratelprof_api_activity_t *activity =
            (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t) + sizeof(args_target_emi_t));
        activity->args = (void*)(activity + 1);

        activity->return_address = (void *)codeptr_ra;
        GET_ARGS_VALUE_target_emi(activity);
        target_task_data->ptr = (void*)activity;

        ratelprof_on_enter_callbacks[RATELPROF_DOMAIN_OMP_REGION](RATELPROF_DOMAIN_OMP_REGION, OMPT_API_ID_TARGET_REGION + kind, activity);
    } else if (endpoint == ompt_scope_end) {
        ratelprof_api_activity_t *activity = (ratelprof_api_activity_t *)(target_task_data->ptr);
        ratelprof_on_exit_callbacks[RATELPROF_DOMAIN_OMP_REGION](RATELPROF_DOMAIN_OMP_REGION, OMPT_API_ID_TARGET_REGION + kind, activity);

        target_task_data->ptr = 0;  // Clear the pointer
    }
}

// --------------------- Data Operation Callbacks ---------------------

void on_ompt_callback_target_data_op_emi(
    ompt_scope_endpoint_t endpoint,
    ompt_data_t *target_task_data,
    ompt_data_t *target_data,
    ompt_id_t *host_op_id,
    ompt_target_data_op_t optype,
    void *src_addr,
    int src_device_num,
    void *dest_addr,
    int dest_device_num,
    size_t bytes,
    const void *codeptr_ra)
{
    if (endpoint == ompt_scope_begin) {
        ratelprof_api_activity_t *activity =
            (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t) + sizeof(args_target_data_op_t));
        activity->args = (void*)(activity + 1);

        activity->return_address = (void *)codeptr_ra;
        GET_ARGS_VALUE_target_data_op(activity);
        target_data->ptr = (void*)activity;

        ratelprof_on_enter_callbacks[RATELPROF_DOMAIN_OMP_REGION](RATELPROF_DOMAIN_OMP_REGION, OMPT_API_ID_TARGET_DATA_REGION + optype, activity);
    } else if (endpoint == ompt_scope_end) {
        ratelprof_api_activity_t *activity = (ratelprof_api_activity_t *)(target_data->ptr);

        ratelprof_on_exit_callbacks[RATELPROF_DOMAIN_OMP_REGION](RATELPROF_DOMAIN_OMP_REGION, OMPT_API_ID_TARGET_DATA_REGION + optype, activity);
        target_data->ptr = 0;  // Clear the pointer
    }
}

// --------------------- Target Submit Callbacks ---------------------

void on_ompt_callback_target_submit_emi(
    ompt_scope_endpoint_t endpoint,
    ompt_data_t *target_data,
    ompt_id_t *host_op_id,
    unsigned int requested_num_teams)
{
    if (endpoint == ompt_scope_begin) {
        ratelprof_api_activity_t *activity =
            (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t) + sizeof(args_target_submit_emi_t));
        activity->args = (void*)(activity + 1);

        activity->return_address = NULL;
        GET_ARGS_VALUE_target_submit_emi(activity);
        target_data->ptr = (void*)activity;

        ratelprof_on_enter_callbacks[RATELPROF_DOMAIN_OMP_REGION](RATELPROF_DOMAIN_OMP_REGION, OMPT_API_ID_target_submit, activity);
    } else if (endpoint == ompt_scope_end) {
        ratelprof_api_activity_t *activity = (ratelprof_api_activity_t *)(target_data->ptr);
        ratelprof_on_exit_callbacks[RATELPROF_DOMAIN_OMP_REGION](RATELPROF_DOMAIN_OMP_REGION, OMPT_API_ID_target_submit, activity);
        target_data->ptr = 0;  // Clear the pointer
    }
}

// --------------------- Data Mapping Callback ---------------------


void on_ompt_callback_target_map_emi(
    ompt_scope_endpoint_t endpoint,
    ompt_data_t *target_task_data,
    ompt_data_t *target_data,
    unsigned int nitems,
    void **host_addr,
    void **device_addr,
    size_t *bytes,
    unsigned int *mapping_flags,
    const void *codeptr_ra)
{
    if (endpoint == ompt_scope_begin) {
        ratelprof_api_activity_t *activity =
            (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t) + sizeof(args_target_map_emi_t));
        activity->args = (void*)(activity + 1);

        activity->return_address = (void *)codeptr_ra;
        GET_ARGS_VALUE_target_map_emi(activity);
        target_data->ptr = (void*)activity;

        ratelprof_on_enter_callbacks[RATELPROF_DOMAIN_OMP_REGION](RATELPROF_DOMAIN_OMP_REGION, OMPT_API_ID_target_map, activity);
    } else if (endpoint == ompt_scope_end) {
        ratelprof_api_activity_t *activity = (ratelprof_api_activity_t *)(target_data->ptr);

        ratelprof_on_exit_callbacks[RATELPROF_DOMAIN_OMP_REGION](RATELPROF_DOMAIN_OMP_REGION, OMPT_API_ID_target_map, activity);
        target_data->ptr = 0;  // Clear the pointer
    }
}


// --------------------- Device Lifecycle Callbacks ---------------------

void on_ompt_callback_device_finalize(
    int device_num)
{
    LOG(LOG_LEVEL_DEBUG, "[OMPT] device_finalize - Device: %d\n", device_num);
}

void on_ompt_callback_device_load(
    int device_num,
    const char *filename,
    int64_t offset_in_file,
    void *vma_in_file,
    size_t bytes,
    void *host_addr,
    void *device_addr,
    uint64_t module_id)
{
    LOG(LOG_LEVEL_DEBUG, "[OMPT] device_load - Device: %d, File: %s, Module ID: %lu\n",
           device_num, filename, module_id);
}

void on_ompt_callback_device_unload(
    int device_num,
    uint64_t module_id)
{
    LOG(LOG_LEVEL_DEBUG, "[OMPT] device_unload - Device: %d, Module ID: %lu\n",
           device_num, module_id);
}

void on_ompt_callback_device_initialize(
        int device_num,
        const char *type,
        ompt_device_t *device,
        ompt_function_lookup_t lookup,
        const char *documentation) 
{
    LOG(LOG_LEVEL_DEBUG, "[OMPT] device_initialize - Device: %d, Type: %s, lookup: %p, Documentation: %s\n",
           device_num, type, lookup, documentation);
}

// --------------------- OMPT Tool Initialization and Finalization ---------------------
int ompt_initialize(
    ompt_function_lookup_t lookup,
    int initial_device_num,
    ompt_data_t *tool_data)
{
    ompt_set_callback_t ompt_set_callback = (ompt_set_callback_t) lookup("ompt_set_callback");

    if (ompt_set_callback) {
        ratelprof_ompt_set_callback(ompt_callback_device_initialize);
        ratelprof_ompt_set_callback(ompt_callback_device_finalize);
        ratelprof_ompt_set_callback(ompt_callback_device_load);
        ratelprof_ompt_set_callback(ompt_callback_device_unload);
        ratelprof_ompt_set_callback(ompt_callback_target_emi);
        ratelprof_ompt_set_callback(ompt_callback_target_data_op_emi);
        ratelprof_ompt_set_callback(ompt_callback_target_submit_emi);
        ratelprof_ompt_set_callback(ompt_callback_target_map_emi);
    }

    LOG(LOG_LEVEL_DEBUG, "[OMPT] Tool initialized on device %d\n", initial_device_num);
    return 1; // success
}


void ompt_finalize(ompt_data_t *tool_data)
{
    LOG(LOG_LEVEL_DEBUG, "[OMPT] Tool finalized.\n");
}

ompt_start_tool_result_t *ompt_start_tool(
    unsigned int omp_version,
    const char *runtime_version)
{
    if (is_set_domain(RATELPROF_DOMAIN_OMP_REGION_NAME)) {
        static ompt_start_tool_result_t result = {&ompt_initialize, &ompt_finalize, {0}};
        return &result;
    }
    return NULL;
}


