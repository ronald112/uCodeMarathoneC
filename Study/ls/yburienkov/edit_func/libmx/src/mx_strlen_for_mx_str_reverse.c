#include "libmx.h"

unsigned int mx_strlen_for_mx_str_reverse(const char *s) {
    unsigned int counter = 0;

    for (; *s != '\0'; s++, counter++);
    return counter;
}
