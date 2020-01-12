#include "pathfinder.h"

void mx_check_first_line(t_dijk  *djk_var, int i, int *j, int *chk_frst_ln) {
    if (i != 0 && djk_var->temp_i != 0 && djk_var->temp_j != 0) {
        djk_var->is_chk_alt[djk_var->temp_i][djk_var->temp_j] = false;
    }
    if (i != 0) {
        if (djk_var->cnt_before != 0
        && djk_var->cnt_parents
        == djk_var->index_for_sort[djk_var->cnt_before - 1])
            djk_var->cnt_before--;
        djk_var->cnt_before++;
        djk_var->index_for_sort[djk_var->cnt_before - 1]
        = djk_var->cnt_parents;
        djk_var->is_chk_alt[i][*j] = true;
        djk_var->temp_i = i;
        djk_var->temp_j = *j;
    }

    *j = djk_var->parent[i][*j];
    *chk_frst_ln += i;
}

