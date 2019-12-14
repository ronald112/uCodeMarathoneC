#include "libmx.h"
static char *mx_strjoin_mod(char *s1, char s2) {
    char *result = NULL;
    if (!s1 && !s2) return result;
    else if (!s2)  return mx_strdup(s1);      
    else if (!s1) return mx_strdup(&s2);
    else {
        result = mx_strnew(mx_strlen(s1) + 1);
        
        result = mx_strcpy(result, s1);
        result[mx_strlen(s1)] = s2;
        if (mx_strlen(s1) != 0) {            
            mx_strdel(&s1);
        }
    }
    return result;
}
char *mx_read_mod_readline(size_t buf_size, char delim, const int fd, int *size) {
    char *bufer = "";
    static char *static_bufer = "";    
    int stat_read = 1;
    int i = 0;
    for (;;) {
        if (mx_strlen(static_bufer) != 0) {
            for (i = 0; *static_bufer != '\0'; static_bufer++, i++) {
                if (*static_bufer == delim) {  
                    *size = mx_strlen(bufer);
                    static_bufer++;
                    i++;
                    char *temp = mx_strdup(static_bufer);
                    for (; i > 0; i--, static_bufer--); 
                    mx_strdel(&static_bufer);
                    static_bufer = mx_strjoin(static_bufer, temp);
                    mx_strdel(&temp);
                    return bufer;
                }    
                bufer = mx_strjoin_mod(bufer, *static_bufer);
            }            
                for (; i > 0; i--, static_bufer--);        
                mx_strdel(&static_bufer);
        }
        static_bufer = mx_strnew(buf_size);
        if ((stat_read = read(fd, static_bufer, buf_size)) == -1) {
            *size = -1;
            return "";
        } else if (stat_read == 0) {
            *size = -1;
            mx_strdel(&static_bufer);
            mx_strdel(&bufer);
            return "";
        }
    }    
}
