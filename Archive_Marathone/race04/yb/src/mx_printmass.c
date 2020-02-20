#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/errno.h>

void mx_printchar(char c);

void mx_printmass(char *mass, int len, int hight) {
	for (int i = 0; i <= hight; i++) {
		for (int j = 0; j < len; j++) {
			mx_printchar(*(mass + len * i + j));
		}
		mx_printchar('\n');
	}
}

