#ifndef LUA_COMPATIBILITY_H
#define LUA_COMPATIBILITY_H

#include <lua.h>
#include <lauxlib.h>

// Macro for backward compatibility using luaL_newlib
#if LUA_VERSION_NUM >= 502
#define luaL_register(L, name, funcs) luaL_newlib(L, funcs)
#endif

#endif // LUA_COMPATIBILITY_H