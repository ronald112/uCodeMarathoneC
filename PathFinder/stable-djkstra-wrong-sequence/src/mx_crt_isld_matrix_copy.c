#include "pathfinder.h"

// add node to graph
void mx_crt_isld_matrix_copy(t_grph *graph, t_main *vars) {
    int arr[2] = {0};
    int index = 0;
    int i = 0;
    vars->chk_valid_nmb_isld = 2;
    
    for (int j = 0; graph->file_str[i] != '\0'; i++)
        if (graph->file_str[i] != vars->delims[j])
            vars->str = mx_strjoin_mod1(vars->str, graph->file_str[i]);
        else if (j < 2 && ++j) {
            for (int k = 0; k < vars->nmb_isld; k++)
                if (mx_strcmp(vars->str, graph->isld[k]) == 0) {
                    arr[index++] = k;
                    free(vars->str);
                    vars->str = mx_strnew(0);
                }
        }
        else {
            mx_set_weight_arr(graph, vars, arr);
            mx_free_vars_str(vars, &j, &index);
        }
}
