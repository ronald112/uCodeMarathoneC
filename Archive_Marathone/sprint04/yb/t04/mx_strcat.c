int mx_strlen(const char *s);

char *mx_strcat(char *s1, const char *s2) {
    int first_len = mx_strlen(s1);
    int sec_len = mx_strlen(s2);
    int max_len = sec_len + first_len + 2;
    for (int i = first_len, j = 0; i < max_len; i++) {
        s1[i] = s2[j];
        j++;
    }
    return &s1[0];   
}
