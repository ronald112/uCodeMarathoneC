#include "libmx.h"

int mx_strlen(const char *s) {
    int counter = 0;

    for (; s && *s != '\0'; s++, counter++);
    return counter;
}
