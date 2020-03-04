#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    size_t i;
    const char *str = s;

    for (i = 0; i < n && str[i] != c; i++);
    if (str[i] == c)
        return (void *)&str[i];
    return NULL;
}
