#include <stdbool.h>

bool mx_is_prime(int num) {
    for (int i = 2; i <= (num/2); i++)
        if ((num % i) == 0) 
            return 0;
    return 1;
}
