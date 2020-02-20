#include "list.h"

const int mx_list_size(t_list *list) {
    if(list == NULL) return 0;
    int counter = 1;
    t_list *node = list;
    while (node -> next != NULL) {
        node = node -> next;
        counter++;
    }
    return counter;
}

void mx_pop_index(t_list **list, int index) {
    t_list *tmp = *list;
    t_list *link = NULL;
    if(index <= 0) {
        mx_pop_front(list);
    }
    else {
        if(index == mx_list_size(*list)-1) {
            mx_pop_back(list);
        }
        
        else {
            for(int i = 0; i < index - 2; i++) {
            tmp = tmp -> next;
            }
            link = tmp -> next -> next;
            //free(tmp -> next -> data);
            free(tmp -> next);
            tmp -> next = link;
        }
    }
}
