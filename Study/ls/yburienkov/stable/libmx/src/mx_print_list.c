#include "libmx.h"

void mx_print_list(t_list **n) {
    t_list *temp = *n;

    while (temp != NULL) {
        mx_printstr("[");
        mx_printstr(temp->data);
        mx_printstr("]");
        mx_printstr(" ");
        temp = temp->next;
    }
}
