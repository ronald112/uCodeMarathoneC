#include "../inc/pathfinder.h"

void mx_add_to_str(t_dijk *djk_var, int j, int i, char **isld) {
    char *temp = mx_get_nb_way(djk_var, j, i);

    djk_var->route = mx_add_to_begin(
    mx_add_to_begin(djk_var->route, " -> "), isld[j]);
    djk_var->dist = mx_add_to_begin(
    mx_add_to_begin(djk_var->dist, " + "), temp);
    mx_strdel(&temp);
}
