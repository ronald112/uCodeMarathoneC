#include "pathfinder.h"

static int check_error_dist(t_main *vars, int j, int i) {
    int rslt_rdln = 1;

    if (j == 2)
        vars->cnt_n_readline++;
    if ((rslt_rdln = mx_get_rslt_rdline(vars, j)) < 1) {
        if (mx_strlen(vars->str) == 0 && j > 0) {
            printf("debug1\n");
            mx_wrong_line(i + 1);
        }
        if (j == 0 && mx_strlen(vars->str) == 0
            && vars->cnt_n_readline < vars->cnt_n) {
                printf("debug2\n");
            mx_wrong_line(i + 1);
        }
    }
    return rslt_rdln;
}

static void check_exstra_n(t_main *vars, int i) {
    if (vars->str[0] != '\0' ) {
        mx_wrong_line(i);
    }
}

char **mx_crt_isld_matrix(t_main *vars, t_grph *graph) {
    char **isld = (char **)malloc(vars->nmb_isld * sizeof(char *));
    int rslt_rdln = 1;
    int k = 0;
    int i = 0;

    for (; rslt_rdln > 0; i++)
        for (int j = 0; j < 3; j++) {
            if ((rslt_rdln = check_error_dist(vars, j, i)) < 1)
                break;
            mx_add_to_graph(vars, graph, j, i);
            if ((mx_check_isvalid_alpha(vars->str, j)) == 1) {
                if (j < 2)
                    k = mx_add_to_isld(vars, isld, k);
            }
            else
                mx_wrong_line(i + 1);
            mx_strdel(&vars->str);
        }
    check_exstra_n(vars, i);
    return isld;
}
