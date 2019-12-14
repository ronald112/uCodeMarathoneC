#include "libmx.h"
int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (lineptr != NULL) {        
        int size = 0;
        *lineptr = mx_read_mod_readline(buf_size, delim, fd, &size);
        return size;	    
	} else 
        return -2;
    return -2;
}

