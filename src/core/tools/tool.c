#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <time.h>
#include <dlfcn.h>
#include <ratelprof.h>
#include <ratelprof_ext.h>
#include <plugin.h>

typedef struct plugin_manager_s {
    void* plugin_handle;
    ratelprof_status_t (*plugin_initialize)(ratelprof_plugin_t**);
    ratelprof_status_t (*plugin_finalize)(ratelprof_plugin_t**);
    ratelprof_status_t (*get_api_callback)(const ratelprof_plugin_t*, ratelprof_domain_t, api_callback_handler_t*); 
    ratelprof_status_t (*get_activity_callback)(const ratelprof_plugin_t*, activity_callback_t*, void**); 
} plugin_manager_t;

plugin_manager_t plugin_manager = {0};
ratelprof_plugin_t* plugin = NULL;

static void* load_symbol(void *handle, const char *symbol) {
    void *sym = dlsym(handle, symbol);
    if (sym == NULL) {
        fprintf(stderr, "Error loading symbol %s: %s\n", symbol, dlerror());
        if (handle) dlclose(handle);
        abort();
    }
    return sym;
}

static void open_plugin_manager(plugin_manager_t* pm) {
    if (!pm->plugin_handle) {
        pm->plugin_handle = get_plugin_lib();
        pm->plugin_initialize = load_symbol(pm->plugin_handle, "ratelprof_plugin_initialize");
        pm->plugin_finalize = load_symbol(pm->plugin_handle, "ratelprof_plugin_finalize");
        pm->get_api_callback = load_symbol(pm->plugin_handle, "ratelprof_get_api_callback");
        pm->get_activity_callback = load_symbol(pm->plugin_handle, "ratelprof_get_activity_callback");
    }
}

static void close_plugin_manager(plugin_manager_t* pm) {
    if (pm->plugin_handle) {
        dlclose(pm->plugin_handle);
        pm->plugin_handle = NULL;
    }
}

void onLoad()
{
    ratelprof_init();
    ratelprof_ext_init();
    
    open_plugin_manager(&plugin_manager);
    plugin_manager.plugin_initialize(&plugin);

    // API Table Init
    api_callback_handler_t callback_handler;
    for (ratelprof_domain_t domain = 0; domain < RATELPROF_NB_DOMAIN; domain++)
    {
        if (is_set_domain(ratelprof_get_domain_name(domain))) {
            plugin_manager.get_api_callback(plugin, domain, &callback_handler);
            ratelprof_set_api_callback(domain, callback_handler);
            ratelprof_enable_domain(domain);
        }
    }

    // Profiling Table Init
	if (is_set_domain("RATELPROF_DOMAIN_PROFILING")) {
		ratelprof_enable_profiling_table();
	}

    // Activity System Init
    activity_callback_t activity_callback;
    void* json_buffer;
    plugin_manager.get_activity_callback(plugin, &activity_callback, &json_buffer);

    ratelprof_pool_properties_t props = {
        .activity_callback = activity_callback,
        .activity_callback_user_args = json_buffer,
        .buffer_size = get_buffer_size()
    };
    ratelprof_activity_pool_init(&props);
    ratelprof_start();
}

void onExit()
{
    ratelprof_stop();
    
    ratelprof_activity_pool_flush_activities();
    ratelprof_activity_pool_fini();

    for (ratelprof_domain_t domain = 0; domain < RATELPROF_NB_DOMAIN; domain++)
    {
        if (is_set_domain(ratelprof_get_domain_name(domain))) {
		    ratelprof_disable_domain(domain);
        }
    }
    
	if (is_set_domain("RATELPROF_DOMAIN_PROFILING")) {
		ratelprof_disable_profiling_table();
	}
    
    ratelprof_fini();
    ratelprof_ext_fini();

    plugin_manager.plugin_finalize(&plugin);
    close_plugin_manager(&plugin_manager);
}

__attribute__((constructor(101))) void init(void) 
{
    onLoad();
}

__attribute__((destructor(101))) void fini(void) 
{
    int cr = atexit( onExit );
    assert( cr == 0 );
}