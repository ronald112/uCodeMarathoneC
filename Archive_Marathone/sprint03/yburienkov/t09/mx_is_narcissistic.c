//mx_pow.c
#include <stdbool.h>

double mx_pow(double n, unsigned int pow);

bool mx_is_narcissistic(int num) {
    int num_sec = num;
    int counter = 0;
    //int temp = 0;
    int result = 0;
    while (num_sec != 0) {
        counter++;
        num_sec /= 10;
    }
    num_sec = num;
    while (num_sec != 0) {        
        result = result + (mx_pow((num_sec % 10), counter));
        num_sec /= 10;
    }
    if (result == num)
        return 1;
    return 0; 
}
