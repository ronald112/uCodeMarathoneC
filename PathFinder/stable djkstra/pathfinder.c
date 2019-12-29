#include "libmx.h"

typedef struct s_graph {
    char *file_str;
    // Matrix
    int **array;
    char **isld;
}t_grph;

typedef struct s_main {
    int fd; 
    int nmb_isld;
    char *str;
    char *delims;
}t_main;

typedef struct s_dijkstra {
    int nmb_isld;
    int *isld_nm;
    bool *is_chk;
    bool **is_chk_alt;
    int **parent;
    char *route;  
    char *dist;  
}t_dijk;

t_main *create_vars(int fd, int nmb_isld) {
    t_main* util_vars = (t_main*)malloc(sizeof(t_main));

    util_vars->fd = fd;
    util_vars->nmb_isld = nmb_isld;
    util_vars->str = mx_strdup("");
    util_vars->delims = "-,\n";
    return util_vars;
}

t_grph *create_graph(t_main *vars) {
    t_grph *main_graph = (t_grph*)malloc(sizeof(t_grph));

    main_graph->array = (int**)malloc(vars->nmb_isld * sizeof(int*));
    main_graph->file_str = NULL;    
    for (int i = 0; i < vars->nmb_isld; i++) 
        main_graph->array[i] = (int*)malloc(vars->nmb_isld * sizeof(int));		
    
    for (int i = 0; i < vars->nmb_isld; i++) 
        for (int j = 0; j < vars->nmb_isld; j++) 
            main_graph->array[i][j] = 0;

    return main_graph;
}

static bool mx_check_valid_1Line(const char *str) {	
    for (int i = 0; str[i] != '\0'; i++) 
        if (!(mx_isdigit(str[i])))
            return 0;
        
    return 1;
}

