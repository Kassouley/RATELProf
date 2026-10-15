#include <stdint.h>
#include <stdlib.h>

#include <ratelprof.h>
#include "ratelprof_ext.h"
#include "memory_structure/cht.h"

typedef uint64_t roctx_range_id_t;

#define CALL(func, ...) ((__##func##_t)roctx_api_table.api_fn[ROCTX_API_ID_##func])(__VA_ARGS__)

#define DEFAULT_RANGE_ACTIVITIES_CAPACITY 1024

__thread ratelprof_stack_t roctx_activity_stack = {0};

int i_roctxRangePushA(const char* message, void* return_address) {
    if (roctx_activity_stack.capacity == 0) {
        ratelprof_stack_init(&roctx_activity_stack, DEFAULT_RANGE_ACTIVITIES_CAPACITY);
    }
    
    ratelprof_roctx_activity_t* activity = (ratelprof_roctx_activity_t*) ratelprof_activity_pool_alloc_activity(sizeof(ratelprof_roctx_activity_t));

    ratelprof_stack_push(&roctx_activity_stack, (uint64_t)(uintptr_t) activity);

    activity->domain = RATELPROF_DOMAIN_ROCTX;

    activity->message = strdup(message);
    get_id(&activity->id);
    activity->pid = get_pid();
    activity->tid = get_tid();
    activity->return_address = return_address;

    activity->start_time = ratelprof_get_clock_now();


    return CALL(roctxRangePushA, message, NULL);
}

int i_roctxRangePop() {
    uint64_t popped_activity = 0; 
    if (ratelprof_stack_pop(&roctx_activity_stack, &popped_activity) == RATELPROF_STATUS_SUCCESS) {
        ratelprof_roctx_activity_t* activity = (ratelprof_roctx_activity_t*)(uintptr_t) popped_activity;
        activity->stop_time = ratelprof_get_clock_now();
        get_correlation_id(&activity->corr_id, &activity->has_children);
        ratelprof_activity_pool_push_activity(activity);
    }

    return CALL(roctxRangePop);
}


static cht_t* roctx_ht = NULL;

roctx_range_id_t i_roctxRangeStartA(const char* message, void* return_address) {
    if (!roctx_ht) {
        roctx_ht = cht_create(DEFAULT_RANGE_ACTIVITIES_CAPACITY);
    }

    roctx_range_id_t id = CALL(roctxRangeStartA, message, NULL);


    ratelprof_roctx_activity_t* activity = (ratelprof_roctx_activity_t*) ratelprof_activity_pool_alloc_activity(sizeof(ratelprof_roctx_activity_t));

    activity->domain = RATELPROF_DOMAIN_ROCTX;

    activity->message = strdup(message);
    get_id(&activity->id);
    activity->pid = get_pid();
    activity->tid = get_tid();
    activity->return_address = return_address;

    activity->start_time = ratelprof_get_clock_now();

    cht_set(roctx_ht, id, activity);

    return id;
    
}

void i_roctxRangeStop(roctx_range_id_t id) {
    void *activity_ptr = cht_get(roctx_ht, id);

    if (activity_ptr) {
        ratelprof_roctx_activity_t *activity = (ratelprof_roctx_activity_t *)activity_ptr;
        activity->stop_time = ratelprof_get_clock_now();
        get_correlation_id(&activity->corr_id, &activity->has_children);
        ratelprof_activity_pool_push_activity(activity);
    }

    CALL(roctxRangeStop, id);
}


void i_roctxMarkA(const char* message, void* return_address) {
    ratelprof_roctx_activity_t* activity = (ratelprof_roctx_activity_t*) ratelprof_activity_pool_alloc_activity(sizeof(ratelprof_roctx_activity_t));
    activity->start_time = ratelprof_get_clock_now();

    activity->domain = RATELPROF_DOMAIN_ROCTX;

    activity->message = strdup(message);
    get_id(&activity->id);
    get_correlation_id(&activity->corr_id, &activity->has_children);
    activity->pid = get_pid();
    activity->tid = get_tid();
    activity->return_address = return_address;

    ratelprof_activity_pool_push_activity(activity);

    activity->stop_time = ratelprof_get_clock_now();
}
