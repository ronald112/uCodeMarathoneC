#include "pathfinder.h"

int mx_get_min_distance(t_fin_out *fin_out) {
    int min_val = INT_MAX;
    int min_ind = 0;

    for (int i = 0; i < fin_out->nmb_isld; i++)
        if (fin_out->visit_marker_djik[i] == false
            && fin_out->isld_weight[i] < min_val) {
            min_val = fin_out->isld_weight[i];
            min_ind = i;
        }
    return min_ind;
}
