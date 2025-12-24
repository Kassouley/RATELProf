#include <stdlib.h>

#include "utils/rprofrep_argument_manager.h"

#include "args_helper/ompt_args.h"
#include "args_helper/hsa_args.h"
#include "args_helper/hip_args.h"
#include "args_helper/omp_tgt_rtl_args.h"
#include "args_helper/omp_routine_args.h"
#include "args_helper/mpi_args.h"

#include "rprofrep_encode_type.h"

#define SET_WRITER_AUX(name, ldomain, udomain) \
    arg_manager->__##ldomain##_api_arg_writer[udomain##_API_ID_##name].write_arg   = (rprofrep_write_arg_cb_t) write_##name##_args_to_buffer; \
    arg_manager->__##ldomain##_api_arg_writer[udomain##_API_ID_##name].write_param = (rprofrep_write_param_cb_t) write_##name##_params_to_buffer;


void rprofrep_init_argument_manager(rprofrep_argument_manager_t* arg_manager) 
{
    // Initialize HIP API argument writers
    #define SET_WRITER(name) SET_WRITER_AUX(name, hip, HIP)
    FOR_EACH_HIP_FUNC(SET_WRITER);
    #undef SET_WRITER

    // Initialize HSA API argument writers
    #define SET_WRITER(name) SET_WRITER_AUX(name, hsa, HSA)
    FOR_EACH_HSA_FUNC(SET_WRITER);
    #undef SET_WRITER

    // Initialize MPI API argument writers
    #define SET_WRITER(name) SET_WRITER_AUX(name, mpi, MPI)
    FOR_EACH_MPI_FUNC(SET_WRITER);
    #undef SET_WRITER

    // Initialize OMP TGT RTL API argument writers
    #define SET_WRITER(name) SET_WRITER_AUX(name, omp_tgt_rtl, OMP_TGT_RTL)
    FOR_EACH_OMP_TGT_RTL_FUNC(SET_WRITER);
    #undef SET_WRITER

    // Initialize OMP Routine API argument writers
    #define SET_WRITER(name) SET_WRITER_AUX(name, omp_routine, OMP_ROUTINE)
    FOR_EACH_OMP_ROUTINE_FUNC(SET_WRITER);
    #undef SET_WRITER
  
    // Initialize OMPT API argument writers
    #define SET_WRITER(name) SET_WRITER_AUX(name, ompt, OMPT)
    FOR_EACH_OMPT_FUNC(SET_WRITER);
    #undef SET_WRITER

    // Map domain to corresponding argument writer arrays
    arg_manager->api_arg_writer[RATELPROF_DOMAIN_HIP]         = arg_manager->__hip_api_arg_writer;
    arg_manager->api_arg_writer[RATELPROF_DOMAIN_HSA]         = arg_manager->__hsa_api_arg_writer;
    arg_manager->api_arg_writer[RATELPROF_DOMAIN_MPI]         = arg_manager->__mpi_api_arg_writer;
    arg_manager->api_arg_writer[RATELPROF_DOMAIN_OMP_TGT_RTL] = arg_manager->__omp_tgt_rtl_api_arg_writer;
    arg_manager->api_arg_writer[RATELPROF_DOMAIN_OMP_ROUTINE] = arg_manager->__omp_routine_api_arg_writer;
    arg_manager->api_arg_writer[RATELPROF_DOMAIN_OMP_REGION]  = arg_manager->__ompt_api_arg_writer;
}



void rprofrep_write_args(
    rprofrep_encode_context_t* ctx,
    msgpack_buffer_t* buf,
    ratelprof_domain_t domain,
    ratelprof_api_id_t funid,
    const void* func_args
) {
    rprofrep_argument_manager_t* arg_manager = &ctx->arg_manager;
    rprofrep_write_arg_cb_t write_arg = arg_manager->api_arg_writer[domain][funid].write_arg;
    write_arg(func_args, ctx, buf);
}


void rprofrep_write_params(
    rprofrep_encode_context_t* ctx,
    msgpack_buffer_t* buf,
    ratelprof_domain_t domain,
    ratelprof_api_id_t funid
) {
    rprofrep_argument_manager_t* arg_manager = &ctx->arg_manager;
    rprofrep_write_param_cb_t write_param = arg_manager->api_arg_writer[domain][funid].write_param;
    write_param(ctx, buf);
}