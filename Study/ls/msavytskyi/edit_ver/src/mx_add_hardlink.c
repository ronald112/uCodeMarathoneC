#include "uls.h"

void mx_add_hardlink(char *path, char **result) {
    char buff[256];

    mx_memset(buff, '\0', 256);
    readlink(path, buff, 256);
    if (mx_strlen(buff)) {
        *result = mx_addstr(*result, " -> ");
        *result = mx_addstr(*result, buff);
    }
}
