#include "../inc/pathfinder.h"

t_main *mx_create_vars(int fd, int nmb_isld) {
    t_main* util_vars = (t_main *)malloc(sizeof(t_main));

    util_vars->fd = fd;
    util_vars->nmb_isld = nmb_isld;
    util_vars->str = mx_strdup("");
    util_vars->delims = "-,\n";
    return util_vars;
}
