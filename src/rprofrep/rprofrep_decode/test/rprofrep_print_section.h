#ifndef RPROFREP_PRINT_SECTION_H
#define RPROFREP_PRINT_SECTION_H

#include <stdio.h>
#include <inttypes.h>
#include <time.h>
#include "ratelprof.h"
#include "rprofrep_decode.h"

#define print_section_title(section_id) \
    printf("\n==================== %s Section ====================\n", get_section_name(section_id)); \


#define print_section_end() \
    printf("\n====================================================\n");

#define print_declare_table(...)                                    \
    const int _widths[] = { __VA_ARGS__ };                          \
    const int _count = sizeof(_widths) / sizeof(_widths[0]);        \

#define print_table_separator()                                         \
    do {                                                                \
        for (int _i = 0; _i < _count; _i++) {                           \
            for (int _j = 0; _j < _widths[_i]; _j++)                    \
                printf("-");                                            \
            if (_i + 1 < _count)                                        \
                printf(" + ");                                          \
        }                                                               \
        printf("\n");                                                   \
    } while (0)


#define print_table_header(...)                                              \
    do {                                                                     \
        const char *const _labels[] = { __VA_ARGS__ };                       \
        const int nlabels = sizeof(_labels) / sizeof(_labels[0]);            \
        int _n = (_count < nlabels) ? _count : nlabels;                      \
        for (int _i = 0; _i < _n; _i++) {                                    \
            printf("%-*s", _widths[_i], _labels[_i]);                        \
            if (_i + 1 < _n)                                                 \
                printf(" | ");                                               \
        }                                                                    \
        printf("\n");                                                        \
    } while (0)


static inline const char* tail32(const char* s)
{
    if (!s) return "(null)";

    size_t len = strlen(s);

    if (len <= 32)
        return s;

    return s + (len - 32);
}



static inline char *build_prototype(const char *func_name, int arg_count, char** arg_types, char** arg_names) {
    const char *return_type = "void";

    size_t buf_size = strlen(func_name) + 8; 

    for (int i = 0; i < arg_count; i++) {
        buf_size += strlen(arg_types[i]) + strlen(arg_names[i]) + 2; // "type name, "
        if (strcmp(arg_names[i], "retval") == 0) {
            return_type = arg_types[i];
        }
    }

    char *prototype = malloc(buf_size);
    if (!prototype) return NULL;

    char *p = prototype;
    p += sprintf(p, "%s %s(", return_type, func_name);

    int first = 1;
    for (int i = 0; i < arg_count; i++) {
        if (strcmp(arg_names[i], "retval") == 0) continue;

        if (!first) {
            *p++ = ',';
            *p++ = ' ';
        }
        first = 0;

        size_t tlen = strlen(arg_types[i]);
        memcpy(p, arg_types[i], tlen);
        p += tlen;
        *p++ = ' ';
        size_t nlen = strlen(arg_names[i]);
        memcpy(p, arg_names[i], nlen);
        p += nlen;
    }

    *p++ = ')';
    *p++ = ';';
    *p = '\0';

    return prototype;
}


static bool print_api_data_entry(uint64_t id, rprofrep_api_data_entry_t* entry, void* user_data) {
    printf("%-6" PRIu64 " | %s\n", id,
            build_prototype(entry->fname, entry->num_args, entry->arg_types, entry->arg_names));
    return true;
}

static inline rprofrep_status_t rprofrep_print_api_data_section(rprofrep_decode_context_t* ctx)
{
    print_section_title(RPROFREP_SECTION_API_DATA);

    print_declare_table(6, 128);

    print_table_separator();
    print_table_header("ID", "Function Prototype");
    print_table_separator();

    rprofrep_for_each_api_data(ctx, print_api_data_entry, NULL);

    print_table_separator();
    print_section_end();

    return RPROFREP_STATUS_SUCCESS;
}



static bool print_location_entry(uint64_t id, rprofrep_location_entry_t* entry, void* user_data) {
    printf("%-6" PRIu64 " | 0x%016" PRIx64 " | %-32s | %-32s | %s:%" PRIu64 "\n",
            id,
            entry->return_address,
            tail32(entry->objectfile),
            tail32(entry->function),
            tail32(entry->filename),
            entry->line);
    return true;
}

static inline rprofrep_status_t rprofrep_print_location_section(rprofrep_decode_context_t* ctx)
{
    print_section_title(RPROFREP_SECTION_LOCATION);

    print_declare_table(6, 18, 32, 32, 40);

    print_table_separator();
    print_table_header("ID", "Address", "Object File", "Function", "File");
    print_table_separator();

    rprofrep_for_each_location(ctx, print_location_entry, NULL);

    print_table_separator();
    print_section_end();

    return RPROFREP_STATUS_SUCCESS;
}


static bool print_string_entry(uint64_t id, char* str, void* user_data) {        
    printf("String ID %10lu: %s\n", id, str);
    return true;
}


