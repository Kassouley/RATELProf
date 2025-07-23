#ifndef RATELPROF_MACRO_H
#define RATELPROF_MACRO_H

#define EXPAND_API_PREFIX_ID(func)           ADD_API_PREFIX(ID_##func)

#define RATELPROF_API_ID(func)               EXPAND_API_PREFIX_ID(func),

#define RATELPROF_GET_FUNAME_BY_ID_OF(func)  case EXPAND_API_PREFIX_ID(func): return #func;

#define RATELPROF_GET_FUNID_BY_NAME_OF(func) else if (strcmp(name, #func) == 0) return EXPAND_API_PREFIX_ID(func);

#define RATELPROF_GET_FUNADDR_BY_ID_OF(func) case EXPAND_API_PREFIX_ID(func): return i_##func;

#endif