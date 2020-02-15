#include "minilibmx.h"

static int mx_open(const char *arr) {
	int status = 0;
	if ((status = open(arr, O_RDONLY)) == -1) {
		mx_printerr( "mx_cp: ");
		mx_printerr(arr);
        mx_printerr(": ");
		mx_printerr(strerror(errno));
		mx_printerr("\n");
		exit(1);
	}	
	return status;
}

static int mx_open_tocopy(const char *arr) {
	int status = 0;
	if ((status = open(arr, O_RDWR | O_CREAT | O_EXCL, 0644)) == -1) {
		mx_printerr( "mx_cp: ");
		mx_printerr(arr);
        mx_printerr(": ");
		mx_printerr(strerror(errno));
		mx_printerr("\n");
		exit(1);				
	}
	return status;
}

static void mx_read_mod(const int status, int status_copy) {
	int stat_read = 0;
	char symb = '\0';
	int stat_copy = 0;
	while ((stat_read = read(status, &symb, 1)) > 0) {
		stat_copy = write(status_copy, &symb, 1);
		if (stat_read != stat_copy) {
			mx_printerr(strerror(errno));
			mx_printerr("\n");
			exit(1);
		}
	}
}

int main (int agrc, char *argv[]) {
	if (agrc != 3) {
		mx_printerr("usage: ./mx_cp [source_file] [target_file]\n");
		exit(1);
	}	   
    char *path = argv[1];
	char *path_to_copy = argv[2];
	int status_open_src = mx_open(path);
	int status_open_dst = mx_open_tocopy(path_to_copy);
	mx_read_mod(status_open_src, status_open_dst);
	if (close(status_open_src)) {
		mx_printerr("error\n");
		exit(1);
	} 
	if (close(status_open_dst)) {
		mx_printerr("error\n");
		exit(1);
	} 	
	return 0;
}
