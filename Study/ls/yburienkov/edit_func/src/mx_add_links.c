#include "uls.h"

void mx_add_links(nlink_t link, t_catalog *cat, char **result) {
    char *temp = mx_itoa(link);
    long long cnt = 0;

    *result = mx_addstr(*result, " ");
    for (; link != 0; link /= 10, cnt++);
    cnt = cat->max_size_oflink - cnt;
    for (; cnt != 0; cnt--)
        *result = mx_addstr(*result, " ");
    *result = mx_addstr(*result, temp);
    *result = mx_addstr(*result, " ");

    mx_strdel(&temp);
}
