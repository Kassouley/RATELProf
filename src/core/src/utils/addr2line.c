#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define TABLE_SIZE 1024

// =========================
// addr2line context
// =========================

typedef struct addr2line_ctx {
    pid_t pid;
    FILE *in;
    FILE *out;
    char *object_path;
    struct addr2line_ctx *next;
} addr2line_ctx;

// =========================
// hash table
// =========================

static addr2line_ctx *g_table[TABLE_SIZE];

static uint32_t hash_str(const char *s)
{
    uint32_t h = 2166136261u;
    while (*s) {
        h ^= (unsigned char)(*s++);
        h *= 16777619;
    }
    return h % TABLE_SIZE;
}

// =========================
// spawn addr2line process
// =========================

static addr2line_ctx *ctx_create(const char *object_path)
{
    int in_pipe[2];
    int out_pipe[2];

    if (pipe(in_pipe) || pipe(out_pipe))
        return NULL;

    pid_t pid = fork();
    if (pid < 0)
        return NULL;

    if (pid == 0) {
        dup2(in_pipe[0], STDIN_FILENO);
        dup2(out_pipe[1], STDOUT_FILENO);

        close(in_pipe[0]);
        close(in_pipe[1]);
        close(out_pipe[0]);
        close(out_pipe[1]);

        execlp("addr2line",
               "addr2line",
               "-e", object_path,
               "-f",
               "-C",
               NULL);

        _exit(127);
    }

    close(in_pipe[0]);
    close(out_pipe[1]);

    addr2line_ctx *ctx = calloc(1, sizeof(*ctx));
    ctx->pid = pid;
    ctx->in = fdopen(in_pipe[1], "w");
    ctx->out = fdopen(out_pipe[0], "r");
    ctx->object_path = strdup(object_path);

    if (!ctx->in || !ctx->out || !ctx->object_path)
        return NULL;

    setvbuf(ctx->in, NULL, _IONBF, 0);

    return ctx;
}

// =========================
// lookup ctx in hash table
// =========================

static addr2line_ctx *get_ctx(const char *object_path)
{
    uint32_t h = hash_str(object_path);

    addr2line_ctx *cur = g_table[h];
    while (cur) {
        if (strcmp(cur->object_path, object_path) == 0)
            return cur;
        cur = cur->next;
    }

    // not found → create
    addr2line_ctx *ctx = ctx_create(object_path);
    if (!ctx)
        return NULL;

    ctx->next = g_table[h];
    g_table[h] = ctx;

    return ctx;
}

// =========================
// main API
// =========================

/*
 * addr2line:
 *  - object_path: path to binary/shared-object (from dladdr->dli_fname)
 *  - addr: the runtime address
 *  - dli_fbase: base address (from dladdr->dli_fbase if available)
 *
 * On success:
 *   *out_func = strdup(<function name>)
 *   *out_file = strdup(<file>)
 *   *out_line = line_number
 * Caller must free() them.
 */
// TODO (13/04/2026) : Better support for Non PIE/shared lib address with offset and base subtract 
//                     (for now we cheat using filename but it's not robust/right way to do it)
// TODO (23/09/2025) : Support escape char in object_path ("'`\s etc.)
bool addr2line(const char *object_path,
                       void *addr,
                       void *base_addr,
                       char **out_func,
                       char **out_file,
                       uint64_t *out_line)
{
    if (!object_path || !addr || !out_func || !out_file || !out_line)
        return false;

    addr2line_ctx *ctx = get_ctx(object_path);
    if (!ctx)
        return false;

    uintptr_t query = (uintptr_t)addr;

    if (strstr(object_path, ".so"))
        query -= (uintptr_t)base_addr;

    // send address
    fprintf(ctx->in, "0x%lx\n", (unsigned long)query);

    char *line = NULL;
    size_t len = 0;

    // function
    if (getline(&line, &len, ctx->out) <= 0)
        return false;

    line[strcspn(line, "\n")] = 0;
    *out_func = strdup(line);

    // file:line
    if (getline(&line, &len, ctx->out) <= 0) {
        free(*out_func);
        *out_func = NULL;
        return false;
    }

    line[strcspn(line, "\n")] = 0;

    char *colon = strrchr(line, ':');

    if (!colon) {
        *out_file = strdup(line);
        *out_line = 0;
    } else {
        *colon = 0;
        *out_file = strdup(line);
        *out_line = strtoull(colon + 1, NULL, 10);
    }

    free(line);
    return true;
}

// =========================
// cleanup
// =========================

void addr2line_pool_destroy(void)
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        addr2line_ctx *cur = g_table[i];
        while (cur) {
            addr2line_ctx *next = cur->next;

            if (cur->in) fclose(cur->in);
            if (cur->out) fclose(cur->out);
            if (cur->pid > 0) waitpid(cur->pid, NULL, 0);

            free(cur->object_path);
            free(cur);

            cur = next;
        }
        g_table[i] = NULL;
    }
}


// static bool addr2line(const char *object_path, void *addr, void *base_addr,
//                         char **out_func, char **out_file, uint64_t *out_line)
// {
//     if (!object_path || !addr || !out_func || !out_file || !out_line) return false;

//     uintptr_t query_addr = (uintptr_t)addr;

//     if (strstr(object_path, ".so") != NULL) {
//         query_addr -= (uintptr_t)base_addr;
//     }

//     char cmd[1024];
//     int n = snprintf(cmd, sizeof(cmd),
//                      "addr2line -e '%s' -f -C 0x%lx",
//                      object_path, (unsigned long) query_addr);

//     if (n < 0 || n >= (int)sizeof(cmd)) return false;

//     FILE *fp = popen(cmd, "r");
//     if (!fp) return false;

//     char *line = NULL;
//     size_t len = 0;
//     ssize_t read;

//     /* function name */
//     read = getline(&line, &len, fp);
//     if (read <= 0) { free(line); pclose(fp); return false; }
//     if (read > 0 && line[read-1] == '\n') line[read-1] = '\0';
//     *out_func = strdup(line);

//     /* file:line */
//     read = getline(&line, &len, fp);
//     if (read <= 0) { free(line); pclose(fp); free(*out_func); *out_func=NULL; return false; }
//     if (read > 0 && line[read-1] == '\n') line[read-1] = '\0';
    
//     /* split file and line */
//     char *colon = strrchr(line, ':');
//     if (!colon) {
//         *out_file = strdup(line);
//         *out_line = 0;
//     } else {
//         *colon = '\0';
//         *out_file = strdup(line);
//         *out_line = atoi(colon + 1);
//     }

//     free(line);
//     pclose(fp);
//     return true;
// }