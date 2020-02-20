#ifndef LIST_H
#define LIST_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;


t_list *mx_create_node(void *data);

#endif
