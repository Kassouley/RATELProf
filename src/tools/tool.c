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
        LOG(LOG_LEVEL_WARN, "Error loading symbol %s: %s\n", symbol, dlerror());
    }
    return sym;
}

static void open_plugin_manager(plugin_manager_t* pm) {
    if (!pm->plugin_handle) {
        void* handle = get_plugin_lib();
        if (!handle) {
            LOG(LOG_LEVEL_FATAL, "RPROF: Environment variable %s is not set.\n", ENV_PLUGIN_PATH);
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

ratelprof_status_t onLoad()
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    LOG(LOG_LEVEL_INFO, "Initializing RATELProf . . .\r");
    RATELPROF_TRY(
        ratelprof_init(RATELPROF_NB_DOMAIN_EXT),
        LOG(LOG_LEVEL_FATAL, "Failed to init RATELProf core part.\n")
    );

    RATELPROF_TRY(
        ratelprof_ext_init(),
        LOG(LOG_LEVEL_FATAL, "Failed to init RATELProf extension part.\n")
    );
    
    open_plugin_manager(&plugin_manager);
    plugin_manager.plugin_initialize(&plugin);
    LOG(LOG_LEVEL_INFO, "Initializing RATELProf : SUCCESS\n");

    // API Table Init
    api_callback_handler_t callback_handler;
    for (ratelprof_domain_t domain = 0; domain < RATELPROF_NB_DOMAIN; domain++)
    {
        const char* domain_name = ratelprof_get_domain_name(domain);
        if (is_set_domain(domain_name)) {
            LOG(LOG_LEVEL_INFO, "Configuring domain '%s' . . . \r", domain_name);
            plugin_manager.get_api_callback(plugin, domain, &callback_handler);

            RATELPROF_TRY(
                ratelprof_set_api_callback(domain, callback_handler),
                LOG(LOG_LEVEL_ERROR, "Cannot set domain '%s' callback\n", domain_name)
            );
            RATELPROF_TRY(
                ratelprof_enable_domain(domain),
                LOG(LOG_LEVEL_ERROR, "Cannot enable domain '%s'\n", domain_name)
            );
            LOG(LOG_LEVEL_INFO, "Domain '%s' enabled.          \n", domain_name);
        }
    }

	if (is_set_domain(RATELPROF_DOMAIN_OMP_REGION_NAME)) {
        plugin_manager.get_api_callback(plugin, RATELPROF_DOMAIN_OMP_REGION, &callback_handler);
        RATELPROF_TRY(
            ratelprof_set_api_callback(RATELPROF_DOMAIN_OMP_REGION, callback_handler),
            LOG(LOG_LEVEL_ERROR, "Cannot set domain 'OMPT' callback\n")
        );
    }

    // Profiling Table Init
	if (is_set_domain(RATELPROF_DOMAIN_PROFILING_NAME)) {
        LOG(LOG_LEVEL_INFO, "Enabling profiling traced functions . . . \r");
        RATELPROF_TRY(
            ratelprof_enable_profiling_table(),
            LOG(LOG_LEVEL_FATAL, "Cannot enable profiling function tracing.\n")
        );
        LOG(LOG_LEVEL_INFO, "Profiling traced functions enabled.       \n");
	}

	if (is_set_domain(RATELPROF_DOMAIN_COPY_NAME)) {
        LOG(LOG_LEVEL_INFO, "Enabling memory transfers profiling . . .\r");
        RATELPROF_TRY(
            ratelprof_enable_memcpy_profiling(),
            LOG(LOG_LEVEL_FATAL, "Cannot enable memory transfers profiling.\n")
        );
        LOG(LOG_LEVEL_INFO, "Memory transfers profiling enabled.      \n");
	}

	if (is_set_domain(RATELPROF_DOMAIN_KERNEL_NAME)) {
        LOG(LOG_LEVEL_INFO, "Enabling kernel dispatch profiling . . .\r");
        RATELPROF_TRY(
            ratelprof_enable_kernel_dispatch_profiling(),
            LOG(LOG_LEVEL_FATAL, "Cannot enable kernel dispatch profiling.\n")
        );
        LOG(LOG_LEVEL_INFO, "Kernel dispatch profiling enabled.      \n");
	}

	if (is_set_domain(RATELPROF_DOMAIN_BARRIERAND_NAME) && is_set_domain(RATELPROF_DOMAIN_BARRIEROR_NAME)) {
        LOG(LOG_LEVEL_INFO, "Enabling barrier dispatch profiling . . .\r");
        RATELPROF_TRY(
            ratelprof_enable_barrier_dispatch_profiling(),
            LOG(LOG_LEVEL_FATAL, "Cannot enable barrier dispatch profiling.\n")
        );
        LOG(LOG_LEVEL_INFO, "Barrier dispatch profiling enabled.      \n");
	}

    // Activity System Init
    activity_callback_t activity_callback = NULL;
    void* user_args = NULL;
    if (plugin_manager.get_activity_callback)
        plugin_manager.get_activity_callback(plugin, &activity_callback, &user_args);

    ratelprof_pool_properties_t props = {
        .activity_callback = activity_callback,
        .activity_callback_user_args = user_args,
        .buffer_size = envtoll("RATELPROF_BUFFER_SIZE", 0x200000)
    };
    ratelprof_activity_pool_init(&props);

    /*
     * TODO 29/03/2025 : Find a better way to do this.
     * The problem is if enable the hsa_shut_down function after calling this line
     * it will overwrite this affectation but we want i_gpu_hsa_shut_down to be used
     * whenever HSA API table is enable or not. So to avoid this overwrite we put
     * it after the enabling of HSA API table, but what will happened if we add
     * a feature that let user enable HSA API table during runtime and not at init
     */ 
    hsa_api_table.api_ptr[HSA_API_ID_hsa_shut_down] = i_gpu_hsa_shut_down;

    LOG(LOG_LEVEL_INFO, "Starting profiling . . .\n");
    ratelprof_start();

    LOG(LOG_LEVEL_INFO, "Application output :\n\n");

    return status;
}

void onExit()
{
    ratelprof_stop();
    printf("\n");
    LOG(LOG_LEVEL_INFO, "Profiling finished.\n");

    ratelprof_lifecycle_t* lc = ratelprof_get_lifecycle();
 
    ratelprof_time_t main_start        = ratelprof_get_timestamp_ms(lc->main_start);
    ratelprof_time_t main_stop         = ratelprof_get_timestamp_ms(lc->main_stop);
    ratelprof_time_t constructor_start = ratelprof_get_timestamp_ms(lc->constructor_start);
    ratelprof_time_t destructor_stop   = ratelprof_get_timestamp_ms(lc->destructor_stop);

    LOG(LOG_LEVEL_INFO, "Application duration : %10lu ms\n", main_stop - main_start);
    LOG(LOG_LEVEL_INFO, "Constructor duration : %10lu ms\n", main_start - constructor_start);
    LOG(LOG_LEVEL_INFO, "Destructor duration :  %10lu ms\n", destructor_stop - main_stop);
    LOG(LOG_LEVEL_INFO, "Total duration :       %10lu ms\n", destructor_stop - main_start);
    
    LOG(LOG_LEVEL_INFO, "Flushing activities . . .\r");
    
    ratelprof_status_t status = ratelprof_activity_pool_flush_activities();
    if (status == (ratelprof_status_t)RATELPROF_STATUS_NO_CALLBACK_SET) {
        LOG(LOG_LEVEL_WARN, "Activity callback not setted.\n");
    } else if (status != RATELPROF_STATUS_SUCCESS) {
        LOG(LOG_LEVEL_FATAL, "Failed to flush activity pool.\n");
    }

    if (ratelprof_activity_pool_fini())
        LOG(LOG_LEVEL_FATAL, "Failed to finalize activity pool.\n");

    LOG(LOG_LEVEL_INFO, "Flushing activities :     SUCCESS\n");

    LOG(LOG_LEVEL_INFO, "Finalizing RATELProf . . .\r");
    
    if(ratelprof_fini())
        LOG(LOG_LEVEL_FATAL, "Failed to finalize RATELProf core part.\n");

    plugin_manager.plugin_finalize(&plugin);
    close_plugin_manager(&plugin_manager);

    if(ratelprof_ext_fini())
        LOG(LOG_LEVEL_FATAL, "Failed to finalize RATELProf extension part.\n");

    LOG(LOG_LEVEL_INFO, "Finalizing RATELProf :    SUCCESS\n");
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