#include "libmx.h"

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

t_main *mx_create_vars(int fd, int nmb_isld) {
    t_main* util_vars = (t_main *)malloc(sizeof(t_main));

    util_vars->fd = fd;
    util_vars->nmb_isld = nmb_isld;
    util_vars->str = mx_strdup("");
    util_vars->delims = "-,\n";
    return util_vars;
}

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

bool mx_check_valid_1Line(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(mx_isdigit(str[i])))
            return 0;
    }

    return 1;
}

bool mx_check_isvalid_alpha(const char *str, int j) {
    if (j < 2) {
        for (int i = 0; str[i] != '\0'; i++) 
            if (!(mx_isalpha(str[i])))
                return 0;
        return 1;
    } 
    else {
        if (mx_check_valid_1Line(str)) 
            return 1;        
        else 
            return 0;
    }
}

void mx_wrong_line(int i) {
    char *itoa = mx_itoa(i + 1);

    mx_printerr("error: line ");
    mx_printerr(itoa);
    mx_strdel(&itoa);
    mx_printerr(" isn't valid\n");
    exit(1);
}

void mx_first_check(int *fd, int nmb_argc, char const *rl_argv) {
    if (nmb_argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    } 
    if ((*fd = open(rl_argv, O_RDONLY)) == -1) {
        mx_printerr("error: file ");
        mx_printerr(rl_argv);
        mx_printerr(" doesn't exist\n");
        exit(1);
    } 	
}

void mx_check_file_empty(t_main *vars, char const *rl_argv) {
    int str = -1;
    
    if ((str = mx_read_line(&vars->str, 1, '\n', vars->fd)) < 0) {
        mx_printerr("error: file ");
        mx_printerr(rl_argv);
        mx_printerr(" is empty\n");
        exit(1);
    }
}

void mx_check_valid_frst_line(t_main *vars) {
    if (mx_strlen(vars->str) > 9) {
        mx_printerr("error: line 1 isn't valid\n");
        exit(1);
    }
    if ((mx_check_valid_1Line(vars->str)) == 0) {
        if (vars->str)
            mx_strdel(&vars->str);
        mx_printerr("error: line 1 isn't valid\n");
        exit(1);
    }
    else {
        vars->nmb_isld = mx_atoi(vars->str);
        if (vars->str)
            mx_strdel(&vars->str);
    }
}

void mx_check_valid_file(int nmb_argc,
    char const *rl_argv, t_main *vars) {
    mx_first_check(&vars->fd, nmb_argc, rl_argv);
    mx_check_file_empty(vars, rl_argv);
    mx_check_valid_frst_line(vars);
}

// add a smb(s2) to the string(s1)
char *mx_strjoin_mod1(char *s1, char s2) {
    char *result = NULL;

    if (!s1 && !s2) 
        return result;
    else if (!s2) {
        result = mx_strdup(s1);
        free(s1);
        return result;
    }
    else {
        result = mx_strnew(mx_strlen(s1) + 1);
        result = mx_strcpy(result, s1);
        result[mx_strlen(s1)] = s2;
        free(s1);
    }
    return result;
}

// copy and delete src string
char *mx_addstr(char *str, char *arr) {
    char *temp = mx_strjoin(str, arr);

    if (str) mx_strdel(&str);
    return temp;
}

int mx_get_rslt_rdline(t_main *vars, int j) {
    int rslt_rdln = 1;

    rslt_rdln = mx_read_line(&vars->str, 1, vars->delims[j], vars->fd);
    return rslt_rdln;    
}

void mx_add_to_graph(t_main *vars, t_grph *graph, int j) {
    graph->file_str = mx_addstr(graph->file_str, vars->str);
    graph->file_str = mx_strjoin_mod1(graph->file_str, vars->delims[j]);
}

int mx_add_to_isld(t_main *vars, char **isld, int flag, int k) {   
    for (int d = 0; d < k; d++)
        if ((flag = mx_strcmp(vars->str, isld[d])) == 0) 
            break;
    if (flag != 0) {
        isld[k++] = mx_strdup(vars->str);
        vars->chk_valid_nmb_isld++;
    }
    if (k > vars->nmb_isld) {
        mx_printerr("error: invalid number of islands\n");
        exit(1);        
    }
    return k;
}

