#include "libmx.h"

// int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
//     if (lineptr != NULL) {        
//         int size = 0;
//         *lineptr = mx_read_mod_readline(buf_size, delim, fd, &size);
//         return size;	    
// 	} else 
//         return -2;
//     return -2;
// }

static void lineptr_realloc(char **lineptr, int buf_size, size_t size) {
    if (size >= malloc_usable_size(*lineptr))
        *lineptr = mx_realloc(*lineptr, size + buf_size);
}

static bool hande_rest_str(char **lineptr, char delim, char **str, size_t *readedbytes) {
    int char_index;

    if (*str != NULL) {
        char_index = mx_get_char_index(*str, delim);
        if (char_index >= 0) {
            mx_strdel(lineptr);
            *lineptr = mx_strnew(0);
            (*str)++;
            return true;
        }
        else {
            mx_strcat(*lineptr, *str);
            (*readedbytes) += mx_strlen(*str);
        }
    }
    return false;
}

static void create_lineptr(char **lineptr, char *str, int buf_size) {
    mx_strdel(lineptr);
    *lineptr = mx_strnew(buf_size == 2147483647 ? buf_size - 1 :
                                                  str ? mx_strlen(str)
                                                        : buf_size);
    mx_memset(*lineptr, 0, malloc_usable_size(*lineptr));
}

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    int sz = 0;
    int char_index;
    size_t readedbytes = 0;
    char *buffer = mx_strnew(buf_size == 2147483647 ? buf_size - 1 : buf_size);
    static char *str = NULL;
    bool flag = false;

    if (fd == -1 || read(fd, buffer, 0))
        return -2;

    create_lineptr(lineptr, str, buf_size);
    flag = hande_rest_str(lineptr, delim, &str, &readedbytes);

    while (!flag && (sz = read(fd, buffer, buf_size)) >= 0) {
        char_index = mx_get_char_index(buffer, delim);
    
        if (char_index >= 0) {
            lineptr_realloc(lineptr, char_index, readedbytes + 1);
            mx_strncpy(*lineptr + readedbytes, buffer, char_index);
            str = (str ? mx_strcpy(str, buffer + char_index + 1)
                       : mx_strdup(buffer + char_index + 1));
            readedbytes += char_index;
            break;
        }
        else {
            if (sz == 0)
                return -1;
            lineptr_realloc(lineptr, buf_size, readedbytes + sz);
            mx_strcpy(*lineptr + readedbytes, buffer);
            readedbytes += sz;
        }
        mx_memset(buffer, 0, buf_size);
    }
    mx_strdel(&buffer);
    return (int)readedbytes;
}


