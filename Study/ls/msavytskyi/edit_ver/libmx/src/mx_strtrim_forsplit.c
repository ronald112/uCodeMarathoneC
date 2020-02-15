#include "libmx.h"
char *mx_strtrim_forsplit(const char *str, char c) {
    if (str == NULL)
        return NULL;
    else {
        int size = mx_strlen(str);
        int i = 0;
        int j = size;
        char *arr = NULL;

        for (;mx_isspace_forsplit(str[i], c); i++);
        for (;mx_isspace_forsplit(str[j], c); j--, i++);
        size -= i;
        arr = mx_strnew(size);
        for (j = 0; i < size; j++, i++) {
            arr[j] = str[i];        
        }
        arr[j] = '\0';
        return arr;
    }
}
