#define _GNU_SOURCE
#include <bfd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <string.h>
#include <pthread.h>

#include "ratelprof/ratelprof_source_location.h"
#include "ratelprof/ratelprof_status.h"


// Cache for location data
// Save for each address the location data
static cached_source_data_t *location_cache = NULL;
static pthread_mutex_t cache_mutex = PTHREAD_MUTEX_INITIALIZER;


// Cache for BFD data
// Save for each object file the corresponding BFD data
static bfd_cache_entry_t *bfd_cache = NULL;
static pthread_mutex_t bfd_cache_mutex = PTHREAD_MUTEX_INITIALIZER;


static bfd_cache_entry_t *get_cached_bfd(const char *filename) {
    pthread_mutex_lock(&bfd_cache_mutex);

    for (bfd_cache_entry_t *entry = bfd_cache; entry; entry = entry->next) {
        if (strcmp(entry->filename, filename) == 0) {
            pthread_mutex_unlock(&bfd_cache_mutex);
            return entry;
        }
    }

    bfd *abfd = bfd_openr(filename, NULL);
    if (!abfd) {
        pthread_mutex_unlock(&bfd_cache_mutex);
        return NULL;
    }

    if (!bfd_check_format(abfd, bfd_object)) {
        bfd_close(abfd);
        pthread_mutex_unlock(&bfd_cache_mutex);
        return NULL;
    }

    long symcount = bfd_get_symtab_upper_bound(abfd);
    if (symcount <= 0) {
        bfd_close(abfd);
        pthread_mutex_unlock(&bfd_cache_mutex);
        return NULL;
    }

    asymbol **symbols = malloc(symcount);
    if (!symbols) {
        bfd_close(abfd);
        pthread_mutex_unlock(&bfd_cache_mutex);
        return NULL;
    }

    symcount = bfd_canonicalize_symtab(abfd, symbols);
    if (symcount < 0) {
        free(symbols);
        bfd_close(abfd);
        pthread_mutex_unlock(&bfd_cache_mutex);
        return NULL;
    }


    bfd_cache_entry_t *new_entry = malloc(sizeof(bfd_cache_entry_t));
    new_entry->filename = strdup(filename);
    new_entry->abfd = abfd;
    new_entry->symbols = symbols;
    new_entry->next = bfd_cache;
    bfd_cache = new_entry;

    pthread_mutex_unlock(&bfd_cache_mutex);
    return new_entry;
}



static bool match_addr_callback(ratelprof_source_data_t *location, void *user_data) {
    ratelprof_source_data_t *args = (ratelprof_source_data_t*) user_data;

    if (location->addr == args->addr) {
        *args = *location;
        return true;
    }
    return false;
}


static ratelprof_status_t add_new_cache_entry(ratelprof_source_data_t data) {
    cached_source_data_t *new_entry = malloc(sizeof(cached_source_data_t));
    if (!new_entry) {
        return RATELPROF_STATUS_MALLOC_FAILED;
    }

    new_entry->location = data;
    new_entry->next = NULL;

    pthread_mutex_lock(&cache_mutex);
    new_entry->next = location_cache;
    location_cache = new_entry;
    pthread_mutex_unlock(&cache_mutex);
    return RATELPROF_STATUS_SUCCESS;
}


