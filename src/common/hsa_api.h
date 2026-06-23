#ifndef HSA_API_H_
#define HSA_API_H_

#include "domains/minimal_abi/hsa_minimal_abi.h"

hsa_status_t hsa_init();
hsa_status_t hsa_shut_down();
hsa_status_t hsa_status_string(hsa_status_t status, const char ** status_string);
hsa_status_t hsa_agent_get_info(hsa_agent_t agent, hsa_agent_info_t attribute, void* value);
hsa_status_t hsa_isa_get_info_alt(hsa_isa_t isa, hsa_isa_info_t attribute, void *value);
hsa_status_t hsa_iterate_agents(hsa_status_t (*callback)(hsa_agent_t agent, void* data), void* data);

#endif // HSA_API_H_