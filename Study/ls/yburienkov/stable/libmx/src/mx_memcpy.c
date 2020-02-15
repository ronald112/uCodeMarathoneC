#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    for (size_t i = 0; i < n; i++)
        ((char *restrict)dst)[i] = ((const char *restrict)src)[i];
    return dst;
}
