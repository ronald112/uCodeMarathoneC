#include "uls.h"

void add_ch_symb_link(char **result, char *path, mode_t mode) {
    char buff[256] = "\0";

    readlink(path, buff, 256);
    if (mode & S_IFDIR)
        *result = mx_addstr(*result, "d");
    else if ((mode & S_IFLNK) && mx_strlen(buff))
        *result = mx_addstr(*result, "l");
    else
        *result = mx_addstr(*result, "-");
}

char *mx_get_permissions(mode_t mode, char *path) {
    char *result = NULL;
    
    add_ch_symb_link(&result, path, mode);
    result = mx_addstr(result, (mode & S_IRUSR) ? "r" : "-");
    result = mx_addstr(result, (mode & S_IWUSR) ? "w" : "-");
    result = mx_addstr(result, (mode & S_IXUSR) ? "x" : "-");
    result = mx_addstr(result, (mode & S_IRGRP) ? "r" : "-");
    result = mx_addstr(result, (mode & S_IWGRP) ? "w" : "-");
    result = mx_addstr(result, (mode & S_IXGRP) ? "x" : "-");
    result = mx_addstr(result, (mode & S_IROTH) ? "r" : "-");
    result = mx_addstr(result, (mode & S_IWOTH) ? "w" : "-");
    if (mode & S_ISVTX)
        result = mx_addstr(result, "t");
    else if (mode & S_IXOTH)
        result = mx_addstr(result, "x");
    else
        result = mx_addstr(result, "-");
    return result;
}
