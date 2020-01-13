#include "pathfinder.h"

void list_swap(void **lst1, void **lst2) {
    void *temp = *lst1;

    *lst1 = *lst2;
    *lst2 = temp;
}

int *mx_return_int(int num) {
    int *ret = (int *)malloc(sizeof(int));

    *ret = num;
    return ret;
}

t_list *mx_lget_byindex(t_list *list, int index) {
    t_list *temp = list;

    for (; temp && index--; temp = temp->next);
    return temp;
}

t_list *mx_cplist(t_list *src) {
    t_list *new_list = NULL;

    for(t_list *temp = src; temp; temp = temp->next) {
        mx_push_back(&new_list, mx_return_int(*(int *)temp->data));
    }
    return new_list;
}
