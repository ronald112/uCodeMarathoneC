#include "libmx.h"

typedef struct s_path t_path;

struct s_path {
	int index_island;
	int waight_path;
	t_path *next;
};

static bool mx_check_valid_1Line(const char *str) {
	
	for (int i = 0; str[i] != '\0'; i++) 
		if (!(mx_isdigit(str[i])))
			return 0;
	return 1;
}

static bool mx_check_isvalid_alpha(const char *str, int j) {
	if (j < 2) {
		for (int i = 0; str[i] != '\0'; i++) 
			if (!mx_isalpha(str[i]))
				return 0;	
		return 1;
	} else {
		if (mx_check_valid_1Line(str)) { 
			printf("%s\n", str);
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

static void mx_check_valid_file(int nmb_argc, char const *rl_argv, int *nmb_islands, char **read_line_rslt, int *fd1) {
	
	
	mx_first_check(fd1, nmb_argc, rl_argv);
	   
	if (mx_file_to_str(rl_argv)) {
		mx_printerr("error: file ");
		mx_printerr(rl_argv);
		mx_printerr(" is empty\n");
		exit(1);
	}	
	if (!(mx_check_valid_1Line(*read_line_rslt))) {
		mx_printerr("error: line 1 isn't valid\n");
		exit(1);
	} else {
		*nmb_islands = mx_atoi(*read_line_rslt);
		// mx_strdel(read_line_rslt);
	}
	
	

}

// static void mx_add_to_list(t_path *list) {

// }

int main(int argc, char const *argv[]) {	
    int fd = 0, nmb_islands = 0;
	char *str = "", *delims = "\n-,";


	mx_check_valid_file(argc, argv[1], &nmb_islands, &str, &fd);	
	
	// t_path **paths = (t_path**)malloc(nmb_islands * sizeof(*paths));
	char **isld = (char**)malloc(nmb_islands * sizeof(*isld));
	int rslt_rdln = 1;
	
	

	for (int i = 0; i < nmb_islands; i++) {
		printf("name %s\n", isld[i]);
	}
	
	// for (int i = 0; i < nmb_islands; i++)
	// 	free(isld[i]);
	// free(isld);

	// for (int i = 0; i < nmb_islands; i++)
	// 	free(paths[i]);
	// free(paths);

	// printf("malloc %li\n", malloc_usable_size(read_line_rslt));
	
	// if (rslt_rdln > 0)
	// free(read_line_rslt);
	if (close(fd)) 
		return 0;
	return 0;
}


// READLINE TRY
// for (int k = 0, i = 0; rslt_rdln > 0 ; i++) {
// 		for (int j = 0, flag = 1; j < 3; j++) {			
// 			rslt_rdln = mx_read_line(&read_line_rslt, 1, delims[j], fd);
// 			if (rslt_rdln < 1) break;
// 			printf("mx_strlen %d\n", mx_strlen(read_line_rslt));

// 			if (mx_check_isvalid_alpha(read_line_rslt, j)) { 
// 				if (j < 2) {
// 					for (int d = 0; d < k; d++) {
// 						flag = 1;
// 						if ((mx_strcmp(read_line_rslt, isld[d])) == 0) {
// 							flag = 0;
// 							break;
// 						}
// 					}
// 					if (flag == 1) {
// 						isld[k] = mx_strdup(read_line_rslt);
// 						k++;
// 					}	
// 				} else {
// 					// add weight
// 				}
// 			}
// 			else mx_wrong_line(i);
// 			free(read_line_rslt);
// 			// mx_read_line(&read_line_rslt, 1, delims[j], fd)
// 			// mx_read_line(&read_line_rslt, 1, ',', fd);
// 			// if (mx_check_valid_Line(read_line_rslt)) isld[i] = mx_strdup(read_line_rslt);
// 			// else mx_wrong_line(i);
// 			// printf("name %s\n", isld[i]);


// 			// paths[i]->index_island = i;
			
			
// 		}
// 		// printf("name00 %s\n", isld[i]);
// 	}

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


