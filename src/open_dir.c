#include "uls.h"

int main(int argc, char **argv) {
    struct dirent *de;
    struct winsize ws;

    ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);

    DIR *dr = opendir(argv[argc - 1]);
    if (dr == NULL) {
        write(1, "error\n", 6);
        return 0;
    }
    t_list *p; 
    while ((de = readdir(dr)) != NULL)
        if(de->d_name[0] != '.') {
            if (p == NULL) {
                p = mx_create_node(de->d_name);
            }
            else {
                mx_push_back(&p, de->d_name);
            }
        }
        int l_s = mx_list_size(p);
        int l = mx_biggest(p);
        mx_mult_colum(p, ws.ws_col, l, l_s);   
        closedir(dr);
        return 0;
}
