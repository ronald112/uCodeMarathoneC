#include "pathfinder.h"

// free djk_struct_parameters
void mx_free_djkstra(t_dijk *djk_var) {
    free(djk_var->isld_nm);
    free(djk_var->is_chk);
    for (int i = 0; i < djk_var->nmb_isld; i++)
        free(djk_var->is_chk_alt[i]);
    free(djk_var->is_chk_alt);
    for (int i = 0; i < djk_var->nmb_isld; i++)
        free(djk_var->parent[i]);
    free(djk_var->parent);
}
