#include "pathfinder.h"

void mx_add_to_str(t_dijk *djk_var, int j, int i, char **isld) {
    char *temp = mx_get_nb_way(djk_var, j, i);
    char *temp_indx = mx_itoa(j);

    djk_var->route_char[djk_var->cnt_parents] = mx_add_to_begin(
    mx_add_to_begin(djk_var->route_char[djk_var->cnt_parents], " -> "), isld[j]);
    djk_var->route_int[djk_var->cnt_parents] = mx_add_to_begin(
    mx_add_to_begin(djk_var->route_int[djk_var->cnt_parents], " -> "), temp_indx);
    djk_var->dist[djk_var->cnt_parents] = mx_add_to_begin(
    mx_add_to_begin(djk_var->dist[djk_var->cnt_parents], " + "), temp);
    mx_strdel(&temp);
    mx_strdel(&temp_indx);
}
