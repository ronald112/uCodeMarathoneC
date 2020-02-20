#ifndef MINILIBMX_H
#define MINILIBMX_H
#include "./calculator.h"

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

bool mx_isspace(char c);
bool mx_isdigit(int c);
int mx_atoi(const char *str);
void mx_printchar(char c);
void mx_printint(int n);
int mx_strlen(const char *s);
void mx_printstr(const char *s);

void mx_printerr(const char *s);

#endif
