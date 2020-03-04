#include "../inc/libmx.h"

_Bool mx_isspace(char c) {
    return (c == '\t' || c == '\n' || c == '\v'
            || c == '\f' || c == '\r' || c == ' ');
}
