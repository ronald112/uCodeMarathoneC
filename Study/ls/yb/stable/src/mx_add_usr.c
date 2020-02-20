#include "uls.h"

void mx_add_pwd(t_dir_data *dir, t_catalog *cat, char **result) {
    struct passwd *pwd = NULL;
    int nmb_delim = cat->max_lnght_namedir - dir->min_lnght_namedir;

    if ((pwd = getpwuid(dir->buff_stat->st_uid)) != NULL)
        *result = mx_addstr(*result, pwd->pw_name);
    *result = mx_addstr(*result, "  ");
    for (; nmb_delim > 0; *result = mx_addstr(*result, " "), nmb_delim--);
}

void mx_add_grp(t_dir_data *dir, t_catalog *cat, char **result) {
    struct group *grp = NULL;
    //int nmb_delim = cat->max_lnght_grpdir - dir->min_lnght_grpdir;

    if ((grp = getgrgid(dir->buff_stat->st_gid)) != NULL)
        *result = mx_addstr(*result, grp->gr_name);
    else {
        char *temp = mx_itoa(dir->buff_stat->st_gid);

        *result = mx_addstr(*result, temp);
        mx_strdel(&temp);
    }
    // printf("[%d %d %d]\n", cat->max_lnght_grpdir, dir->min_lnght_grpdir, nmb_delim);
    //*result = mx_addstr(*result, " ");
    // for (; nmb_delim > 0; *result = mx_addstr(*result, " "), nmb_delim--);
}
