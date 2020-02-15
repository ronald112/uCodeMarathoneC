#ifndef PRINTERR_H
#define PRINTERR_H
// обьявления для случая двойного включения
#include <stdbool.h>
#include <stdlib.h>

bool mx_isdigit(int c);
bool mx_isspace(char c);

void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char *s);
char *mx_strcpy(char *dst, const char *src);
int mx_strlen(const char *s);
int mx_strcmp(const char *s1, const char *s2);
int mx_atoi(const char *str);

#endif
