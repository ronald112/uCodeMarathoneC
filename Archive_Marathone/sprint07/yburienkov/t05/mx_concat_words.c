#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void mx_strdel(char **str);
int mx_strlen(const char *s);//
char *mx_strcpy(char *dst, const char *src);//
char *mx_strnew(const int size);//
char *mx_strdup(const char *str);//
char *mx_strcat(char *s1, const char *s2);//
char *mx_strjoin(char const *s1, char const *s2);

char *mx_concat_words(char **words) {
    char *result = NULL;

    if (*words != NULL) {
        // задаю длинну строки на выходе
        int lengh = 0;
        for(int i = 0; words[i] && words[i] != NULL; i++)
            lengh += mx_strlen(words[i]);    
        lengh += 1;

        result = mx_strnew(lengh);

        for(int i = 0; words[i] != NULL; i++) {
            result = mx_strcat(result, words[i]);
            if (words[i+1] != NULL) 
			    result = mx_strcat(result, " ");
        }
    
        return result;
    }

    return NULL;
}
