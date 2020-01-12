#include "pathfinder.h"

void mx_set_false_arr(t_dijk *djk_var, int k, int y) {
    if (k == 0) {
        for (int i = 0; i < djk_var->nmb_isld; i++)
            for (int j = 0; j < djk_var->nmb_isld; j++)
                if (j != y)
                    djk_var->is_chk_alt[i][j] = 0;
    }
}
