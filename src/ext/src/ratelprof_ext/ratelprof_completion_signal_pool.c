#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#include <ratelprof.h>

#include "ratelprof_ext.h"
#include "ratelprof_ext/ratelprof_completion_signal_pool.h"

#define data_type_t ratelprof_completion_signal_entry_t
#define data_default_value (ratelprof_completion_signal_entry_t){0}
#include "memory_structure/ring_buffer.h"


#define CALL_PROF_FUNC(func, ...) ((__##func##_t)profiling_table.api_ptr[PROFILING_ID_##func])(__VA_ARGS__, NULL)

static ratelprof_completion_signal_pool_t* pool = NULL;

static bool is_signal_valid(ratelprof_completion_signal_t *signal) 
{
    return signal != NULL && signal->proxy.handle != 0 && amd_signal_is_valid(signal->proxy);
}

static bool is_signal_finished(ratelprof_completion_signal_t *signal) 
{
    return amd_signal_atomic_load_value(signal->proxy) == 0;
}

static ring_buffer_t *ratelprof_completion_signal_pool_get_ring_buffer(uint64_t key) 
{
    ring_buffer_t *buffer = NULL;
    ratelprof_status_t status = ratelprof_find_hash(&pool->ring_buffers, key, (void **)&buffer);
    if (status == RATELPROF_STATUS_SUCCESS) {
        return buffer;
    }

    buffer = (ring_buffer_t *)calloc(1, sizeof(*buffer));
    if (!buffer) {
        return NULL;
    }

    if (rb_init(buffer, RATELPROF_COMPLETION_SIGNAL_RING_CAPACITY, RATELPROF_COMPLETION_SIGNAL_RING_CHUNK_SIZE) != 0) {
        free(buffer);
        return NULL;
    }
    if (ratelprof_insert_hash(&pool->ring_buffers, key, buffer) != RATELPROF_STATUS_SUCCESS) {
        rb_destroy(buffer);
        free(buffer);
        return NULL;
    }

    size_t count = atomic_load_explicit(&pool->ring_buffers_array_count, memory_order_relaxed);

    if (count >= pool->ring_buffers_array_capacity) {
        /*
         * Cannot safely realloc here if the consumer is concurrently
         * traversing the array.
         */
        rb_destroy(buffer);
        free(buffer);
        return NULL;
    }

    pool->ring_buffers_array[count] = buffer;

    atomic_store_explicit(&pool->ring_buffers_array_count, count + 1, memory_order_release);

    return buffer;
}


static void *ratelprof_completion_signal_pool_consumer_loop(void *arg) 
{
    ratelprof_completion_signal_pool_t *p = (ratelprof_completion_signal_pool_t *)arg;
    if (!p) {
        return NULL;
    }

    while (true) {
        
        size_t ring_buffers_count = atomic_load_explicit(&p->ring_buffers_array_count, memory_order_acquire);

        for (size_t i = 0; i < ring_buffers_count; i++) {
            ring_buffer_t *ring = p->ring_buffers_array[i];

            ratelprof_completion_signal_entry_t entry = rb_peek(ring);
            if (!is_signal_valid(entry.signal) || !is_signal_finished(entry.signal)) {
                continue;
            }

            entry.callback(entry.callback_arg);

            ratelprof_completion_signal_pool_release_signal(entry.signal);

            rb_advance_tail(ring);

            // Decrement the number of events in the pool
            atomic_fetch_sub_explicit(&p->nevents, 1, memory_order_release);
        }

        size_t nevents = atomic_load_explicit(&p->nevents, memory_order_acquire);
        if (nevents == 0) {
            if (!p->running) {
                break;
            }
            // usleep(100);
        }
    }

    return NULL;
}

