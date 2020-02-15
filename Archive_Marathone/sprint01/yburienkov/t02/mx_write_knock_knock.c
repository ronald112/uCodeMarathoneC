#include <unistd.h>
#include <string.h>

void mx_write_knock_knock(void) {
    char str_first_line[] = "Wake up, NEO \\ (^_^) / ...\n";
    char str_second_line[] = "The Matrix has you ...\n";
    write (1, str_first_line, strlen(str_first_line));
    write (1, str_second_line, strlen(str_second_line));
}
