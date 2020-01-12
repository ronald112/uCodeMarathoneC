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
                if (j != 0 && j != y) {
                    // printf("\n  i%3d\n  j%3d\n  y%3d\n", i, j, y);
                    k += i;
                }
                mx_check_first_line(djk_var, i, &j, &chk_frst_ln);
                break;
            }
    }
    // if (y >= 12) {
    // for (int i = 0; i < djk_var->nmb_isld; i++) {
    //     printf("%3s", isld[i]);
    // }
    // printf("\n");
    // for (int i = 0; i < djk_var->nmb_isld; i++) {
    //     for (int j = 0; j < djk_var->nmb_isld; j++) {
    //         printf("%3d", djk_var->is_chk_alt[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    // }

    mx_set_false_arr(djk_var, k, y);
    mx_write_dist(counter, djk_var, y);
    // printf("%3d %3d %3d %3d %3d\n", chk_frst_ln, counter, k, y, djk_var->cnt_parents);
    return chk_frst_ln;
}
