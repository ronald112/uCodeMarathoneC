#include "pathfinder.h"

void mx_check_file_empty(t_main *vars, char const *rl_argv) {
    int str = -1;
    
    if ((str = mx_read_line(&vars->str, 1, '\n', vars->fd)) < 0) {
        mx_printerr("error: file ");
        mx_printerr(rl_argv);
        mx_printerr(" is empty\n");
        exit(1);
    }
}
