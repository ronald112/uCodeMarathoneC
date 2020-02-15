#include "list.h"

 void mx_pop_front(t_list **list) {   
    t_list *head = *list;    
        
        (*list) = (*list)->next;
        free(head);
        
    
}
