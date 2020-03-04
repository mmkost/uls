#include "../inc/libmx.h"

int mx_atoi(char *str) {
    int sign = 1;
    int sum = 0;

    for (; mx_isspace(*str); str++);
    if (*str == '-' || *str == '+') {
        if (*str == '-')
            sign = -1;
        str++;
    }

    for (; mx_isdigit(*str); str++)
        sum = 10 * sum + sign * (*str - '0');
    return sum;
}
