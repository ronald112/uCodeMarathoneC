#include "list.h"

// t_list *mx_create_node(void *data) {
//     t_list *new = (t_list *)malloc(sizeof(t_list));
//     new -> data = data;
//     new -> next = NULL;
//     return new;
// }

void mx_push_front(t_list **list, void *data) {
    t_list *head = *list;
    t_list *copy;

    copy = mx_create_node(data);
    copy->next = head;
    *list = copy;
}
