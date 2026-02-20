#include <lua.h>
#include <lauxlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rprofrep_decode.h"
#include "rprofrep_lua_utils.h"
#include "rprofrep_lua_msgpack.h"


/* ------------------------------------------------------------------------------------ */
/*                                    EVENT CLASS                                       */
/* ------------------------------------------------------------------------------------ */

// #define is(key, field) (strcmp(key, #field) == 0)

// static int l_event___index(lua_State *L) {
//     rprofrep_event_data_t *e = rprofrep_lua_get_event(L, 1);
//     const char *key = luaL_checkstring(L, 2);

//     printf("l_event___index: key='%s'\n", key);

//          if (is(key, name))     { lua_pushstring(L, e->name);     } 
//     else if (is(key, rank))     { lua_pushnumber(L, e->rank);     } 
//     else if (is(key, domain))   { lua_pushnumber(L, e->domain);   } 
//     else if (is(key, unit))     { lua_pushnumber(L, e->unit);     } 
//     else if (is(key, pid))      { lua_pushnumber(L, e->unit);     } 
//     else if (is(key, gpu_id))   { lua_pushnumber(L, e->unit);     } 
//     else if (is(key, sub_unit)) { lua_pushnumber(L, e->sub_unit); } 
//     else if (is(key, tid))      { lua_pushnumber(L, e->sub_unit); } 
//     else if (is(key, queue_id)) { lua_pushnumber(L, e->sub_unit); } 
//     else if (is(key, sdma_id))  { lua_pushnumber(L, e->sub_unit); } 
//     else if (is(key, phase))    { lua_pushnumber(L, e->phase);    } 
//     else if (is(key, id))       { lua_pushnumber(L, e->id);       } 
//     else if (is(key, start))    { lua_pushnumber(L, e->start);    } 
//     else if (is(key, dur))      { lua_pushnumber(L, e->dur);      } 
//     else if (is(key, stop))     { lua_pushnumber(L, e->start + e->dur); } 
//     else if (is(key, args)) { 
//         uint64_t off = 0;
//         uint64_t nargs = 0;
//         char** args_labels = rprofrep_get_event_args_labels(e, &nargs);

//         lua_newtable(L);                               
//         for (size_t i = 0; i < nargs; i++) {   
//             lua_pushstring(L, args_labels[i]);
//             __decode_msgpack(L, e->args, &off);
//             lua_settable(L, -3);                       
//         } 
//     } else { lua_pushnil(L); }
//     return 1;
// }


// static const struct luaL_Reg l_event_metamethods[] = {
//     register_class_method(event, __index),
//     {NULL, NULL}
// };

// static const struct luaL_Reg l_event_methods[] = {
//     {NULL, NULL}
// };

#define SET_GETTER(fct, field, type) \
static int l_event_##fct(lua_State *L) { \
    rprofrep_event_data_t *e = rprofrep_lua_get_event(L, 1); \
    lua_push##type(L, e->field); \
    return 1; \
} 

SET_GETTER(name,     name,      string)
SET_GETTER(rank,     rank,      number)
SET_GETTER(domain,   domain,    number)
SET_GETTER(unit,     unit,      number)
SET_GETTER(pid,      unit,      number)
SET_GETTER(gpu_id,   unit,      number)
SET_GETTER(sub_unit, sub_unit,  number)
SET_GETTER(tid,      sub_unit,  number)
SET_GETTER(queue_id, sub_unit,  number)
SET_GETTER(sdma_id,  sub_unit,  number)
SET_GETTER(phase,    phase,     number)
SET_GETTER(id,       id,        number)
SET_GETTER(start,    start,     number)
SET_GETTER(dur,      dur,       number)


static int l_event_stop(lua_State *L) {
    rprofrep_event_data_t *e = rprofrep_lua_get_event(L, 1);
    lua_pushnumber(L, e->start + e->dur);
    return 1;
} 

