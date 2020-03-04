#include "../inc/libmx.h"

void mx_printlist(t_list *p) {
    t_list *ptr = p;

    if (!p)
        return;
    for (; ptr->next != NULL; ptr = ptr->next) {
        mx_printstr(ptr->data);
        mx_printstr(" ");
    }
    mx_printstr(ptr->data);
}
