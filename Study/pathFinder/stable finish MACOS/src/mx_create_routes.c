#include "pathfinder.h"

// Distance
static void add_route_to_list_node(t_fin_out *fin_out, t_list *route) {
    t_list *temp = NULL;
    int size = mx_list_size(fin_out->l_parent[*(int *)route->data]);

    for (int i = 0; i < size; ++i) {
        temp = fin_out->l_parent[*(int *)route->data];
        temp = mx_lget_byindex(temp, i);

        mx_push_front(&route, mx_return_int(*(int *)temp->data));
        if (fin_out->src != *(int *)route->data)
            add_route_to_list_node(fin_out, route);
        else
            mx_push_back(&fin_out->l_route, mx_cplist(route));
        mx_pop_front(&route);
    }
}

void mx_create_routes(t_fin_out *fin_out) {
    t_list *route = NULL;

    for (int i = fin_out->src + 1; i < fin_out->nmb_isld; ++i) {
        mx_push_front(&route, mx_return_int(i));
        add_route_to_list_node(fin_out, route);
        mx_pop_front(&route);
    }
}