static int l_event_args(lua_State *L) {
    rprofrep_event_data_t *e = rprofrep_lua_get_event(L, 1);
    uint64_t off = 0;
    uint64_t nargs = 0;
    char** args_labels = rprofrep_get_event_args_labels(e, &nargs);

    lua_newtable(L);                               
    for (size_t i = 0; i < nargs; i++) {   
        lua_pushstring(L, args_labels[i]);
        __decode_msgpack(L, e->args, &off);
        lua_settable(L, -3);                       
    } 
    return 1;
} 
#undef SET_GETTER


static const struct luaL_Reg l_event_metamethods[] = {
    {NULL, NULL}
};

static const struct luaL_Reg l_event_methods[] = {
    register_class_method(event, name),
    register_class_method(event, rank),
    register_class_method(event, domain),
    register_class_method(event, unit),
    register_class_method(event, pid),
    register_class_method(event, gpu_id),
    register_class_method(event, sub_unit),
    register_class_method(event, tid),
    register_class_method(event, queue_id),
    register_class_method(event, sdma_id),
    register_class_method(event, phase),
    register_class_method(event, id),
    register_class_method(event, start),
    register_class_method(event, dur),
    register_class_method(event, stop),
    register_class_method(event, args),
    {NULL, NULL}
};


/* ------------------------------------------------------------------------------------ */
/*                                   ITERATOR CLASS                                     */
/* ------------------------------------------------------------------------------------ */

// __gc metamethod
static int l_iterator___gc(lua_State *L)
{
    rprofrep_event_iterator_t *it = rprofrep_lua_get_iterator(L, 1);
    rprofrep_lua_check(L, rprofrep_event_iterator_destroy(it), "failed to free iterator");
    return 0;
}


static int l_iterator_next(lua_State *L) 
{
    rprofrep_event_iterator_t* it = rprofrep_lua_get_iterator(L, 1);
    rprofrep_event_data_t* event = NULL;
    rprofrep_event_data_t tmp = {0};

    rprofrep_lua_check(L, rprofrep_event_iterator_next(it, &tmp), "failed to get next event");

    if (!tmp.valid) {
        lua_pushnil(L);
        return 1;
    } 

    event = rprofrep_lua_new_event(L);
    *event = tmp;

    return 1;
}

static int l_iterator_count_events(lua_State *L) 
{
    rprofrep_event_iterator_t* it = rprofrep_lua_get_iterator(L, 1);
    size_t count = 0;

    rprofrep_lua_check(L, rprofrep_event_iterator_count_events(it, &count), "failed to count events");

    lua_pushnumber(L, count);

    return 1;
}

static const struct luaL_Reg l_iterator_metamethods[] = {
    register_class_method(iterator, __gc),
    {NULL, NULL}
};

static const struct luaL_Reg l_iterator_methods[] = {
    register_class_method(iterator, next),
    register_class_method(iterator, count_events),
    {NULL, NULL}
};

/* ------------------------------------------------------------------------------------ */
/*                                   CONTEXT CLASS                                      */
/* ------------------------------------------------------------------------------------ */


// __gc metamethod
static int l_context___gc(lua_State *L) {
    rprofrep_decode_context_t *ctx = rprofrep_lua_get_context(L, 1);
    rprofrep_lua_check(L, rprofrep_decode_context_free(ctx), "failed to free context");
    return 0;
}

// utils functions

/**
 * Converts a Lua table at the given stack index to rprofrep_event_filter_t.
 * If no table is provided (nil or no argument), returns NULL.
 * Otherwise, returns a pointer to a statically allocated filter (caller can copy it).
 */
