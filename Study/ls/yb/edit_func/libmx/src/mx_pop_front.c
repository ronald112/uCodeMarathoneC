#include "libmx.h"

void mx_pop_front(t_list **head) {
    if (*head && head) {
        t_list *temp = *head;

        temp = temp->next;
        if (malloc_size((*head)->data))
            free((*head)->data);
        free(*head);
        *head = temp;
    }
}
