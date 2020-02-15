#include "libmx.h"

int mx_count_words(const char *str, char c) {
    int i = 0;
    int counter = 0;

    if (str == NULL)
        return -1;
    for (; str[i] != '\0'; i++)
        if (str[i] != c) {
            for (; str[i] != c && str[i] != '\0'; i++);
            counter++;
        }
    return counter;
}