static inline rprofrep_status_t rprofrep_print_string_section(rprofrep_decode_context_t* ctx)
{
    print_section_title(RPROFREP_SECTION_STRING);

    rprofrep_for_each_string(ctx, print_string_entry, NULL);

    print_section_end();

    return RPROFREP_STATUS_SUCCESS;
}



static bool print_kernel_entry(uint64_t id, rprofrep_kernel_static_data_t* entry, void* user_data) {
    printf("%-6" PRIu64 " | %32s | 0x%-16" PRIx64 " | %-16u | %-16u\n",
            id,
            tail32(entry->kernel_name),
            entry->kernel_object,
            entry->group_segment_size,
            entry->private_segment_size);
    return true;
}


static inline rprofrep_status_t rprofrep_print_kernel_section(rprofrep_decode_context_t* ctx)
{
    print_section_title(RPROFREP_SECTION_KERNEL);

    print_declare_table(6, 32, 18, 16, 16);

    print_table_separator();
    print_table_header("ID", "Name", "Object", "Grp Seg. Size", "Pvt Seg. Size");
    print_table_separator();

    rprofrep_for_each_kernel(ctx, print_kernel_entry, NULL);

    print_table_separator();
    print_section_end();


    return RPROFREP_STATUS_SUCCESS;
}



static inline void rprofrep_print_section_header(rprofrep_decode_context_t* ctx)
{
    rprofrep_header_section_t* header = &ctx->header;
    printf("RATELProf Report Header:\n");
    printf("  Magic: %s\n", header->magic);
    printf("  Report Version: %d.%d.%d\n", header->report_version[0], header->report_version[1], header->report_version[2]);
    printf("\nSections:\n");
    print_declare_table(20, 12, 12);
    print_table_separator();
    print_table_header("Name", "Offset", "Size");
    print_table_separator();

    for (int i = 0; i < RPROFREP_NB_SECTIONS; i++) {
        const char* name = get_section_name(i);
        printf("%-20s | 0x%010" PRIx64 " | 0x%010" PRIx64 "\n",
               name,
               header->sections[i].offset,
               header->sections[i].size);
    }
    print_table_separator();
}




static inline rprofrep_status_t __print_domain_tree(rprofrep_decode_context_t* ctx, rprofrep_group_entry_t* group, void* user_arg) {
    rprofrep_header_section_t* header = &ctx->header;
    size_t base_off = header->sections[RPROFREP_SECTION_EVENTS].offset;
    printf("      - Domain:       %s\n", ratelprof_get_domain_name(group->domain));
    printf("         - Group ID:     %" PRIu64 "\n", group->offset_entry.id);
    printf("         - Num Events:   %" PRIu64 "\n", group->offset_entry.nevents);
    printf("         - Group Offset: 0x%" PRIx64 " (rel)\n", group->offset_entry.offset);
    printf("         - Group Offset: 0x%" PRIx64 " (abs)\n", group->offset_entry.offset + base_off);
    return RPROFREP_STATUS_SUCCESS;
}

static bool is_in_gpu_tree = false;

static inline rprofrep_status_t __print_subunit_tree(rprofrep_decode_context_t* ctx, rprofrep_tree_node_t* node, void* user_arg) {
    printf("    - %s: %" PRId64 "\n",  is_in_gpu_tree ? "QID/SDMA" : "TID",(int64_t) node->value);
    RPROFREP_CHECK_CALL(rprofrep_for_each_domain(ctx, node, __print_domain_tree, NULL));
    return RPROFREP_STATUS_SUCCESS;
}


static inline rprofrep_status_t __print_cpu_tree(rprofrep_decode_context_t* ctx, rprofrep_tree_node_t* node, void* user_arg) {
    is_in_gpu_tree = false;
    printf("  - PID: %" PRIu64 "\n", node->value);
    RPROFREP_CHECK_CALL(rprofrep_for_each_tid(ctx, node, __print_subunit_tree, NULL));
    return RPROFREP_STATUS_SUCCESS;
}


static inline rprofrep_status_t __print_gpu_tree(rprofrep_decode_context_t* ctx, rprofrep_tree_node_t* node, void* user_arg) {
    is_in_gpu_tree = true;
    printf("  - GPU: %" PRIu64 "\n", node->value);
    RPROFREP_CHECK_CALL(rprofrep_for_each_queue(ctx, node, __print_subunit_tree, NULL));
    RPROFREP_CHECK_CALL(rprofrep_for_each_sdma(ctx, node, __print_subunit_tree, NULL));
    return RPROFREP_STATUS_SUCCESS;
}

static inline rprofrep_status_t rprofrep_print_offsets_section(rprofrep_decode_context_t* ctx)
{
    print_section_title(RPROFREP_SECTION_OFFSETS);
    RPROFREP_CHECK_CALL(rprofrep_for_each_gpu(ctx, __print_gpu_tree, NULL));
    RPROFREP_CHECK_CALL(rprofrep_for_each_pid(ctx, __print_cpu_tree, NULL));
    print_section_end();
    return RPROFREP_STATUS_SUCCESS;
}

