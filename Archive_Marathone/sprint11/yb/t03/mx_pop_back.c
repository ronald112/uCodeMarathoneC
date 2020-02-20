#include "list.h"

void mx_pop_back(t_list **list) {   
    t_list *head = *list;

    
        if (head->next == NULL) {
            head = NULL;
            free(head);
        }
        while (head->next->next != NULL) 
            head = head->next;

        free(head->next);
        head->next = NULL;
    
}
