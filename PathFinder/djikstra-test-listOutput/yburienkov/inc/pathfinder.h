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
void mx_add_to_graph(t_main *vars, t_grph *graph, int j, int i);
char **mx_crt_isld_matrix(t_main *vars, t_grph *graph);
void mx_free_vars_str(t_main *vars, int *j, int *index);
void mx_set_weight_arr(t_grph *graph, t_main *vars, int arr[]);
void mx_crt_isld_matrix_copy(t_grph *graph, t_main *vars);
int mx_add_to_isld(t_main *vars, char **isld, int k);

// djkstra
int mx_get_min_distance(t_fin_out *fin_out);
void mx_create_routes(t_fin_out *fin_out);
int mx_set_start_vars(t_fin_out *fin_out, int src);
void mx_add_parent_and_weight(t_grph *graph, t_fin_out *fin_out,
    int min_ind, int j);
void mx_dijkstra(int src, t_grph *graph, t_fin_out *fin_out);

int mx_atoi_pathfinder(const char *str);
// free
void mx_free_fn(t_main *vars, t_grph *graph);
void mx_free_djkstra(t_fin_out *fin_out);

// nextgen
int *mx_return_int(int num);
t_list *mx_get_element_by_index(t_list *list, int index);
// utils
t_list *mx_cplist(t_list *src);
t_list *mx_lget_byindex(t_list *list, int index);
int *mx_return_int(int num);
void list_swap(void **lst1, void **lst2);
void mx_create_routes(t_fin_out *fin_out);
t_list *mx_sort_list_djkstra(t_list *lst, int (*cmp)(void *, void *));
int mx_lget_min_int(void *cmp_what, void *cmp_with);
void mx_print_routes(t_fin_out *fin_out, t_grph *graph);
void *mx_lget_back_el(t_list *src);


#endif
