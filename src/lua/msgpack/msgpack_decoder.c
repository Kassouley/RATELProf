#include <lua.h>
#include <lauxlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "msgpack_decoder.h"

#include "msgpack_ext.h"

/** RATELProf Ext decoding 
 *      Decoding as follow : 
 *          - tool version as 3 uint
 *          - experiment start epoch time as uint
 *          - mpi rank as int -> -1 = no mpi
 *          - lifecycle stop time as map of string to uint
 *          - map node id to agent object
 *          - string extension mapping
 *          - location data
 *          - trace data
 *          - gpu props
 */
void decode_ratelprof_ext(msgpack_decode_ctx_t *ctx) {
    lua_newtable(ctx->L);

    lua_pushstring(ctx->L, "version");
    decode_msgpack(ctx);
    lua_settable(ctx->L, -3);

    lua_pushstring(ctx->L, "experiment_start_epoch");
    decode_msgpack(ctx);
    lua_settable(ctx->L, -3);

    lua_pushstring(ctx->L, "mpi_rank");
    decode_msgpack(ctx);
    lua_settable(ctx->L, -3);

    lua_pushstring(ctx->L, "lifecycle");
    decode_msgpack(ctx);
    lua_settable(ctx->L, -3);

    lua_pushstring(ctx->L, "main_data");
    decode_msgpack(ctx);
    lua_settable(ctx->L, -3);

    lua_pushstring(ctx->L, "node_id");
    decode_msgpack(ctx);
    lua_settable(ctx->L, -3);

    // String array decoding
    decode_msgpack(ctx);  // expects and decodes an array of strings

    lua_pushstring(ctx->L, "locations");
    decode_msgpack(ctx);
    lua_settable(ctx->L, -3);

    lua_pushstring(ctx->L, "trace_events");
    decode_msgpack(ctx);
    lua_settable(ctx->L, -3);

    lua_pushstring(ctx->L, "gpu_props");
    decode_msgpack(ctx);
    lua_settable(ctx->L, -3);
}

void decode_string_array_ext(msgpack_decode_ctx_t *ctx, size_t size) {
    if (ctx->ext_string_array) free(ctx->ext_string_array);
    ctx->ext_string_array = (char**)malloc(size * sizeof(char*));
    ctx->ext_string_array_size = size;
    for (size_t i = 0; i < size; i++) {
        size_t len = 0;
        uint8_t b = read_byte(ctx);

        if ((b & 0xe0) == 0xa0) {
            len = b & 0x1f;
        } else if (b == 0xd9) {
            len = read_byte(ctx);
        } else if (b == 0xda) {
            len = read_uint(ctx, 2);
        } else if (b == 0xdb) {
            len = read_uint(ctx, 4);
        } else {
            luaL_error(ctx->L, "String array extension excepts strings as element.");
        }
        ctx->ext_string_array[i] = read_string(ctx, len);
    }
}

void decode_string_ext(msgpack_decode_ctx_t *ctx, size_t size) {
    size_t index = read_uint(ctx, size);

    if (index < 0 || index >= ctx->ext_string_array_size) {
        luaL_error(ctx->L, "Trying to read an ext string at a wrong index");
    }
    
    if (ctx->ext_string_array) {
        lua_pushstring(ctx->L, ctx->ext_string_array[index]);
    } else {
        luaL_error(ctx->L, "Trying to read an ext string without initialize the string array before");
    }
}



void decode_ext(msgpack_decode_ctx_t *ctx, size_t size) {
    uint8_t type = read_byte(ctx); // type tag

    switch(type) {
        case MSGPACK_EXT_RATELPROF:     decode_ratelprof_ext(ctx); break;          // Custom decoding for RATELProf report
        case MSGPACK_EXT_STRING:        decode_string_ext(ctx, size); break;       // Decoding string id with array
        case MSGPACK_EXT_STRING_ARRAY : decode_string_array_ext(ctx, size); break;
        default: luaL_error(ctx->L, "Unsupported ext type: 0x%02x", type);
    }
}


void decode_string(msgpack_decode_ctx_t *ctx, size_t len) {
    char *buf = read_string(ctx, len);
    lua_pushlstring(ctx->L, buf, len);
    free(buf);
}


