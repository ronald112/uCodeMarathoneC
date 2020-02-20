#include "get_address.h"

char *mx_nbr_to_hex(unsigned long nbr) {    
    char *result = NULL;
    unsigned int counter = 0;
    unsigned long copy = nbr;
    unsigned long temp_copy = nbr;    

    for (; copy != 0; counter++, copy /= 16);
    char arr[counter];
    copy = nbr;

    for (unsigned int i = 0; i < counter; i++) {
        copy = temp_copy % 16;
        temp_copy /= 16;
		if (copy > 9)
			arr[i] = copy + 87;
		else
        	arr[i] = copy + 48;    
    }
    result = mx_strnew(counter);
	
	for (unsigned int i = 0, j = counter - 1; i < counter && j >= 0; i++, j--) 
        result[i] = arr[j];

       return result;
}
