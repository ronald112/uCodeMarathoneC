#include <stdbool.h>
/*
bool equal_nums(int a, int b) {
    return a == b;
}
*/
int mx_comparator(const int *arr, int size, int x, bool (*compare)(int, int)) {
    for (int i = 0;i < size; i++) 
        if (compare(x, arr[i])) 
            return i;
    return -1;
}
