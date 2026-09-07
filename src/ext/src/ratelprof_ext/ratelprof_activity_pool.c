#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <ratelprof.h>

#include "memory_structure/ring_buffer.h"
#include "ratelprof_ext/ratelprof_activity_pool.h"
#include "ratelprof_ext/ratelprof_ext_status.h"

ratelprof_activity_pool_t* global_activity_pool = NULL;

static void* ratelprof_activity_pool_consume_activity(void* arg) {
    ratelprof_activity_pool_t* activity_pool = (ratelprof_activity_pool_t*) arg;
    if (!activity_pool) {
        LOG(LOG_LEVEL_FATAL, "Activity pool is NULL.\n");
        exit(1);
    }
    if (!activity_pool->prop.activity_callback) {
        LOG(LOG_LEVEL_FATAL, "Activity callback is not set.\n");
        exit(1);
    }
    while (activity_pool->active || !rb_is_empty(activity_pool->buffer))
    {
        void *activity = NULL;
        rb_read(activity_pool->buffer, &activity);
        if (!activity)
        {
            usleep(100);
            continue;
        }
        ratelprof_domain_t* domain_ptr = (ratelprof_domain_t*)activity;
        ratelprof_status_t s = activity_pool->prop.activity_callback(*domain_ptr, activity, activity_pool->prop.activity_callback_user_args);
        if (s != RATELPROF_STATUS_SUCCESS)
            LOG(LOG_LEVEL_ERROR, "The activity callback failed to execute. %s (code %d)\n", get_error_string_ext(s), s);
        ratelprof_memory_pool_free(activity);
    }
    return NULL;
}

ratelprof_status_t 
ratelprof_activity_pool_init(ratelprof_pool_properties_t prop)
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    ratelprof_activity_pool_t* ap = (ratelprof_activity_pool_t*) malloc(sizeof(ratelprof_activity_pool_t));
    if (!ap) return RATELPROF_STATUS_MALLOC_FAILED;

    ring_buffer_t* buffer = (ring_buffer_t*) malloc(sizeof(ring_buffer_t));
    if (!buffer) return RATELPROF_STATUS_MALLOC_FAILED;

    ap->buffer = buffer;
    if(rb_init(buffer, prop.capacity, prop.chunk_size) != 0)
        return RATELPROF_STATUS_MALLOC_FAILED;

    ap->active = true;
    memcpy(&ap->prop, &prop, sizeof(ratelprof_pool_properties_t));
    pthread_mutex_init(&ap->mutex, NULL);

    pthread_create(&ap->th, NULL, ratelprof_activity_pool_consume_activity, ap);

    global_activity_pool = ap;

    return status;
}

ratelprof_status_t 
ratelprof_activity_pool_fini()
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    global_activity_pool->active = false;
    pthread_join(global_activity_pool->th, NULL);
    pthread_mutex_destroy(&global_activity_pool->mutex);
    rb_destroy(global_activity_pool->buffer);
    free(global_activity_pool->buffer);
    free(global_activity_pool);
    return status;
}

void 
ratelprof_activity_pool_push_activity(void* activity) 
{
    pthread_mutex_lock(&global_activity_pool->mutex);
    rb_write(global_activity_pool->buffer, activity);
    pthread_mutex_unlock(&global_activity_pool->mutex);
}