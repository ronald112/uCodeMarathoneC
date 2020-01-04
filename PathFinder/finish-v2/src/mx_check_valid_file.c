#include "pathfinder.h"

void mx_check_valid_file(int nmb_argc,
    char const *rl_argv, t_main *vars) {
    mx_first_check(&vars->fd, nmb_argc, rl_argv);
    mx_check_file_empty(vars, rl_argv);
    mx_check_valid_frst_line(vars);
}

