#ifndef RATELPROF_COMPLETION_SIGNAL_POOL_H
#define RATELPROF_COMPLETION_SIGNAL_POOL_H

#include <stdbool.h>
#include <stdint.h>
#include <pthread.h>
#include <stdatomic.h>

#include "ratelprof_ext.h"
#include "domains/minimal_abi/hsa_minimal_abi.h"
#include "ratelprof_ext/memory_structure/ratelprof_hash_table.h"

#define RATELPROF_COMPLETION_SIGNAL_RING_CAPACITY 1
#define RATELPROF_COMPLETION_SIGNAL_RING_CHUNK_SIZE 4096

typedef void (*ratelprof_completion_signal_callback_t)(void *);


typedef struct ratelprof_completion_signal_s {
    struct ratelprof_completion_signal_s *next;
    hsa_signal_t proxy;
    // hsa_signal_t original;
} ratelprof_completion_signal_t;


typedef struct ratelprof_completion_signal_stack_s {
    _Atomic(ratelprof_completion_signal_t*) head;
} ratelprof_completion_signal_stack_t;


typedef struct ratelprof_completion_signal_entry_s {
    uint64_t key;
    ratelprof_completion_signal_t* signal;
    ratelprof_completion_signal_callback_t callback;
    void *callback_arg;
} ratelprof_completion_signal_entry_t;


typedef struct ratelprof_completion_signal_pool_s {
    ratelprof_completion_signal_stack_t all_slots;
    ratelprof_completion_signal_stack_t free_slots;

    ratelprof_hash_table_t ring_buffers;
    void** ring_buffers_array;
    size_t ring_buffers_array_capacity;
    _Atomic(size_t) ring_buffers_array_count;

    _Atomic(size_t) nevents;

    pthread_mutex_t mutex;

    bool running;
    pthread_t consumer_thread;
} ratelprof_completion_signal_pool_t;



void ratelprof_completion_signal_pool_start_consumer();

void ratelprof_completion_signal_pool_stop_consumer();

ratelprof_status_t ratelprof_completion_signal_pool_set_signal(ratelprof_gpu_activity_t *activity, 
                                                 hsa_signal_t* original_signal, 
                                                 uint64_t key,
                                                 ratelprof_completion_signal_callback_t callback);


void ratelprof_completion_signal_pool_release_signal(ratelprof_completion_signal_t *signal);

ratelprof_status_t ratelprof_completion_signal_pool_acquire_signal(ratelprof_completion_signal_t **signal);

ratelprof_status_t ratelprof_completion_signal_pool_init();

ratelprof_status_t ratelprof_completion_signal_pool_fini();

#endif // RATELPROF_COMPLETION_SIGNAL_POOL_H