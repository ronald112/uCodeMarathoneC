#include "pathfinder.h"

void mx_first_check(int *fd, int nmb_argc, char const *rl_argv) {
    if (nmb_argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    } 
    if ((*fd = open(rl_argv, O_RDONLY)) == -1) {
        mx_printerr("error: file ");
        mx_printerr(rl_argv);
        mx_printerr(" doesn't exist\n");
        exit(1);
    } 	
}
