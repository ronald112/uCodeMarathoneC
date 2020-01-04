#include "pathfinder.h"

void mx_print_route(t_dijk *djk_var, int check, int k, int y) {
    if (check != 0 && k > 1)
        djk_var->is_chk_alt[check][y] = false;
}
