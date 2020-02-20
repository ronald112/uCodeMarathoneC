#include <stdbool.h>

bool mx_islower(int c) {
  if ((c >= 'a') && (c <= 'z')) {
    return 1;
  }
  return 0;
}
