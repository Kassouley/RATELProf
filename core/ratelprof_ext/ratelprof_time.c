#include "ratelprof_time.h"
#include <time.h> 

// Get the current timestamp in nanoseconds since the CLOCK_MONOTONIC epoch
ratelprof_time_t ratelprof_get_timestamp_ns(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint64_t)ts.tv_sec * 1000000000ULL + (uint64_t)ts.tv_nsec;
}

// Get the current timestamp in microseconds since the CLOCK_MONOTONIC epoch
ratelprof_time_t ratelprof_get_timestamp_us(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint64_t)ts.tv_sec * 1000000ULL + (uint64_t)(ts.tv_nsec / 1000ULL);
}

// Get the current timestamp in milliseconds since the CLOCK_MONOTONIC epoch
ratelprof_time_t ratelprof_get_timestamp_ms(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint64_t)ts.tv_sec * 1000ULL + (uint64_t)(ts.tv_nsec / 1000000ULL);
}

// Get the current timestamp in seconds since the CLOCK_MONOTONIC epoch
ratelprof_time_t ratelprof_get_timestamp_s(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint64_t)ts.tv_sec;
}
