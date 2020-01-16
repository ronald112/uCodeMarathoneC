#include "libmx.h"

char *mx_strtrim(const char *str) {

    int start = 0;
    int end = mx_strlen(str ? str : "");

    end = end == 0 ? 0 : end - 1;
    char *new_str = NULL;

    if (str) {
        for (; mx_isspace(str[start]); ++start);
        for (; mx_isspace(str[end]) && end > start; --end);

        new_str = mx_strnew(end > start ? end - start + 1 : 0);
        mx_strncpy(new_str, str + start, end - start + 1);
    }
    return new_str;


    // if (str == NULL) return NULL;
    // char *arr = "";
    // int i = 0, j = 0;
    // if (mx_strlen(str) == 1) return arr;
    // for (;mx_isspace(str[i]); i++);
    // if (i == mx_strlen(str)) return arr;
    // int size = mx_strlen(str);    
    // for (i = 0; mx_isspace(str[i]); i++);
    // for (int k = size - 1; mx_isspace(str[k]); j++, k--);  
    // size -= i + j;
    // arr = mx_strnew(size + 1);
    // for (j = 0; j < size; j++, i++) {
    //     arr[j] = str[i];        
    // }
    // arr[size + 1] = '\0';
    // return arr;
}
