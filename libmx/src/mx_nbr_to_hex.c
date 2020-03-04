#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    int i;
    unsigned long temp = nbr;
    char *res;

    for (i = 0; temp / 16; i++)
        temp /= 16;
    res = malloc(i * sizeof(char));
    for (; i >= 0 ; i--) {
		temp = nbr % 16;
        res[i] = (temp < 10) ? temp + 48 : temp + 87;
		nbr /= 16;
	}
    return res;
}
