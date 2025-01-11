#ifndef RATELPROF_ACTIVITY_POOL_H
#define RATELPROF_ACTIVITY_POOL_H

#include "ratelprof.h"
#include "ratelprof_ext.h"
#include "ratelprof_hash_table.h"
#include "ratelprof_queue.h"

typedef void (*activity_callback_t)(ratelprof_domain_t domain, const void* activity, const void* last_activity, void* user_args);

typedef struct ratelprof_pool_properties_s {
    activity_callback_t activity_callback;
    void* activity_callback_user_args;
    int buffer_size;
} ratelprof_pool_properties_t;

typedef struct ratelprof_activity_pool_s {
    ratelprof_queue_t activities;
    void* last_activity;
    ratelprof_pool_properties_t prop;
} ratelprof_activity_pool_t;

ratelprof_status_t 
ratelprof_activity_pool_init(ratelprof_pool_properties_t* prop);

ratelprof_status_t 
ratelprof_activity_pool_fini();

ratelprof_status_t 
ratelprof_activity_pool_flush_activities();

ratelprof_activity_pool_t* 
ratelprof_get_activity_pool();

ratelprof_status_t 
ratelprof_activity_pool_push_activity(void* activity);



#endif // RATELPROF_ACTIVITY_POOL_H