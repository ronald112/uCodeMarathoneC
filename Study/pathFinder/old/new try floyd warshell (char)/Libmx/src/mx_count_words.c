#include "libmx.h"
int mx_count_words(const char *str, char c) {
    if (str == NULL)
        return -1;
    int i = 0, counter = 0;
    for (; str[i] != '\0'; i++) {
        if (str[i] != c) {
            for (; str[i] != c && str[i] != '\0'; i++);
            counter++;            
        }        
    }
    return counter;
}
