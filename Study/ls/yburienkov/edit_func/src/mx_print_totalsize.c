#include "uls.h"

void mx_print_totalsize(t_catalog *cat) {
    mx_printstr("total ");
    mx_printull(cat->size_of_block);
    mx_printstr("\n");
}
