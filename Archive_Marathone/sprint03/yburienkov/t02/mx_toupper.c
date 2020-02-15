#include <stdbool.h>

int mx_toupper(int c) {
  if ((c >= 'A') && (c <= 'Z')) {

    return c;
  }
  else if ((c >= 'a') && (c <= 'z')) {
    return (c - 32);
  }
  return c;
}
