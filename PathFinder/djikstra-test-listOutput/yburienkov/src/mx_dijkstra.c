#include "pathfinder.h"

static int cmp(void *cmp_what, void *cmp_with) {
    int min_lnb = 0;
    if (*(int *)mx_lget_back_el(cmp_what) < *(int *)mx_lget_back_el(cmp_with))
        return -1;
    if (*(int *)mx_lget_back_el(cmp_what)
        == *(int *)mx_lget_back_el(cmp_with)) {
        min_lnb = mx_lget_min_int(cmp_what, cmp_with);

        for (int i = 1; i < min_lnb; ++i) {
            t_list *tmp1 = mx_lget_byindex(cmp_with, i);
            t_list *tmp2 = mx_lget_byindex(cmp_what, i);

            if (*(int *)tmp1->data != *(int *)tmp2->data) {
                return *(int *)tmp2->data - *(int *)tmp1->data;
            }
        }
    }
    return 1;
}

// calculate the path's
void mx_dijkstra(int src, t_grph *graph, t_fin_out *fin_out) {
    int min_ind = mx_set_start_vars(fin_out, src);

    for (int i = 0; i < fin_out->nmb_isld; i++) {
        min_ind = mx_get_min_distance(fin_out);
        fin_out->visit_marker_djik[min_ind] = true;
        for (int j = 0; j < fin_out->nmb_isld; j++)
            mx_add_parent_and_weight(graph, fin_out, min_ind, j);
    }

    mx_create_routes(fin_out);
    mx_sort_list_djkstra(fin_out->l_route, cmp); //
    mx_print_routes(fin_out, graph); //

    mx_free_djkstra(fin_out);
}
