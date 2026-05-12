#include <lua.h>
#include <lauxlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/sendfile.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <wordexp.h>

#define BUF_SIZE 8192

/* helper: push error */
#define fileutils_error(L, fmt, ...) luaL_error(L, "fileutils: " fmt ": %s", ##__VA_ARGS__, strerror(errno))

/* helper: get path */
static inline char *fileutils_get_path(lua_State *L, int index) {
    const char *path = luaL_checkstring(L, index);
    wordexp_t p;

    if (wordexp(path, &p, 0) != 0 || p.we_wordc == 0) {
        luaL_error(L, "cannot expand path '%s'", path);
    }

    char *result = strdup(p.we_wordv[0]);
    wordfree(&p);
    return result;
}

/* helper: get file */
static inline FILE *fileutils_check_file(lua_State *L, int idx) {
    FILE **pf = (FILE **)luaL_checkudata(L, idx, "FILE*");
    if (!pf || !*pf) luaL_error(L, "invalid file");
    return *pf;
}


// Function: fileutils.exists(path: string) -> boolean
static int l_fileutils_exists(lua_State *L) {
    char *path = fileutils_get_path(L, 1);
    lua_pushboolean(L, access(path, F_OK) == 0);
    free(path);
    return 1;
}

// Function: fileutils.size(path: string) -> integer
static int l_fileutils_size(lua_State *L) {
    char *path = fileutils_get_path(L, 1);
    struct stat st;

    if (stat(path, &st) != 0) fileutils_error(L, "cannot get file size for '%s'", path);
    free(path);

    lua_pushinteger(L, st.st_size);
    return 1;
}


static inline size_t __copy_file(lua_State *L, const char *src, const char *dst, const char *dst_modes) {
    FILE *in = fopen(src, "rb");
    if (!in) {
        fileutils_error(L, "cannot open source file '%s'", src);
        return (size_t) -1;
    }


    FILE *out = fopen(dst, dst_modes);
    if (!out) {
        fclose(in);
        fileutils_error(L, "cannot open destination file '%s'", dst);
        return (size_t) -1;
    }

    char buf[BUF_SIZE];
    size_t n;
    size_t total = 0;
    
    while ((n = fread(buf, 1, BUF_SIZE, in)) > 0) {
        if (fwrite(buf, 1, n, out) != n) {
            fclose(in);
            fclose(out);
            fileutils_error(L, "error during file copy");
            return (size_t) -1;
        }
        total += n;
    }

    fclose(in);
    fclose(out);
    return total;
}

// Function: fileutils.cp(src: string, dst: string) -> integer
static int l_fileutils_cp(lua_State *L) {
    char *src = fileutils_get_path(L, 1);
    char *dst = fileutils_get_path(L, 2);

    size_t total = __copy_file(L, src, dst, "wb");
    if (total == (size_t) -1) fileutils_error(L, "cannot copy file '%s' to '%s'", src, dst);
    free(src);
    free(dst);

    lua_pushinteger(L, total);
    return 1;
}


static inline int __copy_dir(lua_State *L, const char *src, const char *dst) {
    size_t total = 0;
    struct stat st;

    if (stat(src, &st) < 0) fileutils_error(L, "cannot stat source directory '%s'", src);

    // Create destination directory if it doesn't exist
    if (mkdir(dst, st.st_mode) < 0) {
        if (errno != EEXIST) fileutils_error(L, "cannot create destination directory '%s'", dst);
    }

    DIR *dir = opendir(src);
    if (!dir) fileutils_error(L, "cannot open source directory '%s'", src);

    struct dirent *entry;

    size_t base_src_len = strlen(src) + 1;
    size_t base_dst_len = strlen(dst) + 1;

    size_t src_len = 0;
    size_t dst_len = 0;
    char *src_path = NULL;
    char *dst_path = NULL;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        src_len = base_src_len + strlen(entry->d_name) + 1;
        dst_len = base_dst_len + strlen(entry->d_name) + 1;

        src_path = (char *)malloc(src_len);
        dst_path = (char *)malloc(dst_len);

        snprintf(src_path, src_len, "%s/%s", src, entry->d_name);
        snprintf(dst_path, dst_len, "%s/%s", dst, entry->d_name);

        if (stat(src_path, &st) < 0) fileutils_error(L, "cannot stat source entry '%s'", src_path);

        if (S_ISDIR(st.st_mode)) {
            total += __copy_dir(L, src_path, dst_path);
        } else if (S_ISREG(st.st_mode)) {
            total += __copy_file(L, src_path, dst_path, "wb");
        }

        free(src_path);
        free(dst_path);
    }

    closedir(dir);
    return total;
}