static inline rprofrep_status_t __iterate_over_events(rprofrep_decode_context_t* ctx, rprofrep_tree_node_t* unit_node, void* user_arg) {
    bool requested_domains[RATELPROF_NB_DOMAIN_EXT] = {0};
    memcpy(requested_domains, user_arg, sizeof(requested_domains));

    rprofrep_event_iterator_t iterator = {0};
    RPROFREP_CHECK_CALL(rprofrep_event_iterator_init(&iterator, ctx, unit_node, requested_domains, NULL));
    if (iterator.initialized == false) {
        return RPROFREP_STATUS_SUCCESS;
    }

    for (size_t i = 0; i < 128; i++)
    {
        rprofrep_event_data_t event = {0};
        RPROFREP_CHECK_CALL(rprofrep_event_iterator_next(&iterator, &event));
        if (!event.valid) break;
        
        printf("%6lu | %10lu | %12ld | %-32s | %6lu | %6lu | %16lu | %16lu \n", 
            event.domain, event.unit, event.sub_unit, tail32(event.name), event.id, event.cid, event.start, event.dur);
    }

    RPROFREP_CHECK_CALL(rprofrep_event_iterator_destroy(&iterator));
    return RPROFREP_STATUS_SUCCESS;
}

static inline rprofrep_status_t rprofrep_print_events_section(rprofrep_decode_context_t* ctx, bool requested_domains[RATELPROF_NB_DOMAIN_EXT])
{
    print_section_title(RPROFREP_SECTION_EVENTS);

    print_declare_table(6, 10, 12, 32, 6, 6, 16, 16);

    print_table_separator();
    print_table_header("Domain", "PID/GPU", "TID/QID/SDMA", "Name", "ID", "CID", "Start", "Dur");
    print_table_separator();

    requested_domains[RATELPROF_DOMAIN_HIP] = true;
    requested_domains[RATELPROF_DOMAIN_KERNEL] = true;
    requested_domains[RATELPROF_DOMAIN_MEMORY] = true;
    requested_domains[RATELPROF_DOMAIN_HSA] = false;

    RPROFREP_CHECK_CALL(rprofrep_for_each_gpu(ctx, __iterate_over_events, requested_domains));
    RPROFREP_CHECK_CALL(rprofrep_for_each_pid(ctx, __iterate_over_events, requested_domains));

    print_table_separator();
    print_section_end();

    return RPROFREP_STATUS_SUCCESS;
}


static inline rprofrep_status_t rprofrep_print_gpu_spec_section(rprofrep_decode_context_t* ctx)
{
    print_section_title(RPROFREP_SECTION_GPU_SPEC);

    RPROFREP_CHECK_CALL(rprofrep_print_gpus_spec(ctx));

    print_section_end();

    return RPROFREP_STATUS_SUCCESS;
}


static inline char *epoch_to_date(time_t epoch)
{
    char *buffer = malloc(32);
    if (!buffer) return NULL;

    time_t seconds = epoch / 1000000000LL;

    struct tm tm_info;
    gmtime_r(&seconds, &tm_info);

    strftime(buffer, 32, "%Y-%m-%d %H:%M:%S", &tm_info);

    return buffer;
}

static inline rprofrep_status_t rprofrep_print_global_section(rprofrep_decode_context_t* ctx)
{
    print_section_title(RPROFREP_SECTION_GLOBAL);

    int64_t  rank = 0;
    uint64_t ts = 0;
    int64_t exit_code = 0;
    char**   argv = NULL;
    uint64_t argc = 0;

    RPROFREP_CHECK_CALL(rprofrep_get_rank(ctx, &rank));
    printf("Rank              : %" PRId64 "\n", rank);

    RPROFREP_CHECK_CALL(rprofrep_get_experiment_time(ctx, &ts));
    printf("Experiment Time   : %s\n", epoch_to_date(ts));

    RPROFREP_CHECK_CALL(rprofrep_get_exit_code(ctx, &exit_code));
    printf("Program exit code : %" PRId64 "\n", exit_code);

    RPROFREP_CHECK_CALL(rprofrep_get_command_line(ctx, &argv, &argc));
    printf("Command line      : ");
    for (uint64_t i = 0; i < argc; ++i) {
        printf("%s%s", argv[i], (i + 1 < argc) ? " " : "");
    }
    printf("\n\n");

    RPROFREP_CHECK_CALL(rprofrep_get_constructor_time(ctx, &ts));
    printf("Constructor Time (ns) : %" PRIu64 "\n", ts);
    RPROFREP_CHECK_CALL(rprofrep_get_main_time(ctx, &ts));
    printf("Main Time        (ns) : %" PRIu64 "\n", ts);
    RPROFREP_CHECK_CALL(rprofrep_get_destructor_time(ctx, &ts));
    printf("Destructor Time  (ns) : %" PRIu64 "\n", ts);
    
    print_section_end();

    return RPROFREP_STATUS_SUCCESS;
}




#endif // RPROFREP_PRINT_SECTION_H