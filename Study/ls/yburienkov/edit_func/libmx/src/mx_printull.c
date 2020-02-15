#include "libmx.h"

void mx_printull(long long n) {
    long digits[20];
    int i = 0;
    long long x = n;

    if (n == 0) {
        mx_printchar('0');
        return;
    }
    if (n < 0) {
        mx_printchar('-');
        x *= -1;
    }
    for (; x > 0; x /= 10) {
        digits[i++] = x % 10;
    }
    while (i > 0) {
        mx_printchar(digits[--i] + 48);
    }
}
