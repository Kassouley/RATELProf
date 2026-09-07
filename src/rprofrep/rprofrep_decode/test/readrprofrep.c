// readrprofrep.c — standalone CLI tool similar to readelf

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rprofrep_decode.h"
#include "rprofrep_print_section.h"

// --------------------------
// SECTION NAME → ENUM
// --------------------------
static int lookup_section_id(const char *name) {
    if (strcmp(name, "GLOBAL")      == 0) return RPROFREP_SECTION_GLOBAL;
    if (strcmp(name, "STRING")      == 0) return RPROFREP_SECTION_STRING;
    if (strcmp(name, "LOCATION")    == 0) return RPROFREP_SECTION_LOCATION;
    if (strcmp(name, "GPU_SPEC")    == 0) return RPROFREP_SECTION_GPU_SPEC;
    if (strcmp(name, "API_DATA")    == 0) return RPROFREP_SECTION_API_DATA;
    if (strcmp(name, "KERNEL")      == 0) return RPROFREP_SECTION_KERNEL;
    if (strcmp(name, "OFFSETS")     == 0) return RPROFREP_SECTION_OFFSETS;
    if (strcmp(name, "EVENTS")      == 0) return RPROFREP_SECTION_EVENTS;
    if (strcmp(name, "CID")         == 0) return RPROFREP_SECTION_CID;

    return -1;
}

// --------------------------
// PRINT USAGE MESSAGE
// --------------------------
static void print_usage(const char *prog) {
    fprintf(stderr,
        "Usage:\n"
        "  %s -h <file>                                 Show rprofrep header\n"
        "  %s -s <SECTION> <file>                       Show a specific section\n\n"
        "  %s -s EVENTS -d <DOMAIN[,DOMAIN]> <file>     Show the events for specified domain (default: all domain)\n\n"
        "Available sections:\n"
        "  GLOBAL STRING LOCATION GPU_SPEC API_DATA KERNEL OFFSETS EVENTS\n\n",
        prog, prog, prog
    );
}

// --------------------------
// MAIN
// --------------------------
int main(int argc, char **argv) {
    if (argc < 3) {
        print_usage(argv[0]);
        return 1;
    }

    const char *filename = NULL;
    int show_header = 0;
    int section_id = -1;

    bool requested_domains[RATELPROF_NB_DOMAIN_EXT] = { true };

    // --------------------------
    // Parse arguments
    // --------------------------
    if (strcmp(argv[1], "-h") == 0) {
        if (argc != 3) {
            print_usage(argv[0]);
            return 1;
        }
        show_header = 1;
        filename = argv[2];
    }
    else if (strcmp(argv[1], "-s") == 0) {
        if (argc != 4) {
            print_usage(argv[0]);
            return 1;
        }

        const char *secname = argv[2];
        section_id = lookup_section_id(secname);
        if (section_id < 0) {
            fprintf(stderr, "ERROR: Unknown section name: %s\n", secname);
            print_usage(argv[0]);
            return 1;
        }

        filename = argv[3];
    }
    else {
        print_usage(argv[0]);
        return 1;
    }

    // --------------------------
    // Initialize decoder
    // --------------------------
    rprofrep_decode_context_t ctx = {0};
    rprofrep_status_t status = rprofrep_decode_context_init(&ctx, filename);
    if (!rprofrep_status_is_success(status)) {
        rprofrep_log_status(status);
        return -1;
    }

    // --------------------------
    // Execute commands
    // --------------------------
    if (show_header) {
        rprofrep_print_section_header(&ctx);
    }


    if (section_id >= 0) {
        switch (section_id) {
            case RPROFREP_SECTION_GLOBAL:
                status = rprofrep_print_global_section(&ctx);
                break;
            case RPROFREP_SECTION_STRING:
                status = rprofrep_print_string_section(&ctx);
                break;
            case RPROFREP_SECTION_LOCATION:
                status = rprofrep_print_location_section(&ctx);
                break;
            case RPROFREP_SECTION_GPU_SPEC:
                status = rprofrep_print_gpu_spec_section(&ctx);
                break;
            case RPROFREP_SECTION_API_DATA:
                status = rprofrep_print_api_data_section(&ctx);
                break;
            case RPROFREP_SECTION_KERNEL:
                status = rprofrep_print_kernel_section(&ctx);
                break;
            case RPROFREP_SECTION_OFFSETS:
                status = rprofrep_print_offsets_section(&ctx);
                break;
            case RPROFREP_SECTION_EVENTS:
                status = rprofrep_print_events_section(&ctx, requested_domains);
                break;
        }
    }

    if (!rprofrep_status_is_success(status)) {
        rprofrep_log_status(status);
        return -1;
    }

    // Cleanup
    rprofrep_decode_context_free(&ctx);
    return 0;
}