static rprofrep_event_filter_t* rprofrep_lua_get_filter(lua_State *L, int index)
{
    if (lua_isnoneornil(L, index)) {
        return NULL;
    }

    luaL_checktype(L, index, LUA_TTABLE);

    rprofrep_event_filter_t* filter = (rprofrep_event_filter_t*)malloc(sizeof(rprofrep_event_filter_t));
    if (!filter) {
        rprofrep_lua_error(L, "Memory allocation failed");
        return NULL;
    }

    // Helper macros
    #define READ_UINT64_FIELD(name) do { \
        lua_getfield(L, index, #name); \
        if (!lua_isnil(L, -1)) filter->name = (uint64_t)luaL_checkinteger(L, -1); \
        else filter->name = 0; \
        lua_pop(L, 1); \
    } while(0)

    #define READ_BOOL_FIELD(name) do { \
        lua_getfield(L, index, #name); \
        if (!lua_isnil(L, -1)) filter->name = lua_toboolean(L, -1); \
        else filter->name = false; \
        lua_pop(L, 1); \
    } while(0)

    READ_UINT64_FIELD(phase);
    READ_UINT64_FIELD(start);
    READ_UINT64_FIELD(stop);
    READ_UINT64_FIELD(dur);

    READ_BOOL_FIELD(phase_EQ);
    READ_BOOL_FIELD(start_GT);
    READ_BOOL_FIELD(start_LT);
    READ_BOOL_FIELD(stop_GT);
    READ_BOOL_FIELD(stop_LT);
    READ_BOOL_FIELD(dur_GT);
    READ_BOOL_FIELD(dur_LT);

    #undef READ_UINT64_FIELD
    #undef READ_BOOL_FIELD

    return filter;
}

// callback function
static rprofrep_status_t run_lua_callback_on_tree(rprofrep_decode_context_t* ctx, rprofrep_tree_node_t* node, void* user_args) 
{
    lua_State* L = ((lua_State**) user_args)[0];
    int* cb      = ((int**) user_args)[1];

    lua_rawgeti(L, LUA_REGISTRYINDEX, *cb);

    int64_t value = (int64_t) node->value;

    lua_pushnumber(L, value);               // arg1
    lua_pushlightuserdata(L, (void *)node); // arg2

    // Call Lua function with 2 args, 0 results
    if (lua_pcall(L, 2, 0, 0) != 0) {
        // Handle Lua error
        const char *err = lua_tostring(L, -1);
        lua_pop(L, 1); // remove error message
        return RPROFREP_STATUS_ERROR("lua callback - %s\n", err);
    }
    return RPROFREP_STATUS_SUCCESS;
}


// Method: ctx:for_each_sub_unit(list: handles, handles_count, callback)
static int l_context_for_each_sub_unit(lua_State *L)
{
    rprofrep_decode_context_t *ctx  = rprofrep_lua_get_context(L, 1);
    rprofrep_tree_node_t* unit_node = rprofrep_lua_get_node(L, 2);
    int cb = rprofrep_lua_get_callback(L, 3);

    rprofrep_lua_check(L, rprofrep_for_each_subunit(ctx, unit_node, run_lua_callback_on_tree, (void*[2]){L, &cb}), 
        "Failed to iterate over sub units");

    return 0;
}



// Method: ctx:for_each_pid(list: domains, callback)
static int l_context_for_each_pid(lua_State *L)
{
    rprofrep_decode_context_t *ctx = rprofrep_lua_get_context(L, 1);
    int cb = rprofrep_lua_get_callback(L, 2);

    rprofrep_lua_check(L, rprofrep_for_each_pid(ctx, run_lua_callback_on_tree, (void*[2]){L, &cb}), 
        "Failed to iterate over units");

    return 0;
}


// Method: ctx:for_each_gpu(list: domains, callback)
static int l_context_for_each_gpu(lua_State *L)
{
    rprofrep_decode_context_t *ctx = rprofrep_lua_get_context(L, 1);
    int cb = rprofrep_lua_get_callback(L, 2);

    rprofrep_lua_check(L, rprofrep_for_each_gpu(ctx, run_lua_callback_on_tree, (void*[2]){L, &cb}), 
        "Failed to iterate over units");

    return 0;
}

