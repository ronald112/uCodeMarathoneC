#include <unistd.h>

#include "mx_strlen.c"

void mx_printstr(const char *s) {
  
  for (int counter = 0; counter < mx_strlen(s) - 1; counter++) {
    write (1, &s[counter], 1);
  }
}
