#include "pathfinder.h"

// free djk_struct_parameters
void mx_free_djkstra(t_fin_out *fin_out) {
    free(fin_out->isld_weight);
    free(fin_out->visit_marker_djik);
    for (t_list *temp = fin_out->l_route; temp; temp = temp->next) {
        t_list *to_clear = temp->data;

        mx_clear_list(&to_clear);
    }
    for (int i = 0; i < fin_out->nmb_isld; i++) {
        mx_clear_list(&fin_out->l_parent[i]);
    }
    free(fin_out->l_parent);
    mx_clear_list(&fin_out->l_route);
}
