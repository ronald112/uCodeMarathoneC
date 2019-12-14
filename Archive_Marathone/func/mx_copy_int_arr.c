#include <stdlib.h>

int *mx_copy_int_arr(const int *src, int size) {
    int *ptrVar = NULL;
    if (size > 0 && src != NULL) {

        if ((ptrVar = (int*)malloc((size) * 4)) == NULL)
            return NULL;
        else
            for (int i = 0; i < size; i++) 
                ptrVar[i] = src[i];        
     return ptrVar; 
    }

    return ptrVar;  
}
