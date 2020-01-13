#include "pathfinder.h"

void mx_check_valid_frst_line(t_main *vars) {
    if ((mx_check_valid_1Line(vars->str)) == 0) {
        if (vars->str)
            mx_strdel(&vars->str);        
        mx_printerr("error: line 1 isn't valid\n");
        exit(1);
    }
    else {
        vars->nmb_isld = mx_atoi_pathfinder(vars->str);
        if (vars->nmb_isld > 99999 || vars->nmb_isld < 0) {
            mx_printerr("error: line 1 isn't valid\n");
            exit(1);
        }
        if (vars->str)
            mx_strdel(&vars->str);
    }
}
