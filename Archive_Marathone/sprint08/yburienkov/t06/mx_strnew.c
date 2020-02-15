#include <stdlib.h>

char *mx_strnew(const int size) {
    long char *ptrVar = NULL;
    if (size > 0) {
        if ((ptrVar = (char*)malloc((size + 1) * 8)) == NULL)
            return NULL;
        else  
            for (int i = 0; i <= size; i++) 
                ptrVar[i] = '\0';     
    
     return ptrVar;
    }

    return NULL;     
}
