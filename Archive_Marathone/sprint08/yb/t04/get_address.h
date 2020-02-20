#ifndef GET_ADDRESS_H
#define GET_ADDRESS_H
// обьявления для случая двойного включения
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

char *mx_strcpy(char *dst, const char *src);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_nbr_to_hex(unsigned long nbr);


#endif
