#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (sub != NULL || str != NULL) {
        int i = 0;
        bool flag = 0;

        for (; str[i] != '\0'; i++) {
            if (str[i] == *sub) {
                for (int j = i; *sub != '\0'; j++, sub++) {
                    if (str[j] != *sub) {
                        flag = 1;
                        break;
                    }
                    else
                        flag = 0;
                }
                if (flag == 0)
                    return i;
            }
        }
        return -1;
    }
    else
        return -2;
}
