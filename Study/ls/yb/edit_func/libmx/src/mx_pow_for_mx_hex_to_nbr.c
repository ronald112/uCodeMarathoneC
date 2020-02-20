#include "libmx.h"

unsigned long mx_pow_for_mx_hex_to_nbr(const int degr, const int src) {
    unsigned long result = 1;

    for (int i = 0; i < degr; i++)
        result *= src;
    return result;
}
