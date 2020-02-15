char *mx_strchr(const char *s, int c);
int mx_strlen(const char *s);
int mx_strncmp(const char *s1, const char *s2, int n);
char *mx_strstr(const char *s1, const char *s2);

int mx_count_substr(const char *str, const char *sub) {
    int substrings = 0;
    char *substr_pointer = mx_strstr(str, sub);
    int substr_index = 0;

    if (substr_pointer != 0) {
        substr_index = substr_pointer - &str[0];
    }

    for (; substr_pointer != 0) {
        substr_pointer = mx_strstr(&str[substr_index + 1], sub);
        substrings++;
        substr_index = substr_pointer - &str[0];
    }return substrings;
}
