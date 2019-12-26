#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    if (nbr == 0) return "0";
    unsigned int counter = 0;
    for (unsigned long i = nbr; i != 0; i /= 16, counter++);    
    char *result = mx_strnew(counter);
    for (int i = counter - 1; nbr != 0; nbr /= 16, i--) {
        if ((nbr % 16) > 9)
            result[i] = (nbr % 16) + 87;
        else
            result[i] = (nbr % 16) + 48;
    }    
    result[counter] = '\0';
    return result;
}
