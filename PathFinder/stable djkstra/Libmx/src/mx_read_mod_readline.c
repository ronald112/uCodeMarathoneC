#include "libmx.h"
static char *strjoin_mod(char *s1, char s2) {
    char *result = NULL;
    if (!s1 && !s2) return result;
    else if (!s2) {
        result = mx_strdup(s1);
        free(s1);
        return result;
    }   
    else {
        result = mx_strnew(mx_strlen(s1) + 1);        
        result = mx_strcpy(result, s1);
        result[mx_strlen(s1)] = s2;
        free(s1);
    }
    return result;
}

// static char *rofl(char *str, int i) {
//     char *result = mx_strnew(i + 1);
//         for (int j = 0; j < mx_strlen(str); j++, i++) {
//             result[j] = str[i];
//         }
//         result[mx_strlen(str)] = '\0';
//     return result;
// }

char *mx_read_mod_readline(size_t buf_size, char delim, const int fd, int *size) {
    char *bufer = mx_strnew(0), *temp = mx_strnew(0);
    static char *static_bufer = "";
    int stat_read = 1, i = 0;
    for (;;) {
        if (mx_strlen(static_bufer) != 0) {
            for (i = 0; *static_bufer != '\0'; static_bufer++, i++) {
                if (*static_bufer == delim) {
                    *size = mx_strlen(bufer);
                    static_bufer++;
                    i++;
                    if (temp) free(temp);
                    temp = mx_strdup(static_bufer);
                    for (; i > 0; i--, static_bufer--); 
                    mx_strdel(&static_bufer);
                    static_bufer = mx_strdup(temp);
                    mx_strdel(&temp);
                    return bufer;
                }
                bufer = strjoin_mod(bufer, *static_bufer);
            }            
                for (; i > 0; i--, static_bufer--);
                if (mx_strlen(static_bufer)) free(static_bufer);
        }
        static_bufer = mx_strnew(buf_size);        
        if ((stat_read = read(fd, static_bufer, buf_size)) < 1) {            
            *size = -1;            
            if (mx_strlen(static_bufer)) free(static_bufer);            
            return bufer;
        }
    }    
}


// test
// char *mx_read_mod_readline(size_t buf_size, char delim, const int fd, int *size) {
//     char *bufer = mx_strnew(0), *temp = mx_strnew(0);
//     static char *static_bufer = NULL;    
//     int stat_read = 1, ind_delim;



//     for (;;) {
//         printf("debug04\n");
        
//         if (static_bufer) {
//             printf("debug05\n");
            
//             if ((ind_delim = mx_get_char_index(static_bufer, delim)) >= 0) {
//                 printf("ind_delim %d\n", ind_delim);
//                 if (mx_strlen(temp)) free(temp);
//                 if (mx_strlen(bufer)) free(bufer);
//                 printf("static_bufer char %c\n", static_bufer[ind_delim]);
//                 temp = mx_strjoin(bufer, mx_strndup(static_bufer, ind_delim));
//                 bufer = mx_strdup(temp);
//                 if (mx_strlen(temp)) free(temp);
//                 *size = mx_strlen(bufer);

//                 for (int j = 0; j < ind_delim; j++, static_bufer++);
                
//                 temp = mx_strdup(static_bufer);
//                 for (int j = ind_delim; j > 0; j--, static_bufer--);
//                 free(static_bufer);
//                 static_bufer = mx_strdup(temp);
//                 printf("static_bufer01 %s\n", static_bufer);
//                 free(temp);

//                 return bufer;
//             }
//             printf("ind_delim %d\n", ind_delim);
//             temp = mx_strdup(bufer);
//             if (mx_strlen(bufer)) free(bufer);
//             bufer = mx_strjoin(temp, static_bufer);
//             if (mx_strlen(temp)) free(temp);
//             free(static_bufer);
//         }
//         static_bufer = mx_strnew(buf_size);
//         if ((stat_read = read(fd, static_bufer, buf_size)) < 1) {            
//             *size = -1;            
//             if (mx_strlen(static_bufer)) free(static_bufer);
//             if (mx_strlen(temp)) free(temp);
//             if (mx_strlen(bufer)) free(bufer);
//             return "";
//         }
//     }    
// }


// for (i = 0; *static_bufer != '\0'; static_bufer++, i++) {
//                 if (*static_bufer == delim) {
//                     *size = mx_strlen(bufer);
//                     static_bufer++;
//                     i++;
//                     free(temp);
//                     temp = mx_strdup(static_bufer);
//                     for (; i > 0; i--, static_bufer--); 
//                     free(static_bufer);
//                     static_bufer = mx_strdup(temp);
//                     free(temp);
//                     return bufer;
//                 }
//                 bufer = mx_strjoin_mod(bufer, *static_bufer);
//             } 

// #include "libmx.h"
// static char *mx_strjoin_mod(char *s1, char s2) {
//     char *result = NULL;
//     if (!s1 && !s2) return result;
//     else if (!s2)  return mx_strdup(s1);      
//     else if (!s1) return mx_strdup(&s2);
//     else {
//         result = mx_strnew(mx_strlen(s1) + 1);
        
//         result = mx_strcpy(result, s1);
//         result[mx_strlen(s1)] = s2;
//         mx_strdel(&s1);
//     }
//     return result;
// }

// char *mx_read_mod_readline(size_t buf_size, char delim, const int fd, int *size) {
//     char *bufer = mx_strnew(0), *temp = "";
//     static char *static_bufer = "";    
//     int stat_read = 1, i = 0;
//     for (;;) {
//         if (mx_strlen(static_bufer) != 0) {
//             for (i = 0; *static_bufer != '\0'; static_bufer++, i++) {
//                 if (*static_bufer == delim) {                    
                    // *size = mx_strlen(bufer);
                    // static_bufer++;
                    // i++;
                    // temp = mx_strdup(static_bufer);
                    // for (; i > 0; i--, static_bufer--); 
                    // mx_strdel(&static_bufer);
                    // static_bufer = mx_strjoin(static_bufer, temp);
                    // mx_strdel(&temp);
                    // return bufer;
//                 }
//                 // bufer = mx_strjoin_mod(bufer, *static_bufer);
//             }            
//                 for (; i > 0; i--, static_bufer--);
//                 if (mx_strlen(static_bufer)) free(static_bufer);
//         }
//         static_bufer = mx_strnew(buf_size);        
//         if ((stat_read = read(fd, static_bufer, buf_size)) < 1) {            
//             *size = -1;            
//             if (mx_strlen(static_bufer)) free(static_bufer);            
//             return bufer;
//         }
//     }    
// }



