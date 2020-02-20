#include <unistd.h>

#include "mx_printchar.c"

void mx_isos_triangle(unsigned int length, char c) {
  int max_length = length; 
for (int count = 0; max_length > count; count++) {
  for (int sec_count = 0; count >= sec_count; sec_count++) {
    mx_printchar(c);
    }
    write (1, "\n", 1);
  }
}
