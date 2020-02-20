#include "minilibmx.h"

int mx_atoi(const char *str) {
    int sign = 1;
    int number = 0;
    int int_len = 0;
    int first = 0;
    int power = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (mx_isspace(str[i])) {
            first++;
        }
    }
    if (str[first] == '-' || str[first] == '+') {
        if (str[first] == '-') {
            sign = -1;
        }
        first++;
    }
    for (int j = first; mx_isdigit(str[j]); j++) {
            power *= 10;
            int_len++;
    }
    power /= 10;
    for (int k = first, len = first + int_len; k < len; k++, power /= 10) {
        number += power*(str[k] - 48);

    }
    return number*sign;
}
