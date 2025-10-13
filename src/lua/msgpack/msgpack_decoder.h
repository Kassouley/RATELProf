#ifndef MSGPACK_DECODER_H
#define MSGPACK_DECODER_H

#include <lua.h>
#include <lauxlib.h>
#include <stdint.h>
#include "msgpack_ext.h"

#define PROGRESS_BAR_LABEL "Data decoding"


// Structure
typedef struct {
    unsigned char *buf;
    size_t off;
    size_t size;
    lua_State *L;
    int is_quiet;

    char** ext_string_array;
    size_t ext_string_array_size;
} msgpack_decode_ctx_t;


// Prototype
void decode_msgpack(msgpack_decode_ctx_t *ctx);


// Function to print a progress bar of the decoding process
static inline void print_progress_bar(const char* prefix, size_t current, size_t total, int is_quiet) {
    if (is_quiet) return;
    const int bar_width = 30;
    static int last_shown = -1;

    if (total == 0) return;
    
    double progress = (double)current / total;
    int filled = (int)(progress * bar_width);

    if (filled != last_shown) {
        last_shown = filled;

        printf("\r%-20s [", prefix);
        for (int i = 0; i < bar_width; ++i) {
            putchar(i < filled ? '=' : ' ');
        }
        printf("] %zu/%zu", current, total);
        fflush(stdout);
    }

    if (current == total) {
        last_shown = -1;
        printf("\n");
    }
}

// Read byte from buffer
static inline uint8_t read_byte(msgpack_decode_ctx_t *ctx) {
    return (uint8_t)ctx->buf[ctx->off++];
}

// Read uint from buffer
static inline uint64_t read_uint(msgpack_decode_ctx_t *ctx, int bytes) {
    uint64_t val = 0;
    for (int i = 0; i < bytes; i++) {
        val = (val << 8) | read_byte(ctx);
    }
    return val;
}

// Read int from buffer
static inline int64_t read_int(msgpack_decode_ctx_t *ctx, int bytes) {
    int64_t val = read_uint(ctx, bytes);
    int shift = (8 - bytes) * 8;
    return (val << shift) >> shift;
}

// Read float from buffer
static inline float read_float32(msgpack_decode_ctx_t *ctx) {
    union { uint32_t i; float f; } u;
    u.i = read_uint(ctx, 4);
    return u.f;
}

// Read double from buffer
static inline double read_float64(msgpack_decode_ctx_t *ctx) {
    union { uint64_t i; double d; } u;
    u.i = read_uint(ctx, 8);
    return u.d;
}

// Read string from buffer
static inline char* read_string(msgpack_decode_ctx_t *ctx, size_t len) {
    if (ctx->off + len > ctx->size) {
        luaL_error(ctx->L, "Attempt to read beyond buffer");
    }

    char *buf = malloc(len + 1);
    if (!buf) {
        luaL_error(ctx->L, "Out of memory");
    }

    memcpy(buf, ctx->buf + ctx->off, len);
    buf[len] = '\0';
    ctx->off += len;

    return buf;
}


#endif