#include "libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    if (lst == NULL)
        return NULL;
    else {
        int swapped = 1;
        t_list *start = lst;
        t_list *end = NULL;

        for (; swapped == 1;) {
            swapped = 0;
            start = lst;
            for (int i = 0; start->next != end; start = start->next, i++) {
                if (cmp(start->data, start->next->data)) {
                    mx_swap_node(&start, &start->next);
                    swapped = 1;
                }
            }
            end = start;
        }
        return lst;
    }
}

