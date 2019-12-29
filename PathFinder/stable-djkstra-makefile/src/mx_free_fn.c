#include "../inc/pathfinder.h"

void mx_free_fn(t_main *vars, t_grph *graph, t_dijk *djk_var) {    
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
