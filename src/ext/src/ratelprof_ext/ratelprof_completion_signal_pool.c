#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#include <ratelprof.h>

#include "ratelprof_ext.h"
#include "ratelprof_ext/ratelprof_completion_signal_pool.h"

#include "memory_structure/mpsc_queue.h"
#include "memory_structure/cht.h"


#define CALL_PROF_FUNC(func, ...) ((__##func##_t)profiling_table.api_ptr[PROFILING_ID_##func])(__VA_ARGS__, NULL)

typedef struct ratelprof_completion_signal_s {
    struct mpsc_queue_node node;
    struct ratelprof_completion_signal_s *next_free;
    struct ratelprof_completion_signal_s *next_sig;

    struct {
        uint64_t key;
        ratelprof_completion_signal_callback_t callback;
        void *callback_arg;
    } props;

    hsa_signal_t proxy;
    // hsa_signal_t original;
} ratelprof_completion_signal_t;


static ratelprof_completion_signal_pool_t* pool = NULL;

static bool is_signal_valid(ratelprof_completion_signal_t *signal) 
{
    return signal != NULL && signal->proxy.handle != 0 && amd_signal_is_valid(signal->proxy);
}

static bool is_signal_finished(ratelprof_completion_signal_t *signal) 
{
    return amd_signal_atomic_load_value(signal->proxy) == 0;
}

static void* ratelprof_completion_signal_pool_get_buffer(uint64_t key) 
{
    void* buffer = cht_get(pool->ht_buffers, key);
    if (buffer) return buffer;

    buffer = malloc(sizeof(struct mpsc_queue));
    if (!buffer) return NULL;
    
    mpsc_queue_init(buffer);

    if (cht_set(pool->ht_buffers, key, buffer) != 0) {
        free(buffer);
        return NULL;
    }

    size_t count = atomic_load_explicit(&pool->buffers_array_count, memory_order_relaxed);

    if (count >= pool->buffers_array_capacity) {
        /*
         * Cannot safely realloc here if the consumer is concurrently
         * traversing the array.
         */
        free(buffer);
        return NULL;
    }

    pool->buffers_array[count] = buffer;

    atomic_store_explicit(&pool->buffers_array_count, count + 1, memory_order_release);

    return buffer;
}


static void *ratelprof_completion_signal_pool_consumer_loop(void *arg) 
{
    ratelprof_completion_signal_pool_t *p = (ratelprof_completion_signal_pool_t *)arg;
    if (!p) {
        return NULL;
    }

    while (true) {
        
        size_t buffers_count = atomic_load_explicit(&p->buffers_array_count, memory_order_acquire);

        for (size_t i = 0; i < buffers_count; i++) {
            struct mpsc_queue *q = p->buffers_array[i];

            if (mpsc_queue_is_empty(q)) continue;

            struct mpsc_queue_node* node = mpsc_queue_tail(q);
            if (!node) continue;

            ratelprof_completion_signal_t* entry = (ratelprof_completion_signal_t*) node;
            if (!is_signal_valid(entry) || !is_signal_finished(entry)) {
                continue;
            }

            entry->props.callback(entry->props.callback_arg);

            mpsc_queue_pop(q);
            
            ratelprof_completion_signal_pool_release_signal(entry);

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

    slot->next_free = NULL;
    slot->next_sig = NULL;

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
        slot->next_free = old_head;
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
        ratelprof_completion_signal_t *next = head->next_free;

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

    pool->buffers_array_capacity = RATELPROF_COMPLETION_SIGNAL_BUFFER_NUMBER;
    atomic_init(&pool->buffers_array_count, 0);
    pool->buffers_array = (void**)calloc(pool->buffers_array_capacity, sizeof(void*));
    if (!pool->buffers_array) {
        free(pool);
        return RATELPROF_STATUS_MALLOC_FAILED;
    }

    atomic_init(&pool->free_slots.head, NULL);
    pool->running = false;

    pool->ht_buffers = cht_create(RATELPROF_COMPLETION_SIGNAL_BUFFER_NUMBER);
    if (!pool->ht_buffers) {
        free(pool);
        return RATELPROF_STATUS_OUT_OF_MEMORY;
    }
    atomic_init(&pool->nevents, 0);

    return RATELPROF_STATUS_SUCCESS;
}


ratelprof_status_t ratelprof_completion_signal_pool_fini()
{
    if (!pool || pool->running) {
        return RATELPROF_STATUS_INVALID_POOL;
    }

    // ratelprof_completion_signal_t *slot = pool->all_slots;
    // while (slot) {
    //     ratelprof_completion_signal_t *next = slot->next;

    //     CALL_PROF_FUNC(hsa_signal_destroy, slot->signal);

    //     free(slot);
    //     slot = next;
    // }

    cht_destroy(pool->ht_buffers, free);

    free(pool);
    pool = NULL;
    return RATELPROF_STATUS_SUCCESS;
}

ratelprof_status_t ratelprof_completion_signal_pool_acquire_signal(ratelprof_completion_signal_t **out) 
{
    if (!out) return RATELPROF_STATUS_INVALID_PTR;

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

    signal->props.key = key;
    signal->props.callback = callback;
    signal->props.callback_arg = callback_arg;

    void* buffer = ratelprof_completion_signal_pool_get_buffer(key);
    if (!buffer) {
        return RATELPROF_STATUS_KEY_NOT_FOUND;
    }
    mpsc_queue_insert(buffer, &signal->node);

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