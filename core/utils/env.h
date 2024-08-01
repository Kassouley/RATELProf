/* # THIS FILE HAS BEEN AUTOMATICALLY GENERATED BY THE GILDA TOOL.
 * # DO NOT MODIFY UNLESS YOU KNOW WHAT YOU ARE DOING.
 * # ANY CHANGES MAY BE OVERWRITTEN BY SUBSEQUENT RUNS OF GILDA.
 */ 

#ifndef ENV_H
#define ENV_H
#include <stdbool.h>

void 
set_hsa_profile_enabled(bool* enabled_functions, 
                  bool* is_full_enabled);

void 
set_hip_profile_enabled(bool* enabled_functions, 
                  bool* is_full_enabled);
 

const char* 
get_function_filter(const char* env_function_filter);
                    
int 
get_profiled_domain(bool* is_profiled); 

bool 
is_profiled_domain(const char *domain);

#endif // ENV_H