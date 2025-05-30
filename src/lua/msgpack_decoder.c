#include <lua.h>
#include <lauxlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PROGRESS_BAR_LABEL "Report decoding"

static inline void print_progress_bar(const char* prefix, size_t current, size_t total) {
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
        putchar('\n');
        last_shown = -1;
    }
}

typedef struct {
    unsigned char *buf;
    size_t off;
    size_t size;
    lua_State *L;
} DecodeCtx;

static inline uint8_t read_byte(DecodeCtx *ctx) {
    return (uint8_t)ctx->buf[ctx->off++];
}

static inline uint64_t read_uint(DecodeCtx *ctx, int bytes) {
    uint64_t val = 0;
    for (int i = 0; i < bytes; i++) {
        val = (val << 8) | read_byte(ctx);
    }
    return val;
}

static inline int64_t read_int(DecodeCtx *ctx, int bytes) {
    int64_t val = read_uint(ctx, bytes);
    int shift = (8 - bytes) * 8;
    return (val << shift) >> shift;
}

static inline float read_float32(DecodeCtx *ctx) {
    union { uint32_t i; float f; } u;
    u.i = read_uint(ctx, 4);
    return u.f;
}

static inline double read_float64(DecodeCtx *ctx) {
    union { uint64_t i; double d; } u;
    u.i = read_uint(ctx, 8);
    return u.d;
}

static inline void read_string(DecodeCtx *ctx, size_t len) {
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

    lua_pushlstring(ctx->L, buf, len);
    free(buf);
}


void read_ext(DecodeCtx *ctx, size_t size) {
    read_byte(ctx); // type tag
    for (size_t i = 0; i < size; i++) read_byte(ctx);
    lua_pushnil(ctx->L); // push nil to indicate skipped data
}


void decode_msgpack(DecodeCtx *ctx);

void decode_array(DecodeCtx *ctx, size_t size) {
    lua_newtable(ctx->L);
    for (size_t i = 0; i < size; i++) {
        decode_msgpack(ctx);
        lua_rawseti(ctx->L, -2, i + 1);
    }
}

void decode_map(DecodeCtx *ctx, size_t size) {
    lua_newtable(ctx->L);
    for (size_t i = 0; i < size; i++) {
        decode_msgpack(ctx); // key
        decode_msgpack(ctx); // value
        lua_settable(ctx->L, -3);
    }
}

void decode_msgpack(DecodeCtx *ctx) {
    print_progress_bar(PROGRESS_BAR_LABEL, ctx->off, ctx->size);
    uint8_t b = read_byte(ctx);

    if (b <= 0x7f) {
        lua_pushinteger(ctx->L, b);  // positive fixint
    } else if (b >= 0xe0) {
        lua_pushinteger(ctx->L, (int8_t)b); // negative fixint
    } else if ((b & 0xe0) == 0xa0) {
        size_t len = b & 0x1f;
        read_string(ctx, len); // fixstr
    } else if ((b & 0xf0) == 0x90) {
        size_t size = b & 0x0f;
        decode_array(ctx, size); // fixarray
    } else if ((b & 0xf0) == 0x80) {
        size_t size = b & 0x0f;
        decode_map(ctx, size); // fixmap
    } else {
        switch (b) {
            case 0xc0: lua_pushnil(ctx->L); break;
            case 0xc2: lua_pushboolean(ctx->L, 0); break;
            case 0xc3: lua_pushboolean(ctx->L, 1); break;

            case 0xca: lua_pushnumber(ctx->L, read_float32(ctx)); break;
            case 0xcb: lua_pushnumber(ctx->L, read_float64(ctx)); break;

            case 0xcc: lua_pushinteger(ctx->L, read_byte(ctx)); break;
            case 0xcd: lua_pushinteger(ctx->L, read_uint(ctx, 2)); break;
            case 0xce: lua_pushinteger(ctx->L, read_uint(ctx, 4)); break;
            case 0xcf: lua_pushinteger(ctx->L, read_uint(ctx, 8)); break;

            case 0xd0: lua_pushinteger(ctx->L, (int8_t)read_byte(ctx)); break;
            case 0xd1: lua_pushinteger(ctx->L, (int16_t)read_int(ctx, 2)); break;
            case 0xd2: lua_pushinteger(ctx->L, (int32_t)read_int(ctx, 4)); break;
            case 0xd3: lua_pushinteger(ctx->L, (int64_t)read_int(ctx, 8)); break;

            case 0xd9: read_string(ctx, read_byte(ctx)); break;        // str8
            case 0xda: read_string(ctx, read_uint(ctx, 2)); break;     // str16
            case 0xdb: read_string(ctx, read_uint(ctx, 4)); break;     // str32

            case 0xc4: read_string(ctx, read_byte(ctx)); break;        // bin8
            case 0xc5: read_string(ctx, read_uint(ctx, 2)); break;     // bin16
            case 0xc6: read_string(ctx, read_uint(ctx, 4)); break;     // bin32

            case 0xdc: decode_array(ctx, read_uint(ctx, 2)); break;     // array16
            case 0xdd: decode_array(ctx, read_uint(ctx, 4)); break;     // array32

            case 0xde: decode_map(ctx, read_uint(ctx, 2)); break;       // map16
            case 0xdf: decode_map(ctx, read_uint(ctx, 4)); break;       // map32

            case 0xd4: read_ext(ctx, 1); break;
            case 0xd5: read_ext(ctx, 2); break;
            case 0xd6: read_ext(ctx, 4); break;
            case 0xd7: read_ext(ctx, 8); break;
            case 0xd8: read_ext(ctx, 16); break;
            case 0xc7: read_ext(ctx, read_byte(ctx)); break;
            case 0xc8: read_ext(ctx, read_uint(ctx, 2)); break;
            case 0xc9: read_ext(ctx, read_uint(ctx, 4)); break;

            default:
                printf("Unsupported type: 0x%02x\n", b);
                luaL_error(ctx->L, "Unsupported type: 0x%02x", b);
        }
    }
}

int lua_decode_msgpack_file(lua_State *L) {
    const char *filename = luaL_checkstring(L, 1);

    FILE *f = fopen(filename, "rb");
    if (!f) return luaL_error(L, "Cannot open file: %s", filename);

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    rewind(f);

    unsigned char *buf = malloc(size);
    if (!buf) {
        fclose(f);
        return luaL_error(L, "Memory allocation failed");
    }

    size_t read = fread(buf, 1, size, f);
    if (read != size) return luaL_error(L, "Bytes read: %ld | Size: %ld", read, size);
    fclose(f);

    DecodeCtx ctx = { .buf = buf, .size = size, .off = 0, .L = L };
    decode_msgpack(&ctx);
    print_progress_bar(PROGRESS_BAR_LABEL, size, size);
    return 1;
}

int luaopen_msgpack_decoder(lua_State *L) {
    luaL_Reg funcs[] = {
        {"decode_msgpack_binary", lua_decode_msgpack_file},
        {NULL, NULL}
    };
#if LUA_VERSION_NUM >= 502
    luaL_newlib(L, funcs);
#else
    luaL_register(L, "msgpack_decoder", funcs);  // Lua 5.1
#endif
    return 1;
}
