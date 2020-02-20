#include "libmx.h"

int mx_tolower(int c) {
    int result = c > 64 && c < 91 ? c + 32 : c;

    return result;
}
