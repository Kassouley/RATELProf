local ContentManager = require("ContentManager")
local Content = require("Content")

msgpack_plugin_c = setmetatable({}, ContentManager)
msgpack_plugin_c.__index = msgpack_plugin_c

function msgpack_plugin_c:new(options, template_path, output_path)
    local attribute = {
        file_name = S:STRING("PLG_SRC"),
        do_not_gen = not options.plugin_gen and true,
        subcontents = {
            ["include_block"] = Content:new(),
            ["init_block"] = Content:new(1),
            ["get_profile_cb_block"] = Content:new(2),
            ["struct_fields"] = Content:new(1)
        } 
    }
    local instance = ContentManager:new(attribute, template_path, output_path)
    if instance then setmetatable(instance, msgpack_plugin_c) end
    return instance
end

function msgpack_plugin_c:generate_content()
    return [[
/** ]]..S:STRING("WARNING_MSG")..[[ 
 */
 
#include <]]..S:STRING("INTERCEPTOR_HDR")..[[>
#include <ratelprof_ext.h>
#include "version.h"
#include "msgpack.h"

#include "activity_plugin.h" 
]]..self.subcontents.include_block..[[ 

typedef struct {
    msgpack_buffer_t buffer;
    size_t size;
} plugin_traces_t;

typedef struct ]]..S:STRING("TOOLS_NAME")..[[_plugin_s {
]]..self.subcontents.struct_fields..[[ 
    api_callback_handler_t ompt_callback_handler;

    activity_callback_t activity_callback;
    plugin_traces_t* traces;
} ]]..S:STRING("PLG_STRUCT")..[[;


/** RATELProf Ext encoding 
 *      Encoding as follow : 
 *          - extension bytes (magic bytes)
 *          - tool version as 3 uint
 *          - experiment start epoch time as uint
 *          - lifecycle stop time as array
 *          - main data
 *          - map node id to agent object
 *          - string extension mapping
 *          - trace data
 */
static inline void encode_ratelprof_ext(ratelprof_plugin_t* p) {
    plugin_traces_t* traces = p->traces;
    
    ratelprof_lifecycle_t* lc = ratelprof_get_lifecycle();
    size_t i = 0;
    msgpack_buffer_t main_buffer;
    msgpack_init(&main_buffer, 0xff, MSGPACK_OVERFLOW_WRITE_TO_FILE, get_output_file());

    msgpack_encode_ext(&main_buffer,  MSGPACK_EXT_RATELPROF, NULL, 0);

    // Encode tool version
    msgpack_encode_array(&main_buffer, 3);
    msgpack_encode_uint(&main_buffer, RATELPROF_MAJOR);
    msgpack_encode_uint(&main_buffer, RATELPROF_MINOR);
    msgpack_encode_uint(&main_buffer, RATELPROF_PATCH);


    // Encode experiment start
    msgpack_encode_uint(&main_buffer, ratelprof_get_timestamp_ns(lc->experiment_start_epoch));

    // Encode lifecycle stop time (first start is 0 and other start are prev stop)
    msgpack_encode_array(&main_buffer, RATELPROF_NB_PHASE);
    for (i = 0; i < RATELPROF_NB_PHASE; i++)
    {
        ratelprof_time_t t = ratelprof_get_timestamp_ns(lc->phase_stop_ts[i]);
        msgpack_encode_uint(&main_buffer, ratelprof_get_normalized_time(t));
    }

    // Encode main data
    msgpack_encode_array(&main_buffer, lc->main_data.argc + 1);
    msgpack_encode_int(&main_buffer, lc->main_data.retval);
    for (i = 0; i < lc->main_data.argc; i++)
    {
        msgpack_encode_string(&main_buffer, lc->main_data.argv[i]);
    }
    

    // Encode map Node ID to Agent Object
    ratelprof_object_tracking_pool_t* pool = ratelprof_object_tracking_pool_get_pool();
    ratelprof_agent_object_t*  agents_list = pool->agents_list;
    size_t                     agents_count = pool->agents_count;

    if (agents_list && agents_count > 0) {
        msgpack_encode_map(&main_buffer, agents_count);
        for (i = 0; i < agents_count; i++) {
            msgpack_encode_uint(&main_buffer, agents_list[i].handle);
            msgpack_encode_uint(&main_buffer, i);
        }
    } else {
        msgpack_encode_map(&main_buffer, 0);
    }

    msgpack_buffer_t trace_events;
    msgpack_init(&trace_events, 0xffffff, MSGPACK_OVERFLOW_REALLOC, NULL);

    // Preprocess trace event data
    size_t nb_domain_util = 0;
    for (i = 0; i < RATELPROF_NB_DOMAIN_EXT; i++) {
        if (traces[i].size != 0)
            nb_domain_util++;
    }
    
    msgpack_encode_map(&trace_events, nb_domain_util);
    for (i = 0; i < RATELPROF_NB_DOMAIN_EXT; i++) {
        if (traces[i].size != 0) {
            msgpack_encode_string_ext(&trace_events, ratelprof_ext_get_domain_name(i));
            msgpack_encode_map(&trace_events, traces[i].size);
            msgpack_concat(&trace_events, &traces[i].buffer);
            msgpack_free(&traces[i].buffer);
        }
    }

    // Encode string extension mapping
    msgpack_encode_string_table_ext(&main_buffer);

    // Encode trace event data
    msgpack_concat(&main_buffer, &trace_events);

    msgpack_free(&main_buffer); // Write data and free
    msgpack_free(&trace_events); // Write data and free
}



]]..S:STRING("PLG_INIT_FUNC_DECL")..[[ 
{
    ]]..S:STRING("PLG_STRUCT")..[[* p = NULL;
    ]]..S:STRING("I_STATUS_TYPE")..[[ status = ]]..S:STATUS("SUCCESS")..[[;
    
    if (plugin == NULL) return ]]..S:STATUS("INVALID_PTR")..[[;
    if (*plugin != NULL) return ]]..S:STATUS("PLUGIN_INIT")..[[;
    
    p = (]]..S:STRING("PLG_STRUCT")..[[*)malloc(sizeof(]]..S:STRING("PLG_STRUCT")..[[));
    if (!p) return ]]..S:STATUS("MALLOC_FAILED")..[[;
    
]]..self.subcontents.init_block..[[ 
    p->ompt_callback_handler.on_enter = on_enter_ompt_callback;
    p->ompt_callback_handler.on_exit = on_exit_ompt_callback; 

    p->activity_callback = activity_callback; 
    
    p->traces = (plugin_traces_t*)malloc(RATELPROF_NB_DOMAIN_EXT * sizeof(plugin_traces_t));
    for (int i = 0; i < RATELPROF_NB_DOMAIN_EXT; i++) {
        p->traces[i].size = 0;
        const char* domain_name = ratelprof_ext_get_domain_name(i);
        if (is_set_domain(domain_name)) {
            msgpack_init(&p->traces[i].buffer, 0xffffff, MSGPACK_OVERFLOW_REALLOC, NULL);
        }
    }

    msgpack_ext_string_init();

    *plugin = p;
    return status;
}

]]..S:STRING("PLG_FINI_FUNC_DECL")..[[ 
{
    ]]..S:STRING("PLG_STRUCT")..[[* p = NULL;
    ]]..S:STRING("I_STATUS_TYPE")..[[ status = ]]..S:STATUS("SUCCESS")..[[;
    if (plugin == NULL) return ]]..S:STATUS("INVALID_PTR")..[[;
    
    p = *plugin;
    if (p == NULL) return ]]..S:STATUS("PLUGIN_IS_NULL")..[[;
    
    encode_ratelprof_ext(p);

    free(p->traces);
    msgpack_ext_string_free();

    free(*plugin);
    *plugin = NULL;
    return status;
}

]]..S:STRING("PLG_GET_CB_FUNC_DECL")..[[ 
{
    if (plugin == NULL) return ]]..S:STATUS("INVALID_PTR")..[[;
    switch(domain)
    {
]]..self.subcontents.get_profile_cb_block..[[ 
        case RATELPROF_DOMAIN_OMP_REGION: *callback_handler = plugin->ompt_callback_handler; break; 
        default: return ]]..S:STATUS("UNKNOWN_DOMAIN")..[[;
    }
    return ]]..S:STATUS("SUCCESS")..[[;
}


ratelprof_status_t ratelprof_get_activity_callback(const ratelprof_plugin_t* plugin, activity_callback_t* activity_callback, void** activity_callback_user_args) 
{
    if (plugin == NULL) return ]]..S:STATUS("INVALID_PTR")..[[;
    if (activity_callback == NULL) return ]]..S:STATUS("INVALID_PTR")..[[;
    if (activity_callback_user_args == NULL) return ]]..S:STATUS("INVALID_PTR")..[[;
    *activity_callback = plugin->activity_callback;
    *activity_callback_user_args = plugin->traces;
    return ]]..S:STATUS("SUCCESS")..[[;
}
]]
    

end

function msgpack_plugin_c:generate_subcontents()
    self.subcontents.include_block:addfLine("#include \"%s\"", S:STRING("DPLG_HDR"))

    self.subcontents.init_block:addfLine("p->%s_callback_handler.on_enter = %s;", S:STRING("DOMAIN"), S:STRING("PLG_OE_CALLBACK_FUNC"))
    self.subcontents.init_block:addfLine("p->%s_callback_handler.on_exit = %s;", S:STRING("DOMAIN"), S:STRING("PLG_OX_CALLBACK_FUNC"))
    
    self.subcontents.get_profile_cb_block:addfLine("case %s: *callback_handler = plugin->%s_callback_handler; break;", S:STRING("DOMAIN_ID"), S:STRING("DOMAIN"))
    
    self.subcontents.struct_fields:addfLine("api_callback_handler_t %s_callback_handler;", S:STRING("DOMAIN"))
end

return msgpack_plugin_c, "COMMON"
