#include "pathfinder.h"

// add path to parents arr
void mx_add_par_path(int j, t_dijk *djk_var, int min_ind) {
    int i = 0;

    for (; i < djk_var->nmb_isld && djk_var->parent[i][j] != -1; i++);
    if (djk_var->parent[i][j] == -1)
        djk_var->parent[i][j] = min_ind;
}
