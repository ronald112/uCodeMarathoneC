#include "libmx.h"

void mx_swap_node(t_list **swap_to, t_list **swap_with) {
    t_list *copy = mx_create_node((*(swap_to))->data);
    
    (*(swap_to))->data = (*(swap_with))->data;
    (*(swap_with))->data = copy->data;
    mx_clear_list(&copy);
}
