#include "ratelprof.h"
#include "ratelprof_ext.h"

const char* get_kernel_name(uint64_t kernel_object)
{
    char* kernel_name = NULL;
    CHECK_RATELPROF_CALL(
        ratelprof_object_tracking_pool_get_kernelName_from_kernelObj(kernel_object, (void*)&kernel_name));
    return kernel_name;
}


ratelprof_status_t ratelprof_ext_init()
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
	status = ratelprof_init_profiling_table();
	if (status != RATELPROF_STATUS_SUCCESS) return status;
	status = ratelprof_object_tracking_pool_init();
	if (status != RATELPROF_STATUS_SUCCESS) return status;
    
    return status;
}


ratelprof_status_t ratelprof_ext_fini()
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
	status = ratelprof_object_tracking_pool_fini();
	if (status != RATELPROF_STATUS_SUCCESS) return status;
    return status;
}