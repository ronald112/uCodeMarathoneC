#include "libmx.h"

static long long mx_min_ll(long long a, long long b) {
    return a < b ? a : b;
}

char *mx_strndup(const char *s1, size_t n) {

    size_t len = mx_min_ll(n, mx_strlen(s1));
    char *s2 = s1 ? mx_strnew(len) : NULL;

    return s2 ? mx_strncpy(s2, s1, len) : NULL;

    // char *arr = mx_strnew(n);
    // for (size_t i = 0; i < n; i++) {
    //     arr[i] = s1[i];
    // }
    // arr[n] = '\0';
    // return arr;
}
