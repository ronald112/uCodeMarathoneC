#include "libmx.h"

static void max_int_case(int *n, long long int *rev) {
    if(*n < 0) {
        mx_printchar('-');
        *n = -(*n);
    }
    while (*n != 0) {
        *rev = *rev * 10 + *n % 10;
        *n /= 10;
    }
}

static void print_int(long long int rev, int reserv) {
    while (rev != 0) {
        mx_printchar(rev % 10 + 48);
        rev /= 10;
    }
    while (reserv % 10 == 0) {
        reserv /= 10;
        mx_printchar('0');
    }
}

static void calculation(int *n, long long int *rev) {
    if (*n == 0) {
        mx_printchar('0');
        return;
    }
    if (*n != -2147483648) {
        max_int_case(n, rev);
    }
    else {
        *rev = 8463847412;
        mx_printchar('-');
    }
}

void mx_printint(int n) {
    int reserv = n;
    long long int rev = 0;

    calculation(&n, &rev);
    print_int(rev, reserv);
}
