#include "uls.h"

static void add_time(char **chr_time, char *tmp_chr_time, time_t mtime) {
    long long diff_time = time(NULL) - mtime;

    if (diff_time > 0 && diff_time < 15778463) {
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

void mx_add_lastchange_time(time_t mtime, char **result) {
    char *tmp_chr_time = ctime(&mtime);
    char *chr_time = NULL;

    add_time(&chr_time, tmp_chr_time, mtime);
    *result = mx_addstr(*result, chr_time);
    *result = mx_addstr(*result, " ");
    mx_strdel(&chr_time);
}
