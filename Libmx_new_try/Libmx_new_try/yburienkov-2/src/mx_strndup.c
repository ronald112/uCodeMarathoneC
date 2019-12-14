#include "libmx.h"
char *mx_strndup(const char *s1, size_t n) {
    char *arr = mx_strnew(n);
    for (size_t i = 0; i < n; i++) {
        arr[i] = s1[i];
    }
    arr[n] = '\0';
    return arr;
}
