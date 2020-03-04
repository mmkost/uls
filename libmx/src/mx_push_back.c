#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *p = mx_create_node(data);

    if (p && list) {
        p->data = data;
        p->next = NULL;
        if(!(*list))
            *list = p;
        else {
            t_list *last = *list;

            while(last->next)
                last = last->next;
            last->next = p;
        }
    }
    return;
}
