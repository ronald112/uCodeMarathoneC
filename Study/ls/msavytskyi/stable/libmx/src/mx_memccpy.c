#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src,
int c, size_t n) {
    unsigned char *cp_dst = dst;
    const unsigned char *cp_src = src;

    for (; n > 0; n--, cp_src++, cp_dst++)  {
        if (*cp_src == c) {
            *cp_dst = *cp_src;
            break;
        }     
        *cp_dst = *cp_src;
    }
    return (void*)dst;
}
