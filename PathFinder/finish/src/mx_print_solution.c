#include "pathfinder.h"

void mx_print_solution(t_dijk *djk_var, int n, char **isld, int src) {
    int k = 1;

    for (int i = src; i < n; i++) {
        if (djk_var->isld_nm[i] != 0) {
            for (; k > 0;)               
                k = mx_print_all(djk_var, i, isld, src);            
            k = 1;
            mx_set_to_false_checker(djk_var);
        }
    }    
    mx_free_djkstra(djk_var);
}
