char *mx_strchr(const char *s, int c);
int mx_strncmp(const char *s1, const char *s2, int n);

char *mx_strstr(const char *s1, const char *s2) {
    int len1 = 0;
    int len2 = 0;
    while (*s1)    
        len1++;
    while (*s2)
        len2++;   


    if (len2 == 0) {
        return(char *)&s1[0];
    }
    for (int i = 0; i < len1; i++) {
        if (s1[i] == s2[i]) {
            int substr_len = 1;

            for (int k = 0, j = i; 
            s1[j] == s2[k] && s1[j] != '\0';
             j++, k++, substr_len++) {
                 if (substr_len - 1 == len2) {
                     return (char *)&s1[i];
                 }
            }
        }
    }
    return 0;
}
