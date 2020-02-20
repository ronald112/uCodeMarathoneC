#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    if (*list == NULL) {
        *list = mx_create_node(data);
    }
    else {
        t_list *cur = *list;

        for (; cur->next != NULL; cur = cur->next);
        cur->next = mx_create_node(data);
    }
}