char **mx_crt_isld_matrix(t_main *vars, t_grph *graph) {
    char **isld = (char **)malloc(vars->nmb_isld * sizeof(char *));
    int rslt_rdln = 1;
    int k = 0;
    int flag = 1;

    for (int i = 0; rslt_rdln > 0; i++)
        for (int j = 0; j < 3; j++) {
            if ((rslt_rdln = mx_get_rslt_rdline(vars, j)) < 1)
                break;
            mx_add_to_graph(vars, graph, j);
            if ((mx_check_isvalid_alpha(vars->str, j)) == 1) {
                if (j < 2)
                    k = mx_add_to_isld(vars, isld, flag, k);
            }
            else 
                mx_wrong_line(i + 1);
            mx_strdel(&vars->str);
        }
    return isld;
}

void mx_free_vars_str(t_main *vars, int *j, int *index) {
    free(vars->str);
    vars->str = mx_strnew(0);
    *j = 0;				
    *index = 0;
}

void mx_set_weight_arr(t_grph *graph, t_main *vars, int arr[]) {
    if (mx_strlen(vars->str) > 9) {
        mx_printerr("error: line ");
        mx_printerr(mx_itoa(vars->chk_valid_nmb_isld));
        mx_printerr(" isn't valid\n");
        exit(1);
    }
    else 
        vars->chk_valid_nmb_isld++;
    graph->array[arr[0]][arr[1]] = mx_atoi(vars->str);
    graph->array[arr[1]][arr[0]] = mx_atoi(vars->str);
}

// add node to graph
void mx_crt_isld_matrix_copy(t_grph *graph, t_main *vars) {
    int arr[2] = {0};
    int index = 0;
    int i = 0;

    vars->chk_valid_nmb_isld = 2;
    for (int j = 0; graph->file_str[i] != '\0'; i++)
        if (graph->file_str[i] != vars->delims[j])
            vars->str = mx_strjoin_mod1(vars->str, graph->file_str[i]);
        else if (j < 2 && ++j) {
            for (int k = 0; k < vars->nmb_isld; k++)
                if (mx_strcmp(vars->str, graph->isld[k]) == 0) {
                    arr[index++] = k;
                    free(vars->str);
                    vars->str = mx_strnew(0);
                }
        }
        else {
            mx_set_weight_arr(graph, vars, arr);
            mx_free_vars_str(vars, &j, &index);
        }
}

int mx_get_min_distance(int *dist, bool *is_chek, t_main *vars) {
    int min_val = INT_MAX;
    int min_ind = 0;

    for (int i = 0; i < vars->nmb_isld; i++)
        if (is_chek[i] == false && dist[i] < min_val) {
            min_val = dist[i];
            min_ind = i;
        }
    return min_ind;
}

char *mx_add_to_begin(char *s1, char *s2) {
    char *result = NULL;

    if (!s1 && !s2)
        return result;
    else if (!s2)
        return mx_strdup(s2);
    else if (!s1)
        return mx_strdup(s1);
    else {
        result = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
        int i = 0;
        for (int j = 0; s2[j] != '\0'; i++, j++)
            result[i] = s2[j];
        for (int j = 0; s1[j] != '\0'; i++, j++)
            result[i] = s1[j];
        result[i] = '\0';
    }
    if (s1)
        mx_strdel(&s1);
    return result;
}