static ratelprof_completion_signal_t *ratelprof_completion_signal_slot_alloc(void) 
{
    ratelprof_completion_signal_t *slot = (ratelprof_completion_signal_t *)malloc(sizeof(ratelprof_completion_signal_t));
    if (!slot) {
        return NULL;
    }

    slot->next = NULL;

    hsa_status_t status = CALL_PROF_FUNC(hsa_signal_create, 1, 0, NULL, &slot->proxy);
    if (status != HSA_STATUS_SUCCESS) {
        free(slot);
        return NULL;
    }

    return slot;
}


static void ratelprof_completion_signal_slot_push(ratelprof_completion_signal_stack_t *s, ratelprof_completion_signal_t *slot) 
{
    ratelprof_completion_signal_t *old_head = atomic_load_explicit(&s->head, memory_order_relaxed);

    do {
        slot->next = old_head;
    } while (!atomic_compare_exchange_weak_explicit(
        &s->head,
        &old_head,
        slot,
        memory_order_release,
        memory_order_relaxed));
}

static ratelprof_completion_signal_t *ratelprof_completion_signal_slot_pop(ratelprof_completion_signal_stack_t *s)
{
    ratelprof_completion_signal_t *head = atomic_load_explicit(&s->head, memory_order_acquire);
    if (head == NULL) return NULL;

    while (head != NULL) {
        ratelprof_completion_signal_t *next = head->next;

        if (atomic_compare_exchange_weak_explicit(
                &s->head,
                &head,
                next,
                memory_order_acquire,
                memory_order_relaxed)) {
            return head;
        }
    }

    return NULL;
}

ratelprof_status_t ratelprof_completion_signal_pool_init()
{
    if (pool) {
        return RATELPROF_STATUS_SUCCESS;
    }

    pool = (ratelprof_completion_signal_pool_t *)calloc(1, sizeof(*pool));
    if (!pool) {
        return RATELPROF_STATUS_MALLOC_FAILED;
    }

    pool->ring_buffers_array_capacity = 64;
    atomic_init(&pool->ring_buffers_array_count, 0);
    pool->ring_buffers_array = (void**)calloc(pool->ring_buffers_array_capacity, sizeof(void*));
    if (!pool->ring_buffers_array) {
        free(pool);
        return RATELPROF_STATUS_MALLOC_FAILED;
    }

    atomic_init(&pool->free_slots.head, NULL);
    pool->running = false;

    ratelprof_status_t status = ratelprof_hashtable_init(&pool->ring_buffers, 64);
    if (status != RATELPROF_STATUS_SUCCESS) {
        free(pool);
        return status;
    }
    atomic_init(&pool->nevents, 0);

    pthread_mutex_init(&pool->mutex, NULL);

    return RATELPROF_STATUS_SUCCESS;
}

static void hash_table_free_value(void *value) 
{
    ring_buffer_t *ring = (ring_buffer_t *)value;
    if (!ring) {
        return;
    }
    rb_destroy(ring);
    free(ring);
}

ratelprof_status_t ratelprof_completion_signal_pool_fini()
{
    if (!pool || pool->running) {
        return RATELPROF_STATUS_INVALID_POOL;
    }

    pthread_mutex_lock(&pool->mutex);
    // ratelprof_completion_signal_t *slot = pool->all_slots;
    // while (slot) {
    //     ratelprof_completion_signal_t *next = slot->next;

    //     CALL_PROF_FUNC(hsa_signal_destroy, slot->signal);

    //     free(slot);
    //     slot = next;
    // }

    ratelprof_hashtable_free(&pool->ring_buffers, hash_table_free_value);
    pthread_mutex_unlock(&pool->mutex);

    pthread_mutex_destroy(&pool->mutex);
    free(pool);
    pool = NULL;
    return RATELPROF_STATUS_SUCCESS;
}

