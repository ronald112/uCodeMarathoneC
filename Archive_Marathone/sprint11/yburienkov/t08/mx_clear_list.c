#include "list.h"

void mx_clear_list(t_list **list){
    t_list *head = *list;
    t_list *temp = NULL;
    while(head -> next != NULL){
        temp = head -> next;
        free(head);
        head = temp;
    }
    free(head);
    head = NULL;
}
