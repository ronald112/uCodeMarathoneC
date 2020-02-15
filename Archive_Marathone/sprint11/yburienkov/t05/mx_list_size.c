#include "list.h"

 int mx_list_size(t_list *list) {   
    int counter = 1; 
    if (list == NULL)   
        return 0;
    for(;list->next != NULL; list = list->next, counter++);
    return counter;
}
