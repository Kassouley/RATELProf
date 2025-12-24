#ifndef RPROFREP_LUA_MSGPACK_H
#define RPROFREP_LUA_MSGPACK_H

#include <lua.h>
#include <lauxlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rprofrep_decode.h"
#include "utils/rprofrep_read_utils.h"

#define __decode_ext(L, buf, off, size) do {                                             \
    uint8_t type = __read_int8(buf, off);                                                \
    switch(type) {                                                                       \
        default: printf("Unsupported ext type: 0x%02x", type);                           \
    }                                                                                    \
} while(0)


#define __decode_array(L, buf, off, size) do {     \
    lua_newtable(L);                               \
    for (size_t i = 0; i < (size); i++) {            \
        __decode_msgpack(L, buf, off);             \
        lua_rawseti(L, -2, i + 1);                 \
    }                                              \
} while (0)

#define __decode_map(L, buf, off, size) do {       \
    lua_newtable(L);                               \
    for (size_t i = 0; i < (size); i++) {            \
        __decode_msgpack(L, buf, off); /* key */   \
        __decode_msgpack(L, buf, off); /* value */ \
        lua_settable(L, -3);                       \
    }                                              \
} while (0)

#define __decode_string(L, buf, off, len) lua_pushlstring(L, __read_string(buf, off, len), len);

#define __decode_int(L, n)    lua_pushinteger(L, n);

#define __decode_uint(L, n)   lua_pushinteger(L, n);

#define __decode_float(L, n)  lua_pushnumber(L, n);

#define __decode_null(L)      lua_pushnil(L);

#define __decode_true(L)      lua_pushboolean(L, 1);

#define __decode_false(L)     lua_pushboolean(L, 0);



// static inline void __decode_string_ext(lua_State *L, rprofrep_decode_context_t *ctx, const uint8_t* buf, size_t* off, size_t size) {
//     uint64_t str_id = 0;

//     switch (size) {
//         case 1:  str_id = __read_uint8(buf, off);  break;
//         case 2:  str_id = __read_uint16(buf, off); break;
//         case 4:  str_id = __read_uint32(buf, off); break;
//         case 8:  str_id = __read_uint64(buf, off); break;
//         default:
//             printf("Invalid string ext size: %zu\n", size);
//             return;
//     }

//     char* str = NULL;
//     if (rprofrep_status_is_success(rprofrep_get_string_by_id(ctx, str_id, &str))) {
//         lua_pushstring(L, str);
//     } else {
//         printf("Failed to get string from id %ld", str_id);
//     }
// }



static inline void __decode_msgpack(lua_State *L, const uint8_t* buf, size_t* off) {

    uint8_t b = __read_byte(buf, off);

    if (b <= 0x7f) { // positive fixint
        __decode_uint(L, b);   

    } else if (b >= 0xe0) { // negative fixint
        __decode_int(L, (int8_t)b); 

    } else if ((b & 0xe0) == 0xa0) { // fixstr
        __decode_string(L, buf, off, b & 0x1f);

    } else if ((b & 0xf0) == 0x90) { // fixarray
        __decode_array(L, buf, off, b & 0x0f);

    } else if ((b & 0xf0) == 0x80) { // fixmap
        __decode_map(L, buf, off, b & 0x0f);

    } else {
        switch (b) {
            case 0xc0: __decode_null(L);  break; // null
            case 0xc2: __decode_false(L); break; // false
            case 0xc3: __decode_true(L);  break; // true

            case 0xca: __decode_float(L, __read_float32(buf, off)); break; // float
            case 0xcb: __decode_float(L, __read_float64(buf, off)); break; // double

            case 0xcc: __decode_uint(L, __read_uint8(buf, off));  break; // uint8
            case 0xcd: __decode_uint(L, __read_uint16(buf, off)); break; // uint16
            case 0xce: __decode_uint(L, __read_uint32(buf, off)); break; // uint32
            case 0xcf: __decode_uint(L, __read_uint64(buf, off)); break; // uint64

            case 0xd0: __decode_int(L, __read_int8(buf, off));  break; // int8
            case 0xd1: __decode_int(L, __read_int16(buf, off)); break; // int16
            case 0xd2: __decode_int(L, __read_int32(buf, off)); break; // int32
            case 0xd3: __decode_int(L, __read_int64(buf, off)); break; // int64

            case 0xd9: __decode_string(L, buf, off, __read_uint8(buf, off));  break;     // str8
            case 0xda: __decode_string(L, buf, off, __read_uint16(buf, off)); break;     // str16
            case 0xdb: __decode_string(L, buf, off, __read_uint32(buf, off)); break;     // str32

            // case 0xc4: __decode_string(L, buf, off, __read_uint8(buf, off));  break;     // bin8
            // case 0xc5: __decode_string(L, buf, off, __read_uint16(buf, off)); break;     // bin16
            // case 0xc6: __decode_string(L, buf, off, __read_uint32(buf, off)); break;     // bin32

            case 0xdc: __decode_array(L, buf, off, __read_uint16(buf, off)); break;     // array16
            case 0xdd: __decode_array(L, buf, off, __read_uint32(buf, off)); break;     // array32

            case 0xde: __decode_map(L, buf, off, __read_uint16(buf, off)); break;       // map16
            case 0xdf: __decode_map(L, buf, off, __read_uint32(buf, off)); break;       // map32

            // case 0xd4: __decode_ext(L, buf, off, 1); break;
            // case 0xd5: __decode_ext(L, buf, off, 2); break;
            // case 0xd6: __decode_ext(L, buf, off, 4); break;
            // case 0xd7: __decode_ext(L, buf, off, 8); break;
            // case 0xd8: __decode_ext(L, buf, off, 16); break;
            // case 0xc7: __decode_ext(L, buf, off, __read_uint8(buf, off));  break;
            // case 0xc8: __decode_ext(L, buf, off, __read_uint16(buf, off)); break;
            // case 0xc9: __decode_ext(L, buf, off, __read_uint32(buf, off)); break;

            default:
                printf("Unsupported type: 0x%02x\n", b);
        }
    }
}

#endif // RPROFREP_LUA_MSGPACK_H