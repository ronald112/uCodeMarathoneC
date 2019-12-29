#include "../inc/pathfinder.h"

// add a smb(s2) to the string(s1)
char *mx_strjoin_mod1(char *s1, char s2) {
    char *result = NULL;

    if (!s1 && !s2) 
        return result;
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
