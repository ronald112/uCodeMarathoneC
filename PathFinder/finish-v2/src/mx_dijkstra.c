#include "pathfinder.h"

// calculate the path's
void mx_dijkstra(int src, t_main *vars, t_grph *graph, t_dijk *djk_var) {
    int min_ind = mx_set_start_vars(vars, djk_var, src);
    int temp = 0;

    for (int i = 0; i < vars->nmb_isld; i++) {
        min_ind = mx_get_min_distance(djk_var->isld_nm,
                                        djk_var->is_chk, vars);
        djk_var->is_chk[min_ind] = true;
        for (int j = 0; j < vars->nmb_isld; j++)
            mx_add_parent_and_weight(graph, djk_var, min_ind, j);
    }

    for (int i = 0; i < djk_var->nmb_isld - 1; i++) {
        for (int j = 0; j < djk_var->nmb_isld; j++) {
            printf("%3d", djk_var->parent[i][j]);
        }
        printf("\n");
    }
printf("\n");printf("\n");printf("\n");
    for (int k = 0; k < djk_var->nmb_isld; k++)
        for (int i = 0; i < djk_var->nmb_isld - 1; i++)
            for (int j = 0; j < djk_var->nmb_isld; j++)
                if (djk_var->parent[i][j] != -1 && djk_var->parent[i + 1][j] != -1
                    && djk_var->parent[i][j] < djk_var->parent[i + 1][j]) {
                    temp = djk_var->parent[i][j];
                    djk_var->parent[i][j] = djk_var->parent[i + 1][j];
                    djk_var->parent[i + 1][j] = temp;
                }

    for (int i = 0; i < djk_var->nmb_isld - 1; i++) {
        for (int j = 0; j < djk_var->nmb_isld; j++) {
            printf("%3d", djk_var->parent[i][j]);
        }
        printf("\n");
    }printf("\n");printf("\n");printf("\n");

    mx_print_solution(djk_var, vars->nmb_isld, graph->isld, src);
}
