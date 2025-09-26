#include <lua.h>
#include <lauxlib.h>
#include "lua_compatibility.h"
#include <stdlib.h>
#include <string.h>

extern char *__cxa_demangle(const char *mangled_name,
                            char *output_buffer,
                            size_t *length,
                            int *status);


static char *strip_parameters(const char *demangled) {
    if (!demangled) return NULL;

    const char *paren = strchr(demangled, '(');
    if (!paren) {
        return strdup(demangled);
    }

    size_t len = (size_t)(paren - demangled);
    char *stripped = malloc(len + 1);
    if (!stripped) return NULL;

    strncpy(stripped, demangled, len);
    stripped[len] = '\0';
    return stripped;
}

static char *demangle(const char *mangled, int no_param) {
    int status = 0;
    char *demangled = __cxa_demangle(mangled, NULL, NULL, &status);

    if (status == 0 && demangled != NULL) {
        if (no_param) {
            char *result = strip_parameters(demangled);
            free(demangled);
            return result;
        }
        return demangled;
    }

    return strdup(mangled);
}

// Lua: demangle(mangled)
static int lua_demangle(lua_State *L) {
    const char *mangled = luaL_checkstring(L, 1);
    int no_param        = lua_toboolean(L, 2);

    char *result = demangle(mangled, no_param);
    lua_pushstring(L, result);
    free(result);
    return 1;
}


// Register functions
int luaopen_demangle(lua_State *L) {
    luaL_Reg funcs[] = {
        {"demangle", lua_demangle},
        {NULL, NULL}
    };

    luaL_register(L, "demangle", funcs);
    return 1;
}
