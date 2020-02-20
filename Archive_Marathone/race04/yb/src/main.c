#include "header.h"

int main(int argc, char *argv[]) {
	int len = 0;
	int hight = 0;
	mx_errcheck(argv[1], argv[2], argv[3], argv[4],argv[5],argc);
	
	t_coor *coor = mx_oper(mx_atoi(argv[2]), mx_atoi(argv[3]), mx_atoi(argv[4]), mx_atoi(argv[5]));
	if (argc !=6)
		mx_printerr("usage: ./race04 [file_name] [x1] [y1] [x2] [y2]");
	mx_param(argv[1], &len, &hight);
	char *mass = (char *)malloc(sizeof(char) * len * hight);
	mx_fullchar(argv[1], mass);
	int *num = (int *)malloc(sizeof(char) * len * hight);
	mx_math(num, mass, coor, len, hight);
	mx_find_max(num, mass, coor, len, hight);
	mx_way(num, mass, coor, len, hight);

	int file_descriptor = open("path.txt", O_CREAT | O_WRONLY | O_RDONLY, 0666);
	while(hight >= 0) {
		write(file_descriptor, mass, len);
		mass+=len;
		write(file_descriptor, "\n", 1);
		hight--;
	}
	close(file_descriptor);

	return 0;
}

void mx_fullchar(char *file, char *mass) {
	int fd;
	char buf[1];

	fd = open(file, O_RDONLY);
	for (int i = 0; read(fd, buf, 1);) {
		if (buf[0] != '\n' && buf[0] != ',') {
			*(mass + i) = buf[0];	
			i++;
		}
	}
}

void mx_way(int *num, char *mass, t_coor *coor, int len, int hight) {
	int x = coor->x2;
	int y = coor->y2;
	int cell = *(num + x* len + y);
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	*(mass + y * len + x) = 42;

	while (cell != 0) { 
		for (int i = 0; i < 4; i ++) {
			if (*(num + len *(x + dx[i]) + y + dy[i]) == cell - 1) { 
				*(mass + len *(x + dx[i]) + y + dy[i]) = '*';
				x += dx[i];
				y += dy[i];
				continue;
			}
		}
	cell -= 1;
	}
	for (int i = 0; i <= hight; i++) {
        for (int j = 0; j < len; j++) { 
			if (*(mass + len * i + j) =='@')
				*(mass + len * i + j) = '.';
		}
	}
}

void mx_printintmass(int *num, int len, int hight) {
	for (int i = 0; i <= hight; i++) 	{
		for (int j = 0; j < len; j++) {
			mx_printchar('|');
			mx_printint(*(num + len * i + j));
			mx_printchar('|');
		}
		mx_printchar('\n');
	}
}

void mx_find_max(int *num, char *mass, t_coor *coor,  int len, int hight) {
	int max = 0;
	int x;
	int y;
	
	for (int i = 0; i <= hight; i++) {
        for (int j = 0; j < len; j++) { 
			if (max <= *(num + len * i + j)){
				max = *(num + len * i + j);
				x = i;
				y = j;
			}
		}
	}
	for (int i = 0; i <= hight; i++) {
        for (int j = 0; j < len; j++) { 
			if (*(num + len * i + j) == *(num + len * x + y)) 
				*(mass + len * i + j) = 'D';
		}
	}
	if (*(num + len * coor->y2 + coor->x2) == max)
		*(mass + len * coor->y2 + coor->x2) = 'X';
	mx_printstr("dist=");
	mx_printint(*(num + len * x + y));
	mx_printchar('\n');
	mx_printstr("exit=");
	mx_printint(*(num + len * coor->y2 + coor->x2));
	mx_printchar('\n');
}
