#include "../inc/pathfinder.h"

int mx_find_route(t_dijk *djk_var, int y, char **isld) {    
    int k = 0;
    int counter = 0;
    int chk_frst_ln = 0;
    int cp_y = y;
    
    for (int i = djk_var->nmb_isld - 1; 
        djk_var->parent[0][y] != -1; counter++)
        for (; i >= 0; i--)
            if (djk_var->parent[i][y] != -1  
                && djk_var->is_chk_alt[i][y] != true) {
                mx_add_to_str(djk_var, y, i, isld);
                djk_var->is_chk_alt[i][y] = mx_check_first_line(i,
                &chk_frst_ln, &k);
                y = djk_var->parent[i][y];
                i = 0;
                break;
            }
    mx_print_route(djk_var, chk_frst_ln, k, y);
    mx_print_dist(counter, djk_var, cp_y);
    return k;
}
