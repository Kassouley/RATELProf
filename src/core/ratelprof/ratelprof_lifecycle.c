/* # THIS FILE HAS BEEN AUTOMATICALLY GENERATED BY THE GILDA TOOL.
 * # DO NOT MODIFY UNLESS YOU KNOW WHAT YOU ARE DOING.
 * # ANY CHANGES MAY BE OVERWRITTEN BY SUBSEQUENT RUNS OF GILDA.
 */ 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
#include <time.h>
#include <unistd.h>
#include "ratelprof.h"
#include "ratelprof_lifecycle.h"

static int (*main_fn)(int, char **, char **);

ratelprof_lifecycle_t lifecycle;

ratelprof_status_t ratelprof_init_lifecycle() 
{
    lifecycle.current_phase = RATELPROF_IN_TOOL_INIT_PHASE;
	clock_gettime(CLOCK_MONOTONIC, &lifecycle.tool_init_start);
    return RATELPROF_STATUS_SUCCESS;
}

ratelprof_status_t ratelprof_fini_lifecycle() 
{
    free(lifecycle.main_data.argv);
	clock_gettime(CLOCK_MONOTONIC, &lifecycle.tool_fini_stop);
    return RATELPROF_STATUS_SUCCESS;
}

ratelprof_phase_t ratelprof_get_current_phase() 
{
    return lifecycle.current_phase;
}


ratelprof_lifecycle_t* ratelprof_get_lifecycle() 
{
    return &lifecycle;
}

int i_main(int argc, char **argv, char **envp)
{
    lifecycle.current_phase = RATELPROF_IN_MAIN_PHASE;
    lifecycle.main_data.argc = argc;
    lifecycle.main_data.argv = (char**)malloc(argc * sizeof(char*));
    for (int i = 0; i < argc; ++i) {
        lifecycle.main_data.argv[i] = strdup(argv[i]);
    }
	clock_gettime(CLOCK_MONOTONIC, &lifecycle.main_start);
    lifecycle.main_data.retval = main_fn(argc, argv, envp);
	clock_gettime(CLOCK_MONOTONIC, &lifecycle.main_stop);
    lifecycle.main_data.pid = get_pid();
    lifecycle.main_data.tid = get_tid();
    lifecycle.current_phase = RATELPROF_IN_DESTRUCTOR_PHASE;
    return lifecycle.main_data.retval;
}

int __libc_start_main(
    int (*main)(int, char **, char **),
    int argc,
    char **argv,
    int (*init)(int, char **, char **),
    void (*fini)(void),
    void (*rtld_fini)(void),
    void *stack_end)
{
    main_fn = main;
    typeof(&__libc_start_main) orig = dlsym(RTLD_NEXT, "__libc_start_main");
    return orig(i_main, argc, argv, init, fini, rtld_fini, stack_end);
}

