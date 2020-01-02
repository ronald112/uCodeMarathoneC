#include "pathfinder.h"

int mx_get_rslt_rdline(t_main *vars, int j) {
    int rslt_rdln = 1;

    rslt_rdln = mx_read_line(&vars->str, 1, vars->delims[j], vars->fd);
    return rslt_rdln;    
}