ratelprof_status_t ratelprof_get_source_location(ratelprof_source_data_t* out, void *addr) {    
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;

    ratelprof_source_data_t tmp = {0};
    ratelprof_source_data_t *data = out ? out : &tmp;

    data->addr = addr;

    if (ratelprof_iterate_location_cache(match_addr_callback, data)) {
        return RATELPROF_STATUS_SUCCESS;
    }

    Dl_info info;
    if (!dladdr(addr, &info)) {
        status = add_new_cache_entry(*data);
        return status == RATELPROF_STATUS_SUCCESS ? RATELPROF_STATUS_DLADDR_FAILED : status;
    }

    const char *object_filename = info.dli_fname;

    data->object_file = object_filename ? strdup(object_filename) : NULL;

    bfd_cache_entry_t *bfd_entry = get_cached_bfd(object_filename);
    if (!bfd_entry) {
        status = add_new_cache_entry(*data);
        return status == RATELPROF_STATUS_SUCCESS ? RATELPROF_STATUS_BFD_FAILED : status;
    }

    bfd *abfd = bfd_entry->abfd;
    asymbol **symbols = bfd_entry->symbols;

    bfd_vma pc = (bfd_vma)addr;
    asection *section = NULL;
    for (section = abfd->sections; section; section = section->next) {
        if (section->vma <= pc && pc < section->vma + bfd_section_size(section)) {
            break;
        }
    }

    if (section) {
        const char *filename = NULL;
        const char *func = NULL;
        unsigned int line = 0;
        if (bfd_find_nearest_line(abfd, section, symbols, pc - section->vma, &filename, &func, &line)) {
            data->filename = filename ? strdup(filename) : NULL;
            data->func     = func ? strdup(func) : NULL;
            data->line     = line;
        } else {
            status = add_new_cache_entry(*data);
            return status == RATELPROF_STATUS_SUCCESS ? RATELPROF_STATUS_BFD_NO_SOURCE_FOUND : status;
        }
    } else {
        status = add_new_cache_entry(*data);
        return status == RATELPROF_STATUS_SUCCESS ? RATELPROF_STATUS_BFD_NO_SECTION_FOUND : status;
    }

    return add_new_cache_entry(*data);
}


bool ratelprof_iterate_location_cache(ratelprof_cache_iter_cb_t callback, void *user_data) {
    pthread_mutex_lock(&cache_mutex);
    for (cached_source_data_t *entry = location_cache; entry; entry = entry->next) {
        if (callback(&entry->location, user_data)) {
            pthread_mutex_unlock(&cache_mutex);
            return true;
        }
    }
    pthread_mutex_unlock(&cache_mutex);
    return false;
}


const char * ratelprof_format_source_location_string(const ratelprof_source_data_t *loc) {
    const char *func     = loc->func ? loc->func : "??";
    const char *filename = loc->filename ? loc->filename : "??";

    size_t len = snprintf(NULL, 0, "%s from %s:%u", func, filename, loc->line);
    char *buf = malloc(len + 1);
    if (!buf) return NULL;

    snprintf(buf, len + 1, "%s from %s:%u", func, filename, loc->line);
    return buf;
}

const char * ratelprof_format_binary_location_string(const ratelprof_source_data_t *loc) {
    const char *object   = loc->object_file ? loc->object_file : "<unknown>";
    void *addr           = loc->addr;

    size_t len = snprintf(NULL, 0, "%s at %p", object, addr);
    char *buf = malloc(len + 1);
    if (!buf) return NULL;

    snprintf(buf, len + 1, "%s at %p", object, addr);
    return buf;
}

void ratelprof_print_location(ratelprof_source_data_t loc) {
    printf("%s [%s]\n", 
        ratelprof_format_source_location_string(&loc), 
        ratelprof_format_binary_location_string(&loc));
}

void ratelprof_get_and_print_location(void *addr) {
    ratelprof_source_data_t loc = {0};
    ratelprof_get_source_location(&loc, addr);
    ratelprof_print_location(loc);
}


void ratelprof_cleanup_source_location(void) {
    // ---- Free BFD cache ----
    pthread_mutex_lock(&bfd_cache_mutex);
    bfd_cache_entry_t *bfd_entry = bfd_cache;
    while (bfd_entry) {
        bfd_cache_entry_t *next = bfd_entry->next;

        if (bfd_entry->symbols)
            free(bfd_entry->symbols);
        if (bfd_entry->abfd)
            bfd_close(bfd_entry->abfd);
        if (bfd_entry->filename)
            free((void *)bfd_entry->filename);

        free(bfd_entry);
        bfd_entry = next;
    }
    bfd_cache = NULL;
    pthread_mutex_unlock(&bfd_cache_mutex);

    // ---- Free caller/source location cache ----
    pthread_mutex_lock(&cache_mutex);
    cached_source_data_t *entry = location_cache;
    while (entry) {
        cached_source_data_t *next = entry->next;

        if (entry->location.object_file)
            free((void *)entry->location.object_file);
        if (entry->location.filename)
            free((void *)entry->location.filename);
        if (entry->location.func)
            free((void *)entry->location.func);

        free(entry);
        entry = next;
    }
    location_cache = NULL;
    pthread_mutex_unlock(&cache_mutex);
}