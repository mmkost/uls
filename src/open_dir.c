#include "uls.h"

int main(int argc, char **argv) {
    struct dirent *de;
    DIR *dr = opendir(argv[argc - 1]);
    if (dr == NULL) {
        write(1,"error\n",6);
        return 0;
    }
    while ((de = readdir(dr)) != NULL) {
        printf("%s\t", de-> d_name);
    }
    closedir(dr);
    //system("leaks -q uls");
    return 0;
}
