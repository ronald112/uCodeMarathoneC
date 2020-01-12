#include "pathfinder.h"

char *mx_get_nb_way(t_dijk *djk_var, int j, int i) {
    char *temp = mx_itoa(djk_var->isld_nm[j] -
    djk_var->isld_nm[djk_var->parent[i][j]]);

    return temp;
}
