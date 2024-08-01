#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <time.h>
#include "ratelprof.h"
#include "ratelprof_ext.h"

static inline uint32_t get_tid() 
{ 
    return syscall(__NR_gettid); 
}

static inline uint32_t get_pid() 
{ 
    return syscall(__NR_getpid); 
}

void hsa_callback_sample(bool is_enter, ratelprof_hsa_api_activity_t* activity) 
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    uint64_t timestamp_ns = ts.tv_sec * 1e9 + ts.tv_nsec;
    if (is_enter){
        activity->start_time = timestamp_ns;
    } else {
        activity->stop_time = timestamp_ns;
        activity->pid = get_pid();
        activity->tid = get_tid();
        ratelprof_memory_pool_push_hsa_activity(activity);
    }
}

void hip_callback_sample(bool is_enter, ratelprof_hip_api_activity_t* activity) 
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    uint64_t timestamp_ns = ts.tv_sec * 1e9 + ts.tv_nsec;
    if (is_enter){
        activity->start_time = timestamp_ns;
    } else {
        activity->stop_time = timestamp_ns;
        activity->pid = get_pid();
        activity->tid = get_tid();
        ratelprof_memory_pool_push_hip_activity(activity);
    }
}


__attribute__((constructor)) void init(void) {
    ratelprof_init();
    ratelprof_memory_pool_init();

    bool* is_profiled = (bool*)malloc(RATELPROF_NB_DOMAIN * sizeof(bool));
    get_profiled_domain(is_profiled);

    if (is_profiled[RATELPROF_DOMAIN_HSA]) {
        set_hsa_profile_callback(hsa_callback_sample);
        ratelprof_enable_domain(RATELPROF_DOMAIN_HSA);
    }
    if (is_profiled[RATELPROF_DOMAIN_HIP]) {
        set_hip_profile_callback(hip_callback_sample);
        ratelprof_enable_domain(RATELPROF_DOMAIN_HIP);
    }

    free(is_profiled);
}

__attribute__((destructor)) void fini(void) {
    ratelprof_memory_pool_flush_activities();
    ratelprof_fini();
}
