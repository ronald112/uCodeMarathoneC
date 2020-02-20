#ifndef HEADER_H
#define HEADER_H
// обьявления для случая двойного включения

typedef struct s_intarr
{
    int *arr;
    int size;
} t_intarr;

int *mx_copy_int_arr(const int *src, int size);


#endif
