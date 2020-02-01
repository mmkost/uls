#include "uls.h"

static _Bool mx_cmp(void * str1, void * str2) {
    char * s1 = (char *) str1;
    char * s2 = (char *) str2;

    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] > s2[i])
           return true;
    }
    return false;
}

int main(int argc, char **argv) {
    struct dirent *de;
    DIR *dr = opendir(argv[argc - 1]);
    if (dr == NULL) {
        write(1, "error\n", 6);
        return 0;
    }

    t_list *p;
    
    if ((de = readdir(dr)) != NULL)
        p = mx_create_node(de -> d_name);
    while ((de = readdir(dr)) != NULL)
        mx_push_back(&p, de -> d_name);

    for (t_list *k = p; k -> next; k = k -> next) {
        mx_printstr(k -> data);
        mx_printstr("\t");
    }

    mx_printstr("\n");

    mx_sort_list(p, &mx_cmp);

    for (t_list *k = p; k -> next; k = k -> next) {
        mx_printstr(k -> data);
        mx_printstr("\t");
    }
    
        //if (mx_strcmp(de -> d_name,argv[1]) == 0){
    
        //}
            //printf("%s\t", de-> d_name);
    
    closedir(dr);
    //system("leaks -q uls");
    return 0;
}

