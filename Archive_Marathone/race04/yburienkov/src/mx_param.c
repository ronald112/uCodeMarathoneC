#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/errno.h>

void mx_param(char *file, int *len, int *hight) {
	int fd;
	char buf[1];
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
            exit(1);
	while(buf[0] != '\n') {
		read(fd, buf, 1);
		if (buf[0] != ',' && buf[0] != '\n')
			*len = *len + 1;
	}
	while (read(fd, buf, 1)) {
		if (buf[0] == '\n')
			*hight = *hight + 1;
	}
    if (close(fd) < 0)
        exit(1);
}
