#ifndef MINILIBMX_H
#define MINILIBMX_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h> // use files
#include <stdio.h>
#include <fcntl.h> // file system
#include <errno.h> // standart error



char *mx_file_to_str(const char *filename);
int mx_strlen(const char *s);
char *mx_strcat(char *s1, const char *s2);
char *mx_strcpy(char *dst, const char *src);
char *mx_strnew(const int size);
char *mx_strdup(const char *str);
char *mx_strjoin(char const *s1, char const *s2);



#endif
