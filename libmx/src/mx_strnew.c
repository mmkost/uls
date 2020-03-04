#include "../inc/libmx.h"

char *mx_strnew(const int size) {
    char *s;

    if (size < 0)
        return NULL;
    s = malloc(sizeof(char) * (size + 1));
    for (int i = 0; i < size + 1; i++)
        s[i] = '\0';
    return s;
}
