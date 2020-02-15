#include "libmx.h"

int mx_get_char_index(const char *str, char c) {
    int index = -2;

    if (str == NULL)
        return index;
    else {
        index = 0;
        while (*str != '\0') {
            if (*str == c)
                return index;
            str++;
            index++;
        }
    }
    return -1;
}
