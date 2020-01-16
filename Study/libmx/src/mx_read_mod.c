#include "libmx.h"
char *mx_read_mod(const int status) {
	int stat_read = 0;
	char symb = '\0';
    char *res = "\0";
    int len = 1;    
	while ((stat_read = read(status, &symb, 1)) > 0) {
        res = mx_strjoin(res, &symb);
        res[len] = '\0';
        len++;
	}
    res[len] = '\0';
    return res;
}
