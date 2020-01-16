#include "pathfinder.h"

int mx_set_start_vars(t_main *vars, t_dijk *djk_var, int src) {
    djk_var->nmb_isld = vars->nmb_isld;
    djk_var->isld_nm = (int *)malloc(vars->nmb_isld * sizeof(int));
    djk_var->is_chk = (bool *)malloc(vars->nmb_isld * sizeof(bool));
    djk_var->parent = (int **)malloc(vars->nmb_isld * sizeof(int *));
    djk_var->is_chk_alt = (bool **)malloc(vars->nmb_isld * sizeof(bool *));

    for (int i = 0; i < vars->nmb_isld; i++) {
        djk_var->parent[i] = (int *)malloc(vars->nmb_isld * sizeof(int));
        for (int j = 0; j < vars->nmb_isld; j++)
            djk_var->parent[i][j] = -1;
        djk_var->is_chk_alt[i] =
        (bool *)malloc(vars->nmb_isld * sizeof(bool));
        for (int j = 0; j < vars->nmb_isld; j++)
            djk_var->is_chk_alt[i][j] = 0;
        djk_var->isld_nm[i] = INT_MAX;
        djk_var->is_chk[i] = false;
    }
    djk_var->isld_nm[src] = 0;
    return 0;
}
