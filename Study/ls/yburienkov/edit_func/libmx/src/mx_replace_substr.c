#include "libmx.h"

static char *calculation(const char *str, const char *sub, const char *replace,
                        int new_size) {
    char *result = mx_strnew(new_size + 1);
    int j = 0;
    int k = 0;
    int result_iter = 0;

    for (int i = 0; i < new_size + 1; i++)
        if (str[i] == *sub) {
            for (j = i, k = 0; str[j] == sub[k] && sub[k] != '\0'; j++, k++);
            if (k == mx_strlen(sub)) {
                for (k = 0; replace[k] != '\0'; j++, k++, result_iter++)
                    result[result_iter] = replace[k];
                i += mx_strlen(sub) - 1;
            }
        }
        else {
            result[result_iter] = str[i];
            result_iter++;
        }
    result[new_size + 1] = '\0';
    return result;
}

char *mx_replace_substr(const char *str, const char *sub,
                        const char *replace) {
    if (str == NULL || sub == NULL || replace == NULL)
        return NULL;
    else {
        if (mx_count_substr(str, sub) == 0) {
            char *res = mx_strdup(str);

            return res;
        }
        else {
            int new_size = (mx_strlen(str) + (mx_strlen(replace)
            * mx_count_substr(str, sub))
            - (mx_strlen(sub) * mx_count_substr(str, sub))) + 1;

            
            return calculation(str, sub, replace, new_size);
        }
    }
}
