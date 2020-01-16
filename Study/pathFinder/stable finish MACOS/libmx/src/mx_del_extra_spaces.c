#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (str == NULL) return NULL;
    char *arr = mx_strtrim(str);
    if (mx_strlen(arr) < 1) return arr;
    int count_w = 0, count_s = 0;
    bool flag = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        if (!mx_isspace(arr[i])) {
            count_w++;
            flag = 0;
        }
        else
        {
            if (flag == 0) {
                count_s++;
                flag = 1;
            }
        }
    }
    char *rslt = mx_strnew(count_w + count_s + 1);
    for (int i = 0, j = 0; arr[i] != '\0'; i++) {
        if (!mx_isspace(arr[i])) {
            rslt[j] = arr[i];
            j++;
            flag = 0;
        }
        else
        {
            if (flag == 0) {
                rslt[j] = ' ';
                j++;
                flag = 1;
            }
        }
    }
    rslt[count_w + count_s + 1] = '\0';
    mx_strdel(&arr);
    return rslt;
}
