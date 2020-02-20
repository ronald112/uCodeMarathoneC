#ifndef HEADER_H
#define HEADER_H

#define USAGE_MSG "usage: ./race04 [file_name] [x1] [y1] [x2] [y2]\n"
#define MAP_NEXIST "map does not exist\n"
#define MAP_ERROR "map error\n"
#define OUT_OF_RANGE "points are out of map range\n"
#define ENTRY_IS_OBSTACLE "entry point cannot be an obstacle\n"
#define EXIT_IS_OBSTACLE "exit point cannot be an obstacle\n"
#define ROUTE_NFOUND "route not found\n"
#define ERR "error\n"

#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/errno.h>

typedef struct t_mass {
    int x1;
    int y1;
    int x2;
    int y2;
} t_coor;

void mx_errcheck(char *filename, char *x1, char *y1, char *x2, char *y2, int argc);
char *mx_strnew(const int size);
char *mx_file_to_str(const char *filename);
bool mx_isspace(char c);
bool mx_isdigit(char c);
bool mx_valid_char(char c);
void mx_printintmass(int *num, int len, int hight);
void mx_math(int *num, char *mass, t_coor *coor, int len, int hight );
int mx_atoi(const char *str);
void mx_printerr(const char *s);
void mx_printstr(const char *s);
int mx_strlen(const char *s);
void mx_printchar(char c);
void mx_param(char *file, int *len, int *hight);
void mx_printmass(char *mass, int len, int hight);
void mx_fullchar(char *file, char *mass);
t_coor *mx_oper(int x1, int y1, int x2, int y2);
void mx_printint(int n);
void mx_find_max(int *num, char *mass, t_coor *coor,  int len, int hight);
void mx_way(int *num, char *mass, t_coor *coor, int len, int hight);

#endif
