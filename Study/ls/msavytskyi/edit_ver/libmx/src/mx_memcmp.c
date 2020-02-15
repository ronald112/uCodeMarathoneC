#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    size_t i = 0;
    const unsigned char *cp_s1 = s1;
    const unsigned char *cp_s2 = s2;
    
    for (; cp_s1[i] == cp_s2[i] && i < n; i++);
    if (i == n) {			
        return 0;
    }
    return cp_s1[i] - cp_s2[i];
}
