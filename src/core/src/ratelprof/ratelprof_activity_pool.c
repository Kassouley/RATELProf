#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

#include "ratelprof.h"

#include "memory_structure/mpsc_queue.h"
#include "memory_structure/hexcore.h"
#include "ratelprof/ratelprof_activity_pool.h"
#include "ratelprof/ratelprof_status.h"

ratelprof_activity_pool_t* global_activity_pool = NULL;

static inline void *
item_from_node(struct mpsc_queue_node *node)
{
    return (void *)(
        (uint8_t *)node + sizeof(struct mpsc_queue_node)
    );
}

static inline struct mpsc_queue_node* node_from_item(void *item)
{
    return (struct mpsc_queue_node *)(
        (uint8_t *)item - sizeof(struct mpsc_queue_node)
    );
}

static void* ratelprof_activity_pool_consume_activity(void* arg) {
    ratelprof_activity_pool_t* activity_pool = (ratelprof_activity_pool_t*) arg;
    if (!activity_pool) {
        LOG(LOG_LEVEL_FATAL, "Activity pool is NULL.\n");
    }
    if (!activity_pool->prop.activity_callback) {
        LOG(LOG_LEVEL_FATAL, "Activity callback is not set.\n");
    }
    while (activity_pool->active || !mpsc_queue_is_empty(activity_pool->buffer))
    {
        struct mpsc_queue_node* node = mpsc_queue_pop(activity_pool->buffer);
        if (!node)
        {
            usleep(100);
            continue;
        }
        void *activity = item_from_node(node);
        ratelprof_domain_t* domain_ptr = (ratelprof_domain_t*)activity;
        ratelprof_status_t s = activity_pool->prop.activity_callback(*domain_ptr, activity, activity_pool->prop.activity_callback_user_args);
        if (s != RATELPROF_STATUS_SUCCESS)
            LOG(LOG_LEVEL_ERROR, "The activity callback failed to execute. %s (code %d)\n", get_error_string(s), s);
        ratelprof_activity_pool_free_activity(activity);
    }
    return NULL;
}

ratelprof_status_t 
ratelprof_activity_pool_init(ratelprof_pool_properties_t prop)
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    ratelprof_activity_pool_t* ap = (ratelprof_activity_pool_t*) malloc(sizeof(ratelprof_activity_pool_t));
    if (!ap) return RATELPROF_STATUS_MALLOC_FAILED;

    struct mpsc_queue* buffer = (struct mpsc_queue*) malloc(sizeof(struct mpsc_queue));
    if (!buffer) return RATELPROF_STATUS_MALLOC_FAILED;

    ap->buffer = buffer;
    mpsc_queue_init(buffer);

    ap->active = true;
    memcpy(&ap->prop, &prop, sizeof(ratelprof_pool_properties_t));

    pthread_create(&ap->th, NULL, ratelprof_activity_pool_consume_activity, ap);

    global_activity_pool = ap;

    hexcore_allocator_init();

    return status;
}

ratelprof_status_t 
ratelprof_activity_pool_fini()
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    global_activity_pool->active = false;
    pthread_join(global_activity_pool->th, NULL);
    free(global_activity_pool->buffer);
    free(global_activity_pool);

    hexcore_allocator_destroy();

    return status;
}


void 
ratelprof_activity_pool_push_activity(void* activity) 
{
    mpsc_queue_insert(global_activity_pool->buffer, node_from_item(activity));
}


void* 
ratelprof_activity_pool_alloc_activity(size_t size) 
{
    void* ptr = hexcore_alloc(size + sizeof(struct mpsc_queue_node));
    return ptr + sizeof(struct mpsc_queue_node);
}

void 
ratelprof_activity_pool_free_activity(void* ptr) 
{
    hexcore_free(ptr - sizeof(struct mpsc_queue_node));
}