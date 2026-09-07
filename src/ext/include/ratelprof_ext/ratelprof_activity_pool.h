#ifndef RATELPROF_ACTIVITY_POOL_H
#define RATELPROF_ACTIVITY_POOL_H

#include <pthread.h>
#include <stdbool.h>
#include <ratelprof.h>

typedef ratelprof_status_t (*activity_callback_t)(ratelprof_domain_t domain, const void* activity, void* user_args);

typedef struct ratelprof_pool_properties_s {
    activity_callback_t activity_callback;
    void* activity_callback_user_args;
    size_t capacity;
    size_t chunk_size;
} ratelprof_pool_properties_t;

typedef struct ratelprof_activity_pool_s {
    pthread_t th;
    bool active;
    void* buffer;
    ratelprof_pool_properties_t prop;
    pthread_mutex_t mutex;
} ratelprof_activity_pool_t;

ratelprof_status_t 
ratelprof_activity_pool_init(ratelprof_pool_properties_t prop);

ratelprof_status_t 
ratelprof_activity_pool_fini();

void 
ratelprof_activity_pool_push_activity(void* activity);

#endif // RATELPROF_ACTIVITY_POOL_H