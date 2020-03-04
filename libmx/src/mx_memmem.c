#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little,
                size_t little_len) {
    const char *b;

    if (big_len < little_len || little_len == 0 || big_len == 0)
        return NULL;
    b = big;
    while (big_len >= little_len && (mx_memcmp(b, little, little_len) != 0)) {
        b++;
        big_len--;
    }
    return (big_len < little_len) ? NULL : (void *)b;
}
