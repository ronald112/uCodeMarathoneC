#include "libmx.h"
char *mx_strcpy(char *dst, const char *src) {

    // for (int i = 0; src[i++]; dst[i] = src[i]);
    // return (*dst = *src, dst);

    int i = 0;
    for (; *src != '\0'; i++, src++) {
        dst[i] = *src;
    }
    dst[i] = '\0';
    return dst;
}
