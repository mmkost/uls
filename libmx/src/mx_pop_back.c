#include "../inc/libmx.h"

void mx_pop_back(t_list **head) {
    t_list *temp = NULL;

    if (!head || !*head)
        return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    }
    else {
        temp = *head;
        for (; temp->next->next; temp = temp->next);
        free(temp->next);
        temp->next = NULL;
    }
}
