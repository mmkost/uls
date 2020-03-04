#include "../inc/libmx.h"

_Bool mx_isdigit(char c) {
    return ((c > 47) && (c < 58)) ? true : false;
}
