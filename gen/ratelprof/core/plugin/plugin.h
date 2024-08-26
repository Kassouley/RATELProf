/* # THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
 * # YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.
 */ 

#ifndef PLUGIN_H
#define PLUGIN_H

#include "hsa_plugin.h"
#include "hip_plugin.h" 

void hsa_callback(bool is_enter, ratelprof_hsa_api_activity_t* activity);
void hip_callback(bool is_enter, ratelprof_hip_api_activity_t* activity);

#endif // PLUGIN_H
