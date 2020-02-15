#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    const unsigned char *str = s;

    for (; *str != c && n > 0; n--, str++);
    if (*str != '\0') {
        return (void*)str;
    }
    return NULL;
}
