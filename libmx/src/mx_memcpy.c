#include "../inc/libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    const char *s = src;
	
	for (char *d = dst; n-- > 0; *(d++) = *(s++));
	return dst;
}
