#include "pathfinder.h"

int *mx_return_int(int num) {
    int *ret = (int *)malloc(sizeof(int));

    *ret = num;
    return ret;
}

t_list *mx_lget_lat(t_list *list, int index) {
    t_list *temp = list;

    for (; temp && index--; temp = temp->next);
    return temp;
}

t_list *mx_cplist(t_list *src) {
    t_list *new_list = NULL;

    for(t_list *temp = src; temp; temp = temp->next) {
        mx_push_back(&new_list, mx_return_int(*(int *)temp->data));
    }
    return new_list;
}

static void add_route_to_list_node(t_fin_out *fin_out, t_list *route) {
    t_list *temp = NULL;
    int size = mx_list_size(fin_out->l_parent[*(int *)route->data]);

    for (int i = 0; i < size; ++i) {
        temp = fin_out->l_parent[*(int *)route->data];
        temp = mx_lget_lat(temp, i);

        mx_push_front(&route, mx_return_int(*(int *)temp->data));

        if (fin_out->src != *(int *)route->data) {
            add_route_to_list_node(fin_out, route);
        }
        else
            mx_push_back(&fin_out->l_route, mx_cplist(route));
        mx_pop_front(&route);
    }
}

static void mx_create_routes(t_fin_out *fin_out) {
    t_list *route = NULL;

    for (int i = fin_out->src + 1; i < fin_out->nmb_isld; ++i) {
        mx_push_front(&route, mx_return_int(i));
        add_route_to_list_node(fin_out, route);
        mx_pop_front(&route);
    }
}

static void mx_print_route(t_fin_out *fin_out, t_grph *graph, t_list *route) {
    t_list *temp = NULL;
    int list_size = mx_list_size(route);

    for (int i = 0; i < list_size - 1 && fin_out; i++) {
        temp = mx_lget_lat(route, i);
        mx_printstr(graph->isld[*(int *)temp->data]);
        mx_printstr(" -> ");
    }
    temp = mx_lget_lat(route, list_size - 1);
    mx_printstr(graph->isld[*(int *)temp->data]);
}

void *mx_lget_back_el(t_list *src) {
    t_list *temp = src;

    for (; temp->next; temp = temp->next);
    return temp->data;
}

static void mx_print_dst(t_fin_out *fin_out, t_list *route) {
    t_list *temp = NULL;
    int list_size = mx_list_size(route);
    int dist = 0;

    for (int i = 1; i < list_size - 1; i++) {
        temp = mx_lget_lat(route, i);
        mx_printint(fin_out->isld_weight[*(int *)temp->data] - dist);
        mx_printstr(" + ");
        dist = fin_out->isld_weight[*(int *)temp->data];
    }
    mx_printint(fin_out->isld_weight[*(int *)mx_lget_back_el(route)] - dist);
    mx_printstr(" = ");
    mx_printint(fin_out->isld_weight[*(int *)mx_lget_back_el(route)]);
}

static void mx_print_routes(t_fin_out *fin_out, t_grph *graph) {
    for (t_list *temp = fin_out->l_route; temp; temp = temp->next) {
        mx_printstr("========================================\n");
        mx_printstr("Path: ");
        mx_printstr(graph->isld[fin_out->src]);
        mx_printstr(" -> ");
        mx_printstr(graph->isld[*(int *)mx_lget_back_el(temp->data)]);
        mx_printstr("\nRoute: ");
        mx_print_route(fin_out, graph, temp->data);
        mx_printstr("\nDistance: ");
        if (mx_list_size(temp->data) > 2)
            mx_print_dst(fin_out, temp->data);
        else
            mx_printint(fin_out->isld_weight[
                *(int *)mx_lget_back_el(temp->data)]);
        mx_printstr("\n========================================\n");
    }
}

// calculate the path's
void mx_dijkstra(int src, t_grph *graph, t_fin_out *fin_out) {
    
    int min_ind = mx_set_start_vars(fin_out, src);
    // int temp = 0;

    for (int i = 0; i < fin_out->nmb_isld; i++) {
        min_ind = mx_get_min_distance(fin_out);
        fin_out->visit_marker_djik[min_ind] = true;
        for (int j = 0; j < fin_out->nmb_isld; j++)
            mx_add_parent_and_weight(graph, fin_out, min_ind, j);
    }
    mx_create_routes(fin_out);

    // mx_sort_list(t.routes, cmp); //
    mx_print_routes(fin_out, graph); //

    // for (int k = 0; k < djk_var->nmb_isld; k++)
    //     for (int i = 0; i < djk_var->nmb_isld - 1; i++)
    //         for (int j = 0; j < djk_var->nmb_isld; j++)
    //             if (djk_var->parent[i][j] != -1 && djk_var->parent[i + 1][j] != -1
    //                 && djk_var->parent[i][j] < djk_var->parent[i + 1][j]) {
    //                 temp = djk_var->parent[i][j];
    //                 djk_var->parent[i][j] = djk_var->parent[i + 1][j];
    //                 djk_var->parent[i + 1][j] = temp;
    //             }

    // for (int i = 0; i < djk_var->nmb_isld; i++) {
    //     for (int j = 0; j < djk_var->nmb_isld; j++) {
    //         printf("%3d", djk_var->parent[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    // mx_print_solution(djk_var, vars->nmb_isld, graph->isld, src);
    mx_free_djkstra(fin_out);
}
