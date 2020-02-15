#include <unistd.h>

void mx_printchar(char c);

void mx_print_alphabet(void) {
int counter_low_case = 97;
    for (int counter_char = 65; counter_char <= 90; counter_char++ ) {
    if (counter_low_case % 2 == 0) {
        mx_printchar(counter_low_case);        
    }
    else {
        mx_printchar(counter_char);
    }
        counter_low_case++;
    }
    write(1, "\n", 1);
}
