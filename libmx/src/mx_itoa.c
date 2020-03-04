#include "../inc/libmx.h"

char *mx_itoa(int number) {
    unsigned int m = (number < 0) ? -number : number;
    int i = 0;
    int v;
    char *s = mx_strnew(11);

    for (v = 1; m / v >= 10; v *= 10);
    if (number < 0)
        s[i++] = '-';
    for (; v > 0; v /= 10)
        s[i++] = ((m / v) % 10) + '0';
    return s;
}
