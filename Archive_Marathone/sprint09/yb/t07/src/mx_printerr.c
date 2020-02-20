#include "../inc/minilibmx.h"

void mx_printerr(const char *s) {
 for (int counter = 0; counter < mx_strlen(s); counter++) {
    write (2, &s[counter], 1);
  }
}
