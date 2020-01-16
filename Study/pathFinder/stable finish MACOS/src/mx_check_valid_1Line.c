#include "pathfinder.h"

bool mx_check_valid_1Line(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(mx_isdigit(str[i]))) {
            return 0;
        }
    }
    return 1;
}
