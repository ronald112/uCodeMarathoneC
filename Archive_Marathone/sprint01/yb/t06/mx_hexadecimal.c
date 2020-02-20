#include <unistd.h>

void mx_printchar(char c);

void mx_hexadecimal(void) {
    for (int counter = 48; counter <= 57; counter++) {
        mx_printchar(counter);    
        write (1, "\n", 1);
    }
    for (int counter = 65; counter <= 90; counter++) {
        mx_printchar(counter);
        write (1, "\n", 1);
    }
}
