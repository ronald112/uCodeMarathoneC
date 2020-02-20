#include "libmx.h"

void mx_str_reverse(char *s) {
    if (s != NULL) {
        int j = mx_strlen(s) - 1;

        for (int i = 0; i < j; j--, i++)
            mx_swap_char(&s[i], &s[j]);
    }
}
