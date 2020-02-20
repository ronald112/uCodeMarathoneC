#include <stdlib.h>
#include "duplicate.h"

t_intarr *mx_del_dup_sarr(t_intarr *src) {
    if (!src) return NULL;    
	int count = 0;
 
  		for (int i = 0; i < src->size; i++) {
    		for (int j = 0; j < count; j++) {
      			if(src->arr[i] == src->arr[j]) {
        			break;
    			}
    			if (j == count) {
      			count++;
    			}
  		    }
        }
        return
}
 
 

/*
int size_str = 0;
    for (; (src->arr) != '\0'; size_str++);
    src->size = size_str;

    int temp[src->size];
    int index = 0;

    for (int i = 0; i < src->size; i++) {
        temp[i] = -2147483648;
    }

    for (int i = 0; i < src->size; i++) {
        t_intarr current = src[i];
        int found = 0;

        for (int j = 0; found == 0 && j < src->size; j++) {
            if (current == temp[j]) {
                found = 1;
            }
        }
        if (found == 0) {
           temp[index] = current;
           index++;
        }
    }
    int *dst_size = &index;

    return mx_copy_int_arr(temp, *dst_size);
 */

