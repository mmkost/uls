#include "libmx.h"

// _Bool bmx_strcmp(char *s1, char *s2) {
//     return (*s1 > *s2) ? true : false;
// }

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)){
    if (!lst )
        return lst;
    void *c;
    for (t_list *i = lst; i -> next; i = i -> next)
        for (t_list *j = i -> next; j; j = j -> next)
            if (cmp(i -> data, j -> data)){
                c = i -> data;
                i -> data = j -> data;
                j -> data = c;
            }
    return lst;
}

// int main(void) {
//     char *s1 = "45";
//     char *s3 = "2"; 
//     char *s2 = "3";
//     char *s4 = "77";
//     t_list *p1 = mx_create_node(s2);
//     mx_push_front(&p1, s1);
//     mx_push_back(&p1, s3);
//     mx_push_front(&p1, s4);
//     mx_printlist(p1);
//     //mx_pop_front(&p1);
//     //mx_printlist(p1);
//     //mx_pop_back(&p1);
//     //mx_printlist(p1);
//     mx_sort_list(p1, bmx_strcmp);
//     mx_printlist(p1);
//     return 0;
// }