char *mx_get_nb_way(t_dijk *djk_var, int j, int i) {
    char *temp = mx_itoa(djk_var->isld_nm[j] -
    djk_var->isld_nm[djk_var->parent[i][j]]);

    return temp;
}

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// old
void mx_add_to_str(t_dijk *djk_var, int j, int i, char **isld) {
    char *temp = mx_get_nb_way(djk_var, j, i);
    char *temp_indx = mx_itoa(j);


    djk_var->route_char[djk_var->cnt_parents] = mx_add_to_begin(
    mx_add_to_begin(djk_var->route_char[djk_var->cnt_parents], " -> "), isld[j]);
    djk_var->route_int[djk_var->cnt_parents] = mx_add_to_begin(
    mx_add_to_begin(djk_var->route_int[djk_var->cnt_parents], " -> "), temp_indx);
    djk_var->dist[djk_var->cnt_parents] = mx_add_to_begin(
    mx_add_to_begin(djk_var->dist[djk_var->cnt_parents], " + "), temp);
    mx_strdel(&temp);
    mx_strdel(&temp_indx);
}
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// Distance
void mx_write_dist(int counter, t_dijk *djk_var, int y) {
    char *temp = mx_itoa(djk_var->isld_nm[y]);

    if (counter != 1) {
        djk_var->dist[djk_var->cnt_parents] = mx_addstr(djk_var->dist[djk_var->cnt_parents], " = ");
        djk_var->dist[djk_var->cnt_parents] = mx_addstr(djk_var->dist[djk_var->cnt_parents], temp);
    }
    else {
        if (djk_var->dist[djk_var->cnt_parents])
            mx_strdel(&djk_var->dist[djk_var->cnt_parents]);
        djk_var->dist[djk_var->cnt_parents] = mx_strdup(temp);
    }
    if (temp)
        mx_strdel(&temp);
}
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void mx_set_false_arr(t_dijk *djk_var, int k, int y) {
    if (k == 0) {
        for (int i = 0; i < djk_var->nmb_isld; i++)
            for (int j = 0; j < djk_var->nmb_isld; j++)
                if (j != y)
                    djk_var->is_chk_alt[i][j] = 0;
    }
}

void mx_check_first_line(t_dijk  *djk_var, int i, int *j, int *chk_frst_ln) {
    if (i != 0 && djk_var->temp_i != 0 && djk_var->temp_j != 0) {
        djk_var->is_chk_alt[djk_var->temp_i][djk_var->temp_j] = false;
    }
    if (i != 0) {
        if (djk_var->cnt_before != 0
        && djk_var->cnt_parents
        == djk_var->index_for_sort[djk_var->cnt_before - 1])
            djk_var->cnt_before--;
        djk_var->cnt_before++;
        djk_var->index_for_sort[djk_var->cnt_before - 1]
        = djk_var->cnt_parents;
        djk_var->is_chk_alt[i][*j] = true;
        djk_var->temp_i = i;
        djk_var->temp_j = *j;
    }

    *j = djk_var->parent[i][*j];
    *chk_frst_ln += i;
}
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int mx_find_route(t_dijk *djk_var, int y, char **isld) {
    int i = djk_var->nmb_isld - 1;
    int k = 0;
    int counter = 0;
    int chk_frst_ln = 0;

    for (int j = y; djk_var->parent[0][j] != -1; counter++) {
        i = djk_var->nmb_isld - 1;
        for (; i >= 0; i--)
            if (djk_var->parent[i][j] != -1
                && djk_var->is_chk_alt[i][j] != true) {
                mx_add_to_str(djk_var, j, i, isld);
                if (j != 0 && j != y) {
                    // printf("\n  i%3d\n  j%3d\n  y%3d\n", i, j, y);
                    k += i;
                }
                mx_check_first_line(djk_var, i, &j, &chk_frst_ln);
                break;
            }
    }
    // if (y >= 12) {
    // for (int i = 0; i < djk_var->nmb_isld; i++) {
    //     printf("%3s", isld[i]);
    // }
    // printf("\n");
    // for (int i = 0; i < djk_var->nmb_isld; i++) {
    //     for (int j = 0; j < djk_var->nmb_isld; j++) {
    //         printf("%3d", djk_var->is_chk_alt[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    // }

    mx_set_false_arr(djk_var, k, y);
    mx_write_dist(counter, djk_var, y);
    // printf("%3d %3d %3d %3d %3d\n", chk_frst_ln, counter, k, y, djk_var->cnt_parents);
    return chk_frst_ln;
}

