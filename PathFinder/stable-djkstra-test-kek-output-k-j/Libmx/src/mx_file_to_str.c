#include "libmx.h"

char *mx_file_to_str(const char *filename) {
	if (filename != NULL) {
	    int status_open_src = 0;
        if ((status_open_src = mx_open(filename)) == -1) {
            return NULL;
		}
	    char *path_to_copy = mx_read_mod(status_open_src);
        return path_to_copy;
	    if (close(status_open_src)) 
		    return NULL;	
	} else 
        return NULL;
	return NULL;
}
