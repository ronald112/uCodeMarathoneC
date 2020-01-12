#ifndef PATHFINDER_H
#define PATHFINDER_H
#include "Libmx/inc/libmx.h"

typedef struct s_graph {
    char *file_str;
    int **array;
    char **isld;
}t_grph;

typedef struct s_main {
    int fd;
    int nmb_isld;
    char *str;
    char *delims;
    int chk_valid_nmb_isld;
}t_main;

typedef struct s_dijk {
    int *index_for_sort;
    int cnt_before;
    int temp_i;
    int temp_j;
    int cnt_parents;
    int nmb_isld;
    int *isld_nm;
    bool *is_chk;
    bool **is_chk_alt;
    int **parent;
    char **path;
    char **route_char;
    char **route_int;
    char **dist;
}t_dijk;

typedef struct s_fin_out {
    t_list **l_parent; // parents
    t_list *l_route; // routes

    int *isld_weight; // dist
    int src; // src
    bool *visit_marker_djik; // visitsd

    int nmb_isld; // slandsnum

}t_fin_out;

t_grph *mx_create_graph(t_main *vars);
t_main *mx_create_vars(int fd, int nmb_isld);

// validations
bool mx_check_valid_1Line(const char *str);
bool mx_check_isvalid_alpha(const char *str, int j);
void mx_wrong_line(int i);
void mx_first_check(int *fd, int nmb_argc, char const *rl_argv);
void mx_check_file_empty(t_main *vars, char const *rl_argv);
void mx_check_valid_frst_line(t_main *vars);
void mx_check_valid_file(int nmb_argc, char const *rl_argv, t_main *vars);

// read and save all file
char *mx_strjoin_mod1(char *s1, char s2);
char *mx_addstr(char *str, char *arr);
int mx_get_rslt_rdline(t_main *vars, int j);
void mx_add_to_graph(t_main *vars, t_grph *graph, int j);
char **mx_crt_isld_matrix(t_main *vars, t_grph *graph);
void mx_free_vars_str(t_main *vars, int *j, int *index);
void mx_set_weight_arr(t_grph *graph, t_main *vars, int arr[]);
void mx_crt_isld_matrix_copy(t_grph *graph, t_main *vars);
int mx_add_to_isld(t_main *vars, char **isld, int k);

// djkstra
int mx_get_min_distance(t_fin_out *fin_out);
char *mx_add_to_begin(char *s1, char *s2);
char *mx_get_nb_way(t_dijk *djk_var, int j, int i);
void mx_add_to_str(t_dijk *djk_var, int j, int i, char **isld);
void mx_write_dist(int counter, t_dijk *djk_var, int y);
void mx_set_false_arr(t_dijk *djk_var, int k, int y);
void mx_check_first_line(t_dijk  *djk_var, int i, int *j, int *chk_frst_ln);
int mx_find_route(t_dijk *djk_var, int y, char **isld);
int mx_get_all_path(t_dijk *djk_var, int i, char **isld, int src);
void mx_set_to_false_checker(t_dijk *djk_var);
void mx_print_solution(t_dijk *djk_var, int n, char **isld, int src);
int mx_set_start_vars(t_fin_out *fin_out, int src);
void mx_add_par_path(int j, t_dijk *djk_var, int min_ind);
void mx_add_parent_and_weight(t_grph *graph, t_fin_out *fin_out,
    int min_ind, int j);
void mx_dijkstra(int src, t_grph *graph, t_fin_out *fin_out);

// void mx_print_all_path(t_dijk *djk_var);
// void mx_set_final_output(t_dijk *djk_var, t_main *vars);
int mx_partition_djkstra(t_dijk *djk_var, int left, int right);
int mx_quicksort_djkstra(t_dijk *djk_var, int left, int right);

int mx_atoi_pathfinder(const char *str);
void mx_bubble_sort_djkstra(t_dijk *djk_var, int left, int right);
// free
void mx_free_fn(t_main *vars, t_grph *graph, t_dijk *djk_var);
void mx_free_djkstra(t_fin_out *fin_out);

// nextgen
int *mx_return_int(int num);
t_list *mx_get_element_by_index(t_list *list, int index);

#endif