// path
int mx_get_all_path(t_dijk *djk_var, int i, char **isld, int src) {
    int k = 0;
    int count = djk_var->cnt_parents;
    char *temp_indx = mx_itoa(src);

    djk_var->temp_i = 0;
    djk_var->temp_j = 0;
    djk_var->path[count] = mx_addstr(djk_var->path[count], isld[src]);
    djk_var->path[count] = mx_addstr(djk_var->path[count], " -> ");
    djk_var->path[count] = mx_addstr(djk_var->path[count], isld[i]);
    k = mx_find_route(djk_var, i, isld);
    djk_var->route_int[djk_var->cnt_parents] = mx_add_to_begin(
    mx_add_to_begin(djk_var->route_int[djk_var->cnt_parents], " -> "), temp_indx);
    djk_var->route_char[djk_var->cnt_parents] = mx_add_to_begin(
    mx_add_to_begin(djk_var->route_char[djk_var->cnt_parents], " -> "), isld[src]);
    djk_var->cnt_parents++;
    mx_strdel(&temp_indx);
    return k;
}

void mx_set_to_false_checker(t_dijk *djk_var) {
    for (int i = 0; i < djk_var->nmb_isld; i++)
        for (int j = 0; j < djk_var->nmb_isld; j++)
            djk_var->is_chk_alt[i][j] = 0;
}

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

void mx_print_solution(t_dijk *djk_var, int n, char **isld, int src) {
    int k = 1;

    for (int j = src; j < n; j++) {
        if (djk_var->isld_nm[j] != 0) {
            for (; k > 0;)
                k = mx_get_all_path(djk_var, j, isld, src);
            k = 1;
            mx_set_to_false_checker(djk_var);
        }
    }

    mx_free_djkstra(djk_var);
}

int mx_set_start_vars(t_main *vars, t_dijk *djk_var, int src) {
    djk_var->nmb_isld = vars->nmb_isld;
    djk_var->isld_nm = (int *)malloc(vars->nmb_isld * sizeof(int));
    djk_var->is_chk = (bool *)malloc(vars->nmb_isld * sizeof(bool));
    djk_var->parent = (int **)malloc(vars->nmb_isld * sizeof(int *));
    djk_var->is_chk_alt = (bool **)malloc(vars->nmb_isld * sizeof(bool *));

    for (int i = 0; i < vars->nmb_isld; i++) {
        djk_var->parent[i] = (int *)malloc(vars->nmb_isld * sizeof(int));
        for (int j = 0; j < vars->nmb_isld; j++)
            djk_var->parent[i][j] = -1;
        djk_var->is_chk_alt[i] =
        (bool *)malloc(vars->nmb_isld * sizeof(bool));
        for (int j = 0; j < vars->nmb_isld; j++)
            djk_var->is_chk_alt[i][j] = 0;
        djk_var->isld_nm[i] = INT_MAX;
        djk_var->is_chk[i] = false;
    }
    djk_var->isld_nm[src] = 0;
    return 0;
}

// add path to parents arr
void mx_add_par_path(int j, t_dijk *djk_var, int min_ind) {
    int i = 0;

    for (; i < djk_var->nmb_isld && djk_var->parent[i][j] != -1; i++);
    if (djk_var->parent[i][j] == -1)
        djk_var->parent[i][j] = min_ind;
}

void mx_add_parent_and_weight(t_grph *graph, t_dijk *djk_var,
    int min_ind, int j) {
    if (graph->array[min_ind][j] && djk_var->isld_nm[min_ind] != INT_MAX
        && djk_var->isld_nm[min_ind] + graph->array[min_ind][j]
        < djk_var->isld_nm[j]) {
        djk_var->parent[0][j] = min_ind;
        djk_var->isld_nm[j] = djk_var->isld_nm[min_ind]
        + graph->array[min_ind][j];
    }
    else if (graph->array[min_ind][j] && djk_var->isld_nm[min_ind] != INT_MAX
        && djk_var->isld_nm[min_ind] + graph->array[min_ind][j]
        == djk_var->isld_nm[j]) {
        mx_add_par_path(j, djk_var, min_ind);
    }
}
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// calculate the path's
void mx_dijkstra(int src, t_main *vars, t_grph *graph, t_dijk *djk_var) {
    int min_ind = mx_set_start_vars(vars, djk_var, src);
    // int temp = 0;

    for (int i = 0; i < vars->nmb_isld; i++) {
        min_ind = mx_get_min_distance(djk_var->isld_nm,
                                        djk_var->is_chk, vars);
        djk_var->is_chk[min_ind] = true;
        for (int j = 0; j < vars->nmb_isld; j++)
            mx_add_parent_and_weight(graph, djk_var, min_ind, j);
    }


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

    mx_print_solution(djk_var, vars->nmb_isld, graph->isld, src);
}

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------

