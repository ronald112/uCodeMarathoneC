#include "libmx.h"
char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (str == NULL || sub == NULL || replace == NULL) return NULL;
    int count_sub = mx_count_substr(str, sub);
    if (count_sub == 0) {
        char *res = mx_strdup(str);
        return res;
    }
    int new_size = (mx_strlen(str) + (mx_strlen(replace) * count_sub) - (mx_strlen(sub) * count_sub)) + 1; 
    char *result = mx_strnew(new_size + 1);
    for (int i = 0, j = 0, k = 0, resut_iter = 0; i < new_size + 1; i++){
        if (str[i] == *sub) {
            for (j = i, k = 0; str[j] == sub[k] && sub[k] != '\0'; j++, k++);
            if (k == mx_strlen(sub)) {
                for (k = 0; replace[k] != '\0'; j++, k++, resut_iter++) {
                    result[resut_iter] = replace[k];
                }
                i += mx_strlen(sub) - 1;
            }
        } else
        {
            result[resut_iter] = str[i];
            resut_iter++;
        }        
    }
    result[new_size + 1] = '\0';
    return result;
}
