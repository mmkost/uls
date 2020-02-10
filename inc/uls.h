#ifndef ULS_H
#define ULS_H

#include "libmx/inc/libmx.h"
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/ioctl.h>

//int main(void);
t_list *mx_sort(t_list *lst);
int mx_biggest(t_list *p);

#endif
