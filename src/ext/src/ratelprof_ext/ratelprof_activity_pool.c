#include <pthread.h>

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
    if (!activity_pool) return RATELPROF_STATUS_MALLOC_FAILED;
    RATELPROF_TRY(
        ratelprof_queue_init(&activity_pool->activities, prop->buffer_size),
        LOG(LOG_LEVEL_ERROR, "Failed to init activity pool. %s (code %d)\n", get_error_string_ext(status), status)
    );
    memcpy(&activity_pool->prop, prop, sizeof(ratelprof_pool_properties_t));

    pthread_mutex_init(&activity_pool->mutex, NULL);

    return status;
}

ratelprof_status_t 
ratelprof_activity_pool_fini()
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    
    pthread_mutex_destroy(&activity_pool->mutex);

    RATELPROF_TRY(
        ratelprof_queue_free(&activity_pool->activities),
        LOG(LOG_LEVEL_ERROR, "Failed to cleanup activity pool. %s (code %d)\n", get_error_string_ext(status), status)
    );
    if (activity_pool) free(activity_pool);
    return status;
}

ratelprof_status_t 
ratelprof_activity_pool_push_activity(void* activity)
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    pthread_mutex_lock(&activity_pool->mutex);
    activity_pool->last_activity = activity;
    RATELPROF_TRY(
        ratelprof_queue_push(&activity_pool->activities, activity),
        LOG(LOG_LEVEL_ERROR, "Unable to push onto activity pool. %s (code %d)\n", get_error_string_ext(status), status)
    );
    pthread_mutex_unlock(&activity_pool->mutex);
    return status;
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
        RATELPROF_TRY(
            ratelprof_queue_pop(&activity_pool->activities, (void*)&activity),
            LOG(LOG_LEVEL_ERROR, "Cannot pop activity from activity pool. %s (code %d)\n", get_error_string_ext(status), status)
        );

        ratelprof_domain_t* domain_ptr = (ratelprof_domain_t*)activity;
        RATELPROF_TRY(
            activity_pool->prop.activity_callback(*domain_ptr, activity, activity_pool->last_activity, activity_pool->prop.activity_callback_user_args),
            LOG(LOG_LEVEL_ERROR, "The activity callback failed to execute. %s (code %d)\n", get_error_string_ext(status), status)
        );
        free(activity);
    }
    return status;
}