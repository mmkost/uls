#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
    int fd = open(file, 'r');
    int len = 0;
    char *str;

    if (fd < 0)
        return NULL;
    for (char buf; read(fd, &buf, sizeof(char)); len++);
    close(fd);

    fd = open(file, 'r');
    if (fd < 0 || len <= 0)
        return NULL;

    str = mx_strnew(len);
    read(fd, str, len);
    close(fd);
    return str;
}
