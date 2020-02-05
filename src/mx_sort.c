#include "uls.h"

t_list *mx_sort(t_list *lst){
    if (!lst )
        return lst;
    t_list *c;
    for (t_list *i = lst; i != NULL; i = i->next)
        for (t_list *j = i->next; j != NULL; j = j->next)
            if (mx_strcmp(i->data, j->data) > 0){
                c = i->data;
                i->data = j->data;
                j->data = c;
            }
    return lst;
}
