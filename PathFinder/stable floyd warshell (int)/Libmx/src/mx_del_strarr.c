#include "libmx.h"
// void mx_del_strarr(char ***arr) {

//     int i = 0;
//     printf("%s\n", *arr[0]);
//     printf("%s\n",(*arr)[0]);
//     for (; *arr[i] != NULL; i++) {
//         printf("number of iter: %d\n",i + 1);
//         mx_strdel(arr[i]);
//     }
//     mx_strdel(*arr);
// }   

void mx_del_strarr(char ***arr) {
   for (int i = 0; (*arr)[i] != NULL; i++) {
       mx_strdel(&(*arr)[i]);
   }
   free(*arr);
   *arr = NULL;
}