// Function: cpdir(src: string, dst: string) -> integer
static int l_fileutils_cpdir(lua_State *L) {
    char *src = fileutils_get_path(L, 1);
    char *dst = fileutils_get_path(L, 2);

    size_t total = __copy_dir(L, src, dst);
    free(src);
    free(dst);
 
    lua_pushinteger(L, total);
    return 1;
}


// Function: fileutils.cat(src: string, dst: string) -> integer
static int l_fileutils_cat(lua_State *L) {
    char *src = fileutils_get_path(L, 1);
    char *dst = fileutils_get_path(L, 2);

    size_t total = __copy_file(L, src, dst, "ab");
    free(src);
    free(dst);

    if (total == (size_t) -1) fileutils_error(L, "cannot concatenate file");

    lua_pushinteger(L, total);
    return 1;
}

static inline ssize_t __zero_copy_files(lua_State *L, const char *src, const char *dst, int dst_flags) {
    int in_fd = open(src, O_RDONLY);
    if (in_fd < 0) {
        fileutils_error(L, "cannot open source file '%s'", src);
        return -1;
    };

    int out_fd = open(dst, O_WRONLY | O_CREAT | dst_flags, 0644);
    if (out_fd < 0) {
        fileutils_error(L, "cannot open destination file '%s'", dst);
        close(in_fd);
        return -1;
    }

    if (dst_flags == 0 && lseek(out_fd, 0, SEEK_END) == (off_t)-1) {
        fileutils_error(L, "cannot seek to end of destination file '%s'", dst);
        close(in_fd);
        close(out_fd);
        return -1;
    }

    struct stat st;
    if (fstat(in_fd, &st) != 0) {
        fileutils_error(L, "cannot stat source file '%s'", src);
        close(in_fd);
        close(out_fd);
        return -1;
    }

    off_t remaining = st.st_size;
    ssize_t total = 0;
    ssize_t sent = 0;

    while (remaining > 0) {
        sent = sendfile(out_fd, in_fd, NULL, remaining);
        if (sent <= 0) {
            fileutils_error(L, "error during zero-copy file transfer from '%s' to '%s'", src, dst);
            close(in_fd);
            close(out_fd);
            return -1;
        }
       
        remaining -= sent;
    }

    close(in_fd);
    close(out_fd);

    return total;
}

// Function: fileutils.zcp(src: string, dst: string) -> integer
static int l_fileutils_zcp(lua_State *L) {
    char *src = fileutils_get_path(L, 1);
    char *dst = fileutils_get_path(L, 2);

    ssize_t total = __zero_copy_files(L, src, dst, O_TRUNC);
    free(src);
    free(dst);

    if (total < 0) fileutils_error(L, "cannot zero-copy file");

    lua_pushinteger(L, total);
    return 1;
}


// Function: fileutils.zcat(src: string, dst: string) -> integer
static int l_fileutils_zcat(lua_State *L) {
    char *src = fileutils_get_path(L, 1);
    char *dst = fileutils_get_path(L, 2);

    ssize_t total = __zero_copy_files(L, src, dst, 0);
    free(src);
    free(dst);

    if (total < 0) fileutils_error(L, "cannot zero-concatenate file");

    lua_pushinteger(L, total);
    return 1;
}

