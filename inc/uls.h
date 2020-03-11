#ifndef ULS_H
#define ULS_H

#include "libmx/inc/libmx.h"
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <sys/types.h>
#include <sys/stat.h>


//int main(void);
t_list *mx_sort(t_list *lst);
int mx_biggest(t_list *p);
void mx_mult_colum(t_list *names, int win_size, int longest, int size_list);
void mx_parse(int argc, char **argv);

struct dirent d;

#endif
