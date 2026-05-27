#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "rprofrep_status.h"

#include "utils/rprofrep_decode_type.h"
#include "utils/rprofrep_read_utils.h"

#include "sections/rprofrep_section_string.h"

#include "sections/rprofrep_section_ref.h"

#include "sections/rprofrep_report_section.h"

// Free string section
rprofrep_status_t rprofrep_free_string_section(rprofrep_ref_section_t* section)
{
    char** strings = (char**) section->entries;

    if (strings)  {
        for (uint64_t i = 0; i < section->nentries; i++) {
            free(strings[i]);
        }
        free(strings);
    }

    return RPROFREP_STATUS_SUCCESS;
}


// Decode the string section
rprofrep_status_t rprofrep_decode_string_section(
    rprofrep_decode_context_t* ctx, 
    uint8_t* buffer, 
    size_t size, 
    rprofrep_ref_section_t* data_out
) {
    size_t offset = 0;
    size_t nentries_offset = size - sizeof(uint64_t);
    uint64_t num_strings = __read_uint64(buffer, &nentries_offset);

    if (num_strings > 0) {
        rprofrep_init_ref_section(data_out, num_strings, sizeof(char*));
        char **strings  = (char**) data_out->entries;

        for (uint64_t i = 0; i < num_strings; i++) {
            strings[i] = __read_mp_string(buffer, &offset);
        }
    }
    return RPROFREP_STATUS_SUCCESS;
}


extern char *__cxa_demangle(const char *mangled_name, char *output_buffer, size_t *length, int *status);

static inline char *__demangle(const char *mangled, bool need_demangle) {
    if (!need_demangle) {
        return strdup(mangled);
    }

    const char *name = mangled;
    char *tmp_name = NULL;
    char *intern_suffix = NULL;
    char *omp_line = NULL;

    // __omp_offloading_<hex>_<hex>_<kernel>_l<line>
    if (strncmp(name, "__omp_offloading_", 18) == 0) {
        const char *p = name + 18;

        // skip hex field
        while (isxdigit(*p)) p++;
        if (*p == '_') p++;

        // skip hex field
        while (isxdigit(*p)) p++;
        if (*p == '_') p++;

        // <kernel>_l<line>
        const char *line_marker = strstr(p, "_l");
        if (line_marker != NULL) {
            tmp_name = strndup(p, line_marker - p);
            name = tmp_name;

            omp_line = strdup(line_marker + 2);
        }
    }

    // <symbol>.intern.<hex>
    const char *intern = strstr(name, ".intern.");
    char *base_name = NULL;

    if (intern != NULL) {
        base_name = strndup(name, intern - name);
        intern_suffix = strdup(intern);
        name = base_name;
    }

    char *result = NULL;

    if (strncmp(name, "_Z", 2) == 0) {
        int status = 0;
        char *demangled = __cxa_demangle(name, NULL, NULL, &status);

        if (status == 0 && demangled != NULL) {
            result = demangled;
        }
    }

    if (result == NULL) {
        free(tmp_name);
        free(base_name);
        free(intern_suffix);
        free(omp_line);
        return strdup(mangled);
    }

    // Re-append .intern.<hex> suffix
    if (intern_suffix != NULL) {
        size_t len = strlen(result) + strlen(intern_suffix) + 1;

        char *final = malloc(len);

        snprintf(final, len, "%s%s", result, intern_suffix);

        free(result);
        result = final;
    }

   
    //  Re-append OpenMP line: (l.<line>)
    if (omp_line != NULL) {
        size_t len = strlen(result) + strlen(omp_line) + 7;
        char *final = malloc(len);

        snprintf(final, len, "%s (l.%s)", result, omp_line);

        free(result);
        result = final;
    }

    free(tmp_name);
    free(base_name);
    free(intern_suffix);
    free(omp_line);

    return result;
}



rprofrep_status_t rprofrep_to_json_string_section(
    rprofrep_decode_context_t* ctx, const char* json_filename, const char* dst_mode, bool need_demangle
) {
    RPROFREP_CHECK_VALID_PTR(ctx, json_filename, dst_mode);

    FILE *f = fopen(json_filename, dst_mode);
    if (!f) return RPROFREP_STATUS_FILE_ERROR("Cannot open file '%s'", json_filename);

    rprofrep_ref_section_t* ref_sct = NULL;
    RPROFREP_CHECK_CALL(rprofrep_get_section(ctx, RPROFREP_SECTION_STRING, (void**)&ref_sct));

    const uint64_t nstrings = ref_sct->nentries;
    char** strings = (char**)ref_sct->entries;

    char json_buf[8192];
    size_t pos = 0;

    #define FLUSH_IF_NEEDED(n) \
        if (pos + (n) >= sizeof(json_buf)) { \
            fwrite(json_buf, 1, pos, f); \
            pos = 0; \
        }

    json_buf[pos++] = '[';

    for (size_t i = 0; i < nstrings; i++)
    {
        if (i) {
            FLUSH_IF_NEEDED(1);
            json_buf[pos++] = ',';
        }
        
        FLUSH_IF_NEEDED(1);
        json_buf[pos++] = '"';

        const char *original = strings[i] ? strings[i] : "";
        char *demangled = __demangle(original, need_demangle);
        char *s = demangled;

        while (*s) {
            FLUSH_IF_NEEDED(1);
            json_buf[pos++] = *s++;
        }
        
        free(demangled);

        FLUSH_IF_NEEDED(1);
        json_buf[pos++] = '"';

    }

    FLUSH_IF_NEEDED(1);
    json_buf[pos++] = ']';

    
    if (pos > 0) {
        fwrite(json_buf, 1, pos, f);
    }

    fclose(f);
    return RPROFREP_STATUS_SUCCESS;

    #undef FLUSH_IF_NEEDED
}