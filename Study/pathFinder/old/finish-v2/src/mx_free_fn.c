#include "pathfinder.h"

void mx_free_fn(t_main *vars, t_grph *graph, t_dijk *djk_var) {
    for (int i = 0; i < vars->nmb_isld * vars->nmb_isld; i++) {
        free(djk_var->path[i]);
        djk_var->path[i] = NULL;

        free(djk_var->dist[i]);
        djk_var->dist[i] = NULL;

        free(djk_var->route[i]);
        djk_var->route[i] = NULL;
    }
    free(djk_var->path);
    free(djk_var->dist);
    free(djk_var->route);
    free(djk_var->index_for_sort);
    free(djk_var);

    for (int i = 0; i < vars->nmb_isld; i++)
        free(graph->isld[i]);
    free(graph->isld);
    if (graph->file_str)
        mx_strdel(&graph->file_str);
    for (int i = 0; i < vars->nmb_isld; ++i)
        free(graph->array[i]);
    free(graph->array);
    free(graph);
    close(vars->fd);
    if (vars->str)
        mx_strdel(&vars->str);
    if (vars)
        free(vars);
}
