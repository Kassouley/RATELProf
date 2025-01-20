#ifndef ACTIVITY_PLUGIN_H
#define ACTIVITY_PLUGIN_H

#include <ratelprof.h>
#include <ratelprof_ext.h>
#include <ratelprof_buffer_manager.h>

// Function declarations
void activity_callback(ratelprof_domain_t domain, const void* activity, const void* last_activity, void* user_args);
void hsa_activity_callback(const ratelprof_api_activity_t* activity, ratelprof_buffer_t* json_buffer);
void hip_activity_callback(const ratelprof_api_activity_t* activity, ratelprof_buffer_t* json_buffer);
void gpu_activity_callback(const ratelprof_gpu_activity_t* activity, ratelprof_buffer_t* json_buffer);
void omp_tgt_rtl_activity_callback(const ratelprof_api_activity_t* activity, ratelprof_buffer_t* json_buffer);
void omp_tgt_activity_callback(const ratelprof_api_activity_t* activity, ratelprof_buffer_t* json_buffer);
void profiling_activity_callback(const ratelprof_profiling_activity_t* activity, ratelprof_buffer_t* json_buffer);

#endif // ACTIVITY_PLUGIN_H
