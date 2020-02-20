#include "libmx.h"

double mx_pow(double n, unsigned int pow) {
    if (pow == 0)
        return 1;
    else {
        double result = n;

        for (unsigned int i = 1; i < pow; i++, result *= n);
        return result;
    }
}
