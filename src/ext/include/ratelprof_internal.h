#ifndef RATELPROF_INTERNAL_H
#define RATELPROF_INTERNAL_H

#include <ratelprof.h>

extern const char* __ratelprof_get_domain_name_impl(ratelprof_domain_t domain);
extern const char* __ratelprof_get_domain_desc_impl(ratelprof_domain_t domain);
extern const char* __ratelprof_get_funame_by_id_impl(ratelprof_domain_t domain, ratelprof_api_id_t funid);
extern ratelprof_api_id_t __ratelprof_get_funid_by_name_impl(ratelprof_domain_t domain, const char* funame);
extern void* __ratelprof_get_funaddr_by_id_impl(ratelprof_domain_t domain, ratelprof_api_id_t funid);
extern ratelprof_status_t __ratelprof_enable_domain_impl(ratelprof_domain_t domain);
extern ratelprof_status_t __ratelprof_disable_domain_impl(ratelprof_domain_t domain);
extern ratelprof_status_t __ratelprof_start_impl(void);
extern ratelprof_status_t __ratelprof_stop_impl(void);
extern ratelprof_status_t __ratelprof_init_impl(unsigned int ndomains);
extern ratelprof_status_t __ratelprof_fini_impl(void);

#endif // RATELPROF_INTERNAL_H
