#include "libmx.h"

// copy character to the string
char *mx_addchr(char *str, char arr) {
    char *one_char = mx_strnew(1);
    char *temp = NULL;

    one_char[0] = arr;
    temp = mx_strjoin(str, one_char);
    if (str)
        mx_strdel(&str);
    mx_strdel(&one_char);
    return temp;
}
