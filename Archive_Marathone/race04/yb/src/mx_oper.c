#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/errno.h>
#include "header.h"

t_coor *mx_oper(int x1, int y1, int x2, int y2) {
	t_coor *a =(t_coor *) malloc(sizeof(t_coor));
	a->x1 = x1;
	a->x2 = x2;
	a->y1 = y1;
	a->y2 = y2;
	return a;
}
