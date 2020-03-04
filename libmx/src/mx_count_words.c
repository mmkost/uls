#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    int rez = 0;

    if (!str)
        return -1;
    if (!c)
        return 1;
    for (int i = 0; str[i]; i++)
        if (str[i] != c)
            for (rez++; (str[i + 1] != c) && str[i + 1]; i++);
    return rez;
}
