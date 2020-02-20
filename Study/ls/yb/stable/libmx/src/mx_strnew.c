#include "libmx.h"

char *mx_strnew(const int size) {
    char *ptrVar = NULL;

    if (size >= 0) {
        if ((ptrVar = malloc((size + 1) * sizeof(char))) == NULL)
            return NULL;
        else  {        
            for (int i = 0; i <= size; i++) 
                ptrVar[i] = '\0';            
        }
        return ptrVar;
    }
    return NULL;     
}


