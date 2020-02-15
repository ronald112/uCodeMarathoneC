#include "libmx.h"
char *mx_strstr(const char *haystack, const char *needle) {
    if (needle == NULL || haystack == NULL)
        return NULL;
    else {
        int i = 0;

        for (; *haystack != '\0'; i++, haystack++) {
            if (*haystack == *needle) {
                for (int j = i; *needle != '\0'; j++, needle++) {
                    if (haystack[j] != *needle) {
                        break;
                    }
                }
                return (char*)haystack;
            }
        }
        return (char*)needle;
    }
}
