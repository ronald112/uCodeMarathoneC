#include "libmx.h"

static char **calculation(char *copy, char c) {
    char **arr = (char**)malloc(mx_count_words(copy, c) * sizeof(char*));
    int k = 0;
    int len_w = 0;
    int counter = 0;

    for (int i = 0; i < mx_count_words(copy, c); i++) {
        for (len_w = 0; copy[k] != c && copy[k] != '\0'; k++, len_w++);
        k += 1;
        len_w++;
        arr[i] = mx_strnew(len_w);
        for (int z = 0; z < len_w - 1;counter++, z++) {
            arr[i][z] = copy[counter];
        }
        counter++;
    }
    arr[mx_count_words(copy, c)] = NULL;
    return arr;
}

char **mx_strsplit(const char *s, char c) {
    if (!s)
        return NULL;
    else {
        char *copy = mx_del_extra_spaces_forsplit(s, c);
        char **result = calculation(copy, c);

        mx_strdel(&copy);
        return result;
    }
}
