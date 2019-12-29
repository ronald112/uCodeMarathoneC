#include "../inc/pathfinder.h"

void mx_check_valid_frst_line(t_main *vars) {
    if ((mx_check_valid_1Line(vars->str)) == 0) {
        if (vars->str) 
            mx_strdel(&vars->str);
        mx_printerr("error: line 1 isn't valid\n");
        exit(1);
    }
    else {
        vars->nmb_isld = mx_atoi(vars->str);		
        if (vars->str) 
            mx_strdel(&vars->str);
    }
}
