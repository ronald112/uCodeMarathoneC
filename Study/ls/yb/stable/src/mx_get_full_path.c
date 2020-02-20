#include "uls.h"

char *mx_get_full_path(char *name, char *path) {
    char *temp = mx_strjoin("/", path);
    char *full_path = mx_strjoin(name, temp);

    mx_strdel(&temp);
    return full_path;
}
