#include "../inc/pathfinder.h"

int mx_add_to_isld(t_main *vars, char **isld, int flag, int k) {   
    for (int d = 0; d < k; d++)
        if ((flag = mx_strcmp(vars->str, isld[d])) == 0) 
            break;
    if (flag != 0) 
        isld[k++] = mx_strdup(vars->str);
    if (k > vars->nmb_isld) {
        mx_printerr("error: invalid number of islands\n");
        exit(1);        
    }
    return k;
}
