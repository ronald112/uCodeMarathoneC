#include "libmx.h"
char *mx_strtrim_forsplit(const char *str, char c) {
    if (str == NULL)
        return NULL;
    int size = mx_strlen(str);
    int i = 0, j = size;
    for (;mx_isspace_forsplit(str[i], c); i++);
    for (;mx_isspace_forsplit(str[j], c); j--, i++);
    size -= i;
    char *arr = mx_strnew(size);
    for (j = 0; i < size; j++, i++) {
        arr[j] = str[i];        
    }
    arr[j] = '\0';
    return arr;
}
