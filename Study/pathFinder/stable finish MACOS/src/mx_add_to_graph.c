#include "pathfinder.h"

void mx_add_to_graph(t_main *vars, t_grph *graph, int j, int i) {
    char *itoa = mx_itoa(i + 1);

    if (j == 2) {
        if (mx_atoi_pathfinder(vars->str) < 0) {
            printf("debug\n");
            mx_printerr("error: line ");
            mx_printerr(itoa);
            mx_strdel(&itoa);
            mx_printerr(" is not valid\n");
            exit(1);
        }
    }
    if (vars->nmb_isld == 0) {
        mx_printerr("error: invalid number of islands\n");
        exit(1);
    }
    graph->file_str = mx_addstr(graph->file_str, vars->str);
    graph->file_str = mx_strjoin_mod1(graph->file_str, vars->delims[j]);
    mx_strdel(&itoa);
}
