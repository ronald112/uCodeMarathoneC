#include "libmx.h"

void mx_pop_back(t_list **head) {
    t_list *tmp = *head;

    for (; tmp->next->next != NULL; tmp = tmp->next);
    free(tmp->next);
    tmp->next = NULL;
}
