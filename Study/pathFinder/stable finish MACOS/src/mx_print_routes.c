#include "pathfinder.h"

static void print_route(t_fin_out *fin_out, t_grph *graph, t_list *route) {
    t_list *temp = NULL;
    int list_size = mx_list_size(route);

    for (int i = 0; i < list_size - 1 && fin_out; i++) {
        temp = mx_lget_byindex(route, i);
        mx_printstr(graph->isld[*(int *)temp->data]);
        mx_printstr(" -> ");
    }
    temp = mx_lget_byindex(route, list_size - 1);
    mx_printstr(graph->isld[*(int *)temp->data]);
}

void *mx_lget_back_el(t_list *src) {
    t_list *temp = src;

    for (; temp->next; temp = temp->next);
    return temp->data;
}

static void print_dst(t_fin_out *fin_out, t_list *route) {
    t_list *temp = NULL;
    int list_size = mx_list_size(route);
    int dist = 0;

    for (int i = 1; i < list_size - 1; i++) {
        temp = mx_lget_byindex(route, i);
        mx_printint(fin_out->isld_weight[*(int *)temp->data] - dist);
        mx_printstr(" + ");
        dist = fin_out->isld_weight[*(int *)temp->data];
    }
    mx_printint(fin_out->isld_weight[*(int *)mx_lget_back_el(route)] - dist);
    mx_printstr(" = ");
    mx_printint(fin_out->isld_weight[*(int *)mx_lget_back_el(route)]);
}

void mx_print_routes(t_fin_out *fin_out, t_grph *graph) {
    for (t_list *temp = fin_out->l_route; temp; temp = temp->next) {
        mx_printstr("========================================\n");
        mx_printstr("Path: ");
        mx_printstr(graph->isld[fin_out->src]);
        mx_printstr(" -> ");
        mx_printstr(graph->isld[*(int *)mx_lget_back_el(temp->data)]);
        mx_printstr("\nRoute: ");
        print_route(fin_out, graph, temp->data);
        mx_printstr("\nDistance: ");
        if (mx_list_size(temp->data) > 2)
            print_dst(fin_out, temp->data);
        else
            mx_printint(fin_out->isld_weight[
            *(int *)mx_lget_back_el(temp->data)]);
        mx_printstr("\n========================================\n");
    }
}
