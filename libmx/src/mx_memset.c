#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    for (char *s = b; len-- > 0; *(s++) = c);
    return b;
}