// Function: fileutils.mv(src: string, dst: string) -> nil
static int l_fileutils_mv(lua_State *L) {
    char *src = fileutils_get_path(L, 1);
    char *dst = fileutils_get_path(L, 2);

    if (rename(src, dst) != 0) fileutils_error(L, "cannot move file '%s' to '%s'", src, dst);

    free(src);
    free(dst);

    return 0;
}

// Function: fileutils.rm(path: string) -> nil
static int l_fileutils_rm(lua_State *L) {
    char *path = fileutils_get_path(L, 1);

    if (unlink(path) != 0) fileutils_error(L, "cannot remove file '%s'", path);

    free(path);

    return 0;
}

// Function: fileutils.basename(path: string) -> string
static int l_fileutils_basename(lua_State *L) {
    char *path = fileutils_get_path(L, 1);
    const char *base = strrchr(path, '/');
    if (base) {
        lua_pushstring(L, base + 1);
    } else {
        lua_pushstring(L, path);
    }
    free(path);
    return 1;
}

// Function: fileutils.realpath(path: string) -> string
static int l_fileutils_realpath(lua_State *L) {
    char *path = fileutils_get_path(L, 1);
    char resolved[4096];
    char* p = realpath(path, resolved);
    if (!p) fileutils_error(L, "cannot resolve real path of '%s'", path);
    free(path);
    lua_pushstring(L, resolved);
    return 1;
}

// Function: fileutils.dirname(path: string) -> string
static int l_fileutils_dirname(lua_State *L) {
    char *path = fileutils_get_path(L, 1);
    const char *base = strrchr(path, '/');
    if (base) {
        size_t dir_len = base - path;
        char *dir = (char *)malloc(dir_len + 1);
        if (!dir) {
            free(path);
            fileutils_error(L, "memory allocation failed");
        }
        strncpy(dir, path, dir_len);
        dir[dir_len] = '\0';
        lua_pushstring(L, dir);
        free(dir);
    } else {
        lua_pushstring(L, ".");
    }
    free(path);
    return 1;
}

// Function: fileutils.join(...) -> string
static int l_fileutils_join(lua_State *L) {
    int nargs = lua_gettop(L);
    if (nargs < 2) {
        fileutils_error(L, "join requires at least 2 arguments");
    }
    size_t capacity = 256;
    size_t len = 0;
    char *result = malloc(capacity);
    if (!result) fileutils_error(L, "memory allocation failed");

    result[0] = '\0';

    for (int i = 1; i <= nargs; i++) {
        char *part = fileutils_get_path(L, i);
        size_t part_len = strlen(part);

        // If absolute path: reset result
        if (part[0] == '/') {
            len = 0;
            result[0] = '\0';
        }

        // Ensure enough space
        while (len + part_len + 2 > capacity) {
            capacity *= 2;
            char *tmp = realloc(result, capacity);
            if (!tmp) {
                free(result);
                free(part);
                fileutils_error(L, "memory allocation failed");
            }
            result = tmp;
        }

        // Add separator if needed
        if (len > 0 && result[len - 1] != '/' && part[0] != '/') {
            result[len++] = '/';
            result[len] = '\0';
        }

        // Avoid double slashes
        const char *to_copy = part;
        if (len > 0 && result[len - 1] == '/' && part[0] == '/') {
            to_copy = part + 1;
            part_len--;
        }

        memcpy(result + len, to_copy, part_len);
        len += part_len;
        result[len] = '\0';

        free(part);
    }

    lua_pushstring(L, result);
    free(result);
    return 1;
}

// Function: fileutils.has_extension(path: string, ext: string) -> string
static int l_fileutils_has_extension(lua_State *L) {
    char *path = fileutils_get_path(L, 1);
    const char *ext = luaL_checkstring(L, 2);

    const char *dot = strrchr(path, '.');
    if (dot) {
        lua_pushboolean(L, strcmp(dot + 1, ext) == 0);
    } else {
        lua_pushboolean(L, 0);
    }

    free(path);
    return 1;
}

