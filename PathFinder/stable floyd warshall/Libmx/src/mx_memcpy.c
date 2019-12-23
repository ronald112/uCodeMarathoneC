#include "libmx.h"
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    unsigned char *cp_dst = dst;
    const unsigned char *cp_src = src;
    for (; n > 0; n--, cp_src++, cp_dst++)  {
        *cp_dst = *cp_src;
    }
    return (void*)dst;
}
