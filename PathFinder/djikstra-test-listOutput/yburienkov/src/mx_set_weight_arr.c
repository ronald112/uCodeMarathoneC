#include "pathfinder.h"

int mx_atoi_pathfinder(const char *str) {
    long int result = 0;
    while ((mx_isdigit(*str) != 1)) {
        str++;
    }
    while ((mx_isdigit(*str) == 1)) {
        result = ((result + (int)*str - 48) * 10);
        str++;
    }
    result /= 10;
    if (result > INT_MAX) {
        return -1;
    }
    return result;
}

void mx_set_weight_arr(t_grph *graph, t_main *vars, int arr[]) {
    if (mx_atoi_pathfinder(vars->str) < 0) {
        mx_printerr("error: line ");
        mx_printerr(mx_itoa(vars->chk_valid_nmb_isld));
        mx_printerr(" isn't valid\n");
        exit(1);
    }
    else
        vars->chk_valid_nmb_isld++;
    graph->array[arr[0]][arr[1]] = mx_atoi_pathfinder(vars->str);
    graph->array[arr[1]][arr[0]] = mx_atoi_pathfinder(vars->str);
}