static int mx_strcmp_djkstra(const char *s1, const char *s2) {
	int i = 0;

	for (; s1[i] == s2[i]; i++) {
		if ( s1[i] == '\0') {
			return 0;
		}
	}
	return s1[i] - s2[i];
}

// char *pivot = arr[(left + (right - 1) / 2)];
//     int pindex = left;
//     for (int i = left; i < right - 1; i++) {
//         if (mx_strlen(arr[i]) > mx_strlen(pivot)) {
//             char *temp = arr[i];
//             arr[i] = arr[pindex];
//             arr[pindex] = temp;
//             pindex++;
//         }
//     }
//     char *temp = arr[right - 1];
//     arr[right - 1] = arr[pindex];
//     arr[pindex]= temp;
//     return pindex;

// int mx_partition_djkstra(t_dijk *djk_var, int left, int right) {
//     char *pivot = djk_var->route_int[(left + (right - 1) / 2)];
//     int pindex = right;
//     char *temp;
//     for (int i = left; i < right; i++) {
//         if (mx_strcmp_djkstra(djk_var->route_int[i], pivot) > 0) {
//             temp = djk_var->route_int[i];
//             djk_var->route_int[i] = djk_var->route_int[pindex];
//             djk_var->route_int[pindex] = temp;
//             temp = djk_var->route_char[i];
//             djk_var->route_char[i] = djk_var->route_char[pindex];
//             djk_var->route_char[pindex] = temp;

//             temp = djk_var->dist[i];
//             djk_var->dist[i] = djk_var->dist[pindex];
//             djk_var->dist[pindex] = temp;
//             pindex++;
//         }
//     }
//     return pindex;
// }

// int mx_quicksort_djkstra(t_dijk *djk_var, int left, int right) {
//     if (djk_var->route_char == NULL)
//         return -1;
//     if (djk_var->route_int == NULL)
//         return -1;
//     int counter = 0;
//     if (left < right) {
//         counter++;
//         int pIndex = mx_partition_djkstra(djk_var, left, right);
//         counter += mx_quicksort_djkstra(djk_var, left, pIndex - 1);
//         counter += mx_quicksort_djkstra(djk_var, pIndex + 1, right);
//     }
//     return counter;
// }

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// // new quick sort
// static void mx_swap_elements(char **left, char **right) {
//     char *temp = *left;
//     *left = *right;
//     *right = temp;
// }

// int mx_quicksort_djkstra(t_dijk *djk_var, int left, int right) {
//     if (!djk_var->route_int) return -1;
//     if (left >= right) return 0;
//     int swaps = 0;
//     int pi = left;
//     char *pivot = djk_var->route_int[left + (right - left) / 2];
    
//     for (int r = right; pi <= r;) {
//         for (; mx_strcmp_djkstra(djk_var->route_int[pi], pivot) < 0; pi++);
//         for (; mx_strcmp_djkstra(djk_var->route_int[pi], pivot) > 0 ; r--);
        
//         if (mx_strcmp_djkstra(djk_var->route_int[pi], djk_var->route_int[r]) > 0) {
//             // if (mx_strlen(djk_var->route_int[pi]) != mx_strlen(djk_var->route_int[r])) {
//                 mx_swap_elements(&djk_var->route_int[pi], &djk_var->route_int[r]);
//                 mx_swap_elements(&djk_var->route_char[pi], &djk_var->route_char[r]);
//                 swaps++;
//             // }
//             pi++;
//             r--;
//         }
//     }
//     return swaps + mx_quicksort_djkstra(djk_var, left, pi - 1) + mx_quicksort_djkstra(djk_var, pi, right);
// }

