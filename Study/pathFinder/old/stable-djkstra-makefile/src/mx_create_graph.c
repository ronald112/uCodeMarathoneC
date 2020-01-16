#include "../inc/pathfinder.h"

t_grph *mx_create_graph(t_main *vars) {
    t_grph *main_graph = (t_grph *)malloc(sizeof(t_grph));

    main_graph->array = (int **)malloc(vars->nmb_isld * sizeof(int *));
    main_graph->file_str = NULL;    
    for (int i = 0; i < vars->nmb_isld; i++) 
        main_graph->array[i] = (int *)malloc(vars->nmb_isld * sizeof(int));		
    
    for (int i = 0; i < vars->nmb_isld; i++) 
        for (int j = 0; j < vars->nmb_isld; j++) 
            main_graph->array[i][j] = 0;

    return main_graph;
}