static int l_context_get_iterator(lua_State *L)
{
    rprofrep_decode_context_t* ctx  = rprofrep_lua_get_context(L, 1);
    rprofrep_tree_node_t*      node = rprofrep_lua_get_node(L, 2);
    luaL_checktype(L, 3, LUA_TTABLE);
    rprofrep_event_filter_t* filter = rprofrep_lua_get_filter(L, 4);
 
    bool requested_domains[RATELPROF_NB_DOMAIN_EXT] = { false };

    int n = lua_objlen(L, 3);
    for (int i = 1; i <= n; i++) {
        // push table[i] onto stack
        lua_rawgeti(L, 3, i);
        uint64_t domain_requested = luaL_checknumber(L, -1);
        requested_domains[domain_requested] = true;
        // pop value
        lua_pop(L, 1);
    }
  
    rprofrep_event_iterator_t tmp = {0};
    
    rprofrep_lua_check(L, rprofrep_event_iterator_init(&tmp, ctx, node, requested_domains, filter), 
        "Failed to create event iterator");

    if (tmp.initialized == false) {
        lua_pushnil(L);
    } else {
        rprofrep_event_iterator_t* iterator = rprofrep_lua_new_iterator(L);
        *iterator = tmp;
    }
    return 1;
}


static int l_context_get_rank(lua_State *L)
{
    rprofrep_decode_context_t *ctx = rprofrep_lua_get_context(L, 1);
    int64_t rank = -1;
    rprofrep_lua_check(L, rprofrep_get_rank(ctx, &rank), "Cannot get rank");
    lua_pushnumber(L, rank);
    return 1;
}

static int l_context_get_run_date(lua_State *L)
{
    rprofrep_decode_context_t* ctx = rprofrep_lua_get_context(L, 1);
    uint64_t epoch = 0;
    rprofrep_lua_check(L, rprofrep_get_experiment_time(ctx, &epoch), "Cannot get experiment time");

    char *buffer = malloc(32);
    if (!buffer) return rprofrep_lua_error(L, "Memory allocation failed");

    time_t seconds = epoch / 1000000000LL;

    struct tm tm_info;
    gmtime_r(&seconds, &tm_info);

    strftime(buffer, 32, "%Y-%m-%d %H:%M:%S", &tm_info);
    lua_pushstring(L, buffer);
    free(buffer);
    return 1;
}


static int l_context_get_run_exit_code(lua_State *L) {
    rprofrep_decode_context_t* ctx = rprofrep_lua_get_context(L, 1);
    int64_t exit_code = 0;
    rprofrep_lua_check(L, rprofrep_get_exit_code(ctx, &exit_code), "Cannot get command exit code");
    lua_pushnumber(L, exit_code);
    return 1;
}


static int l_context_get_run_command_line(lua_State *L) {
    rprofrep_decode_context_t* ctx = rprofrep_lua_get_context(L, 1);
    char** argv = NULL;
    uint64_t argc = 0;

    rprofrep_lua_check(L, rprofrep_get_command_line(ctx, &argv, &argc), "Cannot get command line buffer");

    size_t* len_arr = (size_t*)malloc(argc * sizeof(size_t));
    if (!len_arr) return rprofrep_lua_error(L, "Memory allocation failed");

    size_t total_len = 0;
    for (uint64_t i = 0; i < argc; i++) {
        if (argv[i]) {
            len_arr[i] = strlen(argv[i]);
            total_len += len_arr[i];
            if (i < argc - 1) total_len += 1; // for space between args
        }
    }

    char* result = (char*)malloc(total_len + 1);
    if (!result) return rprofrep_lua_error(L, "Memory allocation failed");

    char* p = result; // pointer to fill buffer
    for (uint64_t i = 0; i < argc; i++) {
        if (argv[i]) {
            size_t len = len_arr[i];
            memcpy(p, argv[i], len);
            p += len;
            if (i < argc - 1) {
                *p = ' ';
                p++;
            }
        }
    }

    *p = '\0'; // null terminate

    lua_pushstring(L, result);
    free(len_arr);
    free(result);

    return 1;
}

