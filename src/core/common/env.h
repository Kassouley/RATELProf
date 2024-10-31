#ifndef ENV_H
#define ENV_H
#include <stdbool.h>
#include <stddef.h>

const char* get_function_filter(const char* env_function_filter);
bool is_profiled_domain(const char *domain);
void* get_plugin_lib();
const char* get_output_file();
size_t get_buffer_size();
uint32_t get_nb_kernel_available();
uint32_t get_max_queue_available();

#endif // ENV_H
