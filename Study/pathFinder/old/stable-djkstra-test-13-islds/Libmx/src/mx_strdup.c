#include "libmx.h"

char *mx_strdup(const char *s1) {

    // char *ptr = mx_strnew(mx_strlen(s1));
    // return ptr ? mx_strcpy(ptr, s1) : NULL;

    char *arr = mx_strnew(mx_strlen(s1));
    for (int i = 0; i < mx_strlen(s1); i++) {
        arr[i] = s1[i];
    }
    arr[mx_strlen(s1)] = '\0';
    return arr;
}
