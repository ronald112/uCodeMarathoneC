#include "pathfinder.h"

static void mx_set_final_output(t_dijk *djk_var, t_main *vars) {
    djk_var->cnt_parents = 0;
    djk_var->path = (char **)malloc(vars->nmb_isld
    * vars->nmb_isld * sizeof(char *));
    djk_var->route = (char **)malloc(vars->nmb_isld
    * vars->nmb_isld * sizeof(char *));
    djk_var->dist = (char **)malloc(vars->nmb_isld
    * vars->nmb_isld * sizeof(char *));
    for (int i = 0; i < vars->nmb_isld * vars->nmb_isld; i++) {
        djk_var->path[i] = NULL;
        djk_var->route[i] = NULL;
        djk_var->dist[i] = NULL;
    }
}

static void mx_print_all_path(t_dijk *djk_var) {
    mx_bubble_sort(djk_var->route, djk_var->cnt_parents);

    for (int i = 0; i < djk_var->cnt_parents; i++) {
        mx_printstr("========================================\n");
        mx_printstr("Path: ");
        mx_printstr(djk_var->path[i]);
        mx_printstr("\nRoute: ");
        mx_printstr(djk_var->route[i]);
        mx_printstr("\nDistance: ");
        mx_printstr(djk_var->dist[i]);
        mx_printstr("\n========================================\n");
    }
}

int main(int argc, char const *argv[]) {
    t_main *vars = mx_create_vars(0, 0);
    t_dijk *djk_var = (t_dijk *)malloc(sizeof(t_dijk));
    t_grph *graph;
    vars->chk_valid_nmb_isld = 0;

    mx_check_valid_file(argc, argv[1], vars);
    graph = mx_create_graph(vars);
    graph->isld = mx_crt_isld_matrix(vars, graph);
    if (vars->nmb_isld != vars->chk_valid_nmb_isld) {
        mx_printerr("error: invalid number of islands\n");
        exit(1);
    }
    mx_crt_isld_matrix_copy(graph, vars);
    mx_set_final_output(djk_var, vars);

    for (int i = 0; i < vars->nmb_isld - 1; i++) 
        mx_dijkstra(i, vars, graph, djk_var);
    mx_print_all_path(djk_var);
    // printf("djk_var->cnt_parents %d\n", djk_var->cnt_parents);
    mx_free_fn(vars, graph, djk_var);

    // system("leaks -q pathfinder");
    return 0;
}
