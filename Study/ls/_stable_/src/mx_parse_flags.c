#include "uls.h"

static void chk_l1C_flags(char c, t_main *info) {
    if (c == 'l') {
        info->flag.is_l = true;
        info->flag.is_1 = false;
        info->flag.is_C = false;
    } if (c == '1') {
        info->flag.is_l = false;
        info->flag.is_1 = true;
        info->flag.is_C = false;
    } if (c == 'C') {
        info->flag.is_l = false;
        info->flag.is_1 = false;
        info->flag.is_C = true;
    }
}

static void chk_line_for_flags(char *argv, t_main *info) {
    for (int i = 0; argv[i] != '\0'; ++i) {
        chk_l1C_flags(argv[i], info);
        if (argv[i] == 'a')
            info->flag.is_a = true;
    }
}

t_catalog *mx_main_parse_fnc(int *argc, char **argv, t_main *info) {
    argv++;
    if (*argc < 2)
        mx_set_flags_false(info->flag);
    else {
        while (*argv) {
            if (*argv[0] != '-')
                break;
            chk_line_for_flags(*argv, info);
            argv++;
            (*argc)--;
        }
    }
    info->am_dir = *argc == 1 ? 1 : *argc - 1;
    mx_init_info(argv, info);
    return info->cat;
}
