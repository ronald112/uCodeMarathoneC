#include "file_to_str.h"

static int mx_open(const char *arr) {
	int status = 0;
	if ((status = open(arr, O_RDONLY)) == -1) {		
		return -1;
	}	
	return status;
}

static char *mx_read_mod(const int status) {
	int stat_read = 0;
	char symb = '\0';
    char *res = NULL;
    int len = 0;    
	while ((stat_read = read(status, &symb, 1)) > 0) { 
        res = mx_strjoin(res, &symb);
        len++;
	}
    res[len * 2] = '\0';
    return res;
}

char *mx_file_to_str(const char *filename) {
	if (filename != NULL) {
	    int status_open_src = mx_open(filename);
        if (status_open_src < 0)
            return NULL;
	    char *path_to_copy = mx_read_mod(status_open_src);    
        return path_to_copy;
	    if (close(status_open_src)) 
		    return NULL;	
	} else 
        return NULL;
	return NULL;
}
