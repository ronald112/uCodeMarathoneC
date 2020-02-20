#include "list.h"

void mx_push_index(t_list **list, void *data, int index) {
    t_list *new_node = mx_create_node(data);
    t_list *temp_left = *list; 
    int flag = 0;
    if (index <= 1) {
        mx_push_front(list, data);
    } else {
           
        for(int i = 0; i < index - 1; i++) {
            if (temp_left->next->next->next == NULL) {
                mx_push_back(list, data);
                i = index;
                flag = 1;
            } else
            temp_left = temp_left->next; 
        }
        if (flag != 1) {
            new_node->next = temp_left->next;
            temp_left->next = new_node;
        }
        
    }    
}
