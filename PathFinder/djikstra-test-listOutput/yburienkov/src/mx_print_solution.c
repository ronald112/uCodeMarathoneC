#include "pathfinder.h"

void mx_print_solution(t_dijk *djk_var, int n, char **isld, int src) {
    int k = 1;
    int temp = 0;
    int count = 0;

    for (int j = src; j < n; j++) {
        if (djk_var->isld_nm[j] != 0) {
            for (; k > 0;) {
                k = mx_get_all_path(djk_var, j, isld, src);
            }

            // printf("%d\n", djk_var->cnt_parents);
            // mx_bubble_sort_djkstra(djk_var, j, djk_var->cnt_parents);
            // temp = djk_var->cnt_parents;
            k = 1;
            mx_set_to_false_checker(djk_var);
        }
    }
}
