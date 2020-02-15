#include "libmx.h"

int mx_toupper(int c) {
    int result = c > 96 && c < 123 ? c - 32 : c;

    return result;
}
