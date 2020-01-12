#include "pathfinder.h"

// path
int mx_get_all_path(t_dijk *djk_var, int i, char **isld, int src) {
    int k = 0;
    int count = djk_var->cnt_parents;
    char *temp_indx = mx_itoa(src);

    djk_var->temp_i = 0;
    djk_var->temp_j = 0;
    djk_var->path[count] = mx_addstr(djk_var->path[count], isld[src]);
    djk_var->path[count] = mx_addstr(djk_var->path[count], " -> ");
    djk_var->path[count] = mx_addstr(djk_var->path[count], isld[i]);
    k = mx_find_route(djk_var, i, isld);
    djk_var->route_int[djk_var->cnt_parents] = mx_add_to_begin(
    mx_add_to_begin(djk_var->route_int[djk_var->cnt_parents], " -> "), temp_indx);
    djk_var->route_char[djk_var->cnt_parents] = mx_add_to_begin(
    mx_add_to_begin(djk_var->route_char[djk_var->cnt_parents], " -> "), isld[src]);
    djk_var->cnt_parents++;
    mx_strdel(&temp_indx);
    return k;
}

