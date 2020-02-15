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

static void mx_read(const int status) {
	int stat_read = 0;
	char symb = '\0';		
	while ((stat_read = read(status, &symb, 1)) > 0) {
		mx_printchar(symb);
	}
	if (stat_read < 0) {
		perror("read");
		exit(1);
	}
	mx_printchar('\n');
}

int main (int agrc, char *argv[]) {
	if (agrc == 1) {		
		char char_from_std = '\0';
		int mx_open = 0;
		while((mx_open = read(0, &char_from_std, 1)) > 0) {
			mx_printchar(char_from_std);
			if (char_from_std == '\n') 				
				exit(1);			
		}
		mx_read(mx_open);
		exit(1);		
	} else if(agrc == 2) {
		int status_open_src = mx_open(argv[1]);
		mx_read(status_open_src);
		if (close(status_open_src)) {
			mx_printstr( "mx_cat: ");			
			mx_printerr(strerror(errno));
			exit(1);
		}
	} else {
		mx_printerr(strerror(errno));	
		exit(1);
	}     
	return (EXIT_SUCCESS);
}
