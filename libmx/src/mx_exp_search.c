#include "../inc/libmx.h"

int mx_exp_search(char **arr, int size, const char *s) {
    int i = 1;

    if (mx_strcmp(arr[0], s) == 0)
        return 0;
    for (; i < size && mx_strcmp(arr[i], s) <= 0; i *= 2);
    return mx_bin_search(arr, i/2, (i < size) ? i : size, s);
}
