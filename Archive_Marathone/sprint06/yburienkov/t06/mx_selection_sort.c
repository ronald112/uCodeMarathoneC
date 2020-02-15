#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int mx_strlen(const char *s);
int mx_strcmp(const char *s1, const char *s2);

void mx_arr_rotate(int *arr, int size, int shift) {
    if (shift < 0) 
            shift = size + (shift % size);
    
    for (int k = 0; k < shift + 1; k++) {
        
            int i = 0;
            int temp = arr[0];
            for (i = 0; i < size - 1; i++) {
                //printf("check");
                arr[i] = arr[i + 1];
            }           
            arr[i] = temp;       
        
    }
    
    
    for (int i = 0; i < size; i++) 
     printf("%d ", arr[i]);
     
}
