#include "uls.h"

int main(int argc, char **argv) {
    struct dirent *de; // Pointer for directory entry
    struct winsize ws;

    ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
    DIR *dr = opendir(".");

    if (dr == NULL) {
        perror("uls");
        return 0;
    }

    // mx_parse(argc, argv);

    t_list *p; 
    while ((de = readdir(dr)) != NULL) {
        print_de(*de);

        if(de->d_name[0] != '.') {
            if (p == NULL) {
                p = mx_create_node(de->d_name);
            }
            else {
                mx_push_back(&p, de->d_name);
            }
        }
    }

    // printf("here's your value %" PRIu64 "\n", )
    int l_s = mx_list_size(p);
    int l = mx_biggest(p);
    mx_mult_colum(p, ws.ws_col, l, l_s);   
    closedir(dr);
    return 0;
}
