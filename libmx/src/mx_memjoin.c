#include "../inc/libmx.h"

void *mx_memjoin(void *dst, void *src, size_t size, size_t len) {
    char *d = dst;
    char *s = src;

    for (int j = 0; j < (int)len; j++)
        d[size + j] = s[j];
    return dst;
}
