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
    if (msgpack_encode_int(buf, value) != 0)
        return luaL_error(L, "msgpack_encode_int failed");
    return 0;
}

/* Lua: buf:encode_uint(value) */
static int l_msgpack_encode_uint(lua_State *L) {
    msgpack_buffer_t *buf = check_buffer(L, 1);
    uint64_t value = (uint64_t)luaL_checkinteger(L, 2);
    if (msgpack_encode_uint(buf, value) != 0)
        return luaL_error(L, "msgpack_encode_uint failed");
    return 0;
}

/* Lua: buf:encode_float(value) */
static int l_msgpack_encode_float(lua_State *L) {
    msgpack_buffer_t *buf = check_buffer(L, 1);
    float value = (float)luaL_checknumber(L, 2);
    if (msgpack_encode_float(buf, value) != 0)
        return luaL_error(L, "msgpack_encode_float failed");
    return 0;
}

/* Lua: buf:encode_double(value) */
static int l_msgpack_encode_double(lua_State *L) {
    msgpack_buffer_t *buf = check_buffer(L, 1);
    double value = luaL_checknumber(L, 2);
    if (msgpack_encode_double(buf, value) != 0)
        return luaL_error(L, "msgpack_encode_double failed");
    return 0;
}

/* Lua: buf:encode_bool(value) */
static int l_msgpack_encode_bool(lua_State *L) {
    msgpack_buffer_t *buf = check_buffer(L, 1);
    bool value = lua_toboolean(L, 2);
    if (msgpack_encode_bool(buf, value) != 0)
        return luaL_error(L, "msgpack_encode_bool failed");
    return 0;
}

/* Lua: buf:encode_nil() */
static int l_msgpack_encode_nil(lua_State *L) {
    msgpack_buffer_t *buf = check_buffer(L, 1);
    if (msgpack_encode_nil(buf) != 0)
        return luaL_error(L, "msgpack_encode_nil failed");
    return 0;
}

/* Lua: buf:encode_string(value) */
static int l_msgpack_encode_string(lua_State *L) {
    msgpack_buffer_t *buf = check_buffer(L, 1);
    const char *str = luaL_checkstring(L, 2);
    if (msgpack_encode_string(buf, str) != 0)
        return luaL_error(L, "msgpack_encode_string failed");
    return 0;
}

/* Lua: buf:encode_array(count) */
static int l_msgpack_encode_array(lua_State *L) {
    msgpack_buffer_t *buf = check_buffer(L, 1);
    size_t count = (size_t)luaL_checkinteger(L, 2);
    if (msgpack_encode_array(buf, count) != 0)
        return luaL_error(L, "msgpack_encode_array failed");
    return 0;
}

/* Lua: buf:encode_map(count) */
static int l_msgpack_encode_map(lua_State *L) {
    msgpack_buffer_t *buf = check_buffer(L, 1);
    size_t count = (size_t)luaL_checkinteger(L, 2);
    if (msgpack_encode_map(buf, count) != 0)
        return luaL_error(L, "msgpack_encode_map failed");
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


/* Lua: buf:tostring() -- returns the raw buffer data as Lua string */
static int l_msgpack_tostring(lua_State *L) {
    msgpack_buffer_t *buf = check_buffer(L, 1);
    lua_pushlstring(L, (const char *)buf->data, buf->size);
    return 1;
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

/* Garbage collector metamethod */
static int l_msgpack_gc(lua_State *L) {
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


static int lmsgpack_to_hex(lua_State *L) {
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


static int lmsgpack_to_b64(lua_State *L) {
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

static int lmsgpack_write(lua_State *L) {
    msgpack_buffer_t *buf = (msgpack_buffer_t *)luaL_checkudata(L, 1, LUA_MSGPACK_BUFFER);
    int res = msgpack_write(buf);
    lua_pushboolean(L, res == 0);
    return 1;
}

static int lmsgpack_concat(lua_State *L) {
    msgpack_buffer_t *dst = (msgpack_buffer_t *)luaL_checkudata(L, 1, LUA_MSGPACK_BUFFER);
    msgpack_buffer_t *src = (msgpack_buffer_t *)luaL_checkudata(L, 2, LUA_MSGPACK_BUFFER);
    int res = msgpack_concat(dst, src);
    lua_pushboolean(L, res == 0);
    return 1;
}


static const luaL_Reg msgpack_methods[] = {
    {"free", l_msgpack_free},
    {"encode_int", l_msgpack_encode_int},
    {"encode_uint", l_msgpack_encode_uint},
    {"encode_float", l_msgpack_encode_float},
    {"encode_double", l_msgpack_encode_double},
    {"encode_bool", l_msgpack_encode_bool},
    {"encode_nil", l_msgpack_encode_nil},
    {"encode_string", l_msgpack_encode_string},
    {"encode_array", l_msgpack_encode_array},
    {"encode_map", l_msgpack_encode_map},
    {"encode_ext", l_msgpack_encode_ext},
    {"tostring", l_msgpack_tostring},
    {"size", l_msgpack_size},
    {"capacity", l_msgpack_capacity},
    {"write", lmsgpack_write},
    {"concat", lmsgpack_concat},
    {"to_hex", lmsgpack_to_hex},
    {"to_b64", lmsgpack_to_b64},
    {NULL, NULL}
};

static const luaL_Reg msgpack_meta[] = {
    {"__gc", l_msgpack_gc},
    {"__tostring", l_msgpack_tostring},
    {NULL, NULL}
};

/* Module function to create a new buffer */
static int l_msgpack_create(lua_State *L) {
    return l_msgpack_new(L);
}

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
    lua_pushinteger(L, MSGPACK_OVERFLOW_REALLOC);
    lua_setfield(L, -2, "OVERFLOW_REALLOC");
    lua_pushinteger(L, MSGPACK_OVERFLOW_WRITE_TO_FILE);
    lua_setfield(L, -2, "OVERFLOW_WRITE_TO_FILE");
    lua_pushinteger(L, MSGPACK_OVERFLOW_APPEND_TO_FILE);
    lua_setfield(L, -2, "OVERFLOW_APPEND_TO_FILE");
    lua_pushinteger(L, MSGPACK_OVERFLOW_WRITE_B64_TO_FILE);
    lua_setfield(L, -2, "OVERFLOW_WRITE_B64_TO_FILE");
    lua_pushinteger(L, MSGPACK_OVERFLOW_APPEND_B64_TO_FILE);
    lua_setfield(L, -2, "OVERFLOW_APPEND_B64_TO_FILE");

    return 1;
}
