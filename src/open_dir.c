#include "uls.h"

int main(int argc, char **argv) {
    struct dirent *de;
    struct winsize ws;

    ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);

    printf("%d\n", ws.ws_col);
    DIR *dr = opendir(argv[argc - 1]);
    if (dr == NULL) {
        write(1, "error\n", 6);
        return 0;
    }
    t_list *p;
    while ((de = readdir(dr)) != NULL)
        if (p == NULL) {
            p = mx_create_node(de->d_name);
        }
        else {
            mx_push_back(&p, de->d_name);

        }
        
    p = mx_sort(p);
    //system("leaks -q uls");
    for (;p != NULL; p = p->next) {
        char *str = p->data;
        //system("leaks -q uls");
        if(str[0] != '.') {
            mx_printstr(p->data);
            mx_printchar('\t');
        }
        //mx_strdel(&str);
    } 
    closedir(dr);
    //system("leaks -q uls");
    return 0;
    system("leaks -q uls");
}

