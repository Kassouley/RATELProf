#include <ratelprof.h>
#include "ratelprof_ext/memory_structure/ratelprof_queue.h"
#include "ratelprof_ext/ratelprof_activity_pool.h"
#include "ratelprof_ext/ratelprof_ext_status.h"

ratelprof_activity_pool_t* activity_pool = NULL;

ratelprof_status_t 
ratelprof_activity_pool_init(ratelprof_pool_properties_t* prop)
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    activity_pool = (ratelprof_activity_pool_t*)malloc(sizeof(ratelprof_activity_pool_t));
    status = ratelprof_queue_init(&activity_pool->activities, prop->buffer_size);
    memcpy(&activity_pool->prop, prop, sizeof(ratelprof_pool_properties_t));
    return status;
}

ratelprof_status_t 
ratelprof_activity_pool_fini()
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    status = ratelprof_queue_free(&activity_pool->activities);
    free(activity_pool);
    return status;
}

ratelprof_status_t 
ratelprof_activity_pool_push_activity(void* activity)
{
    activity_pool->last_activity = activity;
    return ratelprof_queue_push(&activity_pool->activities, activity);
}

ratelprof_activity_pool_t* 
ratelprof_get_activity_pool()
{
    return activity_pool;
}

ratelprof_status_t 
ratelprof_activity_pool_flush_activities()
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    if (activity_pool->prop.activity_callback == NULL) {
        return RATELPROF_STATUS_NO_CALLBACK_SET;
    }
    while(!ratelprof_queue_is_empty(&activity_pool->activities)) {
        void* activity = NULL;
        RATELPROF_TRY(ratelprof_queue_pop(&activity_pool->activities, (void*)&activity));
        ratelprof_domain_t* domain_ptr = (ratelprof_domain_t*)activity;
        activity_pool->prop.activity_callback(*domain_ptr, activity, activity_pool->last_activity, activity_pool->prop.activity_callback_user_args);
        free(activity);
    }
    return status;
}