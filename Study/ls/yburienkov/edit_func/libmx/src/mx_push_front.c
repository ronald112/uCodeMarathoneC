#include "libmx.h"

void mx_push_front(t_list **list, void *data) {
    t_list *temp = NULL;

    if (*list && list) {
        temp = mx_create_node(data);
        temp->next = *list;
        *list = temp;
    }
    else
        *list = (temp = mx_create_node(data));
}
