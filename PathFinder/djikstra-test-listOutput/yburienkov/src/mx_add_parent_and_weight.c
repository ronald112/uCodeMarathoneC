#include "pathfinder.h"

void mx_add_parent_and_weight(t_grph *graph, t_fin_out *fin_out,
    int min_ind, int j) {
    if (!fin_out->visit_marker_djik[j] && graph->array[min_ind][j]
        && fin_out->isld_weight[min_ind] != INT_MAX
        && fin_out->isld_weight[min_ind] + graph->array[min_ind][j]
        < fin_out->isld_weight[j]) {
        mx_clear_list(&fin_out->l_parent[j]);
        mx_push_front(&fin_out->l_parent[j], mx_return_int(min_ind));
        fin_out->isld_weight[j] = fin_out->isld_weight[min_ind]
        + graph->array[min_ind][j];
    }
    else if (!fin_out->visit_marker_djik[j] && graph->array[min_ind][j]
        && fin_out->isld_weight[min_ind] != INT_MAX
        && fin_out->isld_weight[min_ind] + graph->array[min_ind][j]
        == fin_out->isld_weight[j]) {
        mx_push_front(&fin_out->l_parent[j], mx_return_int(min_ind));
    }
}
