#include "pathfinder.h"

// Distance
void mx_print_dist(int counter, t_dijk *djk_var, int y) {    
    if (counter != 1) {
        mx_printstr("\nDistance: ");
        mx_printstr(djk_var->dist);
        mx_printstr(" = ");
        mx_printint(djk_var->isld_nm[y]);
        mx_printstr("\n");
    }
    else {
        mx_printstr("\nDistance: ");
        mx_printint(djk_var->isld_nm[y]);
        mx_printstr("\n");
    } 
    if (djk_var->dist) 
        mx_strdel(&djk_var->dist);
}
