#include "pathfinder.h"

// path
int mx_print_all(t_dijk *djk_var, int i, char **isld, int src) {
    int k = 0;
    djk_var->dist = NULL;
    djk_var->route = NULL;

    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(isld[src]);
    mx_printstr(" -> ");
    mx_printstr(isld[i]);
    mx_printstr("\nRoute: ");
    mx_printstr(isld[src]);
    mx_printstr(" -> ");    
    k = mx_find_route(djk_var, i, isld);
    mx_printstr("========================================\n");
    return k;
}
