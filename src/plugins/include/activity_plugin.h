#ifndef ACTIVITY_PLUGIN_H
#define ACTIVITY_PLUGIN_H

#include <ratelprof.h>

#include "hip_plugin.h"
#include "hsa_plugin.h"
#include "omp_tgt_rtl_plugin.h"
#include "omp_routine_plugin.h"
#include "ompt_plugin.h"
#include "mpi_plugin.h"

ratelprof_status_t activity_callback(ratelprof_domain_t domain, const void* activity, const void* last_activity, void* user_args);

#endif // ACTIVITY_PLUGIN_H
