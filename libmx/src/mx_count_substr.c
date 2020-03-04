#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int count = 0;
    int m;
    int n;

    if (!str || !sub)
        return -1;
    if (!*sub)
        return 0;
    n = mx_strlen(sub);
    m = mx_strlen(str) - n + 1;

    for (int i = 0; i < m; i++)
        if (mx_strncmp(&str[i], sub, n) == 0) {
            count++;
            i += n - 1;
        }
    return count;
}
