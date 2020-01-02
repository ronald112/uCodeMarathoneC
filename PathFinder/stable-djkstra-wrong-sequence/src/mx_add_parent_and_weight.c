#include "pathfinder.h"

void mx_add_parent_and_weight(t_grph *graph, t_dijk *djk_var,
    int min_ind, int j) {
    if (graph->array[min_ind][j] && djk_var->isld_nm[min_ind] != INT_MAX
        && djk_var->isld_nm[min_ind] + graph->array[min_ind][j]
        < djk_var->isld_nm[j]) {
        djk_var->parent[0][j] = min_ind;
        djk_var->isld_nm[j] = djk_var->isld_nm[min_ind]
        + graph->array[min_ind][j];
    } 
    else if (graph->array[min_ind][j] && djk_var->isld_nm[min_ind] != INT_MAX
        && djk_var->isld_nm[min_ind] + graph->array[min_ind][j]
        == djk_var->isld_nm[j]) {
        mx_add_par_path(j, djk_var, min_ind);
    }	
}
