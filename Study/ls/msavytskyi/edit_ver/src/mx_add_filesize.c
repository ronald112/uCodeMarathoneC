#include "uls.h"

void mx_add_filesize(off_t size, t_catalog *cat, char **result) {
    char *temp = mx_ltoa(size);
    long long cnt = 0;

    if (size == 0)
        cnt = 1;
    for (; size != 0; size /= 10, cnt++);
    cnt = cat->max_size_ofdir - cnt;
    for (; cnt != 0; cnt--)
        *result = mx_addstr(*result, " ");
    *result = mx_addstr(*result, temp);
    mx_strdel(&temp);
}
