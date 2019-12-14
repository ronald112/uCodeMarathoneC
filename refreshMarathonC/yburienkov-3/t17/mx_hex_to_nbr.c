#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

static bool mx_isdigit(int c) {
  if ((c >= '0') && (c <= '9')) {
    return 1;
  }
  return 0;
}

static unsigned long pow(const int degr, const int src) {
    unsigned long result = 1;
    for (int i = 0; i < degr; i++)
        result *= src;
    return result;
}

unsigned long mx_hex_to_nbr(const char *hex) {
     
    unsigned long result = 0;   

    int degree = 0;
    for (; hex[degree] != '\0'; degree++);
    int counter = degree;
    degree--;   
   
    for (int i = 0; i < counter && degree >= 0; i++, degree--) {

        if (mx_isdigit(hex[i])) 
            result = result + ((hex[i] - '0') * pow(degree, 16)) * 10;            
         else if ((hex[i] >= 'A') && (hex[i] <= 'F')) 
            result = result + ((hex[i] - 55) * pow(degree, 16)) * 10;             
         else if ((hex[i] >= 'a') && (hex[i] <= 'f')) 
            result = result + ((hex[i] - 87) * pow(degree, 16)) * 10;        
        else 
            return 0;    
    }

    result /= 10;

    return result;
}
