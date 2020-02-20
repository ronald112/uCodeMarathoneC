#include "libmx.h"

bool mx_isspace_forsplit(char c, char d) {
  if ((c == '\n') || (c == '\v') || (c == '\f' )) {
    return 1;
  }
  else if ((c == '\r') || (c == '\t')) {
    return 1;
  }
  else if (c == d) {
    return 1;
  }
  return 0;
}
