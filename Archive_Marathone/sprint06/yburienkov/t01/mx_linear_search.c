int mx_strcmp(const char *s1, const char *s2);
//#include <stdio.h>
int mx_linear_search(char **arr, const char *s) {
     int result = -1;    
     for (int i = 0; arr[i] != '\0'; i++) {
        if (mx_strcmp(arr[i], s) == 0) {
            result = i;
        } 
    }
    return result;
}
