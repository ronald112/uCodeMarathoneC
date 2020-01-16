#include "pathfinder.h"

bool mx_check_first_line(t_dijk  *djk_var, int i, int *chk_frst_ln, int *k) {
    if (i != 0) {
        if (djk_var->cnt_before != 0 && djk_var->index_for_sort[djk_var->cnt_before - 1] == djk_var->cnt_parents) {
        }
        else {
            djk_var->cnt_before++;
            djk_var->index_for_sort[djk_var->cnt_before - 1] = djk_var->cnt_parents;
        }
        *chk_frst_ln = i;
        *k = *k + 1;
        return true;
    }
    return false;
}
