#include "../inc/pathfinder.h"

bool mx_check_first_line(int i, int *chk_frst_ln, int *k) {
    if (i != 0) {
        *chk_frst_ln = i;
        *k = *k + 1;
        return true;        
    }
    return false;
}
