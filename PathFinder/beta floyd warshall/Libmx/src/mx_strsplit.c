#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (!s) return NULL;
    char *copy = mx_del_extra_spaces_forsplit(s, c);
    int len = mx_count_words(copy, c);
    int counter = 0;
    char **arr = (char**)malloc(len * sizeof(char*));
    int k = 0, len_w = 0;
    for (int i = 0; i < len; i++) {
        for (len_w = 0; copy[k] != c && copy[k] != '\0'; k++, len_w++);
        k += 1;
        len_w++;
        arr[i] = mx_strnew(len_w);
        for (int z = 0; z < len_w - 1;counter++, z++) {
            arr[i][z] = copy[counter];
        }
        counter++;
    }    
    arr[len] = NULL;
    mx_strdel(&copy);
    return arr;
}
