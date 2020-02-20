#include <unistd.h>
#include <stdbool.h>

char *mx_strnew(const int size);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strtrim(const char *str);
int mx_strlen(const char *s);
void mx_strdel(char **str);
bool mx_isspace(char c);

char *mx_del_extra_whitespaces(const char *str) {
    char *temp_str1 = mx_strtrim(str);
    int temp_len = mx_strlen(temp_str1);
    char prev_char = '\0';
    char *temp_str2 = mx_strnew(temp_len);

    if (temp_len > 0) {
        prev_char = temp_str1[0];
    }

    for (int i = 0, j = 0; temp_str1[i] != '\0'; i++) {
        if (!mx_isspace(temp_str1[i])) {
            temp_str2[j] = temp_str1[i];
            j++;
        }
        if (mx_isspace(temp_str1[i]) && !mx_isspace(prev_char)) {
            temp_str2[j] = ' ';
            j++;
        }
        prev_char = temp_str1[i];
    }
    mx_strdel(&temp_str1);

    return temp_str2;
}