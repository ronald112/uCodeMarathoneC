#include "get_address.h"

char *mx_get_address(void *p) {
    unsigned long long adr = (unsigned long long)p;
    char *ptr_address = mx_nbr_to_hex(adr);
    int ptr_len = mx_strlen(ptr_address);
    char *full_address = mx_strnew(ptr_len+2);

    full_address[0] = '0';
    full_address[1] = 'x';

    for (int i = 2, j = 0; ptr_address[j] != '\0'; i++, j++) {
        full_address[i] = ptr_address[j];
    }
    return full_address;
}
