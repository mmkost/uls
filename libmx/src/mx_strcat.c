#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int i = mx_strlen(s1);
    int n = mx_strlen(s2);

    for (int j = 0; j < n + 1; j++) 
        s1[i + j] = s2[j];
    return s1;
}