ratelprof_status_t ratelprof_completion_signal_pool_acquire_signal(ratelprof_completion_signal_t **out) 
{
    if (!out) {
        return RATELPROF_STATUS_INVALID_PTR;
    }

    ratelprof_completion_signal_t *signal = ratelprof_completion_signal_slot_pop(&pool->free_slots);

    if (!signal) {
        signal = ratelprof_completion_signal_slot_alloc();
        if (!signal) return RATELPROF_STATUS_OUT_OF_MEMORY;
    } else {
        amd_signal_refresh(signal->proxy);
    }

    // signal->original.handle = 0;

    *out = signal;

    return RATELPROF_STATUS_SUCCESS;
}

void ratelprof_completion_signal_pool_release_signal(ratelprof_completion_signal_t *signal)
{
    amd_signal_invalidate(signal->proxy);
    ratelprof_completion_signal_slot_push(&pool->free_slots, signal);
}

static ratelprof_status_t ratelprof_completion_signal_pool_enqueue(uint64_t key,
                                              ratelprof_completion_signal_t* signal,
                                              ratelprof_completion_signal_callback_t callback,
                                              void *callback_arg) {
    if (!signal) {
        return RATELPROF_STATUS_INVALID_PTR;
    }

    ratelprof_completion_signal_entry_t entry = {
        .key = key,
        .signal = signal,
        .callback = callback,
        .callback_arg = callback_arg
    };


    pthread_mutex_lock(&pool->mutex);

    ring_buffer_t *ring = ratelprof_completion_signal_pool_get_ring_buffer(key);
    if (!ring) {
        pthread_mutex_unlock(&pool->mutex);
        return RATELPROF_STATUS_KEY_NOT_FOUND;
    }
    rb_write(ring, entry);
    pthread_mutex_unlock(&pool->mutex);

    // Increment the number of events in the pool
    atomic_fetch_add_explicit(&pool->nevents, 1, memory_order_relaxed);

    return RATELPROF_STATUS_SUCCESS;
}

void ratelprof_completion_signal_pool_start_consumer() {
    if (!pool || pool->running) {
        return;
    }

    pool->running = true;
    pthread_create(&pool->consumer_thread, NULL, ratelprof_completion_signal_pool_consumer_loop, pool);
}

void ratelprof_completion_signal_pool_stop_consumer() {
    if (!pool || !pool->running) {
        return;
    }

    pool->running = false;
    pthread_join(pool->consumer_thread, NULL);
}


// static bool callback_update_signal(hsa_signal_value_t value, void* arg) {
//     ratelprof_completion_signal_t* signal = (ratelprof_completion_signal_t*)arg;
//     if (signal->proxy.handle == 0) {
//         printf("Proxy signal is invalid in callback_update_signal\n");
//     }
//     if (signal->original.handle == 0) {
//         printf("Original signal is invalid in callback_update_signal\n");
//     }
//     amd_signal_copy_signal(signal->proxy, signal->original);
//     return true;
// }


ratelprof_status_t ratelprof_completion_signal_pool_set_signal(ratelprof_gpu_activity_t *activity, 
                                                 hsa_signal_t* original_signal, 
                                                 uint64_t key,
                                                 ratelprof_completion_signal_callback_t callback) {

    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    ratelprof_completion_signal_t* signal = NULL;
    
    RATELPROF_TRY(ratelprof_completion_signal_pool_acquire_signal(&signal));
  
    // signal->original = *original_signal;
    activity->proxy_signal = signal->proxy;

    // if (original_signal->handle == 0) {
        *original_signal = signal->proxy;
    // } else {
    //     hsa_status_t s = CALL_PROF_FUNC(hsa_amd_signal_async_handler, *original_signal, HSA_SIGNAL_CONDITION_LT, 1, callback_update_signal, signal);
    //     if (s != HSA_STATUS_SUCCESS) {
    //         LOG(LOG_LEVEL_ERROR, "Failed to set async handler: hsa error(%d)\n", s);
    //     }
    // }

    RATELPROF_TRY(ratelprof_completion_signal_pool_enqueue(key, signal, callback, activity));

    return status;
}