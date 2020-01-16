#include "../inc/pathfinder.h"

// add to the beginning o the string
char *mx_add_to_begin(char *s1, char *s2) {
    char *result = NULL;

    if (!s1 && !s2) 
        return result;
    else if (!s2)  
        return mx_strdup(s2);      
    else if (!s1) 
        return mx_strdup(s1);
    else {
        result = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
        int i = 0;
        for (int j = 0; s2[j] != '\0'; i++, j++) 
            result[i] = s2[j];
        for (int j = 0; s1[j] != '\0'; i++, j++) 
            result[i] = s1[j];        
        result[i] = '\0';
    }
    if (s1) 
        mx_strdel(&s1);
    return result;
}
