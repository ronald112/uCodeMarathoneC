#include "list.h"

void mx_push_front(t_list **list, void *data) {
    t_list *head = *list;
    t_list *copy;

    copy = mx_create_node(data);
    copy->next = head;
    *list = copy;
}
