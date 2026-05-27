#ifndef MEMORY_OP_HELPER_H
#define MEMORY_OP_HELPER_H

#include <string.h>
#include <stdbool.h>
#include <stdint.h>

typedef enum ratelprof_memory_op_e {
    RATELPROF_MEMORY_OP_BLIT_SET,
    RATELPROF_MEMORY_OP_BLIT_SET_2D,
    RATELPROF_MEMORY_OP_BLIT_COPY,
    RATELPROF_MEMORY_OP_BLIT_COPY_ALIGNED,
    RATELPROF_MEMORY_OP_BLIT_COPY_RECT,
    RATELPROF_MEMORY_OP_BLIT_COPY_ALIGNED_RECT,
    RATELPROF_MEMORY_OP_SDMA_COPY,
    // RATELPROF_MEMORY_OP_ALLOC, // Not yet Implement
    // RATELPROF_MEMORY_OP_FREE,
    RATELPROF_MEMORY_NB_OP,
    RATELPROF_MEMORY_OP_UNKNOWN,
} ratelprof_memory_op_t;


typedef struct {
    size_t off;
    size_t sz;
} __info_t;

typedef struct {
    __info_t src_ptr;
    __info_t dst_ptr;
    __info_t size;
} blit_kernel_copy_arg_info_t;

#define is_blit_copy_kernel(op) (op == RATELPROF_MEMORY_OP_BLIT_COPY \
    || op == RATELPROF_MEMORY_OP_BLIT_COPY_ALIGNED \
    || op == RATELPROF_MEMORY_OP_BLIT_COPY_RECT \
    || op == RATELPROF_MEMORY_OP_BLIT_COPY_ALIGNED_RECT)

#define is_blit_set_kernel(op) (op == RATELPROF_MEMORY_OP_BLIT_SET \
    || op == RATELPROF_MEMORY_OP_BLIT_SET_2D)

static blit_kernel_copy_arg_info_t blit_copy_kernel_arg_info[RATELPROF_MEMORY_NB_OP] = {
    [RATELPROF_MEMORY_OP_BLIT_COPY] = {
        .src_ptr = { .off = 0,  .sz = 8 },
        .dst_ptr = { .off = 8,  .sz = 8 },
        .size    = { .off = 16, .sz = 8 },
    },

    [RATELPROF_MEMORY_OP_BLIT_COPY_ALIGNED] = {
        .src_ptr = { .off = 0,  .sz = 8 },
        .dst_ptr = { .off = 8,  .sz = 8 },
        .size    = { .off = 40, .sz = 8 },
    },

    [RATELPROF_MEMORY_OP_BLIT_COPY_RECT] = {
        .src_ptr = { .off = 0,  .sz = 8 },
        .dst_ptr = { .off = 8,  .sz = 8 },
        .size    = { .off = 96, .sz = 32 },
    },

    [RATELPROF_MEMORY_OP_BLIT_COPY_ALIGNED_RECT] = {
        .src_ptr = { .off = 0,  .sz = 8 },
        .dst_ptr = { .off = 8,  .sz = 8 },
        .size    = { .off = 96, .sz = 32 },
    },
};

static inline void get_blit_copy_kernel_arg_data(ratelprof_memory_op_t op, uint8_t* buf, uintptr_t* src_ptr, uintptr_t* dst_ptr, size_t* size) 
{
    blit_kernel_copy_arg_info_t info = blit_copy_kernel_arg_info[op];

    *src_ptr = *(uintptr_t*)( buf + info.src_ptr.off );
    *dst_ptr = *(uintptr_t*)( buf + info.dst_ptr.off );

    if (op == RATELPROF_MEMORY_OP_BLIT_COPY || op == RATELPROF_MEMORY_OP_BLIT_COPY_ALIGNED)
    {
        *size = *(size_t*)( buf + info.size.off );
    } 
    else if (op == RATELPROF_MEMORY_OP_BLIT_COPY_RECT || op == RATELPROF_MEMORY_OP_BLIT_COPY_ALIGNED_RECT)
    {
        // TODO: 26/05/2026 - Check if the way to get size for rect copy is correct
        struct { size_t _u; size_t h; size_t __u; size_t w;} rect_size = *(typeof(rect_size)*)( buf + info.size.off );  
        *size = rect_size.w * rect_size.h;
    }
}

