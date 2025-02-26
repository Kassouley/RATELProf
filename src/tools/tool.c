#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <time.h>
#include <dlfcn.h>
#include <ratelprof.h>
#include <ratelprof_ext.h>

typedef struct ratelprof_plugin_s ratelprof_plugin_t;

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
        void* handle = get_plugin_lib();
        if (!handle) {
            fprintf(stderr, "RPROF: Environment variable %s is not set.\n", ENV_PLUGIN_PATH);
            exit(1);
        }
        pm->plugin_handle = handle;
        pm->plugin_initialize       = load_symbol(handle, "ratelprof_plugin_initialize");
        pm->plugin_finalize         = load_symbol(handle, "ratelprof_plugin_finalize");
        pm->get_api_callback        = load_symbol(handle, "ratelprof_get_api_callback");
        pm->get_activity_callback   = load_symbol(handle, "ratelprof_get_activity_callback");
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
    printf("RPROF: Initializing RATELProf . . .");
    ratelprof_init();
    ratelprof_ext_init();
    
    open_plugin_manager(&plugin_manager);
    plugin_manager.plugin_initialize(&plugin);
    printf("\rRPROF: Initializing RATELProf :  SUCCESS\n");

    // API Table Init
    api_callback_handler_t callback_handler;
    for (ratelprof_domain_t domain = 0; domain < RATELPROF_NB_DOMAIN; domain++)
    {
        const char* domain_name = ratelprof_get_domain_name(domain);
        if (is_set_domain(domain_name)) {
            printf("RPROF: Configuring domain '%s' . . .", domain_name);
            plugin_manager.get_api_callback(plugin, domain, &callback_handler);
            ratelprof_set_api_callback(domain, callback_handler);
            ratelprof_enable_domain(domain);
            printf("\rRPROF: Domain '%s' enabled.          \n", domain_name);
        }
    }

    // Profiling Table Init
	if (is_set_domain("RATELPROF_DOMAIN_PROFILING")) {
        printf("RPROF: Enabling profiling traced functions . . .");
		ratelprof_enable_profiling_table();
        printf("\rRPROF: Profiling traced functions enabled.          \n");
	}
    
    printf("RPROF: Enabling GPU profiling . . .");
    ratelprof_enable_gpu_api_table();
    printf("\rRPROF: GPU profiling enabled.          \n");

    // Activity System Init
    activity_callback_t activity_callback;
    void* json_buffer;
    plugin_manager.get_activity_callback(plugin, &activity_callback, &json_buffer);

    ratelprof_pool_properties_t props = {
        .activity_callback = activity_callback,
        .activity_callback_user_args = json_buffer,
        .buffer_size = envtoll("RATELPROF_BUFFER_SIZE", 0x200000)
    };
    ratelprof_activity_pool_init(&props);

    printf("RPROF: Starting profiling . . .\n");
    ratelprof_start();

    printf("RPROF: Application output :\n\n");

}

void onExit()
{
    ratelprof_stop();
    printf("\nRPROF: Profiling finished.\n");

    ratelprof_lifecycle_t* lc = ratelprof_get_lifecycle();
 
    ratelprof_time_t main_start = ratelprof_get_timestamp_ms(lc->main_start);
    ratelprof_time_t main_stop = ratelprof_get_timestamp_ms(lc->main_stop);
    ratelprof_time_t constructor_start = ratelprof_get_timestamp_ms(lc->constructor_start);
    ratelprof_time_t destructor_stop = ratelprof_get_timestamp_ms(lc->destructor_stop);

    printf("RPROF: Application duration : %10lu ms\n", main_stop - main_start);
    printf("RPROF: Constructor duration : %10lu ms\n", main_start - constructor_start);
    printf("RPROF: Destructor duration :  %10lu ms\n", destructor_stop - main_stop);
    printf("RPROF: Total duration :       %10lu ms\n", destructor_stop - main_start);
    
    printf("RPROF: Flushing activities . . .");
    ratelprof_activity_pool_flush_activities();
    ratelprof_activity_pool_fini();
    printf("\rRPROF: Flushing activities :     SUCCESS\n");

    printf("RPROF: Finalizing RATELProf . . .");
    ratelprof_fini();

    plugin_manager.plugin_finalize(&plugin);
    close_plugin_manager(&plugin_manager);

    ratelprof_ext_fini();
    printf("\rRPROF: Finalizing RATELProf :    SUCCESS\n");
}

__attribute__((constructor(101))) void init(void) 
{
    onLoad();
}

__attribute__((destructor(101))) void fini(void) 
{
    int cr = atexit( onExit );
    assert( cr == 0 );
    (void)cr;
}