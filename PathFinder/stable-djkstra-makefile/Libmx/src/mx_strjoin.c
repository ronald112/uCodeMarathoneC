#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    char *result = NULL;
    if (!s1 && !s2) return result;
    else if (!s2)  return mx_strdup(s1);      
    else if (!s1) return mx_strdup(s2);
    else {
        result = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
        int i = 0;
        for (; *s1 != '\0'; i++, s1++) 
            result[i] = *s1;    
        for (; *s2 != '\0'; i++, s2++) 
            result[i] = *s2;
        result[i] = '\0';
    }
    return result;
}
