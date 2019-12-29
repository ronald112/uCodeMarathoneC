#include "../inc/pathfinder.h"

void mx_set_weight_arr(t_grph *graph, t_main *vars, int arr[]) {
    graph->array[arr[0]][arr[1]] = mx_atoi(vars->str);
    graph->array[arr[1]][arr[0]] = mx_atoi(vars->str);
}
