#include "libmx.h"

static char *second_count(char *arr, int count_w, int count_s) {
    int j = 0;
    bool flag = 0;
    char *rslt = mx_strnew(count_w + count_s + 1);

    for (int i = 0; arr[i] != '\0'; i++)
        if (!mx_isspace(arr[i])) {
            rslt[j] = arr[i];
            j++;
            flag = 0;
        }
        else if (flag == 0) {
            rslt[j] = ' ';
            j++;
            flag = 1;
        }
    mx_strdel(&arr);
    rslt[count_w + count_s + 1] = '\0';
    return rslt;
}

static char *first_count(char *arr, int *count_w, int *count_s) {
    bool flag = 0;
    char *rslt = NULL;

    for (int i = 0; arr[i] != '\0'; i++) {
        if (!mx_isspace(arr[i])) {
            *count_w += 1;
            flag = 0;
        }
        else if (flag == 0) {
            *count_s += 1;
            flag = 1;
        }
    }
    rslt = second_count(arr, *count_w, *count_s);
    return rslt;
}

char *mx_del_extra_spaces(const char *str) {
    char *arr = NULL;

    if (mx_strlen(arr = mx_strtrim(str)) < 1) return arr;
    if (str != NULL) {
        int count_w = 0;
        int count_s = 0;
        char *rslt = first_count(arr, &count_w, &count_s);

        return rslt;
    }
    else
        return NULL;
}
