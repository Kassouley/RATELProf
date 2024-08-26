#ifndef RATELPROF_TIME_H
#define RATELPROF_TIME_H

#include <stdint.h>

typedef uint64_t ratelprof_time_t;

ratelprof_time_t ratelprof_get_timestamp_ns(void);

ratelprof_time_t ratelprof_get_timestamp_s(void);

ratelprof_time_t ratelprof_get_timestamp_ms(void);

ratelprof_time_t ratelprof_get_timestamp_us(void);


#endif // RATELPROF_TIME_H