#include "ratelprof.h"
#include "ratelprof_ext.h"

const char* get_kernel_name(uint64_t kernel_object)
{
    char* kernel_name = NULL;
    CHECK_RATELPROF_CALL(
        ratelprof_object_tracking_pool_get_kernelName_from_kernelObj(kernel_object, (void*)&kernel_name));
    return kernel_name;
}

const char* ratelprof_ext_get_domain_name(ratelprof_domain_t domain) 
{
	switch((int)domain) {
		case RATELPROF_DOMAIN_COPY:         return RATELPROF_DOMAIN_COPY_NAME;
		case RATELPROF_DOMAIN_KERNEL:       return RATELPROF_DOMAIN_KERNEL_NAME;
		case RATELPROF_DOMAIN_BARRIEROR:    return RATELPROF_DOMAIN_BARRIEROR_NAME;
		case RATELPROF_DOMAIN_BARRIERAND:   return RATELPROF_DOMAIN_BARRIERAND_NAME;
		case RATELPROF_DOMAIN_PROFILING:    return RATELPROF_DOMAIN_PROFILING_NAME;
		default : return ratelprof_get_domain_name(domain) ;
	}
	return "Unknown domain";
}


const char* ratelprof_ext_get_domain_desc(ratelprof_domain_t domain) 
{
	switch((int)domain) {
		case RATELPROF_DOMAIN_COPY:         return RATELPROF_DOMAIN_COPY_DESC;
		case RATELPROF_DOMAIN_KERNEL:       return RATELPROF_DOMAIN_KERNEL_DESC;
		case RATELPROF_DOMAIN_BARRIEROR:    return RATELPROF_DOMAIN_BARRIEROR_DESC;
		case RATELPROF_DOMAIN_BARRIERAND:   return RATELPROF_DOMAIN_BARRIERAND_DESC; 
		case RATELPROF_DOMAIN_PROFILING:    return RATELPROF_DOMAIN_PROFILING_DESC; 
		default : return ratelprof_get_domain_desc(domain) ;
	}
	return "Unknown domain";
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