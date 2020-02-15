#ifndef CREATE_NEW_AGENTS
#define CREATE_NEW_AGENTS

#include <stdlib.h>
#include <stdio.h>
#include "agent.h"

// typedef struct s_agent {
// 	char *name;
// 	int power;
//     int strength;
// } t_agent;

char *mx_strcpy(char *dst, const char *src);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_strdup(const char *str);
t_agent *mx_create_agent(char *name, int power, int strength);

#endif