static bool mx_check_isvalid_alpha(const char *str, int j) {
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

static void mx_wrong_line(int i) {
    char *itoa = mx_itoa(i + 1);

    mx_printerr("error: line ");
    mx_printerr(itoa);
    mx_strdel(&itoa);
    mx_printerr(" isn't valid\n");
    exit(1);
}

static void mx_first_check(int *fd, int nmb_argc, char const *rl_argv) {
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

static void mx_check_valid_file(int nmb_argc, 
    char const *rl_argv, t_main *vars) {
    
    mx_first_check(&vars->fd, nmb_argc, rl_argv);    
    mx_check_file_empty(vars, rl_argv);    	
    mx_check_valid_frst_line(vars);
}

// add a smb(s2) to the string(s1)
static char *strjoin_mod(char *s1, char s2) {
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
static char *mx_addstr(char *str, char *arr){	
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
    graph->file_str = strjoin_mod(graph->file_str, vars->delims[j]);
}

int mx_add_to_isld(t_main *vars, char **isld, int flag, int k) {   
    for (int d = 0; d < k; d++)
        if ((flag = mx_strcmp(vars->str, isld[d])) == 0) 
            break;
    if (flag != 0) 
        isld[k++] = mx_strdup(vars->str);
    // printf("debug k %d nmb %d", k, vars->nmb_isld);
    if (k > vars->nmb_isld) {
        mx_printerr("error: invalid number of islands\n");
        exit(1);        
    }
    return k;
}

static char **crt_isld_matrix(t_main *vars, t_grph *graph, int *chk_nmb_isld) {	
    char **isld = (char**)malloc(vars->nmb_isld * sizeof(char*));
    int rslt_rdln = 1;
    int k = 0;
    int flag = 1;

    for (; rslt_rdln > 0 ; *chk_nmb_isld = *chk_nmb_isld + 1)
        for (int j = 0; j < 3; j++) {
            // printf("debug 1\n");
            if ((rslt_rdln = mx_get_rslt_rdline(vars, j)) < 1)
                break;
            mx_add_to_graph(vars, graph, j);
            if ((mx_check_isvalid_alpha(vars->str, j)) == 1) {
                if (j < 2)
                    k = mx_add_to_isld(vars, isld, flag, k);
            }
            else 
                mx_wrong_line(*chk_nmb_isld);
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
    graph->array[arr[0]][arr[1]] = mx_atoi(vars->str);
    graph->array[arr[1]][arr[0]] = mx_atoi(vars->str);
}

// add node to graph
static void crt_isld_matrix_copy(t_grph *graph, t_main *vars){
    int arr[2] = {0};
    int index = 0;
    int i = 0;
    
    for (int j = 0; graph->file_str[i] != '\0'; i++) 
        if (graph->file_str[i] != vars->delims[j]) 
            vars->str = strjoin_mod(vars->str, graph->file_str[i]);
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

static void mx_free_fn(t_main *vars, t_grph *graph, t_dijk *djk_var) {    
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

static int mx_get_min_distance(int *dist, bool *is_chek, t_main *vars) {
    int min_val = INT_MAX;
    int min_ind = 0;

    for (int i = 0; i < vars->nmb_isld; i++) 
        if (is_chek[i] == false && dist[i] < min_val) {
            min_val = dist[i];
            min_ind = i;
        }
    return min_ind;
}

// add to the beginning o the string
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

void mx_add_to_str(t_dijk *djk_var, int j, int i, char **isld) {
    char *temp = mx_get_nb_way(djk_var, j, i);

    djk_var->route = mx_add_to_begin(
    mx_add_to_begin(djk_var->route, " -> "), isld[j]);
    djk_var->dist = mx_add_to_begin(
    mx_add_to_begin(djk_var->dist, " + "), temp);
    mx_strdel(&temp);
}

// Distance
void mx_print_dist(int counter, t_dijk *djk_var, int y) {    
    if (counter != 1) {
        mx_printstr("\nDistance: ");
        mx_printstr(djk_var->dist);
        mx_printstr(" = ");
        mx_printint(djk_var->isld_nm[y]);
        mx_printstr("\n");
    }
    else {
        mx_printstr("\nDistance: ");
        mx_printint(djk_var->isld_nm[y]);
        mx_printstr("\n");
    } 
    if (djk_var->dist) 
        mx_strdel(&djk_var->dist);
}

void mx_print_route(t_dijk *djk_var, int check, int k, int y) {    
    if (check != 0 && k > 1) 
        djk_var->is_chk_alt[check][y] = false;
    mx_printstr(djk_var->route);
    if (djk_var->route) 
        mx_strdel(&djk_var->route);
}

bool mx_check_first_line(int i, int *chk_frst_ln, int *k) {
    if (i != 0) {
        *chk_frst_ln = i;
        *k = *k + 1;
        return true;        
    }
    return false;
}

int mx_find_route(t_dijk *djk_var, int y, char **isld) {    
    int k = 0;
    int counter = 0;
    int chk_frst_ln = 0;
    int cp_y = y;
    
    for (int i = djk_var->nmb_isld - 1; 
        djk_var->parent[0][y] != -1; counter++)
        for (; i >= 0; i--)
            if (djk_var->parent[i][y] != -1  
                && djk_var->is_chk_alt[i][y] != true) {
                mx_add_to_str(djk_var, y, i, isld);
                djk_var->is_chk_alt[i][y] = mx_check_first_line(i,
                &chk_frst_ln, &k);
                y = djk_var->parent[i][y];
                i = 0;
                break;
            }
    mx_print_route(djk_var, chk_frst_ln, k, y);
    mx_print_dist(counter, djk_var, cp_y);
    return k;
}

// path
int mx_print_all(t_dijk *djk_var, int i, char **isld, int src) {
    int k = 0;
    djk_var->dist = NULL;
    djk_var->route = NULL;

    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(isld[src]);
    mx_printstr(" -> ");
    mx_printstr(isld[i]);
    mx_printstr("\nRoute: ");
    mx_printstr(isld[src]);
    mx_printstr(" -> ");    
    k = mx_find_route(djk_var, i, isld);
    mx_printstr("========================================\n");
    return k;
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

void mx_set_to_false_checker(t_dijk *djk_var) {
    for (int i = 0; i < djk_var->nmb_isld; i++)
        for (int j = 0; j < djk_var->nmb_isld; j++)
            djk_var->is_chk_alt[i][j] = 0;
}

static void printSolution(t_dijk *djk_var, int n, char **isld, int src) {
    int k = 1;

    for (int i = src; i < n; i++) {
        if (djk_var->isld_nm[i] != 0) {
            for (; k > 0;)               
                k = mx_print_all(djk_var, i, isld, src);            
            k = 1;
            mx_set_to_false_checker(djk_var);
        }
    }    
    mx_free_djkstra(djk_var);
}

int mx_set_start_vars(t_main *vars, t_dijk *djk_var, int src) {
    djk_var->nmb_isld = vars->nmb_isld;
    djk_var->isld_nm = (int*)malloc(vars->nmb_isld * sizeof(int));
    djk_var->is_chk = (bool*)malloc(vars->nmb_isld * sizeof(bool));
    djk_var->parent = (int**)malloc(vars->nmb_isld * sizeof(int*));	
    djk_var->is_chk_alt = (bool**)malloc(vars->nmb_isld * sizeof(bool*));

    for (int i = 0; i < vars->nmb_isld; i++) {
        djk_var->parent[i] = (int*)malloc(vars->nmb_isld * sizeof(int));
        for (int j = 0; j < vars->nmb_isld; j++)
            djk_var->parent[i][j] = -1;
        djk_var->is_chk_alt[i] = (bool*)malloc(vars->nmb_isld * sizeof(bool));
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
    if (graph->array[min_ind][j]
        && djk_var->isld_nm[min_ind] != INT_MAX
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

// calculate the path's
static void mx_dijkstra(int src, t_main *vars, t_grph *graph, t_dijk *djk_var) {
    int min_ind = mx_set_start_vars(vars, djk_var, src); 

    for (int i = 0; i < vars->nmb_isld - 1; i++) {
        min_ind = mx_get_min_distance(djk_var->isld_nm, djk_var->is_chk, vars);
        djk_var->is_chk[min_ind] = true;
        for (int j = src; j < vars->nmb_isld; j++) {
            mx_add_parent_and_weight(graph, djk_var, min_ind, j);
        }
    }
    printSolution(djk_var, vars->nmb_isld, graph->isld, src);
}


int main(int argc, char const *argv[]) {
    t_main *vars = create_vars(0, 0);
    t_dijk *djk_var = (t_dijk*)malloc(sizeof(t_dijk));
    t_grph *graph;
    int chk_valid_nmb_isld = 0;

    mx_check_valid_file(argc, argv[1], vars);
    graph = create_graph(vars);    
    graph->isld = crt_isld_matrix(vars, graph, &chk_valid_nmb_isld);
    if (vars->nmb_isld != chk_valid_nmb_isld - 1) {
        mx_printerr("error: invalid number of islands\n");
        exit(1); 
    }
    
    crt_isld_matrix_copy(graph, vars);

    // for (int i = 0; i < vars->nmb_isld; i++)
    //     printf("%5c", graph->isld[i][0]);
    // printf("\n");
    // for (int i = 0; i < vars->nmb_isld; i++) {
    //     printf("%c", graph->isld[i][0]);
    //     for (int j = 0; j < vars->nmb_isld; j++) {
    //         printf("%4d ", graph->array[i][j]);
    //     }
    //     printf("\n");
    // }

    for (int i = 0; i < vars->nmb_isld - 1; i++) {
        mx_dijkstra(i, vars, graph, djk_var);
    }
    mx_free_fn(vars, graph, djk_var);
    // system("leaks -q a.out");
    return 0;
}
