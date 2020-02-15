#ifndef MINILIBMX_H
#define MINILIBMX_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>


bool mx_isdigit(int c);
bool mx_isspace(char c);
bool mx_isalpha(int c);
int mx_toupper(int c);
void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char *s);
char *mx_strcpy(char *dst, const char *src);
int mx_atoi(const char *str);
int mx_strlen(const char *s);
int mx_strcmp(const char *s1, const char *s2);
int mx_is_valid_card(const char *s);
void mx_printerr(const char *s);


#endif
