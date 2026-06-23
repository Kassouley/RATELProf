#ifndef RPROFREP_ARGUMENT_MANAGER_H
#define RPROFREP_ARGUMENT_MANAGER_H

#include "rprofrep_core.h"
#include "rprofrep_fwd.h"

typedef void (*rprofrep_write_arg_cb_t)(const void* func_args, rprofrep_encode_context_t* ctx, msgpack_buffer_t* buf);
typedef void (*rprofrep_write_param_cb_t)(rprofrep_encode_context_t* ctx, msgpack_buffer_t* buf);

typedef struct rprofrep_arg_writer_s {
    rprofrep_write_arg_cb_t write_arg;
    rprofrep_write_param_cb_t write_param;
} rprofrep_arg_writer_t;

typedef struct rprofrep_argument_manager_s
{
    rprofrep_arg_writer_t __hip_api_arg_writer[HIP_API_ID_NB_FUNCTION];
    rprofrep_arg_writer_t __hsa_api_arg_writer[HSA_API_ID_NB_FUNCTION];
    rprofrep_arg_writer_t __mpi_api_arg_writer[MPI_API_ID_NB_FUNCTION];
    rprofrep_arg_writer_t __omp_tgt_rtl_api_arg_writer[OMP_TGT_RTL_API_ID_NB_FUNCTION];
    rprofrep_arg_writer_t __omp_routine_api_arg_writer[OMP_ROUTINE_API_ID_NB_FUNCTION];
    rprofrep_arg_writer_t __ompt_api_arg_writer[OMPT_API_ID_NB_FUNCTION];
    rprofrep_arg_writer_t __rocblas_api_arg_writer[ROCBLAS_API_ID_NB_FUNCTION];
    rprofrep_arg_writer_t __rccl_api_arg_writer[RCCL_API_ID_NB_FUNCTION];

    rprofrep_arg_writer_t* api_arg_writer[RATELPROF_NB_DOMAIN_EXT];

} rprofrep_argument_manager_t;


void rprofrep_init_argument_manager(rprofrep_argument_manager_t* arg_manager);


void rprofrep_write_params(
    rprofrep_encode_context_t* ctx,
    msgpack_buffer_t* buf,
    ratelprof_domain_t domain,
    ratelprof_api_id_t funid
);

void rprofrep_write_args(
    rprofrep_encode_context_t* ctx,
    msgpack_buffer_t* buf,
    ratelprof_domain_t domain,
    ratelprof_api_id_t funid,
    const void* func_args
);

#endif // RPROFREP_ARGUMENT_MANAGER_H