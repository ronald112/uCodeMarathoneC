#include "pathfinder.h"

int mx_find_route(t_dijk *djk_var, int y, char **isld) {
    int i = djk_var->nmb_isld - 1;
    int k = 0;
    int counter = 0;
    int chk_frst_ln = 0;

    for (int j = y; djk_var->parent[0][j] != -1; counter++) {
        i = djk_var->nmb_isld - 1;
        for (; i >= 0; i--)
            if (djk_var->parent[i][j] != -1
                && djk_var->is_chk_alt[i][j] != true) {
                mx_add_to_str(djk_var, j, i, isld);
                djk_var->is_chk_alt[i][j] = mx_check_first_line(i,
                &chk_frst_ln, &k);
                j = djk_var->parent[i][j];
                break;
            }
    }
    mx_print_route(djk_var, chk_frst_ln, k, y);
    mx_print_dist(counter, djk_var, y);
    return k;
}
