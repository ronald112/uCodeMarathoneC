#include "libmx.h"
void mx_pop_front(t_list **head) {
    if (*head) {        
        t_list *tmp = *head;
        (*head) = (*head)->next;
        free(tmp);
    }
}
