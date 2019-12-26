#include "libmx.h"

typedef struct s_graph {
    char *file_str;
    // Matrix
    int **array;
    char **isld;
}t_graph;

typedef struct s_main {
    int fd; 
    int nmb_isld;
    char *str;
    char *delims;    
}t_main;

typedef struct s_warshell {
    long cost;
    char *path;
    char *dist;
    struct s_warshell *next;
}t_warshell;

t_main *create_vars(int fd, int nmb_isld) {
    t_main* util_vars = (t_main*)malloc(sizeof(t_main));
    util_vars->fd = fd;
    util_vars->nmb_isld = nmb_isld;
    util_vars->str = mx_strdup("");
    util_vars->delims = "-,\n";
    return util_vars;
}

t_graph *create_graph(t_main *vars) {
    t_graph *main_graph = (t_graph*)malloc(sizeof(t_graph));

    main_graph->file_str = NULL;

    main_graph->array = (int**)malloc(vars->nmb_isld * sizeof(int*));
    for (int i = 0; i < vars->nmb_isld; i++) 
        main_graph->array[i] = (int*)malloc(vars->nmb_isld * sizeof(int));		
    
    for (int i = 0; i < vars->nmb_isld; i++) 
        for (int j = 0; j < vars->nmb_isld; j++) 
            main_graph->array[i][j] = INT_MAX;

    return main_graph;
}

