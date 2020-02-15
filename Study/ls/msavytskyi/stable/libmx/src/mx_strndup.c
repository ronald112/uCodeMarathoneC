#include "libmx.h"

static long long min_ll(long long a, long long b) {
    long long result = a < b ? a : b;

    return result;
}

char *mx_strndup(const char *s1, size_t n) {
    size_t len = min_ll(n, mx_strlen(s1));
    char *s2 = s1 ? mx_strnew(len) : NULL;
    char *result = s2 ? mx_strncpy(s2, s1, len) : NULL;

    return result;
}
