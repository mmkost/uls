#include "../inc/libmx.h"

int mx_strchr(char *s, char delim, int size) {
    for (int i = 0; i < size; i++)
        if (s[i] == delim)
            return i;
    return -1;
}
