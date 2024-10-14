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
    if (!sym) {
        fprintf(stderr, "Error loading symbol %s: %s\n", symbol, dlerror());
        if (handle) dlclose(handle);
        exit(EXIT_FAILURE);
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


void firstFunction() {
    printf( "firstFunction\n" );
}

void onLoad()
{
    ratelprof_init();
    
    open_plugin_manager(&plugin_manager);
    plugin_manager.plugin_initialize(&plugin);
    api_callback_handler_t callback_handler;

    if (is_profiled_domain("RATELPROF_DOMAIN_HIP")) {
		plugin_manager.get_api_callback(plugin, RATELPROF_DOMAIN_HIP, &callback_handler);
		ratelprof_set_api_callback(RATELPROF_DOMAIN_HIP, callback_handler);
		ratelprof_enable_domain(RATELPROF_DOMAIN_HIP);
	}
	if (is_profiled_domain("RATELPROF_DOMAIN_HSA")) {
		plugin_manager.get_api_callback(plugin, RATELPROF_DOMAIN_HSA, &callback_handler);
		ratelprof_set_api_callback(RATELPROF_DOMAIN_HSA, callback_handler);
		ratelprof_enable_domain(RATELPROF_DOMAIN_HSA);
	}

    activity_callback_t activity_callback;
    void* activity_callback_user_args;
    plugin_manager.get_activity_callback(plugin, &activity_callback, &activity_callback_user_args);

    ratelprof_pool_properties_t props = {
        .activity_callback = activity_callback,
        .activity_callback_user_args = activity_callback_user_args,
        .buffer_size = get_buffer_size()
    };
    ratelprof_activity_pool_init(&props);

}

void onExit()
{
    ratelprof_activity_pool_flush_activities();
    // printf("%d\n",ratelprof_activity_pool_fini());
     if (is_profiled_domain("RATELPROF_DOMAIN_HIP")) {
		ratelprof_disable_domain(RATELPROF_DOMAIN_HIP);
	}
	if (is_profiled_domain("RATELPROF_DOMAIN_HSA")) {
		ratelprof_disable_domain(RATELPROF_DOMAIN_HSA);
	}
    plugin_manager.plugin_finalize(&plugin);
    close_plugin_manager(&plugin_manager);
    ratelprof_fini();
}

__attribute__((constructor(101))) void init(void) 
{
    int cr = atexit( onExit );
    assert( cr == 0 );
    onLoad();
}