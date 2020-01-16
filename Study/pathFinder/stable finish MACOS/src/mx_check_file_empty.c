#include "pathfinder.h"

static void print_err(int case_error, char const *rl_argv) {
    if (case_error == 1) {
        exit(0);
    }
    else if (case_error == 2) {
        mx_printerr("error: file ");
        mx_printerr(rl_argv);
        mx_printerr(" is empty\n");
        exit(1);
    }
    else if (case_error == 3) {
        mx_printerr("error: line 1 is not valid\n");
        exit(1);
    }
}

static void cnt_n(t_main *vars, char *fl_name) {
    for (int i = 0; i < mx_strlen(fl_name); ++i) {
        if (fl_name[i] == '\n')
            vars->cnt_n++;
    }
}

void mx_check_file_empty(t_main *vars, char const *rl_argv) {
    int str = -1;
    char *fl_name = mx_file_to_str(rl_argv);
    char *fl_name_only_symb = mx_del_extra_spaces(fl_name);

    if (mx_strlen(fl_name_only_symb) == 0) {
        print_err(1, rl_argv);
    }
    if ((str = mx_read_line(&vars->str, 2, '\n', vars->fd)) < 0) {
        print_err(3, rl_argv);
    }
    cnt_n(vars, fl_name);
    mx_strdel(&fl_name);
    mx_strdel(&fl_name_only_symb);
}
