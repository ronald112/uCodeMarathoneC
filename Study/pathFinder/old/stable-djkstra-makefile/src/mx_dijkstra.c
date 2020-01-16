#include "../inc/pathfinder.h"

// calculate the path's
void mx_dijkstra(int src, t_main *vars, t_grph *graph, t_dijk *djk_var) {
    int min_ind = mx_set_start_vars(vars, djk_var, src); 

    for (int i = 0; i < vars->nmb_isld - 1; i++) {
        min_ind = mx_get_min_distance(djk_var->isld_nm, djk_var->is_chk, vars);
        djk_var->is_chk[min_ind] = true;
        for (int j = src; j < vars->nmb_isld; j++) {
            mx_add_parent_and_weight(graph, djk_var, min_ind, j);
        }
    }
    mx_print_solution(djk_var, vars->nmb_isld, graph->isld, src);
}
