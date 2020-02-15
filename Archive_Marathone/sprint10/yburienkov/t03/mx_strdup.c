#include "file_to_str.h"
int mx_strlen(const char *s);
char *mx_strcpy(char *dst, const char *src);
char *mx_strnew(const int size);

char *mx_strdup(const char *str) {
    char *res;    
    res = mx_strcpy(mx_strnew(mx_strlen(str)), str);
    return res;
}
