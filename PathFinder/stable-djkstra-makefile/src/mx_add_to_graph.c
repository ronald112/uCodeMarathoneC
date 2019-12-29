#include "../inc/pathfinder.h"

void mx_add_to_graph(t_main *vars, t_grph *graph, int j) {
    graph->file_str = mx_addstr(graph->file_str, vars->str);
    graph->file_str = mx_strjoin_mod1(graph->file_str, vars->delims[j]);
}
