#include "libmx.h"

// void mx_push_front(t_list **list, void *data) {
//     t_list *head = *list;
//     t_list *copy;

//     copy = mx_create_node(data);
//     copy->next = head;
//     *list = copy;
// }


// t_list *head = *list;
    // t_list *copy;

    // copy = mx_create_node(data);
    // copy->next = head;
    // *list = copy;

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
