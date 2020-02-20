#include "libmx.h"

void mx_clear_list(t_list **list){
    if (list && *list) {
        while (*list)
            mx_pop_front(list);
    }
}
