#include <stdlib.h>

void mx_strdel(char **str) {

    if (str && *str)
        free(*str);
    *str = NULL;
}