static bool mx_check_valid_1Line(const char *str) {	
    for (int i = 0; str[i] != '\0'; i++) 
        if (!(mx_isdigit(str[i]))) {
            return 0;
        }
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
        if (mx_check_valid_1Line(str)) { 
            return 1;
        }
        else return 0;
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

static void mx_check_valid_file(int nmb_argc, 
char const *rl_argv, t_main *vars) {
    int str = -1;
    
    mx_first_check(&vars->fd, nmb_argc, rl_argv);
       
    if ((str = mx_read_line(&vars->str, 1, '\n', vars->fd)) < 0) {
        mx_printerr("error: file ");
        mx_printerr(rl_argv);
        mx_printerr(" is empty\n");
        exit(1);
    }	
    if ((mx_check_valid_1Line(vars->str)) == 0) {
        if (vars->str) mx_strdel(&vars->str);
        mx_printerr("error: line 1 isn't govna valid\n");
        if (vars->str) mx_strdel(&vars->str);
        exit(1);
    }
    else {
        vars->nmb_isld = mx_atoi(vars->str);		
        if (vars->str) mx_strdel(&vars->str);
    }
}

// add a smb(s2) to the string(s1)
static char *strjoin_mod(char *s1, char s2) {
    char *result = NULL;
    if (!s1 && !s2) return result;
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
static char *mx_strjoin_mod2(char *str, char *arr){	
    char *temp = mx_strjoin(str, arr);
    if (str) mx_strdel(&str);
    return temp;
}

static char **crt_isld_matrix(t_main *vars, t_graph *graph){	
    char **isld = (char**)malloc(vars->nmb_isld * sizeof(char*));

    for (int k = 0, i = 0, rslt_rdln = 1; rslt_rdln > 0 ; i++) 
        for (int j = 0, flag = 1; j < 3; j++) {
            if ((rslt_rdln = mx_read_line(&vars->str, 
                1, vars->delims[j], vars->fd)) < 1) break;
            graph->file_str = mx_strjoin_mod2(graph->file_str, vars->str);
            graph->file_str = strjoin_mod(graph->file_str, vars->delims[j]);
            if ((mx_check_isvalid_alpha(vars->str, j)) == 1) {
                if (j < 2) {
                    for (int d = 0; d < k; d++)
                        if ((flag = mx_strcmp(vars->str, isld[d])) == 0) 
                            break;
                    if (flag != 0) 
                        isld[k++] = mx_strdup(vars->str);
                }
            }
            else mx_wrong_line(i);
            mx_strdel(&vars->str);
        }
    return isld;
}

// add node to graph
static void crt_isld_matrix_copy(t_graph *graph, t_main *vars){
    int arr[2] = {0};
    int index = 0;
    
    for (size_t j = 0, i = 0; graph->file_str[i] != '\0'; i++) 
        if (graph->file_str[i] != vars->delims[j]) 
            vars->str = strjoin_mod(vars->str, graph->file_str[i]);		
        else  
            if (j < 2) {
                for (int k = 0; k < vars->nmb_isld; k++) 
                    if (mx_strcmp(vars->str, graph->isld[k]) == 0) {
                        arr[index++] = k;	
                        free(vars->str);
                        vars->str = mx_strnew(0);
                    }
                j++;				
            } else {
                graph->array[arr[0]][arr[1]] = mx_atoi(vars->str);
                graph->array[arr[1]][arr[0]] = mx_atoi(vars->str);
                free(vars->str);
                vars->str = mx_strnew(0);
                j = 0;				
                index = 0;
            }		
}

static void free_fn(t_main *vars, t_graph *graph) {    

    for (int i = 0; i < vars->nmb_isld; i++)
        free(graph->isld[i]);
    free(graph->isld);

    if (graph->file_str) mx_strdel(&graph->file_str);

    for (int i = 0; i < vars->nmb_isld; ++i)
        free(graph->array[i]);
    free(graph->array);
    
    free(graph);

    close(vars->fd);
    
    if (vars->str) mx_strdel(&vars->str);
    
    if (vars) free(vars);

    
}

// fill matrix costs and paths
void mx_fill_mtrx(t_graph *graph, t_main *vars, 
t_warshell **wrsh_mtrx) {
  for (int i = 0; i < vars->nmb_isld; i++) {
        for (int j = 0 ; j < vars->nmb_isld; j++) {
            wrsh_mtrx[i][j].cost = graph->array[i][j];
            if (i == j) {
                wrsh_mtrx[i][j].cost = 0;
            }
        }
    }
}

// check cost of weight
bool mx_check_way(t_warshell *arr, int i, int j, int k) {
    if (k != i && k != j && arr->cost > arr->cost + arr->cost) 
        return true;
    else
        return false;
}

// check alt cost of weight
bool mx_check_alt_way(t_warshell *arr, int i, int j, int k) {
    if (k != i && k != j && arr->cost == arr->cost + arr->cost) 
        return true;
    else
        return false;
}
//check 
bool mx_isnum(char *s){
	while(*s){
		if(!mx_isdigit(*s))
			return false;
		s++;
	}
	return true;
}

// add dist to node
void mx_add_dist(char* dst, t_warshell *prev_node, t_warshell *next_node) {
    if (prev_node->dist != NULL) 
        dst = mx_strjoin_mod2(prev_node->dist, " + ");
    if (mx_isnum(dst)) {
        dst = mx_strjoin_mod2(dst, mx_itoa(prev_node->cost));
        dst = mx_strjoin_mod2(dst, " + ");
    }
    
    dst = mx_strjoin_mod2(dst, mx_itoa(next_node->cost));
    
}

// add path to node
void mx_add_path(char* dst, t_warshell *prev_node, char *isld_nm) {
    dst = mx_strjoin_mod2(dst, prev_node->path);
    dst = mx_strjoin_mod2(dst, " -> ");
    dst = mx_strjoin_mod2(dst, isld_nm);
}





// set alt way
void mx_set_alt(t_warshell *crr_node, char *isld_nm, 
t_warshell *prev_node, t_warshell *next_node) {
    t_warshell *new_node = (t_warshell*)malloc(sizeof(t_warshell));
    t_warshell *last;

    new_node->cost = prev_node->cost + next_node->cost;

    mx_add_path(new_node->path, prev_node, isld_nm);

    mx_add_dist(new_node->dist, prev_node, next_node);

    new_node->next = NULL;
    if (crr_node == NULL)
        crr_node = new_node;
    else {
        last = new_node;
        for (;last->next != NULL; last = last->next);
        last->next = new_node;
    }
}

// set route and dist
void mx_set_way(t_warshell *crr_node, char *isld_nm, 
t_warshell *prev_node, t_warshell *next_node) {    
    crr_node->cost = prev_node->cost + next_node->cost;

    mx_add_path(crr_node->path, prev_node, isld_nm);    

    mx_add_dist(crr_node->dist, prev_node, next_node);

    for (;prev_node->next;) {
        prev_node = prev_node->next;
        mx_set_alt(crr_node, isld_nm, prev_node, next_node);
        crr_node = crr_node->next;
    }
}

// set alt WAYS
void mx_set_alt_way(t_warshell *crr_node, char *isld_nm, 
t_warshell *prev_node, t_warshell *next_node) {
    for (;prev_node;) {
        mx_set_alt(crr_node, isld_nm, prev_node, next_node);
        prev_node = prev_node->next;
    }
}

// add last element
void mx_add_the_end(t_graph *graph, t_warshell *arr, t_main *vars) {
    for (int i = 0; i < vars->nmb_isld; i++) {
        for (int j = 0; j < vars->nmb_isld; j++) {
            for (;arr;) {
                arr->path = mx_strjoin_mod2(arr->path, arr->path);
                arr->path = mx_strjoin_mod2(arr->path, " -> ");
                arr->path = mx_strjoin_mod2(arr->path, graph->isld[j]);
                arr = arr->next;
            }
        }
    }    
}


// run Floyd-Warshell 
void mx_run_warshell(t_graph *graph, t_main *vars,
t_warshell **arr) {
    for (int k = 0; k < vars->nmb_isld; k++) {
        for (int i = 0; i < vars->nmb_isld; i++) {
            for (int j = 0 ; j < vars->nmb_isld; j++) {
                if (mx_check_way(&arr[i][j], i, j, k)) 
                    mx_set_way(&arr[i][j], graph->isld[k],
                    &arr[i][k], &arr[k][j]);
                else if (mx_check_way(&arr[i][j], i, j, k))
                    mx_set_alt_way(&arr[i][j], graph->isld[k], 
                    &arr[i][k], &arr[k][j]);
            }
        }
    }
    mx_add_the_end(graph, *arr, vars);
}

// free Warshell matrix
void mx_free_wrsh_mtrx(t_main *vars, t_warshell **wrsh_mtrx) {
    for (int i = 0; i < vars->nmb_isld; i++)
        free(wrsh_mtrx[i]);
    free(wrsh_mtrx);
}

// initialize matrix of structure
t_warshell **mx_crt_wrshl_mtrx(t_main *vars) {    
    t_warshell **wrsh_mtrx = (t_warshell**)malloc(vars->nmb_isld * sizeof(t_warshell*));    
    for (int i = 0; i < vars->nmb_isld; i++)        
        wrsh_mtrx[i] = (t_warshell*)malloc(vars->nmb_isld * sizeof(t_warshell)); 

     return wrsh_mtrx;
}

static void print_start_n_end(char *name1, char *name2){
	mx_printstr("Path: ");
	mx_printstr(name1);
	mx_printstr(" -> ");
	mx_printstr(name2);
	mx_printstr("\n");
}

// print all 
void mx_print_shortests_path(t_warshell *wrsh_mtrx, char *name1, char *name2) {
    while(wrsh_mtrx && wrsh_mtrx->cost != INT_MAX) {
        mx_printstr("========================================\n");
        print_start_n_end(name1, name2);
        mx_printstr("Route: ");
        mx_printstr(wrsh_mtrx->path);
        mx_printstr("\n");
        mx_printstr("Distanse: ");
        if(wrsh_mtrx->dist == NULL)
            mx_printint(wrsh_mtrx->cost);
        else{
            mx_printstr(wrsh_mtrx->dist);
            mx_printstr(" = ");
            mx_printint(wrsh_mtrx->cost);
        }
        mx_printstr("\n");
        mx_printstr("========================================\n");
        wrsh_mtrx = wrsh_mtrx->next;
	}
}

// main fnc of Warshell alg
static void Warshell(t_graph *graph, t_main *vars) {
    
    t_warshell **wrsh_mtrx = mx_crt_wrshl_mtrx(vars);       
    
    mx_fill_mtrx(graph, vars, wrsh_mtrx);
    
    mx_run_warshell(graph, vars, wrsh_mtrx); 

    for(int i = 0; i < vars->nmb_isld; i++)
	 	for(int j = i + 1; j < vars->nmb_isld; j++)
    mx_print_shortests_path(&wrsh_mtrx[i][j], graph->isld[i], graph->isld[j]);
    
    
    mx_free_wrsh_mtrx(vars, wrsh_mtrx);
}

// main func
int main(int argc, char const *argv[]) {
    t_main *vars = create_vars(0, 0);
    
    t_graph *graph;
    mx_check_valid_file(argc, argv[1], vars);	

    graph = create_graph(vars);
    
    graph->isld = crt_isld_matrix(vars, graph);

    crt_isld_matrix_copy(graph, vars);

    // output
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
    // printf("\n");
    
    Warshell(graph, vars);
    free_fn(vars, graph);
    // system("leaks -q a.out");
    return 0;
}

// 5
// A-B,11
// A-C,10
// B-D,5
// C-D,6
// C-E,15
// D-E,4

// 4
// Greenland-Bananal,8
// Fraser-Greenland,10
// Bananal-Fraser,3
// Java-Fraser,5


