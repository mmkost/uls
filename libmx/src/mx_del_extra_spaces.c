#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (str) {
        char *temp = mx_strnew(mx_strlen(str));
        char *s;
        int j = 0;

        for (int i = 0; str[i]; temp[j++] = str[i++])
            if (mx_isspace(str[i]))
                for (temp[j++] = ' '; mx_isspace(str[i]); i++);
        s = mx_strtrim(temp);
        free(temp);
        return s;
    }
    return NULL;
}
