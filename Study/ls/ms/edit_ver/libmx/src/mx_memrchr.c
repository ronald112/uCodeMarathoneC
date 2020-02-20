#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    const unsigned char *str = s;
    size_t i = n;

    for (; str[i] != c && i > 0; i--);
    if (str[i] == c) {
        return (void*)(str + i);
    }
    return NULL;
}
