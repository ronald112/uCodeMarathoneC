#include "libmx.h"

static unsigned long calculation(int counter, int degree, const char *hex) {
    int result = 0;

    for (int i = 0; i < counter && degree >= 0; i++, degree--)
        if (mx_isdigit(hex[i]))
            result = result + ((hex[i] - '0') * mx_pow(degree, 16)) * 10;
        else if ((hex[i] >= 'A') && (hex[i] <= 'F'))
            result = result + ((hex[i] - 55) * mx_pow(degree, 16)) * 10;
        else if ((hex[i] >= 'a') && (hex[i] <= 'f'))
            result = result + ((hex[i] - 87) * mx_pow(degree, 16)) * 10;
        else
            return 0;
    result /= 10;
    return result;
}

unsigned long mx_hex_to_nbr(const char *hex) {
    if (hex != NULL) {
        unsigned long result = 0;
        int degree = 0;
        int counter = 0;

        for (; hex[degree] != '\0'; degree++);
        counter = degree;
        degree--;
        result = calculation(counter, degree, hex);
        return result;
    }
    else
        return 0;
}
