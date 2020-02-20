#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    for (;*arr ;) {
        mx_printstr(*arr);
        arr++;
        if (arr)
            mx_printstr(delim);
    }
    mx_printchar('\n');
    
}
