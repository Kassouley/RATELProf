#include <stdint.h>
#include <stdlib.h>

#include <ratelprof.h>
#include "ratelprof_ext.h"

typedef uint64_t roctx_range_id_t;

#define CALL(func, ...) ((__##func##_t)roctx_api_table.api_fn[ROCTX_API_ID_##func])(__VA_ARGS__)

#define DEFAULT_RANGE_ACTIVITIES_CAPACITY 1024

__thread ratelprof_stack_t roctx_activity_stack = {0};

int i_roctxRangePushA(const char* message, void* return_address) {
    if (roctx_activity_stack.capacity == 0) {
        ratelprof_stack_init(&roctx_activity_stack, DEFAULT_RANGE_ACTIVITIES_CAPACITY);
    }
    
    ratelprof_roctx_activity_t* activity = (ratelprof_roctx_activity_t*) malloc(sizeof(ratelprof_roctx_activity_t));

    ratelprof_stack_push(&roctx_activity_stack, (uint64_t)(uintptr_t) activity);

    activity->domain = RATELPROF_DOMAIN_ROCTX;

    activity->message = strdup(message);
    get_correlation_id(&activity->corr_id);
    get_id(&activity->id);
    activity->pid = get_pid();
    activity->tid = get_tid();
    activity->return_address = return_address;

    activity->start_time = ratelprof_get_curr_timespec();

    ratelprof_activity_pool_push_activity(activity);

    return CALL(roctxRangePushA, message, NULL);
}

int i_roctxRangePop() {
    uint64_t popped_activity = 0; 
    if (ratelprof_stack_pop(&roctx_activity_stack, &popped_activity) == RATELPROF_STATUS_SUCCESS) {
        ratelprof_roctx_activity_t* activity = (ratelprof_roctx_activity_t*)(uintptr_t) popped_activity;
        activity->stop_time = ratelprof_get_curr_timespec();
        pop_id();
    }

    return CALL(roctxRangePop);
}


static ratelprof_hash_table_t roctx_activity_hash_table = {0};

roctx_range_id_t i_roctxRangeStartA(const char* message, void* return_address) {
    if (roctx_activity_hash_table.size == 0) {
        ratelprof_hashtable_init(&roctx_activity_hash_table, DEFAULT_RANGE_ACTIVITIES_CAPACITY);
    }

    roctx_range_id_t id = CALL(roctxRangeStartA, message, NULL);


    ratelprof_roctx_activity_t* activity = (ratelprof_roctx_activity_t*) malloc (sizeof(ratelprof_roctx_activity_t));

    activity->domain = RATELPROF_DOMAIN_ROCTX;

    activity->message = strdup(message);
    get_correlation_id(&activity->corr_id);
    get_id(&activity->id);
    activity->pid = get_pid();
    activity->tid = get_tid();
    activity->return_address = return_address;

    activity->start_time = ratelprof_get_curr_timespec();

    ratelprof_insert_hash(&roctx_activity_hash_table, (uint64_t)id, activity);
    ratelprof_activity_pool_push_activity(activity);

    return id;
    
}

void i_roctxRangeStop(roctx_range_id_t id) {
    void *activity_ptr = NULL;

    if (ratelprof_find_hash(&roctx_activity_hash_table, (uint64_t)id, &activity_ptr) == RATELPROF_STATUS_SUCCESS) {
        ratelprof_roctx_activity_t *activity = (ratelprof_roctx_activity_t *)activity_ptr;
        activity->stop_time = ratelprof_get_curr_timespec();
        pop_id();
    }

    CALL(roctxRangeStop, id);
}


void i_roctxMarkA(const char* message, void* return_address) {
    ratelprof_roctx_activity_t* activity = (ratelprof_roctx_activity_t*) malloc(sizeof(ratelprof_roctx_activity_t));
    activity->start_time = ratelprof_get_curr_timespec();

    activity->domain = RATELPROF_DOMAIN_ROCTX;

    activity->message = strdup(message);
    get_correlation_id(&activity->corr_id);
    get_id(&activity->id);
    activity->pid = get_pid();
    activity->tid = get_tid();
    activity->return_address = return_address;
    pop_id();

    ratelprof_activity_pool_push_activity(activity);

    activity->stop_time = ratelprof_get_curr_timespec();
}
