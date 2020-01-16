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
    graph->array[arr[0]][arr[1]] = mx_atoi_pathfinder(vars->str);
    graph->array[arr[1]][arr[0]] = mx_atoi_pathfinder(vars->str);
}