static int l_context_get_tool_version(lua_State *L)
{
    rprofrep_decode_context_t* ctx = rprofrep_lua_get_context(L, 1);
    uint64_t tool_version[3] = {0};
    rprofrep_lua_check(L, rprofrep_get_tool_version(ctx, tool_version), "Cannot get tool version");
    
    lua_newtable(L);
    rprofrep_lua_push_map_val(L, number, "major", tool_version[0]);
    rprofrep_lua_push_map_val(L, number, "minor", tool_version[1]);
    rprofrep_lua_push_map_val(L, number, "patch", tool_version[2]);

    return 1;
}

static int l_context_get_report_version(lua_State *L)
{
    rprofrep_decode_context_t* ctx = rprofrep_lua_get_context(L, 1);
    rprofrep_header_section_t* header = &ctx->header;
    
    lua_newtable(L);
    rprofrep_lua_push_map_val(L, number, "major", header->report_version[0]);
    rprofrep_lua_push_map_val(L, number, "minor", header->report_version[1]);
    rprofrep_lua_push_map_val(L, number, "patch", header->report_version[2]);

    return 1;
}


static int l_context_get_location(lua_State *L) {
    rprofrep_decode_context_t *ctx = rprofrep_lua_get_context(L, 1);
    rprofrep_event_data_t *e       = rprofrep_lua_get_event(L, 2);
    rprofrep_location_entry_t* loc = NULL;

    if (e->loc_id == (uint64_t)-1) {
        lua_pushnil(L);
        return 1;
    }

    rprofrep_lua_check(L, rprofrep_get_location(ctx, e->loc_id, &loc),
        "failed to get location for id '%ld'", e->loc_id);

    lua_newtable(L);

    rprofrep_lua_push_map_val(L, number, "address",        loc->return_address);
    rprofrep_lua_push_map_val(L, string, "objfile",        loc->objectfile);
    rprofrep_lua_push_map_val(L, string, "func",           loc->function);
    rprofrep_lua_push_map_val(L, string, "filename",       loc->filename);
    rprofrep_lua_push_map_val(L, number, "line",           loc->line);

    return 1;
}


static int l_context_get_correlated_event(lua_State* L) {
    rprofrep_decode_context_t *ctx = rprofrep_lua_get_context(L, 1);
    rprofrep_event_data_t *e       = rprofrep_lua_get_event(L, 2);

    if (!e->cid.valid) {
        lua_pushnil(L);
        return 1;
    } 

    rprofrep_event_data_t* cid_event = NULL;
    rprofrep_event_data_t tmp = {0};

    rprofrep_lua_check(L, rprofrep_get_event_by_cid(ctx, &e->cid, &tmp),
        "failed to get event from cid {off: %lu, group: %lu}", e->cid.offset, e->cid.group_id);

    if (!tmp.valid) {
        lua_pushnil(L);
        return 1;
    } 

    cid_event = rprofrep_lua_new_event(L);
    *cid_event = tmp;

    return 1;
}

static int l_context_find_entry_point_event(lua_State* L) {
    rprofrep_decode_context_t *ctx = rprofrep_lua_get_context(L, 1);
    rprofrep_event_data_t *e       = rprofrep_lua_get_event(L, 2);

    rprofrep_event_data_t entry_point = {0};
    rprofrep_lua_check(L, rprofrep_find_entry_point_event(ctx, e, &entry_point),
        "failed to find entry point event");

    if (!entry_point.valid) {
        lua_pushnil(L);
        return 1;
    }

    rprofrep_event_data_t* new_entry_point = rprofrep_lua_new_event(L);
    *new_entry_point = entry_point;

    return 1;
}


static int l_context_node_is_gpu(lua_State* L) {
    rprofrep_decode_context_t *ctx = rprofrep_lua_get_context(L, 1);
    uint64_t node_id = (uint64_t) luaL_checkinteger(L, 2);
    bool is_gpu = false;

    rprofrep_lua_check(L, rprofrep_node_is_gpu(ctx, node_id, &is_gpu),
        "failed to check if node %lu is GPU", node_id);

    lua_pushboolean(L, is_gpu);
    return 1;
}

