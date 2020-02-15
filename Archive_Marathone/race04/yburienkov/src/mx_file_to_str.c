#include "header.h"
char *mx_file_to_str(const char *filename) {
    if (!filename) return NULL;
    int fd = open(filename, O_RDONLY);
    if (fd == -1) return NULL;
    int length = 0;
    char buf[1];
    while(read(fd, buf, 1) && buf[0] != EOF)
	    length++;
    close(fd);
    char *result = mx_strnew(length);
    if (!result) return NULL;
    fd = open(filename, O_RDONLY);
    if (fd == -1) return NULL;
    read(fd, result, length);
    result[length] = '\0';
    close(fd);
    return result;
}

