#include "pathfinder.h"

// Distance
void mx_print_dist(int counter, t_dijk *djk_var, int y) {
    char *temp = mx_itoa(djk_var->isld_nm[y]);

    if (counter != 1) {
        djk_var->dist[djk_var->cnt_parents] = mx_addstr(djk_var->dist[djk_var->cnt_parents], " = ");
        djk_var->dist[djk_var->cnt_parents] = mx_addstr(djk_var->dist[djk_var->cnt_parents], temp);
        // mx_printstr("\nDistance: ");
    }
    else {
        // mx_printstr("\nDistance: ");
        if (djk_var->dist[djk_var->cnt_parents])
            mx_strdel(&djk_var->dist[djk_var->cnt_parents]);
        djk_var->dist[djk_var->cnt_parents] = mx_strdup(temp);
    }
    if (temp)
        mx_strdel(&temp);
}
