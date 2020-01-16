#include "libmx.h"


unsigned long mx_hex_to_nbr(const char *hex) {
    if (hex == NULL) return 0;     
    unsigned long result = 0;   
    int degree = 0;
    for (; hex[degree] != '\0'; degree++);
    int counter = degree;
    degree--;      
    for (int i = 0; i < counter && degree >= 0; i++, degree--) {

        if (mx_isdigit(hex[i])) 
            result = result + ((hex[i] - '0') * mx_pow(degree, 16)) * 10;            
         else if ((hex[i] >= 'A') && (hex[i] <= 'F')) 
            result = result + ((hex[i] - 55) * mx_pow(degree, 16)) * 10;             
         else if ((hex[i] >= 'a') && (hex[i] <= 'f')) 
            result = result + ((hex[i] - 87) * mx_pow(degree, 16)) * 10;        
        else 
            return 0;    
    }

    result /= 10;

    return result;
}
