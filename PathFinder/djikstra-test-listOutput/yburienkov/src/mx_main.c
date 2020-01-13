#include "pathfinder.h"

int main(int argc, char const *argv[]) {
    t_main *vars = mx_create_vars(0, 0);
    t_grph *graph;
    t_fin_out fin_out;

    vars->chk_valid_nmb_isld = 0;
    mx_check_valid_file(argc, argv[1], vars);
    graph = mx_create_graph(vars);
    graph->isld = mx_crt_isld_matrix(vars, graph);
    if (vars->nmb_isld != vars->chk_valid_nmb_isld) {
        mx_printerr("error: invalid number of islands\n");
        exit(1);
    }
    if (vars->nmb_isld == 0 && vars->chk_valid_nmb_isld == 0) {
        printf("debug1\n");
        return 0;
    }
    mx_crt_isld_matrix_copy(graph, vars);
    fin_out.nmb_isld = vars->nmb_isld;
    for (int i = 0; i < vars->nmb_isld - 1; i++)
        mx_dijkstra(i, graph, &fin_out);
    mx_free_fn(vars, graph);
    // system("leaks -q pathfinder");
    return 0;
}
// 2147483647
