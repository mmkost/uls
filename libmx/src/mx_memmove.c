#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    void *buf = malloc(len);

    mx_memcpy(buf, src, len);
    mx_memcpy(dst, buf, len);
    free(buf);
    return dst;
}
