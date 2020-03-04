#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub,
                        const char *replace) {
    if (str && sub && replace) {
        int n = mx_strlen(sub);
        int count = mx_count_substr(str, sub);
        char *s = mx_strnew(mx_strlen(str) - (n - mx_strlen(replace)) * count);
        int j = 0;

        for (int x; count-- > 0; j += n) {
            x = j;
            j = mx_get_substr_index(str + x, sub) + x;
            mx_strncat(s, str + x, j - x);
            mx_strcat(s, replace);
        }
        mx_strcat(s, &str[j]);
        return s;
    }
    return NULL;
}
