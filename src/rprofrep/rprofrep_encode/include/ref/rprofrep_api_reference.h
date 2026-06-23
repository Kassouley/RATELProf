#ifndef RPROFREP_API_REFERENCE_H
#define RPROFREP_API_REFERENCE_H

#include <stdlib.h>

#include "rprofrep_core.h"
#include "rprofrep_encode_type.h"

typedef struct rprofrep_api_data_ref_s
{
    uint64_t __hip_api_existed_ref_id[HIP_API_ID_NB_FUNCTION];
    uint64_t __hsa_api_existed_ref_id[HSA_API_ID_NB_FUNCTION];
    uint64_t __mpi_api_existed_ref_id[MPI_API_ID_NB_FUNCTION];
    uint64_t __omp_tgt_rtl_api_existed_ref_id[OMP_TGT_RTL_API_ID_NB_FUNCTION];
    uint64_t __omp_routine_api_existed_ref_id[OMP_ROUTINE_API_ID_NB_FUNCTION];
    uint64_t __ompt_api_existed_ref_id[OMPT_API_ID_NB_FUNCTION];
    uint64_t __rocblas_api_existed_ref_id[ROCBLAS_API_ID_NB_FUNCTION];
    uint64_t __rccl_api_existed_ref_id[RCCL_API_ID_NB_FUNCTION];

    uint64_t* api_data_existed_ref_id[RATELPROF_NB_DOMAIN_EXT];

    uint64_t ref_counter;
    msgpack_buffer_t buffer;
} rprofrep_api_data_ref_t;


rprofrep_status_t rprofrep_init_api_data_section(rprofrep_api_data_ref_t* data, const char* filename);

void rprofrep_free_api_data_section(rprofrep_api_data_ref_t* data);

rprofrep_status_t rprofrep_write_api_data_section(
    rprofrep_encode_context_t* ctx, 
    rprofrep_api_data_ref_t* data, 
    const char* filename);

uint64_t rprofrep_api_data_get_ref(rprofrep_encode_context_t* ctx, ratelprof_domain_t domain, ratelprof_api_id_t id);

#endif // RPROFREP_API_REFERENCE_H