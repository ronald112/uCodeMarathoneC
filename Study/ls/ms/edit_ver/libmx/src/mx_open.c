#include "libmx.h"

int mx_open(const char *arr) {
    int status = 0;
    
    if ((status = open(arr, O_RDONLY)) == -1) {
        return -1;
    }
    return status;
}
