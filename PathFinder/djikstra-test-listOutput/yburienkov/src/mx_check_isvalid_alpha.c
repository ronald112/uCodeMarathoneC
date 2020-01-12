#include "pathfinder.h"

bool mx_check_isvalid_alpha(const char *str, int j) {
    if (j < 2) {
        for (int i = 0; str[i] != '\0'; i++)
            if (!(mx_isalpha(str[i])))
                return 0;
        return 1;
    }
    else {
        if (mx_check_valid_1Line(str))
            return 1;
        else
            return 0;
    }
}
