#include "libmx.h"

static char *strjoin_mod(char *s1, char s2) {
    char *result = NULL;
    if (!s1 && !s2) return result;
    else if (!s2) {
        result = mx_strdup(s1);
        free(s1);
        return result;
    } else {
        result = mx_strnew(mx_strlen(s1) + 1);        
        result = mx_strcpy(result, s1);
        result[mx_strlen(s1)] = s2;
        if (mx_strlen(s1) > 0) free(s1);
    }
    return result;
}

char *mx_read_mod(const int status) {
	int stat_read = 0;
	char symb = '\0';
    char *res = "\0";
	while ((stat_read = read(status, &symb, 1)) > 0)
        res = strjoin_mod(res, symb);
    return res;
}