static int l_context_get_gpu_id_from_agent(lua_State* L) {
    rprofrep_decode_context_t *ctx = rprofrep_lua_get_context(L, 1);
    uint64_t agent  = (uint64_t) luaL_checkinteger(L, 2);
    uint64_t gpu_id = (uint64_t) -1;

    rprofrep_lua_check(L, rprofrep_get_gpu_id_from_agent(ctx, agent, &gpu_id),
        "failed to get GPU id from agent id %lu", agent);

    lua_pushinteger(L, gpu_id);
    return 1;
}

static int l_context_get_application_time(lua_State* L) {
    rprofrep_decode_context_t *ctx = rprofrep_lua_get_context(L, 1);
    uint64_t ctime = 0;
    uint64_t mtime = 0;
    uint64_t dtime = 0;

    rprofrep_lua_check(L, rprofrep_get_constructor_time(ctx, &ctime),
        "failed to get constructor time");
    rprofrep_lua_check(L, rprofrep_get_main_time(ctx, &mtime),
        "failed to get main time");
    rprofrep_lua_check(L, rprofrep_get_destructor_time(ctx, &dtime),
        "failed to get destructor time");

    lua_pushinteger(L, ctime + mtime + dtime);
    return 1;
}

static int l_context_is_domain_traced(lua_State* L) {
    rprofrep_decode_context_t *ctx = rprofrep_lua_get_context(L, 1);
    ratelprof_domain_t domain = (ratelprof_domain_t) luaL_checkinteger(L, 2);
    bool is_traced = false;

    rprofrep_lua_check(L, rprofrep_is_domain_traced(ctx, domain, &is_traced),
        "failed to get traced domain");

    lua_pushboolean(L, is_traced);
    return 1;
}


static const struct luaL_Reg l_context_metamethods[] = {
    register_class_method(context, __gc),
    {NULL, NULL}
};


static const struct luaL_Reg l_context_methods[] = {
    register_class_method(context, get_iterator),
    register_class_method(context, for_each_gpu),
    register_class_method(context, for_each_pid),
    register_class_method(context, for_each_sub_unit),
    register_class_method(context, get_location),
    register_class_method(context, get_correlated_event),
    register_class_method(context, find_entry_point_event),
    register_class_method(context, get_tool_version),
    register_class_method(context, get_report_version),
    register_class_method(context, get_rank),
    register_class_method(context, get_run_date),
    register_class_method(context, get_run_exit_code),
    register_class_method(context, get_run_command_line),
    register_class_method(context, get_application_time),
    register_class_method(context, node_is_gpu),
    register_class_method(context, get_gpu_id_from_agent),
    register_class_method(context, is_domain_traced),
    {NULL, NULL}
};

/* ------------------------------------------------------------------------------------ */
/*                                   MODULE FUNCTIONS                                   */
/* ------------------------------------------------------------------------------------ */

// Constructor: rprofrep.new(filename)
static int l_rprofrep_decoder_lua_new(lua_State *L) {
    const char *filename = luaL_checkstring(L, 1);
    rprofrep_decode_context_t *ctx = rprofrep_lua_new_context(L);
    rprofrep_lua_check(L, rprofrep_decode_context_init(ctx, filename), "failed to load file '%s'", filename);
    return 1;
}


// Module functions
static const struct luaL_Reg l_rprofrep_decoder_lua_funcs[] = {
    {"new", l_rprofrep_decoder_lua_new},
    {NULL, NULL}
};


int luaopen_rprofrep_decoder_lua(lua_State *L) {
    // Create module classes
    rprofrep_lua_create_class(L, context);
    rprofrep_lua_create_class(L, iterator);
    rprofrep_lua_create_class(L, event);

    // Register module functions
    luaL_register(L, "rprofrep_decoder_lua", l_rprofrep_decoder_lua_funcs);

    return 1;
}