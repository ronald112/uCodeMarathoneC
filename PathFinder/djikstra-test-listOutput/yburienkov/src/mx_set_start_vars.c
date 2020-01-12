#include "pathfinder.h"

int mx_set_start_vars(t_fin_out *fin_out, int src) {    
    fin_out->visit_marker_djik = (bool *)malloc(sizeof(bool) * fin_out->nmb_isld);
    fin_out->isld_weight = (int *)malloc(sizeof(int) * fin_out->nmb_isld);
    fin_out->l_parent = (t_list **)malloc(sizeof(t_list *) * fin_out->nmb_isld);
    fin_out->l_route = NULL;
    for (int i = 0; i < fin_out->nmb_isld; i++) {
        fin_out->isld_weight[i] = INT_MAX;
        fin_out->visit_marker_djik[i] = false;
        fin_out->l_parent[i] = NULL;
    }
    fin_out->isld_weight[src] = 0;
    fin_out->src = src;
    return 0;
}
