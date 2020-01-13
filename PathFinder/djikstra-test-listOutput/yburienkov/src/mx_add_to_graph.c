#include "pathfinder.h"

void mx_add_to_graph(t_main *vars, t_grph *graph, int j, int i) {
    char *itoa = mx_itoa(i + 1);

    if (j == 2) {
        printf("vars->str %s\n", vars->str);
        if (mx_atoi_pathfinder(vars->str) == 0 
            || mx_atoi_pathfinder(vars->str) < 0) {
            mx_printerr("error: line ");
            mx_printerr(itoa);
            mx_strdel(&itoa);
            mx_printerr(" isn't valid\n");
            exit(1);
        }
    }
    graph->file_str = mx_addstr(graph->file_str, vars->str);
    graph->file_str = mx_strjoin_mod1(graph->file_str, vars->delims[j]);
    mx_strdel(&itoa);
}
