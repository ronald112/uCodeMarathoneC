#include "uls.h"

static void add_time(char **chr_time, char *tmp_chr_time, int year) {
    if (year == 2020) {
        for (int i = 3; i < 16; i++)
            *chr_time = mx_addchr(*chr_time, tmp_chr_time[i]);
    }
    else {
        for (int i = 3; i < 11; i++)
            *chr_time = mx_addchr(*chr_time, tmp_chr_time[i]);
        *chr_time = mx_addchr(*chr_time, ' ');
        for (int i = 20; i < 24; i++)
            *chr_time = mx_addchr(*chr_time, tmp_chr_time[i]);
    }
}

void mx_add_lastchange_time(const time_t time, char **result) {
    char *tmp_chr_time = ctime(&time);
    char *chr_time = NULL;
    int year = 0;

    for (int i = 20; i < 24; ++i) {
        chr_time = mx_addchr(chr_time, tmp_chr_time[i]);
    }
    year = mx_atoi(chr_time);
    mx_strdel(&chr_time);
    add_time(&chr_time, tmp_chr_time, year);
    *result = mx_addstr(*result, chr_time);
    *result = mx_addstr(*result, " ");
    mx_strdel(&chr_time);
}
