#include "../inc/libmx.h"

int mx_bin_search(char **arr, int l, int r, const char *s) {
    for (int m = l + (r - l) / 2; l <= r; m = l + (r - l) / 2) {
        if (mx_strcmp(arr[m], s) == 0)
            return m;
        (mx_strcmp(arr[m], s) < 0) ? (l = m + 1) : (r = m - 1);
    }
    return -1;
}
