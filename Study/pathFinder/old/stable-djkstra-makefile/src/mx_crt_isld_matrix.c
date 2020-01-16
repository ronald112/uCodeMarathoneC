#include "../inc/pathfinder.h"

char **mx_crt_isld_matrix(t_main *vars, t_grph *graph, int *chk_nmb_isld) {
    char **isld = (char **)malloc(vars->nmb_isld * sizeof(char *));
    int rslt_rdln = 1;
    int k = 0;
    int flag = 1;

    for (; rslt_rdln > 0 ; *chk_nmb_isld = *chk_nmb_isld + 1)
        for (int j = 0; j < 3; j++) {
            // printf("debug 1\n");
            if ((rslt_rdln = mx_get_rslt_rdline(vars, j)) < 1)
                break;
            mx_add_to_graph(vars, graph, j);
            if ((mx_check_isvalid_alpha(vars->str, j)) == 1) {
                if (j < 2)
                    k = mx_add_to_isld(vars, isld, flag, k);
            }
            else 
                mx_wrong_line(*chk_nmb_isld);
            mx_strdel(&vars->str);
        }
    return isld;
}
