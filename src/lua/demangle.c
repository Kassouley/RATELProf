#include <lua.h>
#include <lauxlib.h>
#include <stdlib.h>
#include <string.h>

extern char *__cxa_demangle(const char *mangled_name,
                            char *output_buffer,
                            size_t *length,
                            int *status);

static char *strip_parameters(char *demangled) {
    if (!demangled) return NULL;

    char *paren = strrchr(demangled, '(');
    if (paren)
        *paren = '\0';

    return demangled;
}

static char *demangle(const char *mangled, int no_param) {
    int status;
    char *demangled = __cxa_demangle(mangled, NULL, NULL, &status);

    if (status == 0 && demangled) {
        return no_param ? strip_parameters(demangled) : demangled;
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
