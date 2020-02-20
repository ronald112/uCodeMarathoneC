#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    int i = 0;

    for (; i < len; i++) {        
        dst[i] = *src;
        if (*src != '\0')
            src++;
    }
    return dst;
}
