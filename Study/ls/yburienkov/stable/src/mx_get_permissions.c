#include "uls.h"

char *mx_get_permissions(mode_t mode) {
    char *result = NULL;

    result = mx_addstr(result, (mode & S_IFDIR) ? "d" : "-");
    result = mx_addstr(result, (mode & S_IRUSR) ? "r" : "-");
    result = mx_addstr(result, (mode & S_IWUSR) ? "w" : "-");
    result = mx_addstr(result, (mode & S_IXUSR) ? "x" : "-");
    result = mx_addstr(result, (mode & S_IRGRP) ? "r" : "-");
    result = mx_addstr(result, (mode & S_IWGRP) ? "w" : "-");
    result = mx_addstr(result, (mode & S_IXGRP) ? "x" : "-");
    result = mx_addstr(result, (mode & S_IROTH) ? "r" : "-");
    result = mx_addstr(result, (mode & S_IWOTH) ? "w" : "-");
    result = mx_addstr(result, (mode & S_IXOTH) ? "x" : "-");
    return result;
}
