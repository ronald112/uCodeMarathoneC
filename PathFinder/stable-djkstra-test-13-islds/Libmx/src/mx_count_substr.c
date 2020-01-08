#include "libmx.h"
int mx_count_substr(const char *str, const char *sub) {
    if (sub == NULL || str == NULL)
        return -1;
    int i = 0, counter = 0, j = 0, k = 0;
    int flag = 0;
    for (; str[i] != '\0'; i++) {
        if (str[i] == *sub) {            
            for (j = i, k = 0; sub[k] != '\0'; j++, k++) {
                if (str[j] != sub[k]) {                    
                    break;
                }
                 else
                    flag++;
            }

            if (flag == mx_strlen(sub)) {
                counter++;                
                i += k - 1;
                flag = 0;
            }
        }        
    }
    
    return counter;
}