void decode_array(msgpack_decode_ctx_t *ctx, size_t size) {
    lua_newtable(ctx->L);
    for (size_t i = 0; i < size; i++) {
        decode_msgpack(ctx);
        lua_rawseti(ctx->L, -2, i + 1);
    }
}

void decode_map(msgpack_decode_ctx_t *ctx, size_t size) {
    lua_newtable(ctx->L);
    for (size_t i = 0; i < size; i++) {
        decode_msgpack(ctx); // key
        decode_msgpack(ctx); // value
        lua_settable(ctx->L, -3);
    }
}

void decode_msgpack(msgpack_decode_ctx_t *ctx) {
    print_progress_bar(PROGRESS_BAR_LABEL, ctx->off, ctx->size, ctx->is_quiet);
    uint8_t b = read_byte(ctx);

    if (b <= 0x7f) {
        lua_pushinteger(ctx->L, b);         // positive fixint
    } else if (b >= 0xe0) {
        lua_pushinteger(ctx->L, (int8_t)b); // negative fixint
    } else if ((b & 0xe0) == 0xa0) {
        size_t len = b & 0x1f;
        decode_string(ctx, len);            // fixstr
    } else if ((b & 0xf0) == 0x90) {
        size_t size = b & 0x0f;
        decode_array(ctx, size);            // fixarray
    } else if ((b & 0xf0) == 0x80) {
        size_t size = b & 0x0f;
        decode_map(ctx, size);              // fixmap
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

            case 0xd9: decode_string(ctx, read_byte(ctx)); break;        // str8
            case 0xda: decode_string(ctx, read_uint(ctx, 2)); break;     // str16
            case 0xdb: decode_string(ctx, read_uint(ctx, 4)); break;     // str32

            case 0xc4: decode_string(ctx, read_byte(ctx)); break;        // bin8
            case 0xc5: decode_string(ctx, read_uint(ctx, 2)); break;     // bin16
            case 0xc6: decode_string(ctx, read_uint(ctx, 4)); break;     // bin32

            case 0xdc: decode_array(ctx, read_uint(ctx, 2)); break;     // array16
            case 0xdd: decode_array(ctx, read_uint(ctx, 4)); break;     // array32

            case 0xde: decode_map(ctx, read_uint(ctx, 2)); break;       // map16
            case 0xdf: decode_map(ctx, read_uint(ctx, 4)); break;       // map32

            case 0xd4: decode_ext(ctx, 1); break;
            case 0xd5: decode_ext(ctx, 2); break;
            case 0xd6: decode_ext(ctx, 4); break;
            case 0xd7: decode_ext(ctx, 8); break;
            case 0xd8: decode_ext(ctx, 16); break;
            case 0xc7: decode_ext(ctx, read_byte(ctx)); break;
            case 0xc8: decode_ext(ctx, read_uint(ctx, 2)); break;
            case 0xc9: decode_ext(ctx, read_uint(ctx, 4)); break;

            default:
                printf("Unsupported type: 0x%02x\n", b);
                luaL_error(ctx->L, "Unsupported type: 0x%02x", b);
        }
    }
}

int lua_decode_msgpack_file(lua_State *L) {
    const char *filename = luaL_checkstring(L, 1);
    int is_quiet = lua_toboolean(L, 2);

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

    msgpack_decode_ctx_t ctx = { .buf = buf, .size = size, .off = 0, .L = L, .is_quiet = is_quiet };
    decode_msgpack(&ctx);
    print_progress_bar(PROGRESS_BAR_LABEL, size, size, is_quiet);

    if (ctx.ext_string_array) {
        for (size_t i = 0; i < ctx.ext_string_array_size; ++i) free(ctx.ext_string_array[i]);
        free(ctx.ext_string_array);
    }
    return 1;
}

int luaopen_msgpack_decoder(lua_State *L) {
    luaL_Reg funcs[] = {
        {"decode_msgpack_binary", lua_decode_msgpack_file},
        {NULL, NULL}
    };

    luaL_register(L, "msgpack_decoder", funcs);
    return 1;
}
