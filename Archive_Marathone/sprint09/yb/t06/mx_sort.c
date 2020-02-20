#include <stdbool.h>
/*
bool compare(int a, int b) {
    return a > b;
}
*/

void mx_sort(int *arr, int size, bool (*f)(int, int)) {
    int temp = arr[0];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i; j++) {
            if (f(arr[j], arr[j + 1])) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
