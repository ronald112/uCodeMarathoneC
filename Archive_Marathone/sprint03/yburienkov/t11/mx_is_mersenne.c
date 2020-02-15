#include <stdbool.h>

double mx_pow(double n, unsigned int pow);
bool mx_is_prime(int num);

bool mx_is_mersenne(int n) {
    if (n < 2)
        return false;
        for (int i = 2; i < n; i++)
    if (mx_is_prime(n) && (mx_pow(2 , i) - 1) == n) 
        return true;
    return false;
}

/*
n++;
    unsigned p = 0;
    while(n != 1) {
       if(n & 1) return false;
       n >>= 1;
       p++;
    }    
    for(unsigned i = 2; i * i <= p; i++) {
        if(p % i == 0) return false;
    }
    return true;
 */
