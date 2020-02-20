#include "libmx.h"

int mx_atoi(const char *str) {
    int result = 0;

    while ((mx_isdigit(*str) != 1)) {
        str++;
    }
    while ((mx_isdigit(*str) == 1)) {
        result = ((result + (int)*str - 48) * 10);
        str++;
    }
    result /= 10;
    return result;
}
