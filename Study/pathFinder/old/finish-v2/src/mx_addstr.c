#include "pathfinder.h"

// copy and delete src string
char *mx_addstr(char *str, char *arr) {
    char *temp = mx_strjoin(str, arr);

    if (str) mx_strdel(&str);
    return temp;
}
