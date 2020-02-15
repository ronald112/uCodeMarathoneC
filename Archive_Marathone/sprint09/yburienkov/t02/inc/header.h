#ifndef HEADER_H
#define HEADER_H
// обьявления для случая двойного включения

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

bool mx_isdigit(int c);//
bool mx_isspace(char c);//



void mx_printchar(char c);//
void mx_printint(int n);//
void mx_printstr(const char *s);//
char *mx_strcpy(char *dst, const char *src);//
int mx_strlen(const char *s);//
int mx_strcmp(const char *s1, const char *s2);//
int mx_atoi(const char *str);//
int mx_strlen(const char *s);//



#endif


