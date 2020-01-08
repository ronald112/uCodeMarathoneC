#include "libmx.h"
void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    if (big == NULL) return NULL;
    if (big_len == 0) return NULL;
    if (little == NULL) return NULL;
    if (little_len == 0) return NULL;

    const unsigned char *haystack = big;
    const unsigned char *needle = little;    

    for (; big_len >= little_len; big_len--, haystack++) 
        if ((!mx_memcmp(haystack, needle, little_len))) 
            return (void*)haystack;
    return NULL;
}