static inline void get_blit_fill_kernel_arg_data(ratelprof_memory_op_t op, uint8_t* buf, uint8_t** pattern, uint32_t* pattern_size, size_t* size) 
{
    // TODO (22/05/2026): Check if arg offset are correct
    if (op == RATELPROF_MEMORY_OP_BLIT_SET) {
        uintptr_t buf_ptr = *(uintptr_t*)( buf );
        *pattern = (uint8_t*)( buf + 8 );
        *pattern_size = *(uint32_t*)( buf + 16 );
        uintptr_t end_ptr = *(uintptr_t*)( buf + 24 );
        *size = end_ptr - buf_ptr;
    } else if (op == RATELPROF_MEMORY_OP_BLIT_SET_2D) {
        *pattern = (uint8_t*)( buf + 32 );
        *pattern_size = *(uint32_t*)( buf + 40 );
        unsigned long width = *(unsigned long*)( buf + 52 );
        unsigned long height = *(unsigned long*)( buf + 60 );
        *size = width * height;
    }
}

static inline const char* get_blit_name_by_op(ratelprof_memory_op_t id) 
{
    static const char* ratelprof_memory_op_id_to_str[RATELPROF_MEMORY_NB_OP] = {
        [RATELPROF_MEMORY_OP_BLIT_SET] = "__amd_rocclr_fillBufferAligned",
        [RATELPROF_MEMORY_OP_BLIT_SET_2D] = "__amd_rocclr_fillBufferAligned2D",
        [RATELPROF_MEMORY_OP_BLIT_COPY] = "__amd_rocclr_copyBuffer",
        [RATELPROF_MEMORY_OP_BLIT_COPY_ALIGNED] = "__amd_rocclr_copyBufferAligned",
        [RATELPROF_MEMORY_OP_BLIT_COPY_RECT] = "__amd_rocclr_copyBufferRect",
        [RATELPROF_MEMORY_OP_BLIT_COPY_ALIGNED_RECT] = "__amd_rocclr_copyBufferRectAligned",
        [RATELPROF_MEMORY_OP_SDMA_COPY] = "SDMA Transfer",
    };

    return ratelprof_memory_op_id_to_str[id];
}


static inline ratelprof_memory_op_t get_blit_op_by_name(const char* name) 
{
    if (name == NULL) return RATELPROF_MEMORY_OP_UNKNOWN;
    else if (strcmp(name, "__amd_rocclr_fillBufferAligned.kd")      == 0) return RATELPROF_MEMORY_OP_BLIT_SET;
    else if (strcmp(name, "__amd_rocclr_fillBufferAligned2D.kd")    == 0) return RATELPROF_MEMORY_OP_BLIT_SET_2D;
    else if (strcmp(name, "__amd_rocclr_copyBuffer.kd")             == 0) return RATELPROF_MEMORY_OP_BLIT_COPY;
    else if (strcmp(name, "__amd_rocclr_copyBufferAligned.kd")      == 0) return RATELPROF_MEMORY_OP_BLIT_COPY_ALIGNED;
    else if (strcmp(name, "__amd_rocclr_copyBufferRect.kd")         == 0) return RATELPROF_MEMORY_OP_BLIT_COPY_RECT;
    else if (strcmp(name, "__amd_rocclr_copyBufferRectAligned.kd")  == 0) return RATELPROF_MEMORY_OP_BLIT_COPY_ALIGNED_RECT;
    return RATELPROF_MEMORY_OP_UNKNOWN;
}


#endif // MEMORY_OP_HELPER_H