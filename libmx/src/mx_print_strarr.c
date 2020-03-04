#include "../inc/libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    int i;

    if (arr == NULL || *arr == NULL|| delim == NULL) 
        return;
    for (i = 0; arr[i + 1]; i++) {
        mx_printstr(arr[i]);
        mx_printstr(delim);
    }
    mx_printstr(arr[i]);
    mx_printchar('\n');
}
