#include "minilibmx.h"

bool mx_isspace(char c) {
  if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f' || c == '\r') {
        return true;
    }
    return false;
}
