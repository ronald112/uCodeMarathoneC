//mx_deref_pointer.c

#include <stdio.h>

void mx_deref_pointer(char ******str) {
    static char temp_str[] = "Follow the white rabbit!";
    *****str = temp_str;
}
