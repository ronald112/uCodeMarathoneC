#include "libmx.h"
char *mx_del_extra_spaces_forsplit(const char *str, char c) {
    if (str == NULL)
        return NULL;
    char *arr = mx_strtrim_forsplit(str, c);
    int count_w = 0, count_s = 0;
    bool flag = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        if (!mx_isspace_forsplit(arr[i], c)) {
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
        if (!mx_isspace_forsplit(arr[i], c)) {
            rslt[j] = arr[i];
            j++;
            flag = 0;
        }
        else
        {
            if (flag == 0) {
                rslt[j] = c;
                j++;
                flag = 1;
            }
        }        
    }
    rslt[count_w + count_s + 1] = '\0';
    mx_strdel(&arr);    
    return rslt;
}