// Function: fileutils.remove_extension(path: string) -> string
static int l_fileutils_remove_extension(lua_State *L) {
    char *path = fileutils_get_path(L, 1);
    char *dot = strrchr(path, '.');
    if (dot) *dot = '\0';

    lua_pushstring(L, path);
    free(path);
    return 1;
}

// Function: fileutils.is_absolute(path: string) -> boolean
static int l_fileutils_is_absolute(lua_State *L) {
    char *path = fileutils_get_path(L, 1);
    lua_pushboolean(L, path[0] == '/');
    free(path);
    return 1;
}

// Function: fileutils.is_dir(path: string) -> boolean
static int l_fileutils_is_dir(lua_State *L) {
    char *path = fileutils_get_path(L, 1);
    struct stat st;
    if (stat(path, &st) != 0) fileutils_error(L, "cannot stat file '%s'", path);
    free(path);

    lua_pushboolean(L, S_ISDIR(st.st_mode));
    return 1;
}

// Function: fileutils.is_file(path: string) -> boolean
static int l_fileutils_is_file(lua_State *L) {
    char *path = fileutils_get_path(L, 1);
    struct stat st;
    if (stat(path, &st) != 0) fileutils_error(L, "cannot stat file '%s'", path);
    free(path);

    lua_pushboolean(L, S_ISREG(st.st_mode));
    return 1;
}

// Function: fileutils.mkdir(path: string) -> nil
static int l_fileutils_mkdir(lua_State *L) {
    char *path = fileutils_get_path(L, 1);
    int res = mkdir(path, 0755);
    if (errno == EEXIST) {
        free(path);
        return 0; // Ignore if directory already exists
    }
    if (res != 0) fileutils_error(L, "cannot create directory '%s'", path);
    free(path);
    return 0;
}

// Function: fileutils.rmdir(path: string) -> nil
static int l_fileutils_rmdir(lua_State *L) {
    char *path = fileutils_get_path(L, 1);
    if (rmdir(path) != 0) fileutils_error(L, "cannot remove directory '%s'", path);
    free(path);
    return 0;
}

// Function: fileutils.listdir(path: string) -> table
static int l_fileutils_listdir(lua_State *L) {
    char *path = fileutils_get_path(L, 1);
    DIR *dir = opendir(path);
    if (!dir) fileutils_error(L, "cannot open directory '%s'", path);
    free(path);

    lua_newtable(L);
    struct dirent *entry;
    int index = 1;

    while ((entry = readdir(dir)) != NULL) {
        lua_pushstring(L, entry->d_name);
        lua_rawseti(L, -2, index++);
    }

    closedir(dir);
    return 1;
}

// Function: fileutils.check_in_env(filename: string, env_var: string) -> path | nil
static int l_fileutils_check_in_env(lua_State *L) {
    const char *filename = luaL_checkstring(L, 1);
    const char *env_var = luaL_checkstring(L, 2);
    const char *env_value = getenv(env_var);
    if (!env_value) {
        lua_pushnil(L);
        return 1;
    }

    char *paths = strdup(env_value);
    if (!paths) {
        lua_pushnil(L);
        return 1;
    }

    char *saveptr;
    char *dir = strtok_r(paths, ":", &saveptr);

    while (dir) {
        char full_path[4096];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir, filename);

        if (access(full_path, F_OK) == 0) {
            free(paths);
            lua_pushstring(L, full_path);
            return 1;
        }

        dir = strtok_r(NULL, ":", &saveptr);
    }

    free(paths);
    lua_pushnil(L);
    return 1;
}

#define write_bytes(L, f, arg, type) { \
    type v = (type)luaL_checknumber(L, arg++); \
    if (fwrite(&v, 1, sizeof(v), f) != sizeof(v)) { \
        fileutils_error(L, "write error"); \
    } \
    break; \
}

