#include "libmx.h"
char *mx_itoa(int number) {
	
    _Bool flag = 0;
	_Bool if_negative = 0;
	if (number < 0) {
		if_negative = 1;
		if (number == -2147483648) {
			number++;
			flag = 1;			
		}			
		number *= -1;		
	}
	if (number == 0) {
		char *arr = mx_strnew(1);
		arr[0] = 0 + '0';
		return arr;
    }
	else {
		int copy = number;		
		int counter = 0;		
		while (copy != 0) {
			counter++;
			copy /= 10;
		}		
		copy = number;
		if (if_negative == 1) 
			counter++;

		char *arr = mx_strnew(counter + 1);
		if (if_negative == 1) 
			arr[0] = '-';

		for (int i = counter - 1; i >= if_negative; i--) {
			if (flag == 1) {
				arr[counter - 1] = 8 + '0';				
				flag = 0;
			}
			else 
				arr[i] = (number % 10) + '0';
			number /= 10;	
		}
		arr[counter + 1] = '\0';
		return arr;
	}
}
