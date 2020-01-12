#include "libmx.h"

void mx_clear_list(t_list **list){
    if (list && *list) {
        while (*list)
            mx_pop_front(list);
    }
}

// t_list *head = *list;
    // t_list *temp = NULL;
    // while(head -> next != NULL){
    //     temp = head -> next;
    //     free(head);
    //     head = temp;
    // }
    // free(head);
    // head = NULL;
    // t_list *head = *list;
    // t_list *temp = NULL;
    // while(head != NULL) {
    //     temp = head->next;
    //     free(head);
    //     head = temp;
    // }
    // *list = NULL;
