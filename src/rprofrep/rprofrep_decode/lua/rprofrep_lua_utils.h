#ifndef RPROFREP_LUA_UTILS_H
#define RPROFREP_LUA_UTILS_H

#include <lua.h>
#include <lauxlib.h>


#define RPROFREP_CONTEXT_CLASS  "rprofrep.context"
#define RPROFREP_ITERATOR_CLASS "rprofrep.iterator"
#define RPROFREP_EVENT_CLASS    "rprofrep.event"


#define register_class_method(class, fname) {#fname, l_##class##_##fname}


#define rprofrep_lua_error(L, fmt, ...) luaL_error(L, "rprofrep: " fmt, ##__VA_ARGS__)


static inline void *luaL_checklightuserdata(lua_State *L, int idx) {
    if (!lua_islightuserdata(L, idx)) {
        luaL_error(L, "argument %d must be lightuserdata", idx);
        return NULL;
    }
    return lua_touserdata(L, idx);
}

#define rprofrep_lua_get_node(L, pos) (rprofrep_tree_node_t*) luaL_checklightuserdata(L, pos)


static inline int rprofrep_lua_get_callback(lua_State *L, int pos)
{
    luaL_checktype(L, pos, LUA_TFUNCTION);
    lua_pushvalue(L, pos);
    return luaL_ref(L, LUA_REGISTRYINDEX);
}


#define __rprofrep_lua_get(L, pos, type, name) (type*)luaL_checkudata(L, pos, name) \

#define rprofrep_lua_get_context(L, pos)  __rprofrep_lua_get(L, pos, rprofrep_decode_context_t, RPROFREP_CONTEXT_CLASS)
#define rprofrep_lua_get_iterator(L, pos) __rprofrep_lua_get(L, pos, rprofrep_event_iterator_t, RPROFREP_ITERATOR_CLASS)
#define rprofrep_lua_get_event(L, pos)    __rprofrep_lua_get(L, pos, rprofrep_event_data_t,     RPROFREP_EVENT_CLASS)



static inline void* __rprofrep_lua_new(lua_State *L, size_t size, const char* metatable) {
    void* ud = lua_newuserdata(L, size);
    luaL_getmetatable(L, metatable);
    lua_setmetatable(L, -2);
    return ud;
}

#define rprofrep_lua_new_context(L)  (rprofrep_decode_context_t*) __rprofrep_lua_new(L, sizeof(rprofrep_decode_context_t), RPROFREP_CONTEXT_CLASS)
#define rprofrep_lua_new_iterator(L) (rprofrep_event_iterator_t*) __rprofrep_lua_new(L, sizeof(rprofrep_event_iterator_t), RPROFREP_ITERATOR_CLASS)
#define rprofrep_lua_new_event(L)    (rprofrep_event_data_t*)     __rprofrep_lua_new(L, sizeof(rprofrep_event_data_t),     RPROFREP_EVENT_CLASS)


#define rprofrep_lua_create_class(L, class) do {     \
    luaL_newmetatable(L, "rprofrep." #class);         \
    luaL_register(L, NULL, l_##class##_metamethods);  \
    lua_newtable(L);                                  \
    luaL_register(L, NULL, l_##class##_methods);      \
    lua_setfield(L, -2, "__index");                   \
    lua_pop(L, 1);                                    \
} while(0)


#define rprofrep_lua_push_map_val(L, type, key, val) lua_pushstring(L, key); lua_push##type(L, val); lua_settable(L, -3)
#define rprofrep_lua_push_arr_val(L, type, idx, val) lua_push##type(L, val); lua_rawseti(L, -2, idx)

#define rprofrep_lua_check(L, call, fmt, ...) do { \
    rprofrep_status_t _s = call; \
    if (!rprofrep_status_is_success(_s)) { \
        rprofrep_log_status(_s); \
        return rprofrep_lua_error(L, fmt, ##__VA_ARGS__); \
    } \
} while(0)

typedef struct {
    const char *name;
    int value;
} rprofrep_lua_enum_Reg;

static inline void rprofrep_lua_register_enum(lua_State *L, const rprofrep_lua_enum_Reg *l) {
    lua_newtable(L);
    for (int i = 0; l[i].name != NULL; i++) {
        lua_pushinteger(L, l[i].value);
        lua_setfield(L, -2, l[i].name);
    }
    lua_setfield(L, -2, "enum");
}

#endif // RPROFREP_LUA_UTILS_H