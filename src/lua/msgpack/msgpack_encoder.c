#include <lua.h>
#include <lauxlib.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "msgpack.h"

/* Lua userdata name */
#define LUA_MSGPACK_BUFFER "msgpack_buffer"

/* Helper to check and get userdata */
static msgpack_buffer_t* check_buffer(lua_State *L, int idx) {
    return (msgpack_buffer_t*)luaL_checkudata(L, idx, LUA_MSGPACK_BUFFER);
}


/* Lua: buf:free() */
static int l_msgpack_free(lua_State *L) {
    msgpack_buffer_t *buf = check_buffer(L, 1);
    msgpack_free(buf);
    return 0;
}

/* Lua: buf:encode_int(value) */
static int l_msgpack_encode_int(lua_State *L) {
    msgpack_buffer_t *buf = check_buffer(L, 1);
    int64_t value = (int64_t)luaL_checkinteger(L, 2);
    msgpack_encode_int(buf, value);
    return 0;
}

/* Lua: buf:encode_uint(value) */
static int l_msgpack_encode_uint(lua_State *L) {
    msgpack_buffer_t *buf = check_buffer(L, 1);
    uint64_t value = (uint64_t)luaL_checkinteger(L, 2);
    msgpack_encode_uint(buf, value);
    return 0;
}

/* Lua: buf:encode_float(value) */
static int l_msgpack_encode_float(lua_State *L) {
    msgpack_buffer_t *buf = check_buffer(L, 1);
    float value = (float)luaL_checknumber(L, 2);
    msgpack_encode_float(buf, value);
    return 0;
}

/* Lua: buf:encode_double(value) */
static int l_msgpack_encode_double(lua_State *L) {
    msgpack_buffer_t *buf = check_buffer(L, 1);
    double value = luaL_checknumber(L, 2);
    msgpack_encode_double(buf, value);
    return 0;
}

/* Lua: buf:encode_bool(value) */
static int l_msgpack_encode_bool(lua_State *L) {
    msgpack_buffer_t *buf = check_buffer(L, 1);
    bool value = lua_toboolean(L, 2);
    msgpack_encode_bool(buf, value);
    return 0;
}

/* Lua: buf:encode_nil() */
static int l_msgpack_encode_nil(lua_State *L) {
    msgpack_buffer_t *buf = check_buffer(L, 1);
    msgpack_encode_nil(buf);
    return 0;
}

/* Lua: buf:encode_string(value) */
static int l_msgpack_encode_string(lua_State *L) {
    msgpack_buffer_t *buf = check_buffer(L, 1);
    const char *str = luaL_checkstring(L, 2);
    msgpack_encode_string(buf, str);
    return 0;
}

/* Lua: buf:encode_array(count) */
static int l_msgpack_encode_array(lua_State *L) {
    msgpack_buffer_t *buf = check_buffer(L, 1);
    size_t count = (size_t)luaL_checkinteger(L, 2);
    msgpack_encode_array(buf, count);
    return 0;
}

/* Lua: buf:encode_map(count) */
static int l_msgpack_encode_map(lua_State *L) {
    msgpack_buffer_t *buf = check_buffer(L, 1);
    size_t count = (size_t)luaL_checkinteger(L, 2);
    msgpack_encode_map(buf, count);
    return 0;
}

/* Lua: buf:encode_ext(type, data) */
static int l_msgpack_encode_ext(lua_State *L) {
    msgpack_buffer_t *buf = luaL_checkudata(L, 1, "msgpack_buffer");
    int type = luaL_checkinteger(L, 2);

    size_t len;
    const uint8_t *data_ptr = NULL;

    if (lua_type(L, 3) == LUA_TUSERDATA) {
        msgpack_buffer_t *src_buf = luaL_checkudata(L, 3, "msgpack_buffer");
        data_ptr = src_buf->data;
        len = src_buf->size;
    } else {
        const char *str = luaL_checklstring(L, 3, &len);
        data_ptr = (const uint8_t *)str;
    }

    if (len > 0xffffffff) {
        return luaL_error(L, "data too long for msgpack ext");
    }

    msgpack_encode_ext(buf, (int8_t)type, data_ptr, len);
    return 0;
}

/* Lua: buf:push_byte(byte) */
static int l_msgpack_push_byte(lua_State *L) {
    msgpack_buffer_t *buf = check_buffer(L, 1);
    uint8_t byte = (uint8_t)luaL_checkinteger(L, 2);
    msgpack_push_byte(buf, byte);
    return 0;
}

/* Lua: buf:push_bytes(str) */
static int l_msgpack_push_bytes(lua_State *L) {
    msgpack_buffer_t *buf = check_buffer(L, 1);
    size_t len;
    uint8_t* data = (uint8_t *)luaL_checklstring(L, 2, &len);
    msgpack_push_bytes(buf, data, len);
    return 0;
}

/* Lua: buf:size() */
static int l_msgpack_size(lua_State *L) {
    msgpack_buffer_t *buf = check_buffer(L, 1);
    lua_pushinteger(L, (lua_Integer)msgpack_size(buf));
    return 1;
}

/* Lua: buf:capacity() */
static int l_msgpack_capacity(lua_State *L) {
    msgpack_buffer_t *buf = check_buffer(L, 1);
    lua_pushinteger(L, (lua_Integer)buf->capacity);
    return 1;
}

/* Lua: buf:tostring() -- returns the raw buffer data as Lua string */
static int l_msgpack_tostring(lua_State *L) {
    msgpack_buffer_t *buf = check_buffer(L, 1);
    lua_pushlstring(L, (const char *)buf->data, buf->size);
    return 1;
}

