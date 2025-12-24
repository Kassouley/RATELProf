#ifndef RPROFREP_SECTION_GLOBAL_H
#define RPROFREP_SECTION_GLOBAL_H

#include <stdint.h>

#include "rprofrep_core.h"

#include "utils/rprofrep_decode_type.h"


typedef struct rprofrep_global_section_t {
    int64_t   rank;
    uint64_t  experiment_start;
    uint64_t  lifecycle[RATELPROF_NB_PHASE];
    int64_t   main_ret;
    uint64_t  main_argc;
    char**    main_argv;
    uint64_t  num_agents;
    uint64_t* agents;
    uint64_t* nodes;
} rprofrep_global_data_t;


rprofrep_status_t rprofrep_free_global_section(rprofrep_global_data_t* section);

rprofrep_status_t rprofrep_decode_global_section(
    rprofrep_decode_context_t* ctx, 
    uint8_t* buffer, 
    size_t size, 
    rprofrep_global_data_t* out
);


rprofrep_status_t rprofrep_get_rank(rprofrep_decode_context_t* ctx, int64_t* rank);
rprofrep_status_t rprofrep_get_experiment_time(rprofrep_decode_context_t* ctx, uint64_t* experiment_time);
rprofrep_status_t rprofrep_get_constructor_time(rprofrep_decode_context_t* ctx, uint64_t* time);
rprofrep_status_t rprofrep_get_main_time(rprofrep_decode_context_t* ctx, uint64_t* time);
rprofrep_status_t rprofrep_get_destructor_time(rprofrep_decode_context_t* ctx, uint64_t* time);
rprofrep_status_t rprofrep_get_exit_code(rprofrep_decode_context_t* ctx, int64_t* exit_code);
rprofrep_status_t rprofrep_get_command_line(rprofrep_decode_context_t* ctx, char*** command_line_buffer, uint64_t* buffer_size);

#endif // RPROFREP_SECTION_GLOBAL_H