#include "pathfinder.h"

void mx_wrong_line(int i) {
    char *itoa = mx_itoa(i + 1);

    mx_printerr("error: line ");
    mx_printerr(itoa);
    mx_strdel(&itoa);
    mx_printerr(" isn't valid\n");
    exit(1);
}
