#include "minilibmx.h"

static int mx_open(const char *arr) {
	int status = 0;
	if ((status = open(arr, O_RDONLY)) == -1) {
		mx_printerr("error\n");	
		return -1;
	}	
	return status;
}

static void mx_read(const int status) {
	int stat_read = 0;
	char symb = '\0';
	while ((stat_read = read(status, &symb, 1)) > 0) {
        mx_printchar(symb);
		if (stat_read < 0) {
			mx_printerr("error\n");	
			stat_read = -1;
		}
	}	
	mx_printchar('\n');	
}

int main (int agrc, char *argv[]) {
	if (agrc < 2 || agrc > 2 ) {
		mx_printerr("usage: ./read_file [file_path]\n");
		return 1;
	}	   
    char *path = argv[1];	
	int status_open = mx_open(path);
	if (status_open < 0) 
		return 1;
	mx_read(status_open);		
	if (close(status_open)) mx_printerr("error\n");	
	return 0;
}
