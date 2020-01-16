#include "libmx.h"

char *mx_strtrim(const char *str) {
    if (str == NULL) return NULL;
    char *arr = "";
    int i = 0, j = 0;
    if (mx_strlen(str) == 1) return arr;
    for (;mx_isspace(str[i]); i++);
    if (i == mx_strlen(str)) return arr;
    int size = mx_strlen(str);    
    for (i = 0; mx_isspace(str[i]); i++);
    for (int k = size - 1; mx_isspace(str[k]); j++, k--);  
    size -= i + j;
    arr = mx_strnew(size + 1);
    for (j = 0; j < size; j++, i++) {
        arr[j] = str[i];        
    }
    arr[size + 1] = '\0';
    return arr;
}
