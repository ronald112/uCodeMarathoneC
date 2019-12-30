#include "pathfinder.h"

int mx_get_min_distance(int *dist, bool *is_chek, t_main *vars) {
    int min_val = INT_MAX;
    int min_ind = 0;

    for (int i = 0; i < vars->nmb_isld; i++) 
        if (is_chek[i] == false && dist[i] < min_val) {
            min_val = dist[i];
            min_ind = i;
        }
    return min_ind;
}
