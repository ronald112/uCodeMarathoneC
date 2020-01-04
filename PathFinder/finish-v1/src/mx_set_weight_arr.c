#include "pathfinder.h"

void mx_set_weight_arr(t_grph *graph, t_main *vars, int arr[]) {
    if (mx_strlen(vars->str) > 9) {
        mx_printerr("error: line ");
        mx_printerr(mx_itoa(vars->chk_valid_nmb_isld));
        mx_printerr(" isn't valid\n");
        exit(1);
    }
    else 
        vars->chk_valid_nmb_isld++;
    graph->array[arr[0]][arr[1]] = mx_atoi(vars->str);
    graph->array[arr[1]][arr[0]] = mx_atoi(vars->str);
}
