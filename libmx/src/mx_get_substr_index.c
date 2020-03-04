#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (str && sub) {
        int m = mx_strlen(sub);
        int n;

        if (m == 0)
            return mx_strlen(str);
        n = mx_strlen(str) - m + 1;

        for (int i = 0; i < n; i++)
            if (mx_strncmp(&str[i], sub, m) == 0)
                return i;
        return -1;
    }
    return -2;
}
