//mx_only_printable.c

#include <unistd.h>

void mx_printchar(char c);

void mx_only_printable(void) {
    for (int counter_char = 126; counter_char > 32; counter_char--) {
        mx_printchar(counter_char);
        write (1, "\n", 1);
    }
}
