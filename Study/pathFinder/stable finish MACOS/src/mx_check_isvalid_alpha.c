#include "pathfinder.h"

static bool else_check(char *temp) {
    if (mx_check_valid_1Line(temp)) {
        mx_strdel(&temp);
        return 1;
    }
    else {
        mx_strdel(&temp);
        return 0;
    }
}

bool mx_check_isvalid_alpha(const char *str, int j) {
    char *temp = mx_del_extra_spaces(str);

    if (j < 2) {
        for (int i = 0; i < mx_strlen(str); ++i)
            if (!(mx_isalpha(str[i]))) {
                mx_strdel(&temp);
                return 0;
            }
        mx_strdel(&temp);
        return 1;
    }
    else {
        if (else_check(temp))
            return 1;
        else
            return 0;
    }
}
