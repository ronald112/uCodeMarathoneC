#include "libmx.h"

bool mx_isspace(char c) {
  if ((c == '\n') || (c == '\v') || (c == '\f')) {
    return 1;
  }
  else if ((c == '\r') || (c == '\t')) {
    return 1;
  }
  else if (c == ' ') {
    return 1;
  }
  return 0;
}
