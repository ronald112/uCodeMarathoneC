#include "pathfinder.h"

void mx_bubble_sort_djkstra(t_dijk *djk_var, int left, int right) {
    int was_swapped = 1;
    char *temp;

    for (;was_swapped != 0;) {
        was_swapped = 0;
        for (int i = left; i < right; i++) {
            if (mx_strcmp(djk_var->route_int[i], djk_var->route_int[i + 1]) > 0) {
                temp = djk_var->route_int[i];
                djk_var->route_int[i] = djk_var->route_int[i + 1];
                djk_var->route_int[i + 1] = temp;
                printf("%s %s\n", djk_var->route_int[i], djk_var->route_int[i + 1]);

                temp = djk_var->route_char[i];
                djk_var->route_char[i] = djk_var->route_char[i + 1];
                djk_var->route_char[i + 1] = temp;
                printf("%s %s\n", djk_var->route_char[i], djk_var->route_char[i + 1]);

                temp = djk_var->dist[i];
                djk_var->dist[i] = djk_var->dist[i + 1];
                djk_var->dist[i + 1] = temp;
                printf("%s %s\n", djk_var->dist[i], djk_var->dist[i + 1]);
                // printf("debug\n");
                was_swapped = 1;
            }
        }
    }
}

static void mx_set_final_output(t_dijk *djk_var, t_main *vars) {
    int temp = vars->nmb_isld;

    djk_var->cnt_parents = 0;
    djk_var->cnt_before = 0;
    djk_var->index_for_sort = (int *)malloc(temp
    * temp * temp * sizeof(int));
    djk_var->path = (char **)malloc(temp
    * temp *  temp * sizeof(char *));
    djk_var->route_char = (char **)malloc(temp
    * temp *  temp * sizeof(char *));
    djk_var->route_int = (char **)malloc(temp
    * temp *  temp * sizeof(char *));
    djk_var->dist = (char **)malloc(temp
    * temp * temp * sizeof(char *));
    for (int i = 0; i < temp * temp * temp; i++) {
        djk_var->path[i] = NULL;
        djk_var->route_int[i] = NULL;
        djk_var->route_char[i] = NULL;
        djk_var->dist[i] = NULL;
    }
}

static void mx_print_all_path(t_dijk *djk_var) {
    int j = 0;
    int temp_j = 0;

    for (int i = 0; i < djk_var->cnt_parents; i++) {
        // if (i == djk_var->index_for_sort[j]) {
        //     temp_j = i + 1;
        //     for (;temp_j == djk_var->index_for_sort[j + 1];) {
        //         temp_j++;
        //         j++;
        //         // printf("debug %2d  %2d  %2d\n", i, temp_j, djk_var->index_for_sort[j + 1]);
        //     }
        //     // printf("debug1 %2d  %2d\n", i, temp_j);

        //     mx_bubble_sort_djkstra(djk_var,
        //     i,
        //     temp_j);
        //     j++;
        // }

        mx_printstr("========================================\n");
        mx_printstr("Path: ");
        mx_printstr(djk_var->path[i]);
        // mx_printstr("\nRoute: ");
        // mx_printstr(djk_var->route_int[i]);
        mx_printstr("\nRoute: ");
        mx_printstr(djk_var->route_char[i]);
        mx_printstr("\nDistance: ");
        mx_printstr(djk_var->dist[i]);
        mx_printstr("\n========================================\n");
    }
}

int main(int argc, char const *argv[]) {
    t_main *vars = mx_create_vars(0, 0);
    t_dijk *djk_var = (t_dijk *)malloc(sizeof(t_dijk));
    t_grph *graph;
    t_fin_out fin_out;

    vars->chk_valid_nmb_isld = 0;
    mx_check_valid_file(argc, argv[1], vars);
    graph = mx_create_graph(vars);
    graph->isld = mx_crt_isld_matrix(vars, graph);
    if (vars->nmb_isld != vars->chk_valid_nmb_isld) {
        mx_printerr("error: invalid number of islands\n");
        exit(1);
    }
    mx_crt_isld_matrix_copy(graph, vars);
    // mx_set_final_output(djk_var, vars);
    // for (int i = 0; i < vars->nmb_isld; i++) {
    //     printf("%3s", graph->isld[i]);
    // }
    // printf("\n");
    fin_out.nmb_isld = vars->nmb_isld;
    for (int i = 0; i < vars->nmb_isld - 1; i++)
        mx_dijkstra(i, graph, &fin_out);
    // for (int i = 0; i < djk_var->cnt_before; i++) {
    //     printf("%4d", djk_var->index_for_sort[i]);
    // }
    printf("done!\n");
    // mx_print_all_path(djk_var);
    mx_free_fn(vars, graph, djk_var);
    system("leaks -q pathfinder");
    return 0;
}
