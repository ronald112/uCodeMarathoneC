#include "libmx.h"

char *mx_strdup(const char *s1) {
    char *arr = mx_strnew(mx_strlen(s1));

    for (int i = 0; i < mx_strlen(s1); i++) {
        arr[i] = s1[i];
    }
    arr[mx_strlen(s1)] = '\0';
    return arr;
}
