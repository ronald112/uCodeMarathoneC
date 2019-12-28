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

// TOHA
// static void lineptr_realloc(char **lineptr, int buf_size, size_t size) {
//     if (size >= malloc_size(*lineptr))
//         *lineptr = mx_realloc(*lineptr, size + buf_size);
// }

// static bool hande_rest_str(char **lineptr, char delim, char **str, size_t *readedbytes) {
//     int char_index;

//     if (*str != NULL) {
//         char_index = mx_get_char_index(*str, delim);
//         if (char_index >= 0) {
//             mx_strdel(lineptr);
//             *lineptr = mx_strnew(0);
//             (*str)++;
//             return true;
//         }
//         else {
//             mx_strcat(*lineptr, *str);
//             (*readedbytes) += mx_strlen(*str);
//         }
//     }
//     return false;
// }

// static void create_lineptr(char **lineptr, char *str, int buf_size) {
//     mx_strdel(lineptr);
//     *lineptr = mx_strnew(buf_size == 2147483647 ? buf_size - 1 :
//                                                   str ? mx_strlen(str)
//                                                         : buf_size);
//     mx_memset(*lineptr, 0, malloc_size(*lineptr));
// }

// int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
//     int sz = 0;
//     int char_index;
//     size_t readedbytes = 0;
//     char *buffer = mx_strnew(buf_size == 2147483647 ? buf_size - 1 : buf_size);
//     static char *str = NULL;
//     bool flag = false;

//     if (fd == -1 || read(fd, buffer, 0))
//         return -2;

//     create_lineptr(lineptr, str, buf_size);
//     flag = hande_rest_str(lineptr, delim, &str, &readedbytes);

//     while (!flag && (sz = read(fd, buffer, buf_size)) >= 0) {
//         char_index = mx_get_char_index(buffer, delim);
    
//         if (char_index >= 0) {
//             lineptr_realloc(lineptr, char_index, readedbytes + 1);
//             mx_strncpy(*lineptr + readedbytes, buffer, char_index);
//             str = (str ? mx_strcpy(str, buffer + char_index + 1)
//                        : mx_strdup(buffer + char_index + 1));
//             readedbytes += char_index;
//             break;
//         }
//         else {
//             if (sz == 0)
//                 return -1;
//             lineptr_realloc(lineptr, buf_size, readedbytes + sz);
//             mx_strcpy(*lineptr + readedbytes, buffer);
//             readedbytes += sz;
//         }
//         mx_memset(buffer, 0, buf_size);
//     }
//     mx_strdel(&buffer);
//     return (int)readedbytes;
// }

// // LEHA
#include "libmx.h"

static char *mx_strncat(char *restrict s1, const char *restrict s2, size_t n) {
    int i = mx_strlen(s1);
    for (int j = 0; s2[j] != '\0' && n--; i++, j++) {
        s1[i] = s2[j];
    }
    s1[i] = '\0';
    return s1;
}

static void add_to_line(char **lineptr, char *fragment, int fr_len) {
    int ptr_len = mx_strlen(*lineptr);
    char *temp = NULL;
    if (*lineptr) {
        temp = mx_strncat(mx_strcpy(mx_strnew(ptr_len + fr_len), *lineptr),
                         fragment, fr_len);
        free(*lineptr);
    } else {
        temp = mx_strndup(fragment, fr_len);
    }
    *lineptr = temp;
}

static bool read_from_buffer(char **lineptr, char delim, const int fd,
                             char **static_buf, int *total_bytes) {
    int di = 0;
    int buf_len = 0;
    
    
    if (!static_buf[fd])
        return false;
    di = mx_get_char_index(static_buf[fd], delim);
    buf_len = mx_strlen(static_buf[fd]);
    if (di >= 0) {
        char *temp = NULL;
        // add fragment until delimeter to line:
        add_to_line(lineptr, static_buf[fd], di);
        // reduce static buffer by fragment length:
        temp = mx_strndup(&static_buf[fd][di+1], buf_len - (di+1));
        free(static_buf[fd]);
        static_buf[fd] = temp;
        *total_bytes += di;
        return true;
    }
    // if delimeter not found then add whole static buffer to line:
    add_to_line(lineptr, static_buf[fd], buf_len);
    *total_bytes += buf_len;
    free(static_buf[fd]);
    static_buf[fd] = NULL;
    return false;
}

static bool read_from_fd(char **lineptr, size_t buf_size, char delim,
                         const int fd, char **static_buf, int *total_bytes) {
    char *buf = mx_strnew(buf_size-1);
    int br = 0;
    int di = 0;
    if (!buf)
        return -2;
    

    while ((br = read(fd, buf, buf_size)) > 0) {
        if ((di = mx_get_char_index(buf, delim)) >= 0) {
            add_to_line(lineptr, buf, di);
            static_buf[fd] = mx_strndup(&buf[di+1], br - (di+1));
            free(buf);
            *total_bytes += di;
            return true;
        }
        add_to_line(lineptr, buf, br);
        *total_bytes += br;
        
        mx_memset(buf, '\0', buf_size);
    }
    free(buf);
    return false;
}
int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    static char *static_buf[4096];
    int total_bytes = 0;
    if (fd < 0 || buf_size <= 0)
        return -2;
    if (read_from_buffer(lineptr, delim, fd, static_buf, &total_bytes) ||
        read_from_fd(lineptr, buf_size, delim, fd, static_buf, &total_bytes)) {
        return total_bytes;
    }
    return -1;
}
