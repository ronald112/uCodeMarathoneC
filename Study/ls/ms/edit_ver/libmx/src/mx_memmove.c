#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    const unsigned char *cp_src = src;
    unsigned char *cp_dst = dst;
    char *temp = mx_strnew(len);

    for (size_t i = 0; i < len; i++) 
        temp[i] = cp_src[i];
    for (size_t i = 0; i < len; i++) 
        cp_dst[i] = temp[i];
    mx_strdel(&temp);
    return dst;
}

