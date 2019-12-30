#include "pathfinder.h"

void mx_set_to_false_checker(t_dijk *djk_var) {
    for (int i = 0; i < djk_var->nmb_isld; i++)
        for (int j = 0; j < djk_var->nmb_isld; j++)
            djk_var->is_chk_alt[i][j] = 0;
}
