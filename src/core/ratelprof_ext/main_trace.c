#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
#include <time.h>
#include <unistd.h>
#include "ratelprof.h"
#include "ratelprof_ext.h"
#include "main_trace.h"

static int (*main_fn)(int, char **, char **);

int i_main(int argc, char **argv, char **envp)
{
    ratelprof_main_activity_t* main_activity = (ratelprof_main_activity_t*)malloc(sizeof(ratelprof_main_activity_t));
    main_activity->domain = RATELPROF_DOMAIN_MAIN;
    main_activity->id = push_id();
    main_activity->args.argc = argc;
    main_activity->args.argv = (char**)malloc(argc * sizeof(char*));
    for (int i = 0; i < argc; ++i) {
        main_activity->args.argv[i] = strdup(argv[i]);
    }
	clock_gettime(CLOCK_MONOTONIC, &main_activity->start_time);
    int retval = main_fn(argc, argv, envp);
	clock_gettime(CLOCK_MONOTONIC, &main_activity->stop_time);
    main_activity->args.retval = retval;
    main_activity->pid = get_pid();
    main_activity->tid = get_tid();
    pop_id();
    ratelprof_activity_pool_push_activity(main_activity);
    return retval;
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