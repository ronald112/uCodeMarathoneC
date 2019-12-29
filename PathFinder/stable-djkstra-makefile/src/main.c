#include "../inc/pathfinder.h"

int main(int argc, char const *argv[]) {
    t_main *vars = create_vars(0, 0);
    t_dijk *djk_var = (t_dijk *)malloc(sizeof(t_dijk));
    t_grph *graph;
    int chk_valid_nmb_isld = 0;

    mx_check_valid_file(argc, argv[1], vars);
    graph = mx_create_graph(vars);    
    graph->isld = mx_crt_isld_matrix(vars, graph, &chk_valid_nmb_isld);
    if (vars->nmb_isld != chk_valid_nmb_isld - 1) {
        mx_printerr("error: invalid number of islands\n");
        exit(1); 
    }    
    mx_crt_isld_matrix_copy(graph, vars);
    for (int i = 0; i < vars->nmb_isld - 1; i++) {
        mx_dijkstra(i, vars, graph, djk_var);
    }
    mx_free_fn(vars, graph, djk_var);
    return 0;
}
