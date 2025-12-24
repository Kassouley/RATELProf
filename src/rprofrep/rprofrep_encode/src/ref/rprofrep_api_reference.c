#include <stdio.h>
#include <stdlib.h>

#include "rprofrep_core.h"
#include "rprofrep_encode_type.h"

#include "utils/rprofrep_argument_manager.h"
#include "ref/rprofrep_api_reference.h"

rprofrep_status_t rprofrep_init_api_data_section(rprofrep_api_data_ref_t* data, const char* filename)
{
    RPROFREP_CHECK_ALLOC(data);
    data->ref_counter = 0;

    data->api_data_existed_ref_id[RATELPROF_DOMAIN_HIP]         = data->__hip_api_existed_ref_id;
    data->api_data_existed_ref_id[RATELPROF_DOMAIN_HSA]         = data->__hsa_api_existed_ref_id;
    data->api_data_existed_ref_id[RATELPROF_DOMAIN_MPI]         = data->__mpi_api_existed_ref_id;
    data->api_data_existed_ref_id[RATELPROF_DOMAIN_OMP_TGT_RTL] = data->__omp_tgt_rtl_api_existed_ref_id;
    data->api_data_existed_ref_id[RATELPROF_DOMAIN_OMP_ROUTINE] = data->__omp_routine_api_existed_ref_id;
    data->api_data_existed_ref_id[RATELPROF_DOMAIN_OMP_REGION]  = data->__ompt_api_existed_ref_id;

    memset(data->__hip_api_existed_ref_id,         0xFF, sizeof(data->__hip_api_existed_ref_id));
    memset(data->__hsa_api_existed_ref_id,         0xFF, sizeof(data->__hsa_api_existed_ref_id));
    memset(data->__mpi_api_existed_ref_id,         0xFF, sizeof(data->__mpi_api_existed_ref_id));
    memset(data->__omp_tgt_rtl_api_existed_ref_id, 0xFF, sizeof(data->__omp_tgt_rtl_api_existed_ref_id));
    memset(data->__omp_routine_api_existed_ref_id, 0xFF, sizeof(data->__omp_routine_api_existed_ref_id));
    memset(data->__ompt_api_existed_ref_id,        0xFF, sizeof(data->__ompt_api_existed_ref_id));

    msgpack_init(&data->buffer, 0xFFFF, MSGPACK_OVERFLOW_WRITE_TO_FILE, filename);

    return RPROFREP_STATUS_SUCCESS;
}


void rprofrep_free_api_data_section(rprofrep_api_data_ref_t* data)
{
    msgpack_free(&data->buffer);
}


rprofrep_status_t rprofrep_write_api_data_section(
    rprofrep_encode_context_t* ctx, 
    rprofrep_api_data_ref_t* data, 
    const char* filename
) {
    (void) ctx;
    (void) filename;
    msgpack_push_bytes(&data->buffer, &data->ref_counter, sizeof(data->ref_counter));
    msgpack_write(&data->buffer);
    msgpack_flush(&data->buffer);
    return RPROFREP_STATUS_SUCCESS;
}


uint64_t rprofrep_api_data_get_ref(rprofrep_encode_context_t* ctx, ratelprof_domain_t domain, ratelprof_api_id_t id)
{
    rprofrep_api_data_ref_t* ref = ctx->sections[RPROFREP_SECTION_API_DATA].data;

    uint64_t ref_id = ref->api_data_existed_ref_id[domain][id];
    if (ref_id == (uint64_t)-1) {
        const char* name = ratelprof_get_funame_by_id(domain, id);
        msgpack_encode_string(&ref->buffer, name);
        rprofrep_write_params(ctx, &ref->buffer, domain, id);

        ref_id = ref->ref_counter++;
        ref->api_data_existed_ref_id[domain][id] = ref_id;
    }

    return ref_id;
}