static int l_fileutils_write_pack(lua_State *L) {
    FILE *f = fileutils_check_file(L, 1);
    const char *fmt = luaL_checkstring(L, 2);

    int arg = 3;

    while (*fmt) {
        switch (*fmt++) {
            case 'b': write_bytes(L, f, arg, signed char);
            case 'B': write_bytes(L, f, arg, unsigned char);
            case 'h': write_bytes(L, f, arg, short);
            case 'H': write_bytes(L, f, arg, unsigned short);
            case 'l': write_bytes(L, f, arg, long);
            case 'L': write_bytes(L, f, arg, unsigned long);
            case 'f': write_bytes(L, f, arg, float);
            case 'd': write_bytes(L, f, arg, double);
            case 'T': write_bytes(L, f, arg, size_t);
            case 'i': write_bytes(L, f, arg, int);
            case 'I': write_bytes(L, f, arg, unsigned int);
            case ' ': break;
            default: luaL_error(L, "invalid format '%c'", *(fmt - 1));
        }
    }
    return 0;
}

#define IN_BUF_SIZE  (3 * 4096)   // multiple of 3
#define OUT_BUF_SIZE (4 * 4096)

static const char b64_table[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static int l_fileutils_to_b64(lua_State *L) {
    char* in_filename  = fileutils_get_path(L, 1);
    char* out_filename = fileutils_get_path(L, 2);
    const char* mode = luaL_checkstring(L, 3);

    FILE* in = fopen(in_filename, "rb");
    if (!in) fileutils_error(L, "cannot open input file");
    free(in_filename);

    FILE *out = fopen(out_filename, mode);
    if (!out) fileutils_error(L, "cannot open output file");
    free(out_filename);

    uint8_t ibuf[IN_BUF_SIZE];
    uint8_t obuf[OUT_BUF_SIZE];

    size_t bytes_read;

    while ((bytes_read = fread(ibuf, 1, IN_BUF_SIZE, in)) > 0) {
        size_t i = 0, o = 0;

        // Process full 3-byte chunks
        size_t full_chunks = bytes_read / 3 * 3;

        for (; i < full_chunks; i += 3) {
            uint32_t triple = (ibuf[i] << 16) | (ibuf[i + 1] << 8) | (ibuf[i + 2]);

            obuf[o++] = b64_table[(triple >> 18) & 0x3F];
            obuf[o++] = b64_table[(triple >> 12) & 0x3F];
            obuf[o++] = b64_table[(triple >> 6) & 0x3F];
            obuf[o++] = b64_table[triple & 0x3F];
        }

        // Handle remainder (at most 2 bytes)
        if (i < bytes_read) {
            uint32_t triple = ibuf[i] << 16;
            if (i + 1 < bytes_read)
                triple |= ibuf[i + 1] << 8;

            obuf[o++] = b64_table[(triple >> 18) & 0x3F];
            obuf[o++] = b64_table[(triple >> 12) & 0x3F];

            if (i + 1 < bytes_read) {
                obuf[o++] = b64_table[(triple >> 6) & 0x3F];
            } else {
                obuf[o++] = '=';
            }

            obuf[o++] = '=';
        }

        fwrite(obuf, 1, o, out);
    }

    fclose(in);
    fclose(out);

    return 0;
}

/* ===================== register ===================== */
#define register_function(fname) {#fname, l_fileutils_##fname}

static const struct luaL_Reg fileutils[] = {
    register_function(exists),
    register_function(size),
    register_function(cp),
    register_function(cat),
    register_function(zcp),
    register_function(zcat),
    register_function(mv),
    register_function(rm),
    register_function(basename),
    register_function(realpath),
    register_function(dirname),
    register_function(join),
    register_function(has_extension),
    register_function(remove_extension),
    register_function(is_absolute),
    register_function(is_dir),
    register_function(is_file),
    register_function(mkdir),
    register_function(rmdir),
    register_function(cpdir),
    register_function(listdir),
    register_function(check_in_env),
    register_function(write_pack),
    register_function(to_b64),
    {NULL, NULL}
};

int luaopen_fileutils(lua_State *L) {
    luaL_register(L, "fileutils", fileutils);
    return 1;
}