#include "../inc/libmx.h"

void mx_pop_front(t_list **list) {
    if (list && *list) {
        t_list *p = (*list)->next;

        free(*list);
        *list = p;
    }
    return;
}
