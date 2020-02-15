#include "file_to_str.h"

char *mx_strjoin(char const *s1, char const *s2) {
    char *new_str = NULL; 

    if (s1 != NULL && s2 != NULL) {   
        new_str = mx_strnew((mx_strlen(s1) + mx_strlen(s2)));
        new_str = mx_strcat(mx_strdup(s1), mx_strdup(s2));
        return new_str;    
        
    }
    else if (s2 == NULL) {       
        new_str = mx_strnew((mx_strlen(s1) + 1));
        new_str = mx_strdup(s1);
        return new_str;
    }
    else if (s1 == NULL){
        new_str = mx_strnew((1 + mx_strlen(s2)));
        new_str = mx_strdup(s2); 
        return new_str;
    } 
    
    return NULL;   
}
