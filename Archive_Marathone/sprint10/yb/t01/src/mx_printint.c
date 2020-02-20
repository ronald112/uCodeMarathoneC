#include "minilibmx.h"

void mx_printint(int n) {
    int len = 1;
    int pwr = 1;
    long int number = n;

    if (number < 0) {
        mx_printchar('-');
        number *= -1;
    }
    for (int i = number / 10; i > 0; i /= 10, pwr *= 10) {
        len++;
    }
    for (long int k = 0, cp = number; k < len; k++, cp %= pwr, pwr /= 10) {
        char digit = cp / pwr;
        
        mx_printchar(digit+48);
    }
}
