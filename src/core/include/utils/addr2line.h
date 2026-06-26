#ifndef ADDR2LINE_H
#define ADDR2LINE_H

#include <stdint.h>

bool addr2line(const char *object_path,
                       void *addr,
                       void *base_addr,
                       char **out_func,
                       char **out_file,
                       uint64_t *out_line);

void addr2line_pool_destroy(void);

#endif // ADDR2LINE_H