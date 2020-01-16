#include "pathfinder.h"

void mx_free_vars_str(t_main *vars, int *j, int *index) {
    free(vars->str);
    vars->str = mx_strnew(0);
    *j = 0;
    *index = 0;
}
