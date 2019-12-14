#include <stddef.h>
void mx_printchar(char c);

void mx_printint(int n) {	
	_Bool flag = 0;
	if (n < 0) {
		if (n == -2147483648) {
			n++;
			flag = 1;
		}			
		mx_printchar('-');
		n *= -1;		
	}
	if (n == 0)
		mx_printchar('0');
	else {
		int copy = n;
		int counter = 0;		
		while (copy != 0) {
			counter++;
			copy /= 10;
		}		
		copy = n;
		char arr[counter];
		for (int i = counter - 1; i >= 0; i--) {
			if (flag == 1) {
				arr[counter - 1] = 8;
				flag = 0;
			}
			else 
				arr[i] = n % 10;
			n /= 10;			
		}
		for (int i = 0; i < counter; i++) 		
			mx_printchar(arr[i] + 48);
	}
}

/*
void mx_printint(int n) {	
	if (n < 0) {
		mx_printchar('-');
		n *= -1;
	}
	else if (n == 0)
		mx_printchar('0');
	else {
		long int degr = 1;
		int copy = n;
		int counter = 0;		
		while (copy != 0) {
			counter++;
			copy /= 10;
			degr *= 10;
		}		
		for (int i = counter; i > 0; i--) {
			copy = n % degr;		
			mx_printchar(copy + 48);
			degr /= 10;
		}
		
	}
}
*/



/*
//mx_printint.c
#include <stdio.h>

void mx_printchar(char c); 

void mx_printint(int n){
    long int sec_n = n;
    long int counter = 0;
    long int max_char = 1;
    int first_res = 0;
    while (sec_n != 0) {
		sec_n /= 10;
		counter++;
        max_char *=10;
    }
    if (n < 0) {
        n *= -1;
	mx_printchar('-');
    }
    for (int sec_coun = 0; sec_coun <= counter; sec_coun++) {	
        first_res = n / max_char;
	if (sec_coun != 0) {
            mx_printchar(first_res+48);
	}
	n = n % max_char;
	max_char /= 10;
    }   
}
*/

