#include "../inc/libmx.h"

int mx_list_size(t_list *list) {
    if (list) {
        int i = 1;
        t_list *temp = list;

        for (; temp->next != NULL; i++)
            temp = temp->next;
        return i;
    }
    return 0;
}
