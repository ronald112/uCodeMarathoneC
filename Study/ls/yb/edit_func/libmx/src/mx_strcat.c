#include "libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int sum_size = mx_strlen(s1) + mx_strlen(s2);

    for (int i = mx_strlen(s1); i < sum_size; i++, s2++)  {
        s1[i] = *s2;
    }
    s1[sum_size] = '\0';
    return s1;
}