static int mx_partition_djkstra (t_dijk *djk_var, int left, int right) {
    char *pivot = djk_var->route_int[(left + (right - 1) / 2)];
    int pindex = left;
    char *temp = NULL;

    for (int i = left; i < right - 1; i++) {
        if (mx_strcmp_djkstra(djk_var->route_int[i], pivot) < 0) {
            temp = djk_var->route_int[i];
            djk_var->route_int[i] = djk_var->route_int[pindex];
            djk_var->route_int[pindex] = temp;
            temp = djk_var->route_char[i];
            djk_var->route_char[i] = djk_var->route_char[pindex];
            djk_var->route_char[pindex] = temp;
            pindex++;
        }
    }
    temp = djk_var->route_int[right - 1];
    djk_var->route_int[right - 1] = djk_var->route_int[pindex];
    djk_var->route_int[pindex]= temp;

    temp = djk_var->route_char[right - 1];
    djk_var->route_char[right - 1] = djk_var->route_char[pindex];
    djk_var->route_char[pindex]= temp;
    return pindex;
} 

int mx_quicksort_djkstra(t_dijk *djk_var, int left, int right) {
    int counter = 0;
    int pIndex = 0;

    if (djk_var->route_int == NULL) return -1;
    if (left < right) {
        counter++;
        pIndex = mx_partition_djkstra(djk_var, left, right);
        counter += mx_quicksort_djkstra(djk_var, left, pIndex - 1);
        counter += mx_quicksort_djkstra(djk_var, pIndex + 1, right);
    } 
    return counter;
}

void mx_set_final_output(t_dijk *djk_var, t_main *vars) {
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
        if (i == djk_var->index_for_sort[j]) {
            temp_j = i + 1;
            for (;temp_j == djk_var->index_for_sort[j + 1];) {
                temp_j++;
                j++;
                // printf("debug %2d  %2d  %2d\n", i, temp_j, djk_var->index_for_sort[j + 1]);
            }
            // printf("debug1 %2d  %2d\n", i, temp_j);
            mx_quicksort_djkstra(djk_var,
            i,
            temp_j);
            j++;
        }

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

void mx_free_fn(t_main *vars, t_grph *graph, t_dijk *djk_var) {
    for (int i = 0; i < vars->nmb_isld * vars->nmb_isld * vars->nmb_isld; i++) {
        free(djk_var->path[i]);
        djk_var->path[i] = NULL;

        free(djk_var->dist[i]);
        djk_var->dist[i] = NULL;

        free(djk_var->route_int[i]);
        djk_var->route_int[i] = NULL;
        free(djk_var->route_char[i]);
        djk_var->route_char[i] = NULL;
    }
    free(djk_var->path);
    free(djk_var->dist);
    free(djk_var->route_char);
    free(djk_var->route_int);
    free(djk_var->index_for_sort);
    free(djk_var);

    for (int i = 0; i < vars->nmb_isld; i++)
        free(graph->isld[i]);
    free(graph->isld);
    if (graph->file_str)
        mx_strdel(&graph->file_str);
    for (int i = 0; i < vars->nmb_isld; ++i)
        free(graph->array[i]);
    free(graph->array);
    free(graph);
    close(vars->fd);
    if (vars->str)
        mx_strdel(&vars->str);
    if (vars)
        free(vars);
}



int main(int argc, char const *argv[]) {
    t_main *vars = mx_create_vars(0, 0);
    t_dijk *djk_var = (t_dijk *)malloc(sizeof(t_dijk));
    t_grph *graph;

    vars->chk_valid_nmb_isld = 0;
    mx_check_valid_file(argc, argv[1], vars);
    graph = mx_create_graph(vars);
    graph->isld = mx_crt_isld_matrix(vars, graph);
    if (vars->nmb_isld != vars->chk_valid_nmb_isld) {
        mx_printerr("error: invalid number of islands\n");
        exit(1);
    }
    mx_crt_isld_matrix_copy(graph, vars);
    mx_set_final_output(djk_var, vars);
    // for (int i = 0; i < vars->nmb_isld; i++) {
    //     printf("%3s", graph->isld[i]);
    // }
    // printf("\n");
    for (int i = 0; i < vars->nmb_isld - 1; i++)
        mx_dijkstra(i, vars, graph, djk_var);
    // for (int i = 0; i < djk_var->cnt_before; i++) {
    //     printf("%4d", djk_var->index_for_sort[i]);
    // }
    // printf("\n");
    mx_print_all_path(djk_var);
    mx_free_fn(vars, graph, djk_var);
    // system("leaks -q pathfinder");
    return 0;
}
