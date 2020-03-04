#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    void *dst;

    if (!ptr)
        return malloc(size);
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    size_t len = ((int) size > mx_strlen((char *)ptr)) ? size : mx_strlen(ptr);

    dst = malloc(len);
    if (!dst)
        return dst;
    mx_memmove(dst, ptr, (len < malloc_size(ptr)) ? len : malloc_size(ptr));
    free(ptr);
    return dst;
}
