#include "pathfinder.h"

int mx_lget_min_int(void *cmp_what, void *cmp_with) {
    int min_lnb = 0;

    if (mx_list_size(cmp_what) < mx_list_size(cmp_with))
        min_lnb = mx_list_size(cmp_what);
    else
        min_lnb = mx_list_size(cmp_with);
    return min_lnb;
}

t_list *mx_sort_list_djkstra(t_list *lst, int (*cmp)(void *, void *)) {
    int swapped = 1;
    t_list *start = lst;
    t_list *end = NULL;

    if (lst == NULL) return NULL;
    for (; swapped == 1;) {
        swapped = 0;
        start = lst;
        for (int i = 0; start->next != end; start = start->next, i++) {
            if (cmp(start->data, start->next->data) > 0) {
                list_swap(&start->data, &start->next->data);
                swapped = 1;
            }
        }
        end = start;
    }
    return lst;
}