/* Garbage collector metamethod */
static int l_msgpack___gc(lua_State *L) {
    msgpack_buffer_t *buf = check_buffer(L, 1);
    msgpack_free(buf);
    return 0;
}

/* Lua: buf = msgpack_encoder.new(capacity, mode, filename) */
static int l_msgpack_new(lua_State *L) {
    size_t capacity = luaL_checkinteger(L, 1);
    int mode = luaL_checkinteger(L, 2);
    const char *filename = NULL;
    if (MSGPACK_IS_FILE_MODE(mode)) {
        luaL_checktype(L, 3, LUA_TSTRING);
        filename = lua_tostring(L, 3);
    }

    msgpack_buffer_t *buf = (msgpack_buffer_t *)lua_newuserdata(L, sizeof(msgpack_buffer_t));
    memset(buf, 0, sizeof(msgpack_buffer_t));
    
    if (msgpack_init(buf, capacity, mode, filename) != 0) {
        return luaL_error(L, "failed to initialize msgpack buffer");
    }

    luaL_getmetatable(L, "msgpack_buffer");
    lua_setmetatable(L, -2);
    return 1;
}


static int l_msgpack_to_hex(lua_State *L) {
    msgpack_buffer_t *buf = (msgpack_buffer_t *)luaL_checkudata(L, 1, LUA_MSGPACK_BUFFER);

    if (!buf->data || buf->size == 0) {
        lua_pushstring(L, "");
        return 1;
    }

    size_t hex_len = buf->size * 2;
    char *hex_str = (char *)malloc(hex_len + 1);
    if (!hex_str) {
        return luaL_error(L, "memory allocation failed in to_hex");
    }

    static const char hex_chars[] = "0123456789abcdef";
    for (size_t i = 0; i < buf->size; ++i) {
        hex_str[i * 2]     = hex_chars[(buf->data[i] >> 4) & 0xF];
        hex_str[i * 2 + 1] = hex_chars[buf->data[i] & 0xF];
    }

    hex_str[hex_len] = '\0';
    lua_pushstring(L, hex_str);
    free(hex_str);
    return 1;
}


static int l_msgpack_to_b64(lua_State *L) {
    msgpack_buffer_t *buf = (msgpack_buffer_t *)luaL_checkudata(L, 1, LUA_MSGPACK_BUFFER);

    if (!buf->data || buf->size == 0) {
        lua_pushstring(L, "");
        return 1;
    }

    size_t b64_len;
    char *b64_str = msgpack_to_b64(buf, &b64_len);
    if (!b64_str) {
        return luaL_error(L, "memory allocation failed in to_b64");
    }

    lua_pushlstring(L, b64_str, b64_len);

    free(b64_str);
    return 1;
}

static int l_msgpack_write(lua_State *L) {
    msgpack_buffer_t *buf = (msgpack_buffer_t *)luaL_checkudata(L, 1, LUA_MSGPACK_BUFFER);
    int res = msgpack_write(buf);
    lua_pushboolean(L, res == 0);
    return 1;
}

static int l_msgpack_concat(lua_State *L) {
    msgpack_buffer_t *dst = (msgpack_buffer_t *)luaL_checkudata(L, 1, LUA_MSGPACK_BUFFER);
    msgpack_buffer_t *src = (msgpack_buffer_t *)luaL_checkudata(L, 2, LUA_MSGPACK_BUFFER);
    msgpack_concat(dst, src);
    return 1;
}

#define register_method(fname) {#fname, l_msgpack_##fname}

static const luaL_Reg msgpack_methods[] = {
    register_method(free),
    register_method(encode_int),
    register_method(encode_uint),
    register_method(encode_float),
    register_method(encode_double),
    register_method(encode_bool),
    register_method(encode_nil),
    register_method(encode_string),
    register_method(encode_array),
    register_method(encode_map),
    register_method(encode_ext),
    register_method(push_byte),
    register_method(push_bytes),
    register_method(tostring),
    register_method(size),
    register_method(capacity),
    register_method(write),
    register_method(concat),
    register_method(to_hex),
    register_method(to_b64),
    {NULL, NULL}
};

static const luaL_Reg msgpack_meta[] = {
    register_method(__gc),
    {"__tostring", l_msgpack_tostring},
    {NULL, NULL}
};

/* Module function to create a new buffer */
static int l_msgpack_create(lua_State *L) {
    return l_msgpack_new(L);
}

#define export_enum(enum) \
    lua_pushinteger(L, MSGPACK_##enum); \
    lua_setfield(L, -2, #enum);

int luaopen_msgpack_encoder(lua_State *L) {
    /* Create MsgpackBuffer metatable */
    luaL_newmetatable(L, LUA_MSGPACK_BUFFER);
    luaL_register(L, NULL, msgpack_meta);
    lua_newtable(L);
    luaL_register(L, NULL, msgpack_methods);
    lua_setfield(L, -2, "__index");
    lua_pop(L, 1);

    /* Module table */
    lua_newtable(L);
    lua_pushcfunction(L, l_msgpack_create);
    lua_setfield(L, -2, "new");

    /* Export overflow modes as constants */
    export_enum(OVERFLOW_REALLOC)
    export_enum(OVERFLOW_WRITE_TO_FILE)
    export_enum(OVERFLOW_APPEND_TO_FILE)
    export_enum(OVERFLOW_WRITE_B64_TO_FILE)
    export_enum(OVERFLOW_APPEND_B64_TO_FILE)
    return 1;
}
