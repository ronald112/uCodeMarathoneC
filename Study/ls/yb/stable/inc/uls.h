#ifndef ULS_H
#define ULS_H

#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/acl.h>
#include <sys/xattr.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "libmx.h"

#define MX_FILE_WS 81

typedef struct s_dir_data {
    struct dirent *data;    // информация про файл/папку дирента
    int min_lnght_namedir;
    int min_lnght_grpdir;
    char *name;             // имя файла или папки
    char *path;             // path to the file/dir
    struct stat *buff_stat; // stat buff
    struct s_dir_data *next;// следующий файл/папка
} t_dir_data;

typedef struct s_catalog {
    blkcnt_t size_of_block;   // size of file/dir
    int max_lnght_namedir;
    int max_lnght_grpdir;
    long long max_size_ofdir;
    long long max_size_oflink;
    bool is_dir;
    char *c_name;           // имя каталога
    t_dir_data *dir;        // все файлы в дир (1)
    t_dir_data *dir_data;   // файлы без . и .. (2)
    int am_files;           // количество (2)
    int am_data;            // количество (1)
    int lines_for_print;    // линии для принтинга
    int max_length;
    struct s_catalog *c_next;
} t_catalog;

typedef struct s_flag {
	bool is_a;
	bool is_l;
	bool is_C;
	bool is_1;
    bool is_tofile;
} t_flag;

typedef struct s_main {     //** структура, которая хранит массивом все каталоги, взятые из аргумента
    int am_dir;             // количество каталогов из аргумента
    char *uls_name;         // add char that keeps "uls: "
    t_catalog *cat;         // массив каталогов (директорик из аргумента)
    t_flag flag;
} t_main;

t_catalog *mx_main_parse_fnc(int *argc, char **argv, t_main *info);
void mx_set_flags_false(t_flag flags);
t_catalog *mx_create_list_of_catalog(int amount);
void mx_init_info(char **argv, t_main *info);
void mx_print_lflag(t_catalog *catalog, t_flag flags);
char *mx_get_full_path(char *name, char *path);
void mx_ladd_to_tdir(t_dir_data *list, t_catalog *cat, t_flag flag);
char *mx_get_permissions(mode_t mode);

void mx_add_xatr(char *path, char **result);
void mx_add_links(nlink_t link, t_catalog *cat, char **result);
void mx_add_pwd(t_dir_data *dir, t_catalog *cat, char **result);
void mx_add_grp(t_dir_data *dir, t_catalog *cat, char **result);
void mx_add_filesize(off_t size, t_catalog *cat, char **result);
void mx_add_lastchange_time(time_t time, char **result);
void mx_add_hardlink(char *path, char **result);

#endif